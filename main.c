#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"


int main() {
	char action = ' ';
	bool flag = 1;
//	double amount=0;
//	int account=0;
	while (flag){
		printf("Welcome to your bank account:\n" );
		printf("press key to choose an action from the following: \n" );
		printf("o: Opens account with intial deposit\n" );
		printf("b: Checks the balance of an open account by number\n" );
		printf("d: Deposit money to an open account, returns the new balance\n" );
		printf("w: withdraw money from an open account, returns the new balance\n" );
		printf("c: closes an open account\n" );
		printf("i: adds interest to all open account\n" );
		printf("p: prints all open accounts and their balance\n" );
		printf("e: closes all the account and exits the program\n" );
		printf ("Transaction type?:\n");
		scanf (" %c", &action);
		switch (action)
		{
			case 'o' :
			case 'O' : {
		//		printf("Initial deposit?\n");
		//		scanf("%lf", &amount);
				openAccount();
			}break;
			case 'b' :
			case 'B': {
	//			printf("Account number?\n");
	//			scanf("%d" , &account);
				balance();
			}break;
			case 'd' :
			case 'D': {
	//			printf("Account number?\n");
		//		scanf("%d" , &account);
			//	printf("Amount?\n");
				//scanf("%lf", &amount);
				deposit();
			}break;
			case 'w' :
			case 'W': {
		//		printf("Account number?\n");
		//		scanf("%d" , &account);
		//		printf("Amount?\n");
		//		scanf("%lf", &amount);
				withdraw();
			}break;
			case 'c' :
			case 'C': {
		//		printf("Account number?\n");
		//		scanf("%d" , &account);
				closeAccount ();
			}break;
			case 'i' :
			case 'I': {
//				printf("Interest rate?\n");
	//			scanf("%lf", &amount);
				addInterest();
			}break;
			case 'p' :
			case 'P': {
				print();
			}break;
			case 'e' :
			case 'E': {
				printf("exiting\n");
				progExit();
				flag=0;
			} break;
			default: {
			printf("Error, wrong character for transcation type.\n");
			}
		}
	}
	return 0;
}
