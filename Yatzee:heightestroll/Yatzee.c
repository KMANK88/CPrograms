//
//  Yatzee.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 1/30/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int roll=0;
int Die1;
int Die2;
int Die3;
int Die4;
int Die5;


int main(int argc, const char * argv[]) {
   
    char answer;
    int Die1 = rand() % 6 + 1 ;
    int Die2 = rand() % 6 + 1 ;
    int Die3 = rand() % 6 + 1 ;
    int Die4 = rand() % 6 + 1 ;
    int Die5 = rand() % 6 + 1 ;

    printf("Welcome to Yahtzee!!\n");
    printf("You have 3 rolls to try and get 5 of a kind\n\n");

    
    for(int i =0; i < 3; i++){
        roll ++;
    printf("Here we go - roll %d!\n", roll);
    
    printf("Die 1: %d\n" ,Die1);
    printf("Die 2: %d\n" ,Die2);
    printf("Die 3: %d\n" ,Die3 );
    printf("Die 4: %d\n" ,Die4);
    printf("Die 5: %d\n" ,Die5 );
        if(roll == 3){
            break;
        }
    printf("Please answer the following (y or n)\n");
    printf("Would you like to reroll die 1?:\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
        Die1= rand() % 6 +1;
    }else if ( answer == 'n'){
        Die1=Die1;
        }
   
        printf("Would you like to reroll die 2?:\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
        Die2= rand() % 6 +1;
    }else if ( answer == 'n'){
        Die2=Die2;
       
    }
        printf("Would you like to reroll die 3?:\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
        Die3= rand() % 6 +1;
    }else if ( answer == 'n'){
        Die3=Die3;
    }
        printf("Would you like to reroll die 4?:\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
        Die4= rand() % 6 +1;
    }else if ( answer == 'n'){
        Die4=Die4;
    }
        printf("Would you like to reroll die 5?:\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
        Die5= rand() % 6 +1;
    }else if ( answer == 'n'){
        Die5=Die5;
    }
    }
    
    if (Die1 == Die2 && Die2==Die3 && Die3 == Die4 && Die4==Die5){
        printf("***************\n");
        printf("YAHTZEE!!!!!!!!\n");
        printf("***************\n");
    }else{
        printf("Sorry - Better luck next time!");
    }


    return 0;
}
