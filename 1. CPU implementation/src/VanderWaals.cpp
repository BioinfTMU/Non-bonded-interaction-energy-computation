#include "VanderWaals.h"
#include <vector>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>


map<string,map<string,string>> mapreplace_V;
map<string,map<string,int>> mapitp_V;
map<string,int> map_atomtype_name_V;
double atomtype_val_V[58][2];
double nonbond_val_V[1485][2];
double coef_V[2];


void vanderwaals_coef (string residuei,string residuej,string ati, string atj)
{
	int indx=0;
	string atom_i="",atom_j="";

	 while(atom_i == ""){
			atom_i=mapreplace_V[residuei][ati];
			ati.pop_back();
	 }
	 while(atom_j ==""){
			atom_j=mapreplace_V[residuej][atj];
			atj.pop_back();
	 }

	if(atom_i != atom_j){
		//find c6 and c12
		indx=mapitp_V[atom_i][atom_j];
		if(indx==0){
			indx=mapitp_V[atom_j][atom_i];
		}
				coef_V[0]=nonbond_val_V[indx-1][0];
				coef_V[1]=nonbond_val_V[indx-1][1];
	}else{
		indx= map_atomtype_name_V[atom_i];
		coef_V[0]=atomtype_val_V[indx-1][0];
		coef_V[1]=atomtype_val_V[indx-1][1];
	}
}




VanderWaals::VanderWaals(vector <int>residue_indx,vector<string> residue,vector<string> atom,vector<double> atomX
		,vector<double> atomY,vector<double>atomZ,double nonbond_val_itp[][2],double atomtype_val_itp[][2],map<string,map<string,string>> mapreplace_rtp,map<string,map<string,int>> mapitp) {

		map<pair<int, int>, int> pairs;
		vector<int> final_residuei_indx,final_residuej_indx;
		vector<double>sum_val;
		vector<string> final_residue_i,final_residue_j;

		mapreplace_V.insert(mapreplace_rtp.begin(),mapreplace_rtp.end());
		mapitp_V.insert(mapitp.begin(),mapitp.end());

		//Parsing ITP file
		for(int i=0;i<1485;i++){
				nonbond_val_V[i][0]=nonbond_val_itp[i][0];
				nonbond_val_V[i][1]=nonbond_val_itp[i][1];
		}
		for(int i=0;i<54;i++){
				atomtype_val_V[i][0]=atomtype_val_itp[i][0];
				atomtype_val_V[i][1]=atomtype_val_itp[i][1];
		}

		cout<<"VanderWaals compute!"<<endl;

		for(int i=0;i<atom.size();i++){
			for(int j=i+1;j<atom.size();j++){
				if(residue_indx.at(i) != residue_indx.at(j)){
					dis=sqrt(pow(atomX.at(i)-atomX.at(j),2.0)+pow(atomY.at(i)-atomY.at(j),2.0)
							+pow(atomZ.at(i)-atomZ.at(j),2.0));
					if(dis<1.0 && dis>0.452){
						//compute c6 and c12
						vanderwaals_coef(residue.at(i),residue.at(j),atom.at(i),atom.at(j));
			//copmute WaanderWaals
						val=((coef_V[1]/pow(dis,12))-(coef_V[0]/pow(dis,6)));
						vanderwaalsi_indx.push_back(residue_indx.at(i));
						vanderwaals_residuei.push_back(residue.at(i));
						vanderwaals_atomi.push_back(atom.at(i));
						vanderwaalsj_indx.push_back(residue_indx.at(j));
						vanderwaals_residuej.push_back(residue.at(j));
						vanderwaals_atomj.push_back(atom.at(j));
						vanderwaals_val.push_back(val);
							//save in map
							pairs.insert(make_pair(make_pair(residue_indx.at(i),residue_indx.at(j)),pairs.size()));
					}
				}
			}
		}


		cout<<"VanderWalls force computed!"<<endl;
		cout<<"Save Results"<<endl;
		for(int i=0;i<pairs.size();i++){
			sum_val.push_back(0);
			final_residue_i.push_back("");
			final_residue_j.push_back("");
			final_residuei_indx.push_back(0);
			final_residuej_indx.push_back(0);
		}

		for(int i=0;i<vanderwaals_val.size();i++){
				sum_val.at(pairs[{ vanderwaalsi_indx.at(i), vanderwaalsj_indx.at(i) }])+=vanderwaals_val.at(i);
				final_residue_i.at(pairs[{ vanderwaalsi_indx.at(i), vanderwaalsj_indx.at(i) }])=vanderwaals_residuei.at(i);
				final_residue_j.at(pairs[{ vanderwaalsi_indx.at(i), vanderwaalsj_indx.at(i) }])=vanderwaals_residuej.at(i);
				final_residuei_indx.at(pairs[{ vanderwaalsi_indx.at(i), vanderwaalsj_indx.at(i) }])=vanderwaalsi_indx.at(i);
				final_residuej_indx.at(pairs[{ vanderwaalsi_indx.at(i), vanderwaalsj_indx.at(i) }])=vanderwaalsj_indx.at(i);
		}


	//save wanderwaals
		  ofstream forcefile ("VanderWaals.csv");
		  if (forcefile.is_open())
		  {
		    	forcefile <<"vander waals force calculate"<<endl;
		    	forcefile <<"Residue index"<<","<<"Residue"<<","<<"Residue index"<<","
		    			<<"Residue"<<","<<"VanderWaals"<<endl;
		    for(int i = 0; i < pairs.size(); i ++){
		    	forcefile <<final_residuei_indx.at(i)<<","<<final_residue_i.at(i) << ","
		    			<<final_residue_j.at(i)<<","
						<< final_residuej_indx.at(i) << ","
						<<sum_val.at(i)<<endl;
		    }
		    forcefile.close();
			cout<<"Results Saved"<<endl;
		  }
		  else cout << "Unable to open forcefile";
}

