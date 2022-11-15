

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "Grofile.h"

class Parser{
public:

    ifstream grofile;
	vector<string> residue,atom;
	vector<double> atomX,atomY,atomZ;
	vector <int> atom_indx,residue_indx;
    Parser( string );
    
};

#endif
