#include "ItpParser.h"
#include "Atomtypes.h"
#include "Nonbondparams.h"
#include "Pairtypes.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;




ItpParser::ItpParser(string itpfile) {

	int indx=0;
	string data;
	itp.open(itpfile);

	if (itp.is_open()) {
		//AtomType
		getline(itp, data);
		getline(itp, data);

		while (itp >> data && data != "[") {
			Atomtypes atomtypes;
			atomtypes.name = data;
			 map_atomtype_name.insert({atomtypes.name,indx+1});
			itp >> data;
			atomtypes.at_num = atoi(data.c_str());
			itp >> data;
			atomtypes.mass = atof(data.c_str());
			itp >> data;
			atomtypes.charge = atof(data.c_str());
			itp >> data;
			atomtypes.ptype = data;
			itp >> data;
			atomtypes.c6 = atof(data.c_str());
			atomtype_val[indx][0]=atomtypes.c6;
			itp >> data;
			atomtypes.c12 = atof(data.c_str());
			atomtype_val[indx][1]=atomtypes.c12;
			indx+=1;
		}
		cout<<"Parsing"<<endl;

		//nonebonded
		indx=0;
		getline(itp, data);
		getline(itp, data);

		while (itp >> data && data != "[") {
			Nonbond_params nonbond;
			nonbond.i = data;
			itp >> nonbond.j;
			itp >> nonbond.func;
			itp >> nonbond.c6;
			itp >> nonbond.c12;
			mapitp.insert(make_pair(nonbond.i, map<string, int>()));
			mapitp[nonbond.i].insert(make_pair(nonbond.j, indx+1));
			nonbond_name[indx][0]=nonbond.i;
			nonbond_name[indx][1]=nonbond.j;
			nonbond_val[indx][0]=nonbond.c6;
			nonbond_val[indx][1]=nonbond.c12;
			indx+=1;
		}
	}else{
		cout<<"Itp file does not exist!"<<endl;
	}


	//save itp
		  ofstream itpresult ("itpfile.txt");
		  if (itpresult.is_open())
		  {
		    for(int i = 0; i < indx; i ++){
		    	itpresult << nonbond_name[i][0] << " "<< nonbond_name[i][1]<<" "<< nonbond_val[i][0]
						<<" "<<nonbond_val[i][1]<<endl;
		    }
		    itpresult.close();
		  }
		  else cout << "Unable to open itpresult";
}
