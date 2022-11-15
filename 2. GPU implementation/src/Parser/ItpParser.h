/*
 * ItpParser.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Emam15
 */

#ifndef PARSER_ITPPARSER_H_
#define PARSER_ITPPARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "Atomtypes.h"
#include "Nonbondparams.h"
#include "Pairtypes.h"

class ItpParser{
public:

	ifstream itp;
	vector<Atomtypes> allatomtypes;
	vector<Nonbond_params> allnonbond;
	//create nonbond names and values matrix
	string nonbond_name[1485][2];
	float nonbond_val[1485][2];
	map<string,map<string,int>> mapitp;
	map<string,int> map_atomtype_name;
	float atomtype_val[58][2];
    ItpParser( string );

};



#endif /* PARSER_ITPPARSER_H_ */
