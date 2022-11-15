//============================================================================
// Name        : PDBParser.cpp
// Author      : Niloufar Seyed Majidi
// Version     :
// Copyright   : Niloufar Seyed Majidi
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Parser/GroParser.h"
#include "Parser/RtpParser.h"
#include "Parser/ItpParser.h"
#include "VanderWaals.h"
#include "Electrostatic.h"
#include "Hydrogenbond.h"
#include <iomanip>
#include <time.h>
#include <bits/stdc++.h>



int main() {
	clock_t tStart = clock();

	map<string,map<string,string>> mapreplace;
	map<string,map<string,float>> mapreplace_es;
	map<string,map<string,int>> mapitp;
	map<string,int> map_atomtype_name;
	float atomtype_val[58][2];
	float nonbond_val[1485][2];

	//Gro Parser
	string CompleteGROFileName = "12as.gro";
	Parser GroParser(CompleteGROFileName);

	//parsing RTP file
	string Rtpfile = "aminoacids.rtp";
	RtpParser RtpParser(Rtpfile);
	mapreplace=RtpParser.mapreplace;
	mapreplace_es=RtpParser.mapreplace_es;

	//Parsing ITP file
	string Itpfile = "ffnonbonded.itp";
	ItpParser ItpParser(Itpfile);
	for(int i=0;i<1485;i++){
			nonbond_val[i][0]=ItpParser.nonbond_val[i][0];
			nonbond_val[i][1]=ItpParser.nonbond_val[i][1];
	}
	mapitp=ItpParser.mapitp;
	map_atomtype_name=ItpParser.map_atomtype_name;
	for(int i=0;i<54;i++){
			atomtype_val[i][0]=ItpParser.atomtype_val[i][0];
			atomtype_val[i][1]=ItpParser.atomtype_val[i][1];
	}


//VanderWaals Compute
	VanderWaals VanderWaals(GroParser.residue_indx,GroParser.residue,GroParser.atom,GroParser.atomX
			,GroParser.atomY,GroParser.atomZ,nonbond_val,atomtype_val,mapreplace,mapitp);

//Electrostatic Compute
		Electrostatic Electrostatic(GroParser.residue_indx,GroParser.residue,GroParser.atom,GroParser.atomX
				,GroParser.atomY,GroParser.atomZ,mapreplace_es);

//Hydrogenbond Compute
		Hydrogenbond Hydrogenbond(GroParser.residue_indx,GroParser.residue,GroParser.atom,GroParser.atomX
					,GroParser.atomY,GroParser.atomZ,nonbond_val,atomtype_val,mapreplace,mapitp);


		  cout<<"Time taken:"<< (double)(clock() - tStart)/CLOCKS_PER_SEC;

	return 0;
}
