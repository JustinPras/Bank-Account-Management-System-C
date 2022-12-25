/*******************************************************************************
 * Linked List (Account database)
*******************************************************************************/
#include "Program.h"

struct Node *head = NULL;
/*******************************************************************************
 * This function adds a node to the linked list
 * inputs:
 * - account_t *account (indicates what account to add to the linked list)
 * outputs:
 * - none (adds a node to the linked list)
*******************************************************************************/
void addNode(account_t *account) {
    node *newNode = malloc(sizeof(node));
    newNode->acc = *account;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}
/*******************************************************************************
 * This function searches for a node (bank account) in the linked list
 * inputs:
 * - int accountNo (indicates which node to search for)
 * outputs:
 * - node* current (the node that contains the account searched for by the user)
*******************************************************************************/
node* searchNode(int accountNo) {
    node *current = head;
    if (head == NULL) { /*If list is empty */
        return NULL;
    } 
    while (current->acc.accountNo != accountNo) {
        if (current->next == NULL) {
            return NULL;
        } 
        else {
            current = current->next;
        }
    }
    return current;
}
/*******************************************************************************
 * This function deletes a node in the linked list
 * inputs:
 * - int accountNo (indicates which node to search for)
 * outputs:
 * - none (deletes the searched node from the linked list)
*******************************************************************************/
void deleteNode(int accountNo) {
    node *temp = head;
    node *prev = NULL;

    /* if the first node is the searched account */
    if (temp != NULL && temp->acc.accountNo == accountNo) {
        deleteFile(accountNo);
        head = temp->next;
        free(temp);
        printf("\n    Account deleted.\n");
    }
    else {
        /* navigate through list */
        while (temp != NULL && temp->acc.accountNo != accountNo) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\n    Account does not exist...\n");
        }
        else {
            deleteFile(accountNo);
            prev->next = temp->next;
            free(temp);
            printf("\n    Account deleted.\n");
        }
    }
}
