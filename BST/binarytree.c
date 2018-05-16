//
//  binarytree.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/8/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include "binarytree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//TREE Height and size?
void initialize(binary_tree* bt){
 
    bt->size =0;
    bt->root = NULL;        //initalize the root and size to 0.
}

bool search( binary_tree* bt, int key){
    
    node* curr = (node*)malloc(sizeof(node));   //creating a temp orary node.
    
    curr = bt->root;            //node is the root
    while(curr != NULL){
        if(key == curr->data){      //if the data is the key return the found key.
           // printf("Found\n");
            return curr;
        }else if(key < curr->data){ // if key is smaller then  node data go left
            curr = curr->left;
        }else{
            curr = curr->right;         //if key is bigger go right on node
        }
    }
   // printf("Could not find");
    return NULL;        //if node not on tree rutrn null.
}

void insert(binary_tree* bt, int key){
    
    node* temp = (node*)malloc(sizeof(node));       //temp node
    node* curr = (node*)malloc(sizeof(node));   //Current node
    temp->data = key;
    
    temp->left = NULL;
    temp->right = NULL; //set the left adn right side to null

    if(bt->root == NULL){
         bt->root = temp;       //if it is null put the data on the root
       
       // printf("Added to root node %d\n", bt->root->data);
    }else{
        curr = bt->root;
        while(curr !=NULL){
        
            if(key < curr->data){       //key is less than data go left
                
                if(curr->left ==NULL){
                    curr->left = temp;
                    //printf("added %d to the left\n", curr->data);
                    curr=NULL;
                }else{
                    //printf("added %d to the left\n", curr->data);
                    curr = curr->left;
                }
            }else{      //key is bigger go right.
                if(curr->right == NULL){
                    //printf("added %d to the left\n", curr->data);

                    curr->right = temp;
                    curr = NULL;
                }else{
                   // printf("added %d to the right\n", curr->data);
                    curr = curr->right;
                }
            }
            
            temp->right = NULL;
            temp->left = NULL;
        }
    }
    bt->size++;     //increase size

}
void printNodeInOrder(node* ptr){
    if(ptr == NULL){
        return;             // return the in order recurrsivly. with passign in a node.
    }
    printNodeInOrder(ptr->left);
    printf("%d ", ptr->data);
    printNodeInOrder(ptr->right);
}

    void printinorder(binary_tree* bt){
         node* temp = (node*)malloc(sizeof(node));
        temp = bt->root;
        printNodeInOrder(temp);     //this accepts a binary tree so another method takes a node.
    }

void printNodePreOrder(node* ptr){
    if(ptr == NULL){
        return;
    }
    printf("%d ", ptr->data);
    printNodePreOrder(ptr->left);
    printNodePreOrder(ptr->right);
}

    void printpreorder(binary_tree* bt){
        node* temp = (node*)malloc(sizeof(node));
        temp = bt->root;
        printNodePreOrder(temp);
    }
void printNodePostOrder(node* ptr){
    if(ptr == NULL){
        return;
    }
    printNodePostOrder(ptr->left);
    printNodePostOrder(ptr->right);
    printf("%d ", ptr->data);
}

    void printpostorder(binary_tree* bt){

        node* temp = (node*)malloc(sizeof(node));
        temp = bt->root;
        printNodePostOrder(temp);
    }

    int btsize(binary_tree* bt){
     //   printf("SIZE is %d" ,bt->size);
        return bt->size;
    }

    int treeheight(binary_tree* bt){
        int height1=0;
        int height2=0;
        int height;
        
        if(bt->root->data == 0){
            return height;
        }else{
            
            
            node* ptr = (node*)malloc(sizeof(node));
            ptr = bt->root;
            
            while(ptr->left != NULL || ptr->right !=NULL){
                height1++;              //if there is one side that is not null increase the height on the right side
                if(ptr->left == NULL){
                    ptr= ptr->left;
                }else{
                    ptr = ptr->right;
                }
            }
            ptr = bt->root;
            while(ptr->left != NULL || ptr->right !=NULL){
                height2++;      //increase the height on the right side.
                if(ptr->right == NULL){
                    ptr = ptr->left;
                }else{
                    ptr = ptr->right;
                }
            }
        }
        
        if(height1 >height2){
            height = height1;   //what is bigger left height or right height.
        }else{
            height = height2;
        }
        
        return height +1 ;
    }



