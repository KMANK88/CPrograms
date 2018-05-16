//
//  marchMadness.c
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 3/14/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include <stdio.h>


typedef struct Team_struct{
    char name[50];
    int seed;
    int rpi;
    
} Team;


int main(void) {
    
    //arrays composed of Teams, team struct is defined above
   
    
    Team roundOneEast[16];
    Team roundTwoEast[8];
    Team roundThreeEast[4];
    Team roundFourEast[2];
    
    Team roundOneMidWest[16];
     Team roundTwoMidWest[8];
     Team roundThreeMidWest[4];
     Team roundFourMidWest[2];
    
   Team roundOneWest[16];
    Team roundTwoWest[8];
    Team roundThreeWest[4];
    Team roundFourWest[2];
    
    
    
     Team roundOneSouth[16];
     Team roundTwoSouth[8];
    Team roundThreeSouth[4];
    Team roundFourSouth[2];
    
    Team finalFour[4];
    
    Team champGame[2];
    Team Winner[1];
    
    FILE* file = fopen("bracketFile.txt", "r");
    
    if (file == NULL) {
        printf("Could not open file.\n");
        return -1; // -1 indicates error
    }
    //============================================= SOUNTHERN CONFERENCE
    //building round one array for the southern conference
    for(int i = 0; i < 16; i++){
        Team newTeam;
        newTeam.seed = 0;
        newTeam.rpi = 0;
        fscanf(file, "%s %d %d", newTeam.name, &newTeam.seed, &newTeam.rpi);
        roundOneSouth[i] = newTeam;
        
        printf("Team: %s, Seed: %d, rpi: %d\n", newTeam.name, newTeam.seed, newTeam.rpi);
    }
    fflush(stdin);

    
    //building the second round array, winners based on seed.
    printf("\n");
    int j = 0;
    for(int i = 0; i < 16; i ++){
        if(roundOneSouth[i].seed > roundOneSouth[i + 1].seed){ //this comparison isn't working correctly
            roundTwoSouth[j] = roundOneSouth[i + 1];
        }
        else{
            roundTwoSouth[j] = roundOneSouth[i];
        }
        j++;
        i++; //increment again so that we move to the next pair and determine those winners
        
    }
    printf("Round one winners\n");
    for(int i = 0; i < 8; i++){
        printf("%s Seed:%d, rpi: %d\n", roundTwoSouth[i].name, roundTwoSouth[i].seed, roundTwoSouth[i].rpi);
    }
    
    printf("\n");
    int k=0;
    for(int i=0; i< 8; i++){
        if(i==0){
            continue;
        }else if(roundTwoSouth[i].seed > roundTwoSouth[i-1].seed){
            roundThreeSouth[k] = roundTwoSouth[i-1];
        }
        else{
            roundThreeSouth[k] = roundTwoSouth[i];
        }
        k++;
        i++;
    
    }
    printf("Round Two winners\n");
    for(int i=0; i<4; i++){
        printf("%s Seed:%d, rpi: %d\n", roundThreeSouth[i].name, roundThreeSouth[i].seed, roundThreeSouth[i].rpi);
    }
    
    printf("\n");
    int p=0;
    for(int i=0; i< 4; i++){
        if(i==0){
            continue;
            
        }else if(roundFourSouth[i].seed > roundThreeSouth[i-1].seed){
            roundFourSouth[p] = roundThreeSouth[i-1];
        }else{
            roundFourSouth[p]= roundThreeSouth[i];
        }
        p++;
        i++;
    }
    printf("Elite eight\n");
    for(int i=0; i< 2; i++){
        printf("%s Seed: %d,  rpi: %d\n", roundFourSouth[i].name, roundFourSouth[i].seed, roundFourSouth[i].rpi);
    }
    
    int o=0;
    for(int i=0; i<2; i++){
        if(i==0){
            continue;
        }else if(roundFourSouth[i].seed > roundFourSouth[i-1].seed){
            finalFour[0] = roundFourSouth[i-1];
        }else{
            finalFour[0] =  roundFourSouth[i];
        }
        o++;
        i++;
    }
    printf("\n");
    printf("South winner: %s Seed: %d, rpi: %d\n", finalFour[0].name, finalFour[0].seed, finalFour[0].rpi);
    printf("\n");
    
    //=======================WESTERN
    //building the round one array for the western conference
    for(int i = 0; i < 16; i++){
        Team newTeam;
        newTeam.seed = 0;
        newTeam.rpi = 0;
        fscanf(file, "%s %d %d", newTeam.name, &newTeam.seed, &newTeam.rpi);
        roundOneWest[i] = newTeam;
        
        printf("Team: %s, Seed: %d, rpi: %d\n", newTeam.name, newTeam.seed, newTeam.rpi);
       
    }
    printf("\n");
    
    int r=0;
    for(int i = 0; i < 16; i ++){
        if(i==0){
            continue;
        }else if(roundOneWest[i].seed > roundOneWest[i - 1].seed){
            roundTwoWest[r] = roundOneWest[i-1];
        }
        else{
            roundTwoWest[r] = roundOneWest[i];
        }
        r++;
        i++; //increment again so that we move to the next pair and determine those winners
        
    }
    printf("Round one winners\n");
    for(int i = 0; i < 8; i++){ //for some reason the roundTwoSouth prints out fine this one doesn't.
        printf("%s Seed: %d, rpi: %d\n", roundTwoWest[i].name, roundTwoWest[i].seed, roundTwoWest[i].rpi);
    }
   
    int b=0;
    for(int i=0; i< 8; i++){
        if(i==0){
            continue;
        }else if(roundTwoWest[i].seed > roundTwoWest[i-1].seed){
            roundThreeWest[b] = roundTwoWest[i-1];
        }
        else{
            roundThreeWest[b] = roundTwoWest[i];
        }
        b++;
        i++;
        
    }
    printf("\n");
    printf("Round Two winners\n");
    for(int i=0; i<4; i++){
        printf("%s Seed:%d, rpi: %d\n", roundThreeWest[i].name, roundThreeWest[i].seed, roundThreeWest[i].rpi);
    }
    printf("\n");
    
    int q=0;
    for(int i=0; i< 4; i++){
        if(i==0){
            continue;
            
        }else if(roundFourWest[i].seed > roundThreeWest[i-1].seed){
            roundFourWest[q] = roundThreeWest[i-1];
        }else{
            roundFourWest[q] = roundThreeWest[i];
        }
        q++;
        i++;
    }
    printf("Elite eight\n");
    for(int i=0; i< 2; i++){
        printf("%s Seed: %d rpi: %d\n", roundFourWest[i].name, roundFourWest[i].seed, roundFourWest[i].rpi);
    }
    
    int c=0;
    for(int i=0; i<2; i++){
        if(i==0){
            continue;
        }else if(roundFourWest[i].seed > roundFourWest[i-1].seed){
            finalFour[1] = roundFourWest[i-1];
        }else{
            finalFour[1] =  roundFourWest[i];
        }
        o++;
        i++;
    }
    printf("\n");
    printf("West winner: %s Seed: %d, rpi: %d\n", finalFour[1].name, finalFour[1].seed, finalFour[1].rpi);
    printf("\n");
    
    //========================East
    
    
    
    //building the round one array for the eastern conference
    for(int i = 0; i < 16; i++){
        Team newTeam;
        newTeam.seed = 0;
        newTeam.rpi = 0;
        fscanf(file, "%s %d %d", newTeam.name, &newTeam.seed, &newTeam.rpi);
        roundOneEast[i] = newTeam;
      
        printf("Team: %s, Seed: %d, rpi: %d\n", newTeam.name, newTeam.seed, newTeam.rpi);
    }
  
  
    int x=0;
    for(int i = 0; i < 16; i ++){
        if(i==0){
            continue;
        }else if(roundOneEast[i].seed > roundOneEast[i - 1].seed){
            roundTwoEast[x] = roundOneEast[i-1];
        }
        else{
            roundTwoEast[x] = roundOneEast[i];
        }
        x++;
        i++; //increment again so that we move to the next pair and determine those winners
        
    }
    printf("\n");
    
    printf("Round one winners\n");
    for(int i = 0; i < 8; i++){ //for some reason the roundTwoSouth prints out fine this one doesn't.
       printf("%s Seed: %d, rpi: %d\n", roundTwoEast[i].name, roundTwoEast[i].seed, roundTwoEast[i].rpi);
    }
    int w=0;
    for(int i=0; i< 8; i++){
        if(i==0){
            continue;
        }else if(roundTwoEast[i].seed > roundTwoEast[i-1].seed){
            roundThreeEast[w] = roundTwoEast[i-1];
        }
        else{
            roundThreeEast[w] = roundTwoEast[i];
        }
        w++;
        i++;
        
    }
    printf("\n");
    printf("Round Two winners\n");
    for(int i=0; i<4; i++){
        printf("%s Seed:%d, rpi: %d\n", roundThreeEast[i].name, roundThreeEast[i].seed, roundThreeEast[i].rpi);
    }
    printf("\n");
    
    int z=0;
    for(int i=0; i< 4; i++){
        if(i==0){
            continue;
            
        }else if(roundFourEast[i].seed < roundThreeEast[i-1].seed){
            roundFourEast[z] = roundThreeEast[i-1];
        }else{
            roundFourEast[z] = roundThreeEast[i];
        }
        z++;
        i++;
    }
    printf("Elite eight\n");
    for(int i=0; i< 2; i++){
        printf("%s Seed: %d rpi: %d\n", roundFourEast[i].name, roundFourEast[i].seed, roundFourEast[i].rpi);
    }

    for(int i=0; i<2; i++){
        if(i==0){
            continue;
        }else if(roundFourEast[i].seed < roundFourEast[i-1].seed){
            finalFour[2] = roundFourEast[i-1];
        }else{
            finalFour[2] =  roundFourEast[i];
        }
       
        i++;
    }
    printf("\n");
    printf("East winner: %s Seed: %d, rpi: %d\n", finalFour[2].name, finalFour[2].seed, finalFour[2].rpi);
    printf("\n");
    
    //==================MidWest
    
    //building the round one array for the midwestern conference
    for(int i = 0; i < 16; i++){
        Team newTeam;
        newTeam.seed = 0;
        newTeam.rpi = 0;
        fscanf(file, "%s %d %d", newTeam.name, &newTeam.seed, &newTeam.rpi);
        roundOneMidWest[i] = newTeam;
        
        printf("Team: %s, Seed: %d, rpi: %d\n", newTeam.name, newTeam.seed, newTeam.rpi);
        
    }
    int m=0;
    for(int i = 0; i < 16; i ++){
        if(i==0){
            continue;
        }else if(roundOneMidWest[i].seed > roundOneMidWest[i - 1].seed){
            roundTwoMidWest[m] = roundOneMidWest[i-1];
        }
        else{
            roundTwoMidWest[m] = roundOneMidWest[i];
        }
        m++;
        i++; //increment again so that we move to the next pair and determine those winners
        
    }
    printf("\n");
    
    printf("Round one winners\n");
    for(int i = 0; i < 8; i++){ //for some reason the roundTwoSouth prints out fine this one doesn't.
        printf("%s Seed: %d, rpi: %d\n", roundTwoMidWest[i].name, roundTwoMidWest[i].seed, roundTwoMidWest[i].rpi);
    }
    int h=0;
    for(int i=0; i< 8; i++){
        if(i==0){
            continue;
        }else if(roundTwoMidWest[i].seed > roundTwoMidWest[i-1].seed){
            roundThreeMidWest[h] = roundTwoMidWest[i-1];
        }
        else{
            roundThreeMidWest[h] = roundTwoMidWest[i];
        }
        h++;
        i++;
        
    }
    printf("\n");
    printf("Round Two winners\n");
    for(int i=0; i<4; i++){
        printf("%s Seed:%d, rpi: %d\n", roundThreeMidWest[i].name, roundThreeMidWest[i].seed, roundThreeMidWest[i].rpi);
    }
    printf("\n");
    
    int d=0;
    for(int i=0; i< 4; i++){
        if(i==0){
            continue;
            
        }else if(roundFourMidWest[i].seed > roundThreeMidWest[i-1].seed){
            roundFourMidWest[d] = roundThreeMidWest[i-1];
        }else{
            roundFourMidWest[d] = roundThreeMidWest[i];
        }
        d++;
        i++;
    }
    printf("Elite eight\n");
    for(int i=0; i< 2; i++){
        printf("%s Seed: %d rpi: %d\n", roundFourMidWest[i].name, roundFourMidWest[i].seed, roundFourMidWest[i].rpi);
    }
    
    for(int i=0; i<2; i++){
        if(i==0){
            continue;
        }else if(roundFourMidWest[i].seed < roundFourMidWest[i-1].seed){
            finalFour[3] = roundFourMidWest[i-1];
        }else{
            finalFour[3] =  roundFourMidWest[i];
        }
        
        i++;
    }
    printf("\n");
    printf("MidWest winner: %s Seed: %d, rpi: %d\n", finalFour[3].name, finalFour[3].seed, finalFour[3].rpi);
    printf("\n");
    //======FinalFour
    
    printf("The Final Four are\n");
    for(int i=0; i<4; i++){
        printf("%s Seed: %d, rpi: %d\n", finalFour[i].name, finalFour[i].seed, finalFour[i].rpi);
    }
    
    int f=0;
    for(int i=0; i<4; i++){
        if(i==0){
            continue;
        }else if(finalFour[i].seed == finalFour[i-1].seed){
            if(finalFour[i].rpi < finalFour[i-1].rpi){
                champGame[f] = finalFour[i];
            }else{
                champGame[f] = finalFour[i-1];
            }
        }else if(finalFour[i].seed > finalFour[i-1].seed){
            
            champGame[f] = finalFour[i-1];
        }else{
            champGame[f]= finalFour[i];
        }
        f++;
        i++;
    }
    
    printf("\nThe Championchip is between\n");
    for(int i=0; i<2; i++){
        printf("%s Seed: %d, rpi: %d\n", champGame[i].name, champGame[i].seed, champGame[i].rpi);
    }
    printf("\n");
    for(int i=0; i<2; i++){
        if(i==0){
            continue;
        }else if(champGame[i].rpi < champGame[i-1].rpi){
            
            Winner[0] = champGame[i-1];
           
        }else{
            Winner[0] = champGame[i];
        }
        i++;
        
    }
    printf("The Winner is %s \nWith the Seed: %d, and a rpi of: %d\n", Winner[0].name, Winner[0].seed, Winner[0].rpi);

    printf("\n");
    fclose(file);
    
    
    return 0;
}
