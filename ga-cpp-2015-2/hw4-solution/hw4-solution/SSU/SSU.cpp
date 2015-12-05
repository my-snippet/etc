//
//  SSU.cpp
//  hw4-solution
//
//  Created by wikibootup on 12/5/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

/* Built-in libraries */
#include "SSU.hpp"

using namespace std;

CSSU::CSSU() {
    
}

CSSU::~CSSU() {
    
}


CSSU::CSSU(string studentName, string studentNumber)
    :
    studentName(studentName),
    studentNumber(studentNumber) {
    
}

/* Get methods */
string CSSU::getStudentName() {
    return this->studentName;
}

string CSSU::getStudentNumber() {
    return this->studentNumber;
}
