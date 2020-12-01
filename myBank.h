#ifndef MYBANK_H
#define MYBANK_H
#define MAX_ACCOUNTS 50

extern double bankAccounts[MAX_ACCOUNTS][2];

void openAccount (double amount);

void balance (int account);

void deposit (int account, double amount);

void withdraw (int account, double amount);

void closeAccount (int account);

void addInterest (double interest_rate);

void print ();

void progExit ();



#endif
