//
//  ShoppingCart.c
//  Programming Languages
//  Created by Karsten Pease on 2/21/18
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

int size =0;
int cartTotal = 0;



ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
    cart.cartItems[cart.cartSize] = item;
    //  printf(" your added item %s", cart.cartItems[cart.cartSize].itemName);
   // printf("\n with a price of %d and %d many times" ,cart.cartItems[cart.cartSize].itemPrice, cart.cartItems[cart.cartSize].itemQuantity);
  
    cart.cartSize ++;
    return cart;
    
}

ShoppingCart RemoveItem(char itemName[], ShoppingCart cart) {
    char found = 'n';
    

    for(int i = 0; i < cart.cartSize; i++) {
        if(strcmp(itemName, cart.cartItems[i].itemName) == 0) {
            MakeItemBlank(&cart.cartItems[i]);
            //strcpy(cart.cartItems[i].itemName,"");
            cartTotal =  -(cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity);
            size = -cart.cartItems[i].itemQuantity;
            cart.cartItems[i] = cart.cartItems[i+1];
            
            found = 't';
           
        }
    }
    
    if(found == 'n') {
        printf("Item not found in cart. Nothing removed.\n");
    }
    cart.cartSize --;
    return cart;
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart) {
    char found = 'n';
    
    for(int i = 0; i < cart.cartSize; i++) {
        if(strcmp(item.itemName,cart.cartItems[i].itemName)==0) {
            cart.cartItems[i].itemQuantity = item.itemQuantity;
            found = 't';
        }
        
        
    }
    if(found =='n'){
         printf("Item not found in cart. Nothing modified.\n");
    }
    
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
    size =0;
     for(int i = 0; i < cart.cartSize; i++) {
         
         size = size + cart.cartItems[i].itemQuantity;
         if(cart.cartSize ==0){
             size = 0;
         }
         }
    return size;
}

void PrintTotal(ShoppingCart cart) {
 cartTotal =0;
    for(int i = 0; i < cart.cartSize; i++) {
        cartTotal = cartTotal + (cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity);
       // printf("\n%s\n",cart.cartItems[i].itemName);
        
    }
    for(int i = 0; i < cart.cartSize; i++) {
        
        printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity, cart.cartItems[i].itemPrice, (cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity));
    }
    
    printf("\nTotal: $%d\n", cartTotal);
}

void PrintDescriptions(ShoppingCart cart) {
    //printf("Item Decriptions\n");
    for(int i = 0; i < cart.cartSize; i++) {
        
        printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
    }
    
   
}

