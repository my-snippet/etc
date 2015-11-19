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
#include <tuple>

using namespace std;

//namespace customNameSpace {

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
        void setBankNameFromUserInput();

        /* Get methods */
        const string getBankName() const;
        const int getBalances() const;
        const double getInterestRate() const;
        const int * getPastBalances() const;
        
        /* Fixed numbers of pastBalances */
        const int numOfPastBalances = 12;
        
        /* Bank name parsing & subsitute */
        tuple<size_t, size_t> FindBankInSentence(string sentence);
        string SubstituteBankName(string sentence, string newBankName);
        
        /* Calculate Compound value after years ( using the passed variable ) */
        double CalCompoundValue(int afterYears);
        
        /* Operator Overloadings */
        friend CBankAccount operator+(const CBankAccount& lhs, const CBankAccount& rhs);
        friend ostream& operator<<(ostream& out, const CBankAccount& obj);
        const CBankAccount& operator =(const CBankAccount &rhs);
    };
//}

#endif /* BankAccount_hpp */
