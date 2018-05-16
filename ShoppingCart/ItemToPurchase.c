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

 void MakeItemBlank(ItemToPurchase* item){
     strcpy(item->itemName, "none");
     item->itemPrice = 0;
     item->itemQuantity = 0;
     strcpy(item->itemDescription, "none");
 }

void PrintItemCost(ItemToPurchase item){
    printf(" %s %d @ $%d = %d\n", item.itemName, item.itemQuantity, item.itemPrice, (item.itemPrice * item.itemQuantity));
 
}





