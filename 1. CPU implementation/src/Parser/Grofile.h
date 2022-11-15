/*
 * GroParser.h
 *
 *  Created on: Jan 13, 2020
 *      Author: alireza
 */

#ifndef GROPARSER_H_
#define GROPARSER_H_
#include<string>
using namespace std;
class GroParser {
public:
	GroParser();
	virtual ~GroParser();
	int residue_num;
	string residue_name;
	string atom_name;
	int atom_num;
	double X;
	double Y;
	double Z;
};




#endif /* GROPARSER_H_ */
