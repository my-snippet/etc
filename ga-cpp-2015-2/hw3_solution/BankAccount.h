#pragma once


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
    /*4번 문제 시작
    CPassWord(char * siteAddr, char * accountId, char * accountPassWord, int accountDate);
    CPassWord::CPassWord(char * siteAddr, char * accountId, char * accountPassWord, int accountDate, PasswordHistory *passwdHistory, int size);
    4번 문제 끝*/
/*
    CPassWord(char * siteAddr, char * accountId, char * accountPassWord, int accountDate, PasswordHistory *passwdHistory = 0, int size = 0);
    void showAllPasswrd(int size);
    void setSiteAddr(char * siteAddr);
    char * getSiteAddr();
    void setAccountId(char * accountId);
    char * getAccountId();
    void setAccountPassword(char * accountPassword);
    char * getAccountPassword();
    void setPasswdHistory(int index, char * lastPassword, int passwordDate);
    PasswordHistory getPasswdHistory(int index);
    void showPastPasswrd(int size);
    void setAllPasswrd(char * siteAddr, char * accountId, char * accountPassword, int accountDate, PasswordHistory * passwdHistory, int size);  
    void setAccountDate(int accountDate);
    int getAccountDate();
*/
};
