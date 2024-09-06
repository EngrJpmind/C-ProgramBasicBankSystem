#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int balance = 1000000;


void printfcomma2 (int n) {
    if (n < 1000) {
        printf ("%d", n);
        return;
    }
    printfcomma2 (n/1000);
    printf (",%03d", n%1000);
}

void clearing();
void home();
void withdraw();
void userbalance();
void deposit();

int main(){
    clearing();

    home();

    return;
}

void clearing(){
    printf("\e[1;1H\e[2J");
}

//---------- coding --------------

void home(){
    clearing();
    int userinput;

    printf("===============Double-J Bank==============\n");
    printf("1. Withdraw\n");
    printf("2. Deposit\n");
    printf("3. Balance\n");

    printf("Input the number of your prefer option: ");
    scanf("%d", &userinput);

    switch(userinput){
        case 1:
            withdraw();
            break;
        case 2:
            deposit();
            break;
        case 3:
            userbalance();
            break;
    }

}

void userbalance(){
    clearing();
    printf("Your Balance: $");
    printfcomma2 (balance/1000);
    printf(",%03d.00\n\n", balance%1000); 
    printf("Press Any Key to Continue\n");  
    getch();
    home();
}

void withdraw(){
    clearing();
    unsigned long n;


    printf("Balance: $");
    printfcomma2 (balance/1000);
    printf(",%03d.00\n", balance%1000);

    printf("How much you would like to withdraw: $");


    scanf("%d", &n);

    while(balance < n){
        clearing();
        printf("Balance: $");
        printfcomma2 (balance/1000);
        printf(",%03d.00\n\n", balance%1000); 


        printf("Insufficinet balance\n");
        printf("How much you would like to withdraw: $");
        scanf("%d", &n);
    }

    balance = balance - n;

    if (n < 1000) {
        clearing();
        printf("You withdraw: $");
        printf ("%d\n\n", n);

        printf("New Balance: $");
        printfcomma2 (balance/1000);
        printf(",%03d.00\n", balance%1000);
        printf("Press Any Key to Continue\n");  
        getch();
        home();
    }
    clearing();
    printf("You withdraw: $");
    printfcomma2 (n/1000);
    printf (",%03d.00\n\n", n%1000);

    printf("New Balance: $");
    printfcomma2 (balance/1000);
    printf(",%03d.00\n", balance%1000);
    printf("Press Any Key to Continue\n");  
    getch();
    home();
}

void deposit(){
    clearing();
    unsigned long n;


    printf("Balance: $");
    printfcomma2 (balance/1000);
    printf(",%03d.00\n", balance%1000);

    printf("How much you would like to Deposit: $");


    scanf("%d", &n);

    balance = balance + n;

    if (n < 1000) {
        clearing();
        printf("You Deposit: $");
        printf ("%d\n\n", n);

        printf("New Balance: $");
        printfcomma2 (balance/1000);
        printf(",%03d.00\n", balance%1000);
        printf("Press Any Key to Continue\n");  
        getch();
        home();
    }
    clearing();
    printf("You Deposit: $");
    printfcomma2 (n/1000);
    printf (",%03d.00\n\n", n%1000);

    printf("New Balance: $");
    printfcomma2 (balance/1000);
    printf(",%03d.00\n", balance%1000);
    printf("Press Any Key to Continue\n");  
    getch();
    home();
}