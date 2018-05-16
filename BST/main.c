//
//  main.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/8/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>
#include "binarytree.c"
#include "binarytree.h"

int main(){
    
    binary_tree bt;
    
    initialize(&bt);
/*
    insert(&bt, 9);
    insert(&bt,23);
    insert(&bt, 12);
    insert(&bt, 8);
    insert(&bt, 6);
    insert(&bt, 7);
    
    
    insert(&bt, 13);
    printf("Tree height: %d\n", treeheight(&bt));
   //printf("\nPrint in order\n");
   //btsize(&bt);
    // printpostorder(&bt);
    //search(&bt, 14);
*/
    bool found;
    int data;
    FILE* inFile = NULL;
    inFile = fopen("myfile.txt","r");
    fscanf(inFile,"%d", &data);
    while(!feof(inFile)){
        insert(&bt, data);
        fscanf(inFile, "%d", &data);
    }
    
printf("\nPrint in order\n");
printinorder(&bt);
printf("\nPrint pre order\n");
printpreorder(&bt);
printf("\nPrint post order\n");
printpostorder(&bt);
printf("\n");
found = search(&bt,33);
if (found){
    printf("FOUND 33\n");
}
found = search(&bt,38);
if (found){
    printf("FOUND 38\n");
}
printf("Number of elements in tree: %d\n", btsize(&bt));
printf("Tree height: %d\n", treeheight(&bt));

    return 0;
}





