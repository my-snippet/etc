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
    
    /* Set all values at once */
    CBankAccount(string bankName, int balances, double interestRate);
    
    /* Set methods */
    void setBankName(string bankName);
    void setBalances(int balances);
    void setInterestRate(double interestRate);
    void setPastBalances(int *pastBalances);
    
    /* Set bank name from user input */
    void setBankNameFromUserInput(CBankAccount instance);

    /* Get methods */
    string getBankName();
    int getBalances();
    double getInterestRate();
    int * getPastBalances();
    
    /* Fixed numbers of pastBalances */
    const int numOfPastBalances = 12;
    
    /* Bank name parsing & subsitute */
    tuple<size_t, size_t> FindBankInSentence(string sentence);
    string SubstituteBankName(string sentence, string newBankName);
    
    /* Calculate Compount Interest after years ( using the passed variable ) */
    double CalCompoundInterest(int afterYears);
    
    /* Operator Overloadings */
    friend CBankAccount operator+(CBankAccount& lhs, CBankAccount& rhs);
    friend ostream& operator<<(ostream& out, CBankAccount& obj);
    const CBankAccount& operator =(const CBankAccount &rhs);
};


#endif /* BankAccount_hpp */
