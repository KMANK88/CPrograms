//
//  main.c

//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/27/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {
    char title[50];
    char col1[50];
    char col2[50];
    int point[50];
    char names[50][50];
    int k=0;
    printf("Enter a title for the data:\n");
    fgets (title, 50, stdin);       //input the title
    printf("You entered: %s\n", title);
    printf("Enter the column 1 header:\n");
    fgets (col1, 50, stdin);    //col 1 input
    printf("You entered: %s\n", col1);
    printf("Enter the column 2 header:\n");
    fgets (col2, 50, stdin);    //col 2 input
    printf("You entered: %s\n", col2);
    col1[strlen(col1) - 1] = '\0';  // making the last char empty.
    col2[strlen(col2) - 1] = '\0';
    int count = 0;
    char dataPoint[50];
    while (count < 50) {
        printf("Enter a data point (-1 to stop input):\n");
        
        fgets (dataPoint, 50, stdin);
        // dataPoint[strlen(dataPoint) - 1] = '\0';
        if (atoi(dataPoint) == -1) {    //making the string an int and seeing if it is a -1 if so  break.
            printf("\n");
            break;
        }
        int commas = 0;
        int i = 0;
        int P =0;
        char integerValue[5] = "";
        // int commaAfterInt = 0;
        int number =0;
        
        while (dataPoint[P] != '\0'){
            if(dataPoint[P] ==','){
                commas ++;
                //reades through for most of the error prevention.
            }else if(isdigit(dataPoint[P])){
                number++;
            }
            P++;
        }
        
        while (dataPoint[i] != '\0') {
            if(isspace(dataPoint[i]) && isspace(dataPoint[i-1])){
                dataPoint[i] = dataPoint[i-1];
                //extra white space remove.
            }
            if(dataPoint[i] != ',' && (isalpha(dataPoint[i]) ||  dataPoint[i] =='.'|| (isspace(dataPoint[i])&& isalpha(dataPoint[i-1]))||(isspace(dataPoint[i])&& dataPoint[i-1] =='.'))){
                if(number ==0){
                    printf("Error: Comma not followed by an integer.\n\n");
                    break;
                }
                
                
                if(commas ==0){
                    printf("Error: No comma in string.\n\n");
                    break;
                }else if(commas > 1){
                    printf("Error: Too many commas in input.\n\n");
                    break;
                    
                    
                }else{
                    //if it passes all error prevention and is not a number or a , make it part of the new array [names].
                    names[count][i] = dataPoint[i];
                    names[count][i+1] = '\0';
                    // printf("%d dataPoint: %c\n", i, dataPoint[i]);
                }
                
                
            }else if(isdigit(dataPoint[i])) {
                int j = 0;
                for (j = 0; integerValue[j] != '\0'; j++);
                integerValue[j] = dataPoint[i];
                integerValue[j + 1] = '\0';
                //inserting the number into the number value array.
            }else{
                
            }
            i++;
            
        }
        
        
        
        if (commas == 0) {
        } else if (commas > 1) {
        } else if (number == 0) {
        } else {
            //previous erro prevention.
            point[count++] = atoi(integerValue);
            
            while (k < count) {
                //unsigned int r = strlen(names[k]);
                printf("Data string: %s\n", names[k]);
                printf("Data integer: %d\n\n", point[k]);
                //prints out what the user inserted for name and data point IF it was legal.
                k++;
            }
        }
        
    }
    printf("%34s", title);
    printf("%-20s|%23s\n",col1,col2);   //prints out the string and 20 spaces
    printf("--------------------------------------------\n");
    int i = 0;
    while (i < count) {
        printf("%-20s|%23d\n", names[i], point[i]);
        i++;
        //loop thorugh to print out vales and names.
    }
    printf("\n");
    i = 0;
    while (i < count) {
        printf("%20s ", names[i]);
        //loop through to print out names.
        int j = 0;
        while (j < point[i]) {
            printf("*");
            //print out as much  * as the data point is.
            j++;
        }
        printf("\n");
        i++;
    }
    
    return 0;
}

