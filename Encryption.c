/*******************************************************************************
 * Encrypt and Decrypt Files
*******************************************************************************/
#include "Program.h"
/*******************************************************************************
 * This function encrypts a bank account text file.
 * inputs:
 * - int accountNo (indicates which account to encrypt)
 * outputs:
 * - encrypted file (the account's details are encrypted in this file)
*******************************************************************************/
void encrypt(int accountNo) {
    /*127 is how many characters there are in the ASCII table */
    int key = accountNo % 127; 
    if (key == 0) {
        key = 20;
    }

    /* +1 for the NULL character '\0' */
    char accountFilePath[FILE_PATH_LENGTH] = "Accounts/"; 
    char encryptedFilePath[FILE_PATH_LENGTH] = "Accounts/";
    char textExtension[5] = ".txt";

    char strAccNo[MAX_ACCOUNT_NO_LENGTH]; 
    sprintf(strAccNo, "%d", accountNo);

    strncat(accountFilePath, strAccNo, ACCOUNT_NO_LENGTH);
    strncat(accountFilePath, textExtension, 5);

    strncat(encryptedFilePath, strAccNo, ACCOUNT_NO_LENGTH);

    FILE* fr;
    fr = fopen(accountFilePath, "r");
    if (fr == NULL) {
        printf("File does not exist.");
    }
    
    FILE* fw;
    fw = fopen(encryptedFilePath, "a");
    char ch;

    while ((ch = fgetc(fr)) != EOF) {
        ch = ch + key;
        fprintf(fw, "%c", ch);
    }
    remove(accountFilePath);
    fclose(fr);
    fclose(fw);
}
/*******************************************************************************
 * This function decrypts an encrypted bank account text file.
 * inputs:
 * - int accountNo (indicates which account to decrypt)
 * outputs:
 * - A text file (allows the program to read the decrypted text)
*******************************************************************************/
void decrypt(int accountNo) {
    /*127 is how many characters there are in the ASCII table */
    int key = accountNo % 127;
    if (key == 0) {
        key = 20;
    }

    /* +1 for the NULL character '\0' */
    char encryptedFilePath[FILE_PATH_LENGTH] = "Accounts/"; 
    char decryptedFilePath[FILE_PATH_LENGTH] = "Accounts/"; 
    char strAccNo[MAX_ACCOUNT_NO_LENGTH];

    sprintf(strAccNo, "%d", accountNo);
    strncat(encryptedFilePath, strAccNo, ACCOUNT_NO_LENGTH);
    strncat(decryptedFilePath, strAccNo, ACCOUNT_NO_LENGTH);
    char* textExtension = ".txt";
    strncat(decryptedFilePath, textExtension, 4);

    FILE* fr;
    fr = fopen(encryptedFilePath, "r");
    if (fr == NULL) {
        printf("File does not exist.");
    }

    FILE* fw;
    fw = fopen(decryptedFilePath, "a");

    char ch;
    while ((ch = fgetc(fr)) != EOF)
    {
        ch = ch - key;
        fprintf(fw, "%c", ch);
    }
    remove(encryptedFilePath);
    fclose(fr);
    fclose(fw);
}
