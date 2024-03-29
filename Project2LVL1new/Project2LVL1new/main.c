//
//  main.c
//  Project2LVL1new
//
//  Created by Ali Yiğit Taş on 20.04.2022.

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    system("cls||clear");
    char isvoted[5][1]= {"0","0","0","0","0"}; //0 means not voted, 1 means voted
    int selectvote, yesvote = 0, novote = 0, votecount = 0;
    char username[5][12]= {"20201701054","20201701010","20211701055","20211701040","45678910123"}; //Usernames
    char inputusername[12];
    char password[5][100] = {"sifre1","sifre2","sifre3","sifre4","sifre5"}; // Users' passwords
    char inputpassword[100];
    
    while (yesvote <= 2 && novote <= 2){ //This block actions until half of users vote same option.
        printf("Enter your username: ");
        scanf("%11s", inputusername);
        
        printf("Enter Your password: ");
        scanf("%99s", inputpassword);
        system("cls||clear"); //clears the terminal screen cls command is for Windows, clear command is for macOS/Linux.
        
        for (int i=0;i<5;i++){ //This loop repeats 5 times to authenticate user (This is 5 because there are 5 users in the system.)
            if (strcmp(username[i], inputusername) == 0 && strcmp(password[i], inputpassword) == 0){//Checking login credentials if not matched, check next one.
                if (strcmp(isvoted[i], "1")==0){ //checking user is voted or not.
                    printf("You have already voted!\n");
                }else { //if user not voted then menu appears
                    printf("Welcome %s!\n",username[i]);
                    printf("Please vote:\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("Your Selection: ");
                    scanf("%d",&selectvote);
                    switch(selectvote){
                        case 1:
                                system("cls||clear");
                                printf("Your YES vote is saved!\n");
                                yesvote++;
                                votecount++;
                                strcpy(isvoted[i],"1"); //saving vote status.
                                break;
                                
                        case 2:
                                system("cls||clear");
                                printf("Your No vote is saved!\n");
                                novote++;
                                votecount++;
                                strcpy(isvoted[i], "1"); //saving vote status.
                                break;
                }
                
            }
            }
        }
        if ((yesvote >= 3 || novote >=3) || votecount == 5){
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
