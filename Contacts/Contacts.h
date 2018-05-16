//
//  Contacts.h
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/20/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#ifndef Contacts_h
#define Contacts_h

#include <stdio.h>

typedef struct ContactNode_struct{
  
    char contactName[50];
    char contactPhoneNum[50];
    struct ContactNode_struct * nextNodePtr;
}ContactNode;

void CreateContactNode(ContactNode* thisNode, char nameInit[], char phoneNumInit[], ContactNode* nextLoc);

void InsertContactAfter(ContactNode* thisNode, ContactNode* newNode);
ContactNode* GetNextContact(ContactNode* thisNode);

void PrintContactNode();




#endif
