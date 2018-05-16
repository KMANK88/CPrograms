//
//  ItemToPurchase.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/15/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//
#include <string.h>
#include <stdio.h>
#include "ItemToPurchase.h"

char itemName[50];
int itemPrice;
int itemQuantity;


 void MakeItemBlank(ItemToPurchase* item){
   strcpy(item->itemName, "none");
   item->itemPrice =0;
   item->itemQuantity =0;
}
int totalCost =0;
int cost=0;
int count=0;

void PrintItemCost(ItemToPurchase item){
    if(count ==0){
        printf("TOTAL COST\n");
    }
    count++;
   
    printf("%s %d @ $%d = $%d\n",item.itemName, item.itemQuantity, item.itemPrice, (item.itemPrice * item.itemQuantity));
        cost = item.itemPrice * item.itemQuantity;
        totalCost += cost;
        cost=0;
    if(count == 2){
        printf("Total: $%d\n", totalCost);
    }
 
}





