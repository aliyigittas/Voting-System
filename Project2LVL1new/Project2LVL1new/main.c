//
//  main.c
//  Project2LVL1new
//
//  Created by Ali Yiğit Taş on 20.04.2022.
//

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    char isvoted[5][1]= {"0","0","0","0","0"};
    int secimoy, yesvote = 0, novote = 0, votecount = 0;
    char username[5][12]= {"20201701054","12345678910","23456789101","34567891012","45678910123"};
    char inputusername[12];
    char password[5][100] = {"sifre1","sifre2","sifre3","sifre4","sifre5"};
    char inputpassword[100];
    
    while (votecount!= 5){
        printf("Enter your username: ");
        scanf("%11s", inputusername);
        
        printf("Enter Your password: ");
        scanf("%99s", inputpassword);
        
        for (int i=0;i<5;i++){
            if (strcmp(username[i], inputusername) == 0 && strcmp(password[i], inputpassword) == 0){
                if (strcmp(isvoted[i], "1")==0){
                    printf("You have already voted!\n");
                }else {
                    printf("Please vote:\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("Your Selection: ");
                    scanf("%d",&secimoy);
                    switch(secimoy){
                        case 1:
                                printf("Your YES vote is saved!\n");
                                yesvote = yesvote + 1;
                                votecount = votecount + 1;
                                strcpy(isvoted[i],"1");
                                break;
                                
                        case 2:
                                printf("Your No vote is saved!\n");
                                novote = novote + 1;
                                votecount = votecount + 1;
                                strcpy(isvoted[i], "1");
                                break;
                }
                
            }
            }
        }
        if(votecount == 5){
            if (yesvote > novote){
                printf("\nThe result is YES.\n");
            }else if (yesvote == novote){
                printf("\nVotes are equal.\n");
            }else{
                printf("\nThe result is NO.\n");
            }
            printf("\nVotes: %d\n", votecount);
            printf("Yes Votes: %d\n", yesvote);
            printf("No Votes: %d\n", novote);
        }
    }
}
