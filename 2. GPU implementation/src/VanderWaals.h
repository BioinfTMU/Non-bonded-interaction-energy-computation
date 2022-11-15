/*
 * VanderWaals.h
 *
 *  Created on: Jan 17, 2020
 *      Author: Emam15
 */

#ifndef VANDERWAALS_H_
#define VANDERWAALS_H_


#include <vector>
#include <map>
using namespace std;

class VanderWaals{
public:

	vector<string> vanderwaals_residuei,vanderwaals_atomi,vanderwaals_residuej,vanderwaals_atomj;
	vector<float> vanderwaalsi_indx,vanderwaalsj_indx,vanderwaals_val, dis_VW,sigma_VW,epsilon_VW;;
	float dis=0;

    VanderWaals(vector <int>residue_indx,vector<string> residue,vector<string> atom,vector<float> atomX,vector<float> atomY
    		,vector<float>atomZ,float nonbond_val_itp[][2],float atomtype_val_itp[][2],map<string
			,map<string,string>> mapreplace_rtp,map<string,map<string,int>> mapitp);

};


#endif /* VANDERWAALS_H_ */
