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
    
    CBankAccount(string bankName, int balances, double interestRate);
    
    /* set methods */
    void setBankName(string bankName);
    void setBalances(int balances);
    void setInterestRate(double interestRate);
    void setPastBalances(int *pastBalances);
    
    /* get methods */
    string getBankName();
    int getBalances();
    double getInterestRate();
    int * getPastBalances();
};


#endif /* BankAccount_hpp */
