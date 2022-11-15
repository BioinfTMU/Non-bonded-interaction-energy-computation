#include "RtpParser.h"
#include "RtpRename.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

map<string,int> maprtp;

void rtpmapmake(){
		maprtp.insert({"ALA",1});
		maprtp.insert({"ARG",1});
		maprtp.insert({"ASN",1});
		maprtp.insert({"ASP",1});
		maprtp.insert({"CYS",1});
		maprtp.insert({"GLN",1});
		maprtp.insert({"GLU",1});
		maprtp.insert({"GLY",1});
		maprtp.insert({"HISA",1});
		maprtp.insert({"HISB",1});
		maprtp.insert({"HISH",1});
		maprtp.insert({"HIS1",1});
		maprtp.insert({"HIS2",1});
		maprtp.insert({"ILE",1});
		maprtp.insert({"LEU",1});
		maprtp.insert({"LYS",1});
		maprtp.insert({"MET",1});
		maprtp.insert({"PHE",1});
		maprtp.insert({"PRO",1});
		maprtp.insert({"SER",1});
		maprtp.insert({"THR",1});
		maprtp.insert({"TRP",1});
		maprtp.insert({"TYR",1});
		maprtp.insert({"VAL",1});
}



RtpParser::RtpParser(string rtpfile) {
	string rtp_data;
	string amino_acide;
//	//RTP Parser
	rtp.open(rtpfile);
	if (rtp.is_open()) {
		rtpmapmake();
		while (rtp >> rtp_data){
			if(rtp_data != "["){
				getline(rtp, rtp_data);
			}else{
				getline(rtp, rtp_data);
				rtp_data.pop_back();
				rtp_data.pop_back();
				rtp_data.replace(0,1,"");

				if(maprtp[rtp_data] != 0){
					amino_acide=rtp_data;
					getline(rtp, rtp_data);
					while(rtp>>rtp_data&& rtp_data != "["){
						RtpRename rtp_rename;
						rtp_rename.i = rtp_data;
						rtp >> rtp_rename.j;
						rtp>> rtp_rename.charge;
						rtp >> rtp_rename.group;
						//save in map
						mapreplace.insert(make_pair(amino_acide, map<string, string>()));
						mapreplace[amino_acide].insert(make_pair(rtp_rename.i,rtp_rename.j));
						mapreplace_es.insert(make_pair(amino_acide, map<string, float>()));
						mapreplace_es[amino_acide].insert(make_pair(rtp_rename.i,rtp_rename.charge+2));
						residue_S.push_back(amino_acide);
						atom_i_S.push_back(rtp_rename.i);
						atom_j_S.push_back(rtp_rename.j);
					}
				}
			}
		}
	}else{
		cout<<"RTP file does not exist!"<<endl;
	}



	//save index.j
		  ofstream rtp_results ("Rtp_results.txt");
		  if (rtp_results .is_open())
		  {
		    for(int i = 0; i < atom_i_S.size(); i ++){
		    	rtp_results <<residue_S.at(i)<<" "<<atom_i_S.at(i)<<" "<<atom_j_S.at(i)<< endl;
		    }
		    rtp_results .close();
		  }
		  else cout << "Unable to open rto_results";




}
