#include "GroParser.h"
#include "Grofile.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

Parser::Parser(string nameOfFile) {

	string gro_data;
	string residue_name;
	string temp;
	int line_number;
	//GRO Parser

	grofile.open(nameOfFile);
	if (grofile.is_open()) {

		getline(grofile, gro_data);
		getline(grofile, gro_data);
		line_number=atoi(gro_data.c_str());
		while (grofile >> gro_data && line_number){
			residue_name="";
			GroParser gro_pars;
			temp=gro_data;
			for(int i=gro_data.size()-3;i<gro_data.size();i++){
				residue_name+=gro_data[i];
				temp.pop_back();
			}
			gro_pars.residue_name=residue_name;
			gro_pars.residue_num=atoi(temp.c_str());
			grofile >> gro_pars.atom_name;
			grofile>> gro_pars.atom_num;
			grofile >> gro_pars.X;
			grofile >> gro_pars.Y;
			grofile >> gro_pars.Z;
			line_number-=1;
			//save in vector
			residue_indx.push_back(gro_pars.residue_num);
			residue.push_back(gro_pars.residue_name);
			atom_indx.push_back(gro_pars.atom_num);
			atom.push_back(gro_pars.atom_name);
			atomX.push_back(gro_pars.X);
			atomY.push_back(gro_pars.Y);
			atomZ.push_back(gro_pars.Z);
		}
			//His detector
			string HISA="NHCACBCGND1HD1CD2HD2CE1HE1NE2CO";
			string HISB="NHCACBCGND1CD2HD2CE1HE1NE2HE2CO";
			string HISH="NHCACBCGND1HD1CD2HD2CE1HE1NE2HE2CO";
			string HIS1="NHCACBCGND1HD1CD2HD2CE1HE1NE2CO";
			string HIS2="NHCACBCGND1HD1CD2HD2CE1HE1NE2CO";
			string temp_HIS="";
			for(int i=0;i<residue.size();i++){
				if(residue.at(i)=="HIS"){
					for(int j=i;j<i+14;j++){
						temp_HIS+=atom.at(j);
					}
					if(temp_HIS==HISA){
						for(int k=i;k<i+14;k++){
							residue.at(k)="HISA";
						}
					}else if(temp_HIS==HISB){
						for(int k=i;k<i+14;k++){
							residue.at(k)="HISB";
						}

					}else if(temp_HIS==HISH){
						for(int k=i;k<i+14;k++){
							residue.at(k)="HISH";
						}
					}else if(temp_HIS==HIS1){
						for(int k=i;k<i+14;k++){
							residue.at(k)="HIS1";
						}
					}else{
						for(int k=i;k<i+14;k++){
							residue.at(k)="HIS2";
						}
					}
					i=i+13;
				}
			}

 			//save atom coordinates
		  ofstream atomfile ("atomfile.txt");
		  if (atomfile.is_open())
		  {
		    for(int i = 0; i < atom.size(); i ++){
		    	atomfile <<residue_indx.at(i)<<" "<< " "<< residue.at(i)
		    			<<" "<<atom_indx.at(i)<<" "<< atom.at(i)
						<<" "<<atomX.at(0)<<" "<<atomY.at(i)<<" "<<atomZ.at(i)
						<<endl;
		    }
		    atomfile.close();
		  }
		  else cout << "Unable to open atomfile";

	}else{
		cout<<"GRO file does not exist!"<<endl;
	}


}
