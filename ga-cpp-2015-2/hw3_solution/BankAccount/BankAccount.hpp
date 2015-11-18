//
//  BankAccount.hpp
//  hw3_solution
//
//  Created by wikibootup on 11/18/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

#ifndef BankAccount_hpp
#define BankAccount_hpp

/* Built-in libraries */
#include <iostream>

using namespace std;


class CBankAccount
{
private:
    string bankName;
    int balances;
    double interestRate;
    int * pastBalances;
    
public:
    CBankAccount();
    ~CBankAccount();
    
    int * getPastBalances();
};


#endif /* BankAccount_hpp */
