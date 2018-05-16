//
//  Stack.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/1/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//
#include <stdbool.h>
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initialize(stack* s){
    s->size = 0;    //make stack size 0;
    s->top = NULL;  //put top of stack NULL
}

void push(stack* s,char* str){
    node* temp = (node*)malloc(sizeof(node));   // make some space for the temporary node
    
    if(s == NULL){
        printf("ERROR: stack empty.");  //error checking
    }
    s->size++;  //increase size of array
    strcpy(temp->data, str);    //copy the string that was inserted into temp->data
    temp->next = s->top;    // the next node is now the top;
    
    s->top = temp;      //what ever was on the temp is now the top of the stack.
    
  //  printf("%s is pushed\n", str);
}

void pop(stack* s, char *str){
    if(s->top == NULL){ //error checking
        printf("Error: nothing to pop\n");
        exit(0);
    }
 node* tempPointer;
 tempPointer = (node*)malloc(sizeof(node));
 tempPointer = s->top;  //put the top of the stack on a temp pointer.
 //printf("Poped: %s\n", s->top);
    
 s->top = s->top->next; //make the top next item the top becuase we are removing it.
    
   
    free(tempPointer);  //clearing what was on the temp pointer
    s->size--; //decreaseing the size of the stack.
    
}

void peek(stack* s, char* str){
    if(s->top == NULL){ //error checking. cant peek an empty array.
        printf("Error: nothing to peek\n");
        exit(0);
    }

    node* tp;
    tp = (node*)malloc(sizeof(node));
    tp = s->top;
    printf("Peek probperty: %s \n",tp->data);
    return; //once function is shown, exit out of peek.

}

bool is_empty(stack* s){
 return (s->size ==0);      //checks to see if fucntion size is empty
    
}
int get_length(stack* s){
 return s->size;            //shows size of stack.
}

void display(stack* s){
    
    if(s->top == NULL){//error checking
        printf("Error: Stack is Empty\n");
        exit(0);
    }else{
        node* temp;     //make a temp node. If we do not do this it will change what is on the stack with out using the pop method. 
        temp = (node*)malloc(sizeof(node));     //make space for temp
        temp = s->top;      //what ever is on stack make that the temp node.
 while(temp->next != NULL){     //while the next item on temp node is not null
     printf("%s ",temp->data);  //print the value
    temp = temp->next;      //go to the next item on the stack.
 }
        printf("%s\n", temp->data); //print last value on stack.
       
}
}


