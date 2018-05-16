//
//  ItemToPurchase.h
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/15/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#ifndef _ItemToPurchase_h
#define _ItemToPurchase_h

typedef struct ItemToPurchase_struct{
    char itemName[50];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase* item);
void PrintItemCost(ItemToPurchase item);


#endif




