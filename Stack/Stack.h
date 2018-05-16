//
//  Stack.h
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/1/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdbool.h>



typedef struct node_struct
{
    char data[100]; //holds the string
   struct node* next;   //pointer to the next node.
} node;

typedef struct stack_struct
{
    int size;
    node* top; //points to node
} stack;

//given to us in class.


void initialize(stack* s);
void push(stack* s,char* str);
void pop(stack* s, char* str);
void peek(stack* s, char* str);
bool is_empty(stack* s);
int get_length(stack* s);
void display(stack* s);

#endif
