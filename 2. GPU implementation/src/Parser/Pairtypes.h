/*
 * Pairtype.h
 *
 *  Created on: Dec 24, 2019
 *      Author: niloufar
 */

#ifndef PAIRTYPES_H_
#define PAIRTYPES_H_
#include<string>
using namespace std;
class Pairtype {
public:
	Pairtype();
	virtual ~Pairtype();
	string i;
	string j;
	int func;
	double c6;
	double c12;
};

#endif /* PAIRTYPES_H_ */
