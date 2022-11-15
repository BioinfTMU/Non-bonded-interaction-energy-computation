

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
	vector<string> residue,atom,unique_residue,f_unique_residue;
	vector<float> atomX,atomY,atomZ;
	vector <int> atom_indx,residue_indx,unique_residue_indx,f_unique_residue_indx;
    Parser( string );
    
};

#endif
