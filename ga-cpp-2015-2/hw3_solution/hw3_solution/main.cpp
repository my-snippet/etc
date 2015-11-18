//
//  main.cpp
//  hw3_solution
//
//  Created by wikibootup on 11/18/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

/* Project libraries */
#include "BankAccount.hpp"

/* Built-in libraries */
#include <iostream>
#include <cassert>

using namespace std;


int _main() {
    /*  Notice :
        This function does not work in the normal way.
        It is called when unit testing.
    */
    
    /* First bank data */
    string firstAccountBankName = "foo Bank";
    int firstAccountBalances = 123;
    double firstAccountInterestRate = 1.23;

    /* Second bank data */
    string secondBankName = "bar Bank";
    int secondBankBalances = 321;
    double secondBankInterestRate = 3.21;

    /* Bank */
    CBankAccount firstAccount(
                              firstAccountBankName,
                              firstAccountBalances,
                              firstAccountInterestRate);
    CBankAccount secondAccount(
                               secondBankName,
                               secondBankBalances,
                               secondBankInterestRate);
    /**/
    
    return 0;
}