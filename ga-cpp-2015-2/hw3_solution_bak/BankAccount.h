 /* If use visual studio? then just */
//#pragma once  
/* else */
#ifndef BankAccount_H
#define BankAccount_H
#endif

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
};
