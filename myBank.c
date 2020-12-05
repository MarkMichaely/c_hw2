#include <stdio.h>
#include "myBank.h"
#define MAX_ACCOUNTS 50
#define MIN_ACCOUNT_NUM 901
#define MAX_ACCOUNT_NUM 950

double bankAccounts [MAX_ACCOUNTS][2] = {0} ;

/*
 * Function:  openAccount
 * --------------------
 *	checks if its possible to open account and if it is, opens one and deposits a number representing the money.
 *  ammount: the ammount to add to account's balance
 *
 */

void openAccount () {
	double amount=0;
	printf("Initial deposit?\n");
if	(scanf("%lf", &amount)==1)
	{if (amount<0) {
		printf("can't deposit a negative ammount\n" );
		return;
	}
	int i=0;
	while (bankAccounts[i][1]==1 && i<MAX_ACCOUNTS){
		i++;
	}
	if (i>MAX_ACCOUNTS) {
		printf("can't open anymore accounts.\n");
		;
	}
	else{
		bankAccounts[i][0]=amount;
		bankAccounts[i][1]=1;
		printf("account number %d is now opened.\n",MIN_ACCOUNT_NUM+i);
	}}
	else {
		printf("failed to read number\n");
	}
}
/*
 * Function:  balance
 * --------------------
 *	checks if account is open and how much money is in it
 *  account: the account number to check
 *	prints the balance if account is open
 */
void balance () {
	int account=0;
	printf("Account number?\n");
	if (scanf("%d" , &account)==1)
	{if (account>MAX_ACCOUNT_NUM || account<MIN_ACCOUNT_NUM) {
		printf("account not in scope.\n");
		return;
	}
	int i = account-MIN_ACCOUNT_NUM;
	if (bankAccounts[i][1]==1){
		printf("account number %d balance is %.2f.\n", account, bankAccounts[i][0]);
	}
	else {
		printf ("account number %d is closed.\n", account);
	}}
	else {
		printf("failed to read number\n");
	}
}
/*
 * Function:  withdraw
 * --------------------
 *	checks if an account is open and if it is removes money frrom it. removing money only possible if amount removed is higher than balance
 *  account: the account number to check
 *	amount: the amount to withdraw
 *	prints the new balance if Function is sucssessful
 */
void withdraw () {
	int account=0;
	double amount=0;
	printf("Account number?\n");
	if (scanf("%d" , &account)==1)
{
	if (account>MAX_ACCOUNT_NUM || account<MIN_ACCOUNT_NUM) {
		printf("account not in scope.\n");
		return;
	}
	int i = account-MIN_ACCOUNT_NUM;
	if (bankAccounts[i][1]==0) {
		printf("account number %d is closed.\n",account);
	}
	else{
		printf("Amount?\n");
		if	(scanf("%lf", &amount)==1)
		{
			if (amount<0){
				printf("can't withdraw a negative amount\n" );
			}
		else	if (amount<=bankAccounts[i][0]){
			bankAccounts[i][0]-=amount;
			printf("account number %d new balance is %.2f.\n",account,bankAccounts[i][0]);
		}

		else {
		printf("account number %d doesn't have enough money.\n",account);
		}
	}
	else {
		printf("failed to read amount\n");
	}
}

	}
	else {
		printf("failed to read number\n");
	}
}
/*
 * Function:  deposit
 * --------------------
 *	checks if an account is open and if it is adds money to it.
 *  account: the account number to check
 *	amount: the amount to deposit
 *	prints the new balance if Function is sucssessful
 */
void deposit (){
	int account=0;
	double amount=0;
	printf("Account number?\n");
	if	(scanf("%d" , &account)==1){
		if (account>MAX_ACCOUNT_NUM || account<MIN_ACCOUNT_NUM) {
			printf("account not in scope.\n");
			return;
		}
	int i = account-MIN_ACCOUNT_NUM;
	if (bankAccounts[i][1]==0) {
		printf("account number %d is closed.\n",account);
	}
	else {
	printf("Amount?\n");
	if (scanf("%lf", &amount)==1){
	if (amount<0) {
		printf("can't deposit negative amount\n" );
	}
	else{
			bankAccounts[i][0]+=amount;
			printf("account number %d new balance is %.2f.\n", account, bankAccounts[i][0]);
	}}
	else{
		printf("failed to read amount\n" );
	}
		}
	}
}
/*
 * Function:  closeAccount
 * --------------------
 *	checks if an account is open and if it is closes it
 *  account: the account number to check
 */
void closeAccount (){
	int account=0;
	printf("Account number?\n");
	if (scanf("%d" , &account)==1){
	if (account>MAX_ACCOUNT_NUM || account<MIN_ACCOUNT_NUM) {
		printf("account not in scope.\n");
		return;
	}
	int i = account-MIN_ACCOUNT_NUM;
	if (bankAccounts[i][1]==1){
		bankAccounts[i][1]=0;
		printf("account number %d is now closed.\n", account);
	}
	else {
		printf ("account number %d is already closed.\n", account);
		}
	}
	else {
		printf("failed to read number\n");
	}
}
/*
 * Function:  addInterest
 * --------------------
 *	recieves a double as interest rate and computes it on all open accounts as follows: balance * 1.(interest)
 *  interest_rate: the interest that works for the accounts
 */
void addInterest (double interest_rate){
	double interest=0;
	printf("Interest rate?\n");
if	(scanf("%lf", &interest)==1){
	int i=0;
	while (i<MAX_ACCOUNTS){
		if (bankAccounts[i][1]==1){
			bankAccounts[i][0]*= (1+(interest_rate/100 ));
		}
	i++;
	}}
	else {
		printf("failed to read interest\n" );
	}
}
/*
 * Function:  print
 * --------------------
 *	prints every open account
 */
void print(){
	int i=0;
	while (i<MAX_ACCOUNTS){
		if (bankAccounts[i][1]==1){
			printf("account number %d balance is %.2f.\n",MIN_ACCOUNT_NUM+i,bankAccounts[i][0]);
		}
		i++;
	}
}
/*
 * Function:  progExit
 * --------------------
 *	cloeses all accounts
 */
void progExit(){
	int i=0;
	while (i<MAX_ACCOUNTS){
		bankAccounts[i][1]=0;
		i++;
	}
}
