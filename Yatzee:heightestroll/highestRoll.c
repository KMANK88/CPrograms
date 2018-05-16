//
//  highestRoll.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 1/31/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   
    char userNameF [30];
    char userNameL [30];
    int Die1,Die2,Die3,Die4,Die5;
    int total=0;
    int small =0;
    int largest =0;
    
    
    srand( time(NULL) );
    Die1 = rand() % 6 +1;
    Die2 = rand() % 6 +1;
    Die3 = rand() % 6 +1;
    Die4 = rand() % 6 +1;
    Die5 = rand() % 6 +1;
    
    small = Die1;
   
    if(Die2 < Die1){
        small = Die2;
    }
    if(Die3 < Die2){
        small = Die3;
    }
    if(Die4 < Die3){
        small = Die4;
    }
    if(Die5 < Die4){
        small = Die5;
    }
    
    
    if(Die1>= Die2 && Die1>= Die3 && Die1>= Die4 && Die1>= Die5){
        largest = Die1;
    }
    if(Die2>= Die1 && Die2>= Die3 && Die2>= Die4 && Die2>= Die5){
        largest = Die2;
    }
    if(Die3>= Die2 && Die3>= Die1 && Die3>= Die4 && Die3>= Die5){
        largest = Die3;
    }
    if(Die4>= Die2 && Die4>= Die3 && Die4>= Die1 && Die1>= Die5){
        largest = Die4;
    }
    if(Die5>= Die2 && Die5>= Die3 && Die5>= Die4 && Die5>= Die1){
        largest = Die5;
    }
   
    
    printf("Please enter your first and last name:\n");
    scanf("%s", userNameF);
    scanf("%s", userNameL);
    printf("Hello %s %s! You rolled:\n", userNameF, userNameL);
    printf("Die 1: %d\n" , Die1);
    printf("Die 2: %d\n" , Die2);
    printf("Die 3: %d\n" , Die3);
    printf("Die 4: %d\n" , Die4);
    printf("Die 5: %d\n" , Die5);
    
    total = Die1 + Die2 +Die3 + Die4 + Die5;
    printf("The total of your 5 die is: %d\n", total );
    printf("The maximum die is: %d\n" , largest);
    printf("The minimum die is: %d\n", small);
    
    
    return 0;
}
