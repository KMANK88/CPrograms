//
//  main.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/20/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include "Contacts.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
char fullName[50];
char phoneNum[50];
char temp[50];

ContactNode* headContact = NULL;
ContactNode* nextContact1 = NULL;
ContactNode* nextContact2 = NULL;




printf("Person 1 \n");
printf("Enter name:\n");
fgets(fullName, 50, stdin);

printf("Enter phone number:\n");
scanf(" %s", phoneNum);

printf("You entered: %s, %s\n\n", fullName, phoneNum);

headContact = (ContactNode*)malloc(sizeof(ContactNode));
CreateContactNode(headContact, fullName, phoneNum, NULL);

fgets(temp, 50, stdin);
printf("Person 2\n");
printf("Enter name:\n");
fgets(fullName, 50, stdin);

printf("Enter phone number:\n");
scanf(" %s", phoneNum);

printf("You entered: %s, %s\n\n", fullName, phoneNum);

nextContact1 = (ContactNode*)malloc(sizeof(ContactNode));
CreateContactNode(nextContact1, fullName, phoneNum, NULL);
InsertContactAfter(headContact, nextContact1);


fgets(temp, 50, stdin);
printf("Person 3\n");
printf("Enter name:\n");
fgets(fullName, 50, stdin);


printf("Enter phone number:\n");
scanf(" %s", phoneNum);

printf("You entered: %s, %s\n\n", fullName, phoneNum);


nextContact2 = (ContactNode*)malloc(sizeof(ContactNode));

CreateContactNode(nextContact2, fullName, phoneNum, NULL);
InsertContactAfter(nextContact1, nextContact2);

printf("CONTACT LIST\n");

PrintContactNode(headContact);

PrintContactNode(nextContact1);

PrintContactNode(nextContact2);

return 0;
}
