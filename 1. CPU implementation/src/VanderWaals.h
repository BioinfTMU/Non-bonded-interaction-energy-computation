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
	vector<double> vanderwaalsi_indx,vanderwaalsj_indx,vanderwaals_val;
	double val=0;
	double dis=0;

    VanderWaals(vector <int>residue_indx,vector<string> residue,vector<string> atom,vector<double> atomX,vector<double> atomY
    		,vector<double>atomZ,double nonbond_val_itp[][2],double atomtype_val_itp[][2],map<string
			,map<string,string>> mapreplace_rtp,map<string,map<string,int>> mapitp);

};


#endif /* VANDERWAALS_H_ */
