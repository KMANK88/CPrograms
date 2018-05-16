//
//  main7.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/15/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "ItemToPurchase.h"


int main(void){
    char name1[50];
    char name2[50];
    
    ItemToPurchase item1;
    ItemToPurchase item2;
    
    printf("Item 1\n");
    printf("Enter the item name:\n");
    scanf(" %[^\n]s" , name1);
    strcpy(item1.itemName,name1);
    printf("Enter the item price:\n");
    scanf("%d", &item1.itemPrice);
    printf("Enter the item quantity:\n");
    scanf("%d" , &item1.itemQuantity);
    printf("\n");
    fflush(stdin);
    printf("Item 2\n");
    printf("Enter the itemname:\n");
    scanf(" %[^\n]s" , name2);
    strcpy(item2.itemName,name2);
    printf("Enter the item price:\n");
    scanf("%d", &item2.itemPrice);
    printf("Enter the item quantity:\n");
    scanf("%d" , &item2.itemQuantity);
    
    
     PrintItemCost(item1);
     PrintItemCost(item2);
    
    return 0;
}

