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
    assert(lhs.bankName == rhs.bankName);
    
    CBankAccount sumAccount(
                            lhs.bankName,
                            lhs.balances + rhs.balances,
                            lhs.interestRate + rhs.interestRate);

    return sumAccount;
}

ostream& operator<<(ostream& out, const CBankAccount& obj) {
    out << "Bank name :" << obj.bankName << "\n";
    out << "Balances :" << obj.balances << "\n";
    out << "InterestRate :" << obj.interestRate << "\n";

    int * pasBalances = obj.pastBalances;
    for(int i = 0 ; i < obj.numOfPastBalances ; i++) {
        out << "PastBalanced #" << i << " : " << pasBalances[i] << "\n";
    }
    
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