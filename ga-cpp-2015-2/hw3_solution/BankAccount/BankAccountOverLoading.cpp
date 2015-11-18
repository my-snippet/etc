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
#include <string>

using namespace std;

CBankAccount operator+(CBankAccount& lhs, CBankAccount& rhs) {
    
    /* Both bank name should be equal */
    assert(lhs.getBankName().compare(rhs.getBankName()) == 0);
    
    CBankAccount sumAccount(
                            lhs.getBankName(),
                            lhs.getBalances() + rhs.getBalances(),
                            lhs.getInterestRate() + rhs.getInterestRate());

    return sumAccount;
}


ostream& operator<<(ostream& out, CBankAccount obj) {
    out << "Bank name :" << obj.getBankName() << "\n";
    out << "Balances :" << obj.getBalances() << "\n";
    out << "InterestRate :" << obj.getInterestRate() << "\n";
    for(int i=0 ; i < obj.getnumOfPastBalances() ; i++) {
        out << "PastBalanced #" << i << " : " << obj.getPastBalances() << "\n";
    }
    return out;
}
