#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*******************************************************************************
 * Constant definitions
*******************************************************************************/
#define NO_OF_LOGIN_DETAILS 1 /* number of allowed login combinations */
#define MAX_PASSWORD_SIZE 20 /* length of password size */
#define MAX_NAME_SIZE 20 /* length of name */
#define MAX_EMAIL_SIZE 40 /* length of email */
#define ACCOUNT_NO_LENGTH 20 /* length of account number */
#define MAX_ACCOUNT_NO_LENGTH 20 /* max length of account number */
#define FILE_PATH_LENGTH 30 /* length of file path */
/*******************************************************************************
 * Structs
*******************************************************************************/
/* struct for login details */
struct details {
    int staffID;
    char password[MAX_PASSWORD_SIZE];
};
typedef struct details details_t;

/* struct for user's birthday */
struct date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};
typedef struct date date_t;

/* struct for user's bank account */
struct account {
    int accountNo;
    char firstName[MAX_NAME_SIZE];
    char lastName[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    char password[MAX_PASSWORD_SIZE];
    float balance;
    date_t birthday;
};
typedef struct account account_t;

/* struct for a linked list */
struct Node {
    struct account acc;
    struct Node *next;
};
typedef struct Node node;
/*******************************************************************************
 * Functions defined in Login.c
*******************************************************************************/
void loginMenu();
void printLoginMenu();
void readDetails(details_t* detailsList, const char ldFileName[]);
int verify(const details_t* detailsList, int staffID, const char password[]);
/*******************************************************************************
 * Functions defined in Runner.c
*******************************************************************************/
void startMenu();
void printStartMenu();
/*******************************************************************************
 * Functions defined in Menu.c
*******************************************************************************/
void accountMenu();
void printAccountMenu();
/*******************************************************************************
 * Functions defined in Accounts.c
*******************************************************************************/
void createAccount();
void editAccount(); 
void deleteAccount(); 
void displayAccount(); 
void deposit();
void withdraw(); 
char* getFName();
char* getLName();
char* getEmail();
char* getPass();
date_t getBirthday();
/*******************************************************************************
 * Functions defined in LinkedList.c
*******************************************************************************/
void addNode(account_t *account);
node* searchNode(int accountNo);
void deleteNode(int accountNo);
/*******************************************************************************
 * Functions defined in FileManager.c
*******************************************************************************/
void editAccountFile(account_t account, char editType);
int readList();
void deleteFile(int accNo);
/*******************************************************************************
 * Functions defined in Encryption.c
*******************************************************************************/
void encrypt(int accountNo);
void decrypt(int accountNo);

#endif
