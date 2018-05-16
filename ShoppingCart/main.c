//
//  main.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/15/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//


#include<stdio.h>
#include<string.h>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
//#include "ItemToPurchase.c"
//#include "ShoppingCart.c"



void PrintMenu(ShoppingCart cart) {//Made menu here so that it is easier to show, and not in middle of code.
    
    printf("MENU\n");
    printf("a - Add item to cart\n");
    printf("r - Remove item from cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n");
    printf("Choose an option:\n");
    
}
int main(void) {
   
    
    char firstCustomerName[50];
    char lastCustomerName[50];
    char date[100];
    char userChoice;;
    char Name[50];
    char description[100];
    int newQuantity = 0;
    int i=0;
    ShoppingCart cart;
     cart.cartSize = 0;

    printf("Enter Customer's Name:\n");
    scanf("%s", firstCustomerName);
    scanf("%s", lastCustomerName);
    
    printf("Enter Today's Date:\n");
    scanf(" %[^\n]s", date);
    
    printf("Customer Name: %s %s\n", firstCustomerName, lastCustomerName);
    printf("Today's Date: %s\n", date);
    
    
    PrintMenu(cart);
    scanf(" %c", &userChoice);
   
    
    while(userChoice != 'q') {
         ItemToPurchase item;
        
        
        if(userChoice == 'a') {
           
            printf("ADD ITEM TO CART\n");
           
            printf("Enter the item name:\n");
            scanf(" %[^\n]s", Name);
            strcpy(item.itemName, Name);
            printf("Enter the item description:\n");
            scanf(" %[^\n]s",description);
            printf("Enter the item price:\n");
            scanf(" %d", &item.itemPrice);
            printf("Enter the item quantity:\n");
            scanf(" %d", &item.itemQuantity);
            strcpy(item.itemDescription, description);
            
           cart = AddItem(item, cart);
            PrintMenu(cart);
            
            
            
        } else if(userChoice == 'r') {
            printf("REMOVE ITEM FROM CART\n");
            printf("Enter name of item to remove:\n");
            scanf(" %[^\n]s", Name);
           cart = RemoveItem(Name, cart);
            PrintMenu(cart);
          
            
        } else if(userChoice == 'c') {
           ItemToPurchase item;
            printf("CHANGE ITEM QUANTITY\n");
            printf("Enter the item name:\n");
            scanf(" %[^\n]s", Name);
            strcpy(item.itemName, Name);
            printf("Enter the new quantity:\n");
            scanf("%d", &newQuantity);
            item.itemQuantity = newQuantity;
           cart = ModifyItem(item,cart);
           
            PrintMenu(cart);
            
        } else if(userChoice == 'i') {
            printf("OUTPUT ITEMS' DESCRIPTIONS\n");
            printf("%s %s's Shopping Cart - %s\n", firstCustomerName, lastCustomerName, date);
            printf("Item Descriptions\n");
            PrintDescriptions(cart);
            PrintMenu(cart);
            
        } else if(userChoice == 'o') {
            printf("OUTPUT SHOPPING CART\n");
            printf("%s %s's Shopping Cart - %s\n", firstCustomerName, lastCustomerName, date);
            
            printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
          
            
            if(GetNumItemsInCart(cart) ==0){
                printf("SHOPPING CART IS EMPTY\n\n");
            }
            
            
            PrintTotal(cart);
            PrintMenu(cart);
        }else{
            printf("Choose an option:\n");
        }
       
        
        scanf(" %c", &userChoice);
    }
    
    return 0;
}


