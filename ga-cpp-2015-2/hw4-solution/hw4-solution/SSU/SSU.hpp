//
//  SSU.hpp
//  hw4-solution
//
//  Created by wikibootup on 12/5/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

#ifndef SSU_hpp
#define SSU_hpp

/* Built-in libraries */
#include <iostream>

using namespace std;

class CSSU
{
private:
    string studentName;
    string studentNumber;
    
public:
    CSSU();
    ~CSSU();

    /* Set all values at once */
    CSSU(string studentName, string studentNumber);
    
};

#endif /* SSU_hpp */
