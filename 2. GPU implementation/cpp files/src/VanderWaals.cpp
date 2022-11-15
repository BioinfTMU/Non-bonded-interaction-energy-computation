#include "VanderWaals.h"
#include <vector>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>


map<string,map<string,string>> mapreplace_V;
map<string,map<string,int>> mapitp_V;
map<string,int> map_atomtype_name_V;
float atomtype_val_V[58][2];
float nonbond_val_V[1485][2];
float coef_V[2];


void vanderwaals_coef (string residuei,string residuej,string ati, string atj)
{
	int indx=0;
	string atom_i,atom_j="";

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




VanderWaals::VanderWaals(vector <int>residue_indx,vector<string> residue,vector<string> atom,vector<float> atomX
		,vector<float> atomY,vector<float>atomZ,float nonbond_val_itp[][2],float atomtype_val_itp[][2],map<string,map<string,string>> mapreplace_rtp,map<string,map<string,int>> mapitp) {

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
					dis=sqrt(pow(atomX.at(i)-atomX.at(j),2.0)+pow(atomY.at(i)-atomY.at(j),2.0)
							+pow(atomZ.at(i)-atomZ.at(j),2.0));
					if(dis<=1.0){
						//compute c6 and c12
						vanderwaals_coef(residue.at(i),residue.at(j),atom.at(i),atom.at(j));

			//copmute WaanderWaals
						vanderwaalsi_indx.push_back(residue_indx.at(i));
						vanderwaals_residuei.push_back(residue.at(i));
						vanderwaals_atomi.push_back(atom.at(i));
						vanderwaalsj_indx.push_back(residue_indx.at(j));
						vanderwaals_residuej.push_back(residue.at(j));
						vanderwaals_atomj.push_back(atom.at(j));
						dis_VW.push_back(dis);
						epsilon_VW.push_back(coef_V[1]);
						sigma_VW.push_back(coef_V[0]);
					}
			}
		}

		cout<<"VanderWalls force computed!"<<endl;
		cout<<"Save Results"<<endl;

		//save index.j
			  ofstream index_i_file ("VanderWaals/index_residue.i.txt");
			  if (index_i_file .is_open())
			  {
			    for(int i = 0; i < vanderwaalsi_indx.size(); i ++){
			    	index_i_file <<vanderwaalsi_indx.at(i)<<endl;
			    }
			    index_i_file .close();
			  }
			  else cout << "Unable to open index_residue.i";


				//save residue.i
					  ofstream residue_i_file ("VanderWaals/residue.i.txt");
					  if (residue_i_file .is_open())
					  {
					    for(int i = 0; i < vanderwaals_residuei.size(); i ++){
					    	residue_i_file <<vanderwaals_residuei.at(i)<<endl;
					    }
					    residue_i_file .close();
					  }
					  else cout << "Unable to open residue_i_file";


						//save atom.i
							  ofstream atom_i_file ("VanderWaals/atom.i.txt");
							  if (atom_i_file .is_open())
							  {
							    for(int i = 0; i < vanderwaals_atomi.size(); i ++){
							    	atom_i_file <<vanderwaals_atomi.at(i)<<endl;
							    }
							    atom_i_file .close();
							  }
							  else cout << "Unable to open atom_i_file";




				//save index.j
					  ofstream index_j_file ("VanderWaals/index_residue.j.txt");
					  if (index_j_file .is_open())
					  {
					    for(int i = 0; i < vanderwaalsj_indx.size(); i ++){
					    	index_j_file <<vanderwaalsj_indx.at(i)<<endl;
					    }
					    index_j_file .close();
					  }
					  else cout << "Unable to open index_residue.j";



						//save residue.j
							  ofstream residue_j_file ("VanderWaals/residue.j.txt");
							  if (residue_j_file .is_open())
							  {
							    for(int i = 0; i < vanderwaals_residuej.size(); i ++){
							    	residue_j_file <<vanderwaals_residuej.at(i)<<endl;
							    }
							    residue_j_file .close();
							  }
							  else cout << "Unable to open residue_j_file";


								//save atom.j
									  ofstream atom_j_file ("VanderWaals/atom.j.txt");
									  if (atom_j_file .is_open())
									  {
									    for(int i = 0; i < vanderwaals_atomj.size(); i ++){
									    	atom_j_file <<vanderwaals_atomj.at(i)<<endl;
									    }
									    atom_j_file .close();
									  }
									  else cout << "Unable to open atom_j_file";



								//save dis_pair
									  ofstream dis_pair_file ("VanderWaals/dis_pair.txt");
									  if (dis_pair_file .is_open())
									  {
									    for(int i = 0; i < dis_VW.size(); i ++){
									    	dis_pair_file <<dis_VW.at(i)<<endl;
									    }
									    dis_pair_file .close();
									  }
									  else cout << "Unable to open dis_pair_file";


										//save epsilon
											  ofstream epsilon_file ("VanderWaals/epsilon.txt");
											  if (epsilon_file .is_open())
											  {
											    for(int i = 0; i < epsilon_VW.size(); i ++){
											    	epsilon_file <<epsilon_VW.at(i)<<endl;
											    }
											    epsilon_file .close();
											  }
											  else cout << "Unable to open epsilon_file";


												//save sigma
													  ofstream sigma_file ("VanderWaals/sigma.txt");
													  if (sigma_file .is_open())
													  {
													    for(int i = 0; i < sigma_VW.size(); i ++){
													    	sigma_file <<sigma_VW.at(i)<<endl;
													    }
													    sigma_file .close();
													  }
													  else cout << "Unable to open sigma_file";
}

