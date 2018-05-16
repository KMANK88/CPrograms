//
//  Stack.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/1/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include "Stack.h"
#include "Stack.c"
#include <stdbool.h>

int main(void){
    stack a;
    char longString[500];
    char *pointer;
    char *words[200];
    
    int i=0;
    
    initialize(&a);     //set stack a to size 0 and top to NULL.
    FILE* file = NULL;
    file = fopen("myfile.txt","r");   //open/read file
    if(file == NULL){
        printf("Could not open file name.txt\n");//error checking for unreachable file
        return -1;
    }

    fgets(longString, 50,file); //get the strings from the file
    pointer = strtok(longString, " ");  //divides strings into tokens by the " "
    while(pointer != NULL){
        words[i] = pointer;     //assign each word in the array from the pointer
        i++;
        pointer = (strtok(NULL," "));      //empty the pointer we already have stored the value
    }
    for(int j=0; j<i; j++){
       // printf("%s\n",words[j]);
        if(*words[j] == '-' ){          //if ther is "-" pop
            
            pop(&a,words[j]);
            
        }else{              //else push the string on the stack.
           // printf("%d\n",j);
            
            push(&a,words[j]);
            
        }
            }
    display(&a);        //show the info that is left on the stack.

    
    
    return 0;
}
