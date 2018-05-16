//
//  binarytree.h
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/8/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#ifndef binarytree_h
#define binarytree_h

#include <stdio.h>
#include <stdbool.h>


typedef struct node{
    int data;           //making node hold data
    struct node* left;  //left pointer
    struct node* right; //right pointer
}node;

typedef struct binary_tree{
    int size;
    struct node* root;
}binary_tree;

void initialize(binary_tree* bt);
bool search(binary_tree* bt, int key);
void insert(binary_tree* bt, int item);
void printinorder(binary_tree* bt);
void printpreorder(binary_tree* bt);
void printpostorder(binary_tree* bt);
int btsize(binary_tree* bt);
int treeheight(binary_tree* bt);




#endif
