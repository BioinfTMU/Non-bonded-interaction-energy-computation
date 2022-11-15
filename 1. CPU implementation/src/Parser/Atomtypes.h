/*
 * Atomtypes.h
 *
 *  Created on: Dec 24, 2019
 *      Author: Niloufar
 */

#ifndef ATOMTYPES_H_
#define ATOMTYPES_H_
#include <string>
using namespace std;
class Atomtypes {
public:
	Atomtypes();
	virtual ~Atomtypes();
	string name;
	int at_num;
	double mass;
	double charge;
	string ptype;
	double c6;
	double c12;
};

#endif /* ATOMTYPES_H_ */
