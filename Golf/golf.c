//
//  golf.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/27/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = NULL;
    int arrSize = 0;
    int arr[7];
    
   
    int score[90];
    int i = 0;
    

    file = fopen("golf.txt", "r");
    
    
    if (file == NULL) {
        printf("Could not open file golf.txt.\n");
        return -1;
    }
    
    for(i = 0; i < 90; ++i) {
        fscanf(file, "%d", &score[i]);
    }
    
    
    for(i = 0; i < 90; i = i +5) {
        arr[0] = arr[0] + score[i];
        arr[1] = arr[1] + score[i + 1];
        arr[2] = arr[2] + score[i + 2];
        arr[3] = arr[3] + score[i + 3];
        arr[4] = arr[4] + score[i + 4];
        
    }
    
    for(i = 0; i < 5; i++) {
        if(i ==0){
            printf("Par for course: %d\n", arr[i]);
        }else{
        printf("Player %d: %d\n",i, arr[i]);
    }
    }
    
    int low = 100;
    for(i = 1; i < 5; ++i) {
        if(arr[i] != 0) {
            if(arr[i] < low) {
                low = arr[i];
            }
        }
    }
    for(i = 1; i < 5; i++) {
        if(low == arr[i]) {
            printf("\nThe winner is Player %d!\n\n", i);
        }
    }
    return 0;
}
