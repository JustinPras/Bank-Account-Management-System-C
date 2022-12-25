/*******************************************************************************
 * Manage Accounts
*******************************************************************************/
#include "Program.h"

/*******************************************************************************
 * This function prompts the user to create a new account
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void createAccount() {
    char choice;
    do {
        account_t newAcc;

        newAcc.accountNo = readList();

        strcpy(newAcc.firstName, getFName());

        strcpy(newAcc.lastName, getLName());

        printf("    Enter email address: ");
        strcpy(newAcc.email, getEmail());
        
        printf("    Enter password: ");
        strcpy(newAcc.password, getPass());
        
        newAcc.birthday = getBirthday();
        newAcc.balance = 0;
        getchar();
        addNode(&newAcc);
        editAccountFile(newAcc, 'c');
        printf("\n    Your account number is %d.", newAcc.accountNo);
        do {
                printf("\n    ");
                printf("Would you like to create another account? (y/n): ");
                scanf("%c", &choice);
                while(getchar() != '\n');
            } while (choice != 'n' && choice != 'y');
    } while (choice == 'y');

}
/******************************************************************************
 * This function prompts the user to delete an account
 * inputs:
 * - none
 * outputs:
 * - none
******************************************************************************/
void deleteAccount() {
    int key;
    char choice;
    do {
        char x;
        printf("\n    What account would you like to delete?");
        printf("\n    Please enter an account number: ");
        scanf("%d", &key);
        x = getchar();
        if(x == '\n'){
            deleteNode(key);
        }
        else{
            do{
                x = getchar();
            }while(x != '\n');
        }
        do {
            printf("\n    Would you like to delete another account? (y/n): ");
            scanf("%c", &choice);
            while(getchar() != '\n');
        } while (choice != 'n' && choice != 'y');
    } while (choice == 'y');
    
}
/******************************************************************************
 * This function prompts the user to search for an account for which the 
 * program will display that account's details
 * inputs:
 * - none
 * outputs:
 * - none
******************************************************************************/
void displayAccount() {
    int key;
    char choice;
    do {
        char x;
        printf("\n    What account would you like to display?");
        printf("\n    Please enter an account number: ");
        scanf("%d", &key);
        x = getchar();
        if(x == '\n'){
            node *result = searchNode(key);
            if (result == NULL) {
                printf("\n    Account does not exist...\n");
            } 
            else {
                printf("\n    Account %d\n", result->acc.accountNo);
                printf("    Name: %s %s\n", result->acc.firstName,
                                            result->acc.lastName);
                printf("    Email: %s\n", result->acc.email);
                printf("    Birthday: %02d/%02d/%4d\n", result->acc.birthday.day,
                                                        result->acc.birthday.month,
                                                        result->acc.birthday.year);
                printf("    Balance: $%.2f\n", result->acc.balance);
            }
        }
        else{
            do{
                x = getchar();
            }while(x != '\n');
        }
        do {
                printf("\n    ");
                printf("Would you like to search for another account? (y/n): ");
                scanf("%c", &choice);
                while(getchar() != '\n');
            } while (choice != 'n' && choice != 'y');
    } while (choice == 'y');
}
/******************************************************************************
 * This function prompts the user to edit the details of an existing account
 * inputs:
 * - none
 * outputs:
 * - none
******************************************************************************/
void editAccount() {
    int key;
    char choice;
    do {
        char x;
        printf("\n    What account would you like to edit?");
        printf("\n    Please enter an account number: ");
        scanf("%d", &key);
        x = getchar();
        if(x == '\n'){
        node *result = searchNode(key);
            if (result == NULL) {
                printf("\n    Account does not exist...\n");
            } else {
                printf("\n    Updating details for account %d...\n", result->acc.accountNo);

                strcpy(result->acc.firstName, getFName());

                strcpy(result->acc.lastName, getLName());
                printf("    Enter email address: ");
                strcpy(result->acc.email, getEmail());

                printf("    Enter password: ");
                strcpy(result->acc.password, getPass());

                result->acc.birthday = getBirthday();
                while(getchar() != '\n');
                editAccountFile(result->acc, 'e');
                printf("\n    Account details for account %d have been changed...\n", result->acc.accountNo);
            }
        }
        else{
            do{
                x = getchar();
            }while(x != '\n');
        }
        do {
            printf("\n    Would you like to update another account? (y/n): ");
            scanf("%c", &choice);
            while(getchar() != '\n');
        } while (choice != 'n' && choice != 'y');
    } while (choice == 'y');
}
/******************************************************************************
 * This function prompts the user to deposit into an account
 * inputs:
 * - none
 * outputs:
 * - none
******************************************************************************/
void deposit() {
    int key;
    char choice;
    do {
        char x;
        printf("\n    What account would you like to deposit into?");
        printf("\n    Please enter an account number: ");
        scanf("%d", &key);
        x = getchar();
        if(x == '\n'){
            node *result = searchNode(key);
            if (result == NULL) {
                printf("\n    Account does not exist...\n");
            } else {
                float amount = 0;
                printf("\n    Enter amount to deposit: ");
                scanf("%f", &amount);
                getchar();

                while (amount <= 0) {
                    printf("\n    Invalid amount. Enter amount to deposit: ");
                    scanf("%f", &amount);
                    while(getchar() != '\n');
                }

                result->acc.balance = result->acc.balance + amount;
                editAccountFile(result->acc, 'e');
                printf("\n    $%.2f has been deposited into account %d", amount, result->acc.accountNo);
                printf("\n    New balance: $%.2f\n", result->acc.balance);
            }
        }
        else{
            do{
                x = getchar();
            }while(x != '\n');
        }
        do {
            printf("\n    Would you like to deposit into another account? (y/n): ");
            scanf("%c", &choice);
            while(getchar() != '\n');
        } while (choice != 'n' && choice != 'y');
    } while (choice == 'y');
}
/******************************************************************************
 * This function prompts the user to withdraw from an account
 * inputs:
 * - none
 * outputs:
 * - none
******************************************************************************/
void withdraw() {
    int key;
    char choice;
    do {
        char x;
        printf("\n    What account would you like to withdraw from?");
        printf("\n    Please enter an account number: ");
        scanf("%d", &key);
        x = getchar();
        if(x == '\n'){
            node *result = searchNode(key);
            if (result == NULL) {
                printf("\n    Account does not exist...\n");
            } else if (result->acc.balance <= 0) {
                printf("\n    Account has insufficent balance...\n");
            } else {
                float amount = 0;
                printf("\n    Enter amount to withdraw: ");
                scanf("%f", &amount);
                getchar();

                while (amount < 0) {
                    printf("\n    Invalid amount. Enter amount to deposit: ");
                    while(getchar() != '\n');
                    scanf("%f", &amount);
                }

                result->acc.balance = result->acc.balance - amount;
                editAccountFile(result->acc, 'e');
                printf("\n    $%.2f has been withdrawn from account %d", amount, result->acc.accountNo);
                printf("\n    New balance: $%.2f\n", result->acc.balance);
            }
        }
        else{
            do{
                x = getchar();
            }while(x != '\n');
        }
        do {
            printf("\n    Would you like to withdraw from another account? (y/n): ");
            scanf("%c", &choice);
            while(getchar() != '\n');
        } while (choice != 'n' && choice != 'y');
    } while (choice == 'y');
    
}
/*******************************************************************************
 * FUNCTIONS THAT HELP WITH CREATING AN ACCOUNT (GETTERS)
*******************************************************************************/
/*******************************************************************************
 * This function prompts the user to enter the user's first name
 * inputs:
 * - none
 * outputs:
 * - char* name (the employee's first name in proper format)
*******************************************************************************/
char* getFName() {
    char* inputString = (char*) malloc(500); 
    char* name = (char*) malloc(MAX_NAME_SIZE);

    printf("\n    Enter first name: ");

    /* 500 is used as a buffer for bad input */
    fgets(inputString, 500, stdin);

    /* Accept the first 20 digits of the input */
    int i = 0;
    while (i != MAX_NAME_SIZE-1) {
        *(name+i) = *(inputString+i);
        i++;
    }

    /* Remove any form of trailing whitespace */
    int index = -1;
    i = 0;
    while (*(name+i) != '\0') {
        if (*(name+i) != ' ' 
            && *(name+i) != '\t' 
            && *(name+i) != '\n') {
            
            index = i;
        }
        i++;
    }
    *(name+index+1) = '\0';

    return name;
}
/*******************************************************************************
 * This function prompts the user to enter the user's last name
 * inputs:
 * - none
 * outputs:
 * - char* name (the employee's last name in proper format)
*******************************************************************************/
char* getLName() {
    char* inputString = (char*) malloc(500); 
    char* name = (char*) malloc(MAX_NAME_SIZE);

    printf("    Enter last name: ");

    /* 500 is used as a buffer for bad input */
    fgets(inputString, 500, stdin);

    /* Accept the first 20 digits of the input */
    int i = 0;
    while (i != MAX_NAME_SIZE-1) {
        *(name+i) = *(inputString+i);
        i++;
    }

    /* Remove any form of trailing whitespace */
    int index = -1;
    i = 0;
    while (*(name+i) != '\0') {
        if (*(name+i) != ' ' 
            && *(name+i) != '\t' 
            && *(name+i) != '\n') {
            
            index = i;
        }
        i++;
    }
    *(name+index+1) = '\0';

    return name;
}
/*******************************************************************************
 * This function prompts the user to enter the user's email
 * inputs:
 * - none
 * outputs:
 * - char* email (the user's email in proper format)
*******************************************************************************/
char* getEmail() {
    char* inputString = (char*) malloc(500); 
    char* email = (char*) malloc(MAX_EMAIL_SIZE);

    /* 500 is used as a buffer for bad input */
    fgets(inputString, 500, stdin);

    /* Accept the first 40 digits of the input */
    int i = 0;
    while (i != MAX_EMAIL_SIZE-1) {
        *(email+i) = *(inputString+i);
        i++;
    }

    /* Remove any form of trailing whitespace */
    int index = -1;
    i = 0;
    while (*(email+i) != '\0') {
        if (*(email+i) != ' ' 
            && *(email+i) != '\t' 
            && *(email+i) != '\n') {
            
            index = i;
        }
        i++;
    }
    *(email+index+1) = '\0';

    return email;
}
/*******************************************************************************
 * This function prompts the user to enter the user's password
 * inputs:
 * - none
 * outputs:
 * - char* password (the user's password in proper format)
*******************************************************************************/
char* getPass() {
    char* inputString = (char*) malloc(500); 
    char* password = (char*) malloc(MAX_PASSWORD_SIZE);

    /* 500 is used as a buffer for bad input */
    fgets(inputString, 500, stdin);

    /* Accept the first 20 digits of the input */
    int i = 0;
    while (i != MAX_PASSWORD_SIZE-1) {
        *(password+i) = *(inputString+i);
        i++;
    }

    /* Remove any form of trailing whitespace */
    int index = -1;
    i = 0;
    while (*(password+i) != '\0') {
        if (*(password+i) != ' ' 
            && *(password+i) != '\t' 
            && *(password+i) != '\n') {
            
            index = i;
        }
        i++;
    }
    *(password+index+1) = '\0';

    return password;
}
/*******************************************************************************
 * This function prompts the user to enter the user's birthday and handles
 * bad input.
 * inputs:
 * - none
 * outputs:
 * - date_t birthday (the user's birthday)
*******************************************************************************/
date_t getBirthday() {
    date_t birthday;

    printf("    Enter birthday: Day: ");
    scanf("%u", &birthday.day);

    /* Prompts the user to enter a day in correct format until valid */
    while (birthday.day < 1 || birthday.day > 31) {
        printf("    Invalid day. Enter birthday: Day: ");
        while(getchar() != '\n');
        scanf("%u", &birthday.day);
    }

    printf("    Enter birthday: Month: ");
    scanf("%u", &birthday.month);

    /* Prompts the user to enter a month in correct format until valid */
    while (birthday.month < 1 || birthday.month > 12) {
        printf("    Invalid month. Enter birthday: Month: ");
        while(getchar() != '\n');
        scanf("%u", &birthday.month);
    }

    printf("    Enter birthday: Year: ");
    scanf("%u", &birthday.year);

    /* Prompts the user to enter a year in correct format until valid */
    while (birthday.year < 1800 || birthday.year > 2017) {
        printf("    Invalid year. Enter birthday: Year: ");
        while(getchar() != '\n');
        scanf("%u", &birthday.year);
    }
    return birthday;
}
