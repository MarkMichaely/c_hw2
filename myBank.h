#ifndef MYBANK_H
#define MYBANK_H
#define MAX_ACCOUNTS 50

extern double bankAccounts[MAX_ACCOUNTS][2];

void openAccount ();

void balance ();

void deposit ();

void withdraw ();

void closeAccount ();

void addInterest ();

void print ();

void progExit ();



#endif
