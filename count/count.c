//
//  count.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 2/15/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>

int main() {
    
    char arr[100];
    char *ptr;
    ptr = arr;
    int vow,cons,dig,space;
    vow =0;
    cons =0;
    dig =0;
    space =0;
    
    
    
    printf("Enter a string:\n");
    scanf("%[^\n]", arr);
    while(*ptr!='\0'){
        
        if(*ptr=='a' || *ptr=='e' || *ptr=='i' || *ptr=='o' || *ptr=='u' || *ptr=='A' ||*ptr=='E'||*ptr=='I'|| *ptr=='O' ||*ptr=='U'){
            vow++;
        }else if((*ptr >='a'&& *ptr <='z') || (*ptr >='A'&& *ptr <='Z')){
            cons++;
        }else if(*ptr >='0' && *ptr <='9'){
            dig++;
        }else if (*ptr ==' '){
            space++;
        }
        ptr++;
    }
    
    printf("Vowles: %d\n", vow);
    printf("Constants: %d\n", cons);
    printf("Digits: %d\n", dig);
    printf("Spaces: %d\n", space);
    
    
    
    return 0;
}
