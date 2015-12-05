//
//  EE.cpp
//  hw4-solution
//
//  Created by wikibootup on 12/5/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

/* Built-in libraries */
#include "EE.hpp"

using namespace std;

CEE::CEE() {
    
}

CEE::~CEE() {
    
}

/* Set all values at once */
CEE::CEE(string studentName, string studentNumber, string studentMajor)
    :
    CSSU(studentName, studentNumber),
    studentMajor(studentMajor) {
        
}

/* Set methods */
void CEE::setStudentMajor(string studentMajor) {
    this->studentMajor = studentMajor;
}

void CEE::setStudentInfo(string studentName, string studentNumber, string studentMajor) {
    setStudentName(studentName);
    setStudentNumber(studentNumber);
    setStudentMajor(studentMajor);
}

/* Get methods */
string CEE::getStudentMajor() {
    return this->studentMajor;
}