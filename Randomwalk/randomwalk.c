//
//  randomwalk.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/8/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    srand ( time(NULL) );       //make a random number each time so its not the
    int size = 11;
    int arr[size];
    int times;
    char ans;
    int coinFlip;
    int start = 5;
    
    do {
    printf("Enter the number of times you would like to flip the coin:\n");
        scanf("%d", &times);
        
        for(int i=0; i < size; i++){
            arr[i] = 0;     //makes all values in the array 0.
        }
        
       
      //s array[startPoint] = array[startPoint + 1];
        
        for(int i = 0; i < times; i++) {            //will loop how many tmies user wnts to flip coin.
            coinFlip = rand() % 2; //random values 0 or 1.
            
            //preventative coding  if it reaches the end or start it will get a  1 or zero so that it does not go out of bounds.
            if(start == size){
                coinFlip =1;
            }else if(start == 0){
                coinFlip = 0;
            }
           
            //determins if it is heads it goes right if it is tails it goes left. in the spot in the array.
            if(coinFlip == 0){
                start = start + 1;
                arr[start] = arr[start] +1;
            }else if(coinFlip == 1){
                start = start -1;
                arr[start] = arr[start] + 1;
            }
        }
        
        //the printing statement. Each time we visited we printed a star.
        for(int i=0; i < size; i++) {
            for(int j=0; j <arr[i]; j++){
                printf("*");
            }
            printf("\n");
        }
        
        
        printf("Would you like to run this program again(y,n)?\n"); //asking the user if they want to run program again
        scanf(" %c", &ans);
        
        if(ans == 'y' || ans == 'n'){   //coding prevention so that if user types something else it will ask again.
            }else{
                printf("Would you like to run this program again(y,n)?\n");
                scanf(" %c", &ans);
            }
        
    } while(ans != 'n');
    return 0;
}
