//
//  main.c
//  project2lvl1
//
//  Created by Ali Yiğit Taş on 14.04.2022.
//
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    bool isvoted1 = false;
    bool isvoted2 = false;
    bool isvoted3 = false;
    bool isvoted4 = false;
    bool isvoted5 = false;
    int secimoy, yesvote = 0, novote = 0, votecount = 0;
    char username[12];
    char password[100];
    
    while (votecount!= 5){
        printf("Enter your username: ");
        scanf("%11s", username);
        
        printf("Enter Your password: ");
        scanf("%99s", password);
        
        if (strcmp(username, "20201701054") == 0 && strcmp(password, "ali123")==0) {
            if (isvoted1 == true){
                printf("You have already voted!\n");
            }else {
                printf("Please vote:\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d",&secimoy);
                switch(secimoy){
                    case 1:
                            printf("Your YES vote is saved!\n");
                            yesvote = yesvote + 1;
                            votecount = votecount + 1;
                            isvoted1 = true;
                            break;
                            
                    case 2:
                            printf("Your No vote is saved!\n");
                            novote = novote + 1;
                            votecount = votecount + 1;
                            isvoted1 = true;
                            break;
            }
            
        }
        }else if (strcmp(username, "hesap2") == 0 && strcmp(password, "sifre2")==0) {
            if (isvoted2 == true){
                printf("You have already voted!\n");
            }else {
                printf("Please vote:\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d",&secimoy);
                switch(secimoy){
                    case 1:
                            printf("Your YES vote is saved!\n");
                            yesvote = yesvote + 1;
                            votecount = votecount + 1;
                            isvoted2 = true;
                            break;
                            
                    case 2:
                            printf("Your No vote is saved!\n");
                            novote = novote + 1;
                            votecount = votecount + 1;
                            isvoted2 = true;
                            break;
            }
            
        }
        }else if (strcmp(username, "hesap3") == 0 && strcmp(password, "sifre3")==0) {
            if (isvoted3 == true){
                printf("You have already voted!\n");
            }else {
                printf("Please vote:\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d",&secimoy);
                switch(secimoy){
                    case 1:
                            printf("Your YES vote is saved!\n");
                            yesvote = yesvote + 1;
                            votecount = votecount + 1;
                            isvoted3 = true;
                            break;
                            
                    case 2:
                            printf("Your No vote is saved!\n");
                            novote = novote + 1;
                            votecount = votecount + 1;
                            isvoted3 = true;
                            break;
            }
            
        }
        }else if (strcmp(username, "hesap4") == 0 && strcmp(password, "sifre4")==0) {
            if (isvoted4 == true){
                printf("You have already voted!\n");
            }else {
                printf("Please vote:\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d",&secimoy);
                switch(secimoy){
                    case 1:
                            printf("Your YES vote is saved!\n");
                            yesvote = yesvote + 1;
                            votecount = votecount + 1;
                            isvoted4 = true;
                            break;
                            
                    case 2:
                            printf("Your No vote is saved!\n");
                            novote = novote + 1;
                            votecount = votecount + 1;
                            isvoted4 = true;
                            break;
            }
            
        }
        }else if (strcmp(username, "hesap5") == 0 && strcmp(password, "sifre5")==0) {
            if (isvoted5 == true){
                printf("You have already voted!\n");
            }else {
                printf("Please vote:\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d",&secimoy);
                switch(secimoy){
                    case 1:
                            printf("Your YES vote is saved!\n");
                            yesvote = yesvote + 1;
                            votecount = votecount + 1;
                            isvoted5 = true;
                            break;
                            
                    case 2:
                            printf("Your No vote is saved!\n");
                            novote = novote + 1;
                            votecount = votecount + 1;
                            isvoted5 = true;
                            break;
            }
            
        }
        }else{
            printf("Incorrect username or password!\n");
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
