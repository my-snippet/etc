//
//  BankAccountOverLoading.cpp
//  hw3_solution
//
//  Created by wikibootup on 11/19/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

#include "BankAccount.hpp"

/* Built-in libraries */
#include <iostream>
#include <cassert>

using namespace std;
//using namespace customNameSpace;

CBankAccount operator+(const CBankAccount& lhs, const CBankAccount& rhs) {
    /* Both bank name should be equal */
    assert(lhs.getBankName() == rhs.getBankName());

    CBankAccount sumAccount(
                            lhs.getBankName(),
                            lhs.getBalances() + rhs.getBalances(),
                            lhs.getInterestRate() + rhs.interestRate);
    
    return sumAccount;
}

ostream& operator<<(ostream& out, const CBankAccount& obj) {
    /*	
     ostream cascading is not allowed to use string type
     indirect solution about this, copy it to char * variable
     */
    char *copyBankName = new char[obj.getBankName().length() + 1];
    strcpy(copyBankName, obj.bankName.c_str());
    
    out <<"Bank name :" << copyBankName << "\n";
    out << "Balances :" << obj.getBalances() << "\n";
    out << "InterestRate :" << obj.getInterestRate() << "\n";
    
    int * pasBalances = obj.pastBalances;
    for (int i = 0; i < obj.numOfPastBalances; i++) {
        out << "PastBalanced #" << i << " : " << pasBalances[i] << "\n";
    }
    
    delete[] copyBankName;
    
    return out;
}

const CBankAccount& CBankAccount::operator=(const CBankAccount &rhs) {
    if(this == &rhs) {
        return *this;
    }
    else {
        bankName = rhs.bankName;
        balances = rhs.balances;
        interestRate = rhs.interestRate;
        
        if(pastBalances != NULL){
            delete [] pastBalances;
        }
        pastBalances = new int [rhs.numOfPastBalances];
        pastBalances = rhs.pastBalances;
    }
    return *this;
}