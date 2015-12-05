//
//  EE.hpp
//  hw4-solution
//
//  Created by wikibootup on 12/5/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

#ifndef EE_hpp
#define EE_hpp

/* Project libraries */
#include "SSU.hpp"

/* Built-in libraries */
#include <iostream>

using namespace std;

class CEE : public CSSU
{
private:
    string studentMajor;
    
public:
    CEE();
    ~CEE();
    
    /* Set all values at once */
    CEE(string studentName, string studentNumber, string studentMajor);
    
    /* Set methods */
    void setStudentMajor(string studentMajor);
    void setStudentInfo(string studentName, string studentNumber, string studentMajor);
    
    /* Get methods */
    string getStudentMajor();
};

#endif /* EE_hpp */
