//
//  BankAccount.cpp
//  hw3_solution
//
//  Created by wikibootup on 11/18/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

#include "BankAccount.hpp"

/* Built-in libraries */
#include <iostream>

using namespace std;


CBankAccount::CBankAccount()
    : pastBalances(NULL) {
}

CBankAccount::~CBankAccount() {

}

int * CBankAccount::getPastBalances()
{
    return this->pastBalances;
}