/*******************************************************************************
 * Login Screen
*******************************************************************************/
#include "Program.h"
/*******************************************************************************
 * This function prompts the user enter their login details
 * inputs:
 * - none
 * outputs:
 * - none (either takes them to the accounts menu or 
            they have to re-enter details)
*******************************************************************************/
void loginMenu() {
    int staffID;
    char password[MAX_PASSWORD_SIZE];
    char ldFileName[] = "loginDetails.txt";
    details_t detailsList[NO_OF_LOGIN_DETAILS];
    readDetails(detailsList, ldFileName);
    while(1) {
        printf("\n    Enter Staff ID: ");
        scanf("%d", &staffID);
        
        printf("    Enter Password: ");
        scanf("%s", password);
        printf("\n");
        if (verify(detailsList, staffID, password) == 1) {
            readList();
            accountMenu();
            break;
        }
        else{
            printf("    Staff ID or Password is Wrong!\n");
            printf("    Please login again.\n");
        }
    }
}
/*******************************************************************************
 * This function prints the login menu
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void printLoginMenu() {
    printf("________________________________________\n\n");
    printf("          Bank Management System\n________________________________________\n\n");
}
/*******************************************************************************
 * This function verifies the login details inputted by the user
 * inputs:
 * - details_t* detailsList (the list of all allowed login combinations)
 * - int staffID (the staff ID inputted from the user to be verified)
 * - char password[] (the password inputted from the user to be verified)
 * outputs:
 * - int (1 if verified, 0 if unverified)
*******************************************************************************/
int verify(const details_t* detailsList,int staffID, const char password[]) {
    int i;
    for (i = 0; i < NO_OF_LOGIN_DETAILS; i++) {
        if ((detailsList+i)->staffID == staffID) {
            if (strcmp((detailsList+i)->password, password) == 0) {
                return 1;
            }
        }
    }
    return 0;
}
/*******************************************************************************
 * This function reads the allowed login detail combinations from a txt file
 * into the database
 * inputs:
 * - details_t* detailsList (the list of all allowed login combinations)
 * - char ldFileName[] (the name of the txt file filled with login combinations)
 * outputs:
 * - none (inputs data into detailsList)
*******************************************************************************/
void readDetails(details_t* detailsList, const char ldFileName[]) {
    FILE* fp;
    fp = fopen(ldFileName, "r");
    int noOfDetails = 0;
    details_t details;
    while (noOfDetails != NO_OF_LOGIN_DETAILS) { /* Read in employee data */
        fscanf(fp, "%d", &details.staffID);
        fscanf(fp, "%s", details.password);
        
        *(detailsList+noOfDetails) = details;
        noOfDetails++;
    }
    fclose(fp);
}
