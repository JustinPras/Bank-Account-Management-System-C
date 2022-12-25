/*******************************************************************************
 * Main Menu Screen
*******************************************************************************/
#include "Program.h"
/*******************************************************************************
 * This function prompts the user to decide what to do on the accounts menu
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void accountMenu(){
    int choice;
    do {
        printAccountMenu();
        printf("    Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                getchar();
                createAccount();
                break;
            case 2:
                editAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                displayAccount();
                break;
            case 5:
                deposit();
                break;
            case 6:
                withdraw();
                break;
            case 7:
                break;
            default:
                printf("    Invalid choice.\n");
        }
    } while (choice != 7);
}
/*******************************************************************************
 * This function prints the accounts menu 
 * inputs:
 * - none
 * outputs:
 * - none (prints the accounts menu to the console, with the different options
            the user can choose)
*******************************************************************************/
void printAccountMenu() {
    printf("________________________________________\n\n");
    printf("          Bank Management System\n________________________________________\n\n");
    printf("          1. Create Account\n          2. Update Account\n");
    printf("          3. Delete Account\n          4. Display Account\n");
    printf("          5. Deposit\n          6. Withdraw\n");
    printf("          7. Logout\n");
    printf("________________________________________\n");
}
