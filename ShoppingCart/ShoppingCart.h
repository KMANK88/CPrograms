//
//  ShoppingCart.h
//
//  Programming Languages
//
//  Created by Karsten Pease on 2/21/18
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#ifndef ShoppingCart_h
#define ShoppingCart_h

#include <stdio.h>
#include "ItemToPurchase.h"

typedef struct ShoppingCart_struct {
     ItemToPurchase cartItems[10];
    char customerName[50];
    char currentDate[50];
    int cartSize;
} ShoppingCart;

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);

ShoppingCart RemoveItem(char itemName[], ShoppingCart cart);

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart);

int GetNumItemsInCart(ShoppingCart cart);

int GetCostOfCart(ShoppingCart cart);

void PrintTotal(ShoppingCart cart);

void PrintDescriptions(ShoppingCart cart);

#endif
