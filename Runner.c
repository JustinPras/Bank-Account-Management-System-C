/*Lab 2 Group 5*/
/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3 - Group Project
 * Members: Justin Praseuthsouk - 14172353
            Benjamin Perez - 14286948
            Zideng Mo - 13168380
            Lex Rafter - 
 * Date of submission: 
 * A brief description of what the code's functionality:
 * System is a bank account database management system, 
 * where the different accounts are encrypted and only decrypted
 * when the account details need to be displayed to the employee.
 *
 * A brief statement on what you could achieve (less than 50 words):
 * We were able to achieve everything that we had set for ourselves,
 * except for the component of compression.
 * 
 * A brief statement on what you could NOT achieve (less than 50 words):
 * We were not able to implement compression into our program. It turned out
 * that our files were too small for Run Length Encoding, and instead of 
 * making the file smaller, it actually made the file bigger.
*******************************************************************************/
/*******************************************************************************
 * List header files
*******************************************************************************/
#include "Program.h"

/*******************************************************************************
 * Main
*******************************************************************************/
int main(void) {
    startMenu();
    return -1;
}
/*******************************************************************************
 * This function prompts the user to decide what to do on the start menu
 * inputs:
 * - none
 * outputs:
 * - none (either takes them to the login menu or displays "Invalid choice")
*******************************************************************************/
void startMenu(){
    int choice;
    do {
        printStartMenu();
        printf("    Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch (choice) {
            case 1:
                loginMenu();
                break;
            case 2:
                break;
            default:
                printf("    Invalid choice.\n");
        }
    } while (choice != 2);
}
/*******************************************************************************
 * This function prints the start menu
 * inputs:
 * - none
 * outputs:
 * - none (prints the start menu to the console, with the different options
            the user can choose)
*******************************************************************************/
void printStartMenu() {
    printf("________________________________________\n\n");
    printf("          Bank Management System\n");
    printf("________________________________________\n\n");
    printf("\t  1. Login\n\t  2. Exit\n");
    printf("________________________________________\n");
}
