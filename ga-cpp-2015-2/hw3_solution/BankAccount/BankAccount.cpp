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

/* Set methods */
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

void setBankNameFromUserInput(CBankAccount instance) {
    string bankNameUserInput;
    cin >> bankNameUserInput;
    instance.setBankName(bankNameUserInput);
}


/* Get methods */
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

/* 
 FindBankInSentence
 It returns a tuple has the positions of Bank name.
 First element : starts with, Second : ends with
*/
tuple<size_t, size_t> CBankAccount::FindBankInSentence(string sentence) {
    string token = "Bank";
    
    size_t bankNameStartPos = sentence.find(token);
    size_t origninalBankNameLength = (
                                      sentence.substr(bankNameStartPos)
                                      ).find_last_of(",") - 1;
    size_t bankNameEndPos = bankNameStartPos + origninalBankNameLength;
    
    return make_tuple(bankNameStartPos, bankNameEndPos);
}

string CBankAccount::SubstituteBankName(string sentence, string newBankName) {
    tuple<size_t, size_t> bankNamePos = this->FindBankInSentence(sentence);
    size_t startPos = get<0>(bankNamePos);
    size_t endPos = get<1>(bankNamePos);
    
    string substitutedSentence = sentence;
    
    substitutedSentence =
    substitutedSentence.erase(startPos, endPos).insert(
                                                       startPos,
                                                       newBankName);
    return substitutedSentence;
}

double CBankAccount::CalCompoundInterest(int afterYears) {    
    double compountInterest;
    
    return compountInterest;
}