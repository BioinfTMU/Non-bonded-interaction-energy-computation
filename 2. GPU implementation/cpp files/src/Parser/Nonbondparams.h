/*
 * Nonbondparams.h
 *
 *  Created on: Dec 24, 2019
 *      Author: niloufar
 */

#ifndef NONBONDPARAMS_H_
#define NONBONDPARAMS_H_
#include<string>
using namespace std;
class Nonbond_params {
public:
	Nonbond_params();
	virtual ~Nonbond_params();
	string i;
	string j;
	int func;
	double c6;
	double c12;
};

#endif /* NONBONDPARAMS_H_ */
