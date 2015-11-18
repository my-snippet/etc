/* Built-in libraries */
#include <iostream>

/* Project libraries */
//#include "BankAccount.h"

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


CBankAccount::CBankAccount() {
    pastBalances = NULL;
}

int main()
{
    CBankAccount instance;

    return 0;
}
