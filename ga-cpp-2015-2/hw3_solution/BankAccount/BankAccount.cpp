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
#include <cassert>

using namespace std;


CBankAccount::CBankAccount()
    : pastBalances(NULL) {
}

CBankAccount::~CBankAccount() {

}

/* Set all values at once */
CBankAccount::CBankAccount(string bankName, int balances, double interestRate)
    : pastBalances(NULL) {
    CBankAccount::setBankName(bankName);
    CBankAccount::setBalances(balances);
    CBankAccount::setInterestRate(interestRate);
}


/* set methods */
void CBankAccount::setBankName(string bankName) {
    this->bankName = bankName;
}

void CBankAccount::setBalances(int balances) {
    this->balances = balances;
}

void CBankAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

void CBankAccount::setPastBalances(int * pastBalances) {
    if(this->pastBalances != NULL)
    {
        delete this->pastBalances;
    }
    
    this->pastBalances = new int[this->numOfPastBalances + 1];
    assert(this->pastBalances != NULL);
    
    copy_n(
           pastBalances,
           this->numOfPastBalances ,
           this->pastBalances);
}

/* get methods */
string CBankAccount::getBankName() {
    return this->bankName;
}

int CBankAccount::getBalances() {
    return this->balances;
}

double CBankAccount::getInterestRate() {
    return this->interestRate;
}

int * CBankAccount::getPastBalances() {
    return this->pastBalances;
}

tuple<size_t, size_t> CBankAccount::FindBankInSentence(string sentence) {
    string token = "Bank";
    
    size_t bankNameStartPos = sentence.find(token);
    size_t origninalBankNameLength = (
                                      sentence.substr(bankNameStartPos)
                                      ).find_last_of(",") - 1;
    size_t bankNameEndPos = bankNameStartPos + origninalBankNameLength;
    
    return make_tuple(bankNameStartPos, bankNameEndPos);
}