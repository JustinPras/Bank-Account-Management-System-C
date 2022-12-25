/*******************************************************************************
 * Manage the Database (Files)
*******************************************************************************/
#include "Program.h"

/*******************************************************************************
 * This function encrypts a bank account text file.
 * inputs:
 * - int accountNo (indicates which account to encrypt)
 * outputs:
 * - encrypted file ()
*******************************************************************************/
void editAccountFile(account_t account, char editType) {
    char filePath[FILE_PATH_LENGTH] = "Accounts/"; 
    char strAccNo[MAX_ACCOUNT_NO_LENGTH];
    char textExtension[5] = ".txt";
    
    sprintf(strAccNo, "%d", account.accountNo);
    strncat(filePath, strAccNo, ACCOUNT_NO_LENGTH);
    if (editType == 'e') {
        remove(filePath);
    }
    strncat(filePath, textExtension, 4);

    FILE* fp;
    fp = fopen(filePath, "w");
    fprintf(fp, "%d %s %s %s %s %f %u %u %u", account.accountNo,
                                            account.firstName,
                                            account.lastName,
                                            account.email,
                                            account.password,
                                            account.balance,
                                            account.birthday.day,
                                            account.birthday.month,
                                            account.birthday.year);
    fclose(fp);
    encrypt(account.accountNo);
}
int readList() {
    int accNo = 100001;
    FILE* fp;
    char filePath[FILE_PATH_LENGTH] = "Accounts/"; 
    char strAccNo[MAX_ACCOUNT_NO_LENGTH];
    char textExtension[5] = ".txt";

    while (1) {
        sprintf(strAccNo, "%d", accNo);
        strncat(filePath, strAccNo, ACCOUNT_NO_LENGTH);
        
        if ((fp = fopen(filePath, "r"))) { 
            decrypt(accNo);
            strncat(filePath, textExtension, 4);
            fp = fopen(filePath, "r");
            account_t account;

            fscanf(fp, "%d", &account.accountNo);
            if (account.accountNo == 0) {
                encrypt(accNo);
                accNo++;
                memmove(filePath, "Accounts/", 10);
                continue;
            }
            fscanf(fp, "%s", account.firstName);
            fscanf(fp, "%s", account.lastName);
            fscanf(fp, "%s", account.email);
            fscanf(fp, "%s", account.password);
            fscanf(fp, "%f", &account.balance);
            fscanf(fp, "%u", &account.birthday.day);
            fscanf(fp, "%u", &account.birthday.month);
            fscanf(fp, "%u", &account.birthday.year);
            addNode(&account);
            encrypt(accNo);
            memmove(filePath, "Accounts/", 10);
            accNo++;
            
        }
        else {
            break;
        }
    }
    return accNo;
}
/*******************************************************************************
 * This function encrypts a bank account text file.
 * inputs:
 * - int accountNo (indicates which account to encrypt)
 * outputs:
 * - encrypted file ()
*******************************************************************************/
void deleteFile(int accNo) {
    FILE* fp;
    
    char filePath[FILE_PATH_LENGTH] = "Accounts/"; 
    char strAccNo[MAX_ACCOUNT_NO_LENGTH];
    char textExtension[5] = ".txt";
    
    sprintf(strAccNo, "%d", accNo);
    strncat(filePath, strAccNo, ACCOUNT_NO_LENGTH);
    strncat(filePath, textExtension, 4);
    decrypt(accNo);

    fp = fopen(filePath, "w");
    fprintf(fp, "%d", 0);
    fclose(fp);
    encrypt(accNo);
}
