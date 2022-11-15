/*
 * RtpParser.h
 *
 *  Created on: Jan 14, 2020
 *      Author: biocool
 */

#ifndef SRC_PARSER_RTPPARSER_H_
#define SRC_PARSER_RTPPARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "RtpRename.h"

class RtpParser{
public:

    ifstream rtp;
    map<string,map<string,string>> mapreplace;
    map<string,map<string,double>>mapreplace_es;
    RtpParser( string );

};



#endif /* SRC_PARSER_RTPPARSER_H_ */
