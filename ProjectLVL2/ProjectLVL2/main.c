//
//  main.c
//  ProjectLVL2
//
//  Created by Ali Yiğit Taş on 18.04.2022.
//

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct userlist {
    char username[50][12];
    char password[50][100];
    char isvotedstatus[50][1];
    char vote[50][1];
    
} list;


int main() {
    system("cls||clear");
    FILE *in, *vts, *usrcount;
    
    if ((in = fopen("users.txt", "r+")) == NULL) {
        fputs("Cannot open users.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    if ((vts = fopen("Votestats.txt", "r+")) == NULL) {
        fputs("Cannot open Votestats.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    if ((usrcount = fopen("Usercount.txt", "r+")) == NULL) {
        fputs("Cannot open Usercount.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    
    int selectmenu, changevote, selectadmin, yesvote = 0, novote = 0, votecount = 0;
    char inputusername[12];
    char inputpassword[12];
    char username3[50][12]; //This is a copy of list.username, i created this because admin acc. can make changes in this array.
    char password3[50][12]; //This is a copy of list.password, i created this because admin acc. can make changes in this array.
    char newpass[100]; //When users changes their passwords or admin adds an acc., it stores in here and program writes to file.
    char newusername[12]; //When admin adds an account username stores in here and program writes to file.
    char isvotedstatus3[50][1]; // This is a copy of list.votedstatus. 2D array.
    char vote3[50][1]; // This is a copy of list.vote. 2D array.
    char votestatus[50];//This is a copy of isvotesstatus3, the difference is this is not 2D array. A means notvoted , B means voted
    char vote2[50]; //X means not voted, Y=yes, N=no.This is a copy of vote3,the difference is this is not 2D array. Program makes changes here and writes to file.
    bool loggedin = false;
    bool Adminloggedin = false;
    int Usercount[1]; //Admin acc. can increase this value by adding new users.
    fscanf(usrcount, "%d", &Usercount[0]);
    //printf("%d",Usercount[0]);
    
    
    for (int j=0;j<50;j++){ //This loop checks txt files for retrieving last the last state.
        fscanf(in, "%11s%*[ \t]%99s ", list.username[j], list.password[j]);
        memcpy(username3[j], list.username[j], sizeof(username3[j]));
        memcpy(password3[j], list.password[j], sizeof(password3[j]));
        fscanf(vts, "%s%*[ \t]%s ", list.isvotedstatus[j], list.vote[j]);
        memcpy(isvotedstatus3[j], list.isvotedstatus[j], sizeof(isvotedstatus3[j]));
        strcpy(&votestatus[j],isvotedstatus3[j]);
        memcpy(vote3[j], list.vote[j], sizeof(vote3[j]));
        strcpy(&vote2[j],vote3[j]);
        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
            yesvote++;
            votecount++;
        }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
            novote++;
            votecount++;
        }
    }
    
    
    while (yesvote <= (Usercount[0]/2) && novote <= (Usercount[0]/2)){
        
        printf("Enter your username: ");
        scanf("%s",inputusername);
        printf("Enter Your password: ");
        scanf("%s",inputpassword);
        system("cls||clear"); //clears the terminal screen cls command is for Windows, clear command is for macOS/Linux.
        for (int j=0;j<50;j++){
            if (strcmp(inputusername,"XXXXXXXXXXX")==0 && strcmp(inputpassword,"XXXXXX")==0){ //Empty account
                break;
            }else if (strcmp(inputusername,"admin")==0 && strcmp(inputpassword,"admin1")==0){ //Admin account
                Adminloggedin = true;
                if(Adminloggedin== true){
                    printf("!!!Admin Panel!!!\n");
                    printf("1.Add User\n");
                    printf("2.Reset Vote Stats\n");
                    printf("3.Exit\n");
                    printf("Your selection: ");
                    scanf("%d",&selectadmin);
                    switch(selectadmin){
                        case 1:
                            //ADD USER
                            system("cls||clear");
                            printf("Enter username to register (11 characters): ");
                            scanf("%s",newusername);
                            printf("Enter a password (6 characters): ");
                            scanf("%s",newpass);
                            if (strlen(newusername)==11 && strlen(newpass)==6){
                                strcpy(username3[Usercount[0]],newusername);
                                strcpy(password3[Usercount[0]],newpass);
                                printf("User is Saved!\n");
                                Usercount[0]++;
                                fseek(in,0,SEEK_SET);
                                for (int i=0;i<50;i++){
                                    fprintf(in,"%s %s\n", username3[i],password3[i]);
                                }
                                fclose(in);
                                fseek(usrcount, 0, SEEK_SET);
                                fprintf(usrcount, "%d", Usercount[0]);
                                fclose(usrcount);
                                fopen("users.txt", "r+");
                            }else {
                                printf("Your username must 11, your password must 6 characters long!\n");
                            }
                            
                        case 2:
                            //RESET VOTES
                            system("cls||clear");
                            for(int j=0; j<50; j++){
                                votestatus[j]='A';
                                vote2[j]='X';
                            }
                            yesvote = 0;
                            novote = 0;
                            votecount = 0;
                            fseek(vts,0,SEEK_SET);
                            for (int i=0;i<50;i++){
                                fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                            }
                            fclose(vts);
                            fopen("Votestats.txt", "r+");
                            printf("Votes deleted succesfully!\n");
                            break;
                            
                        case 3:
                            //LOG OFF
                            system("cls||clear");
                            Adminloggedin = false;
                            break;
                    }
                    break;
                }
            }
            if (strcmp(inputusername,username3[j])==0 && strcmp(inputpassword,password3[j])==0){ //Regular user
                
                loggedin = true;
            }
            if (loggedin == true){
                printf("\nWelcome %s!\n",username3[j]); //User-spesific message
                printf("Menu:\n");
                printf("1. Vote Yes\n");
                printf("2. Vote No\n");
                printf("3. Change Password\n");
                printf("4. See Results\n");
                printf("5. Change Vote\n");
                printf("6. Log off\n");
                printf("Your Selection: ");
                scanf("%d",&selectmenu);
                switch(selectmenu){
                    case 1:
                        //VOTE YES
                        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                            system("cls||clear");
                            printf("You have already voted YES!\n");
                            j--; //These lines keep the program in the same user.
                            break;
                        }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                            system("cls||clear");
                            printf("You have already voted NO!\n");
                            j--;
                            break;
                        }else{
                            system("cls||clear");
                            printf("Your YES vote is saved!\n");
                            yesvote++;
                            votecount++;
                            votestatus[j] = 'B';
                            vote2[j] = 'Y';
                            fseek(vts,0,SEEK_SET); //This line moves the pointer to beginning of the file.
                            for (int i=0;i<50;i++){
                                fprintf(vts,"%c %c\n", votestatus[i],vote2[i]); // This line overwrites all things in the file from beginning.
                            }
                            j--;
                            break;
                        }
                    case 2:
                        //VOTE NO
                        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                            system("cls||clear");
                            printf("You have already voted YES!\n");
                            j--;
                            break;
                        }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                            system("cls||clear");
                            printf("You have already voted NO!\n");
                            j--;
                            break;
                        }else{
                            system("cls||clear");
                            printf("Your No vote is saved!\n");
                            novote++;
                            votecount++;
                            votestatus[j] = 'B';
                            vote2[j] = 'N';
                            fseek(vts,0,SEEK_SET);
                            for (int i=0;i<50;i++){
                                fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                            }
                            j--;
                            break;
                        }
                    case 3:
                        //CHANGE PASSWORD
                        system("cls||clear");
                        printf("Enter your new password: ");
                        scanf("%s", newpass);
                        if (strlen(newpass)==6){
                            strcpy(password3[j],newpass);
                            printf("Your password is changed!\n");
                            fseek(in,0,SEEK_SET);
                            for (int i=0;i<50;i++){
                                fprintf(in,"%s %s\n", username3[i],password3[i]); //This line overwrites all things in the file from the beginning.
                            }
                            fclose(in);
                            fopen("users.txt", "r+");
                        }else {
                            printf("Your password must be 6 characters long!\n");
                        }
                        j--;
                        break;
                        
                    case 4:
                        //SEE RESULTS
                        system("cls||clear");
                        printf("Votes: %d\n", votecount);
                        printf("Yes Votes: %d\n", yesvote);
                        printf("No Votes: %d\n", novote);
                        j--;
                        break;
                        
                    case 5:
                        //CHANGE VOTE
                        system("cls||clear");
                        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                            printf("You voted YES already, are you sure to change your vote to NO?\n");
                            printf("1. Yes\n");
                            printf("2. Delete my vote\n");
                            printf("3. No\n");
                            printf("Your Selection: ");
                            scanf("%d",&changevote);
                            switch(changevote){
                                case 1:
                                    system("cls||clear");
                                    printf("You changed your vote to NO!\n");
                                    yesvote--;
                                    novote++;
                                    vote2[j] = 'N';
                                    fseek(vts,0,SEEK_SET);
                                    for (int i=0;i<50;i++){
                                        fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                                    }
                                    j--;
                                    break;
                                case 2:
                                    system("cls||clear");
                                    printf("Your vote is deleted\n");
                                    yesvote--;
                                    votecount--;
                                    vote2[j] = 'X';
                                    votestatus[j] = 'A';
                                    fseek(vts,0,SEEK_SET);
                                    for (int i=0;i<50;i++){
                                        fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                                    }
                                    j--;
                                    break;
                                case 3:
                                    system("cls||clear");
                                    printf("Operation cancelled by user.\n");
                                    j--;
                                    break;
                            }
                            
                        }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                            printf("You voted NO already, are you sure to change your vote to YES?\n");
                            printf("1. Yes\n");
                            printf("2. Delete my vote\n");
                            printf("3. No\n");
                            printf("Your Selection: ");
                            scanf("%d",&changevote);
                            switch(changevote){
                                case 1:
                                    system("cls||clear");
                                    printf("You changed your vote to YES!\n");
                                    yesvote++;
                                    novote--;
                                    vote2[j] = 'Y';
                                    fseek(vts,0,SEEK_SET);
                                    for (int i=0;i<50;i++){
                                        fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                                    }
                                    j--;
                                    break;
                                case 2:
                                    system("cls||clear");
                                    printf("Your vote is deleted\n");
                                    novote--;
                                    votecount--;
                                    vote2[j] = 'X';
                                    votestatus[j] = 'A';
                                    fseek(vts,0,SEEK_SET);
                                    for (int i=0;i<50;i++){
                                        fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                                    }
                                    j--;
                                    break;
                                case 3:
                                    system("cls||clear");
                                    printf("Operation cancelled by user.\n");
                                    j--;
                                    break;
                            }
                            
                        }else{
                            system("cls||clear");
                            printf("You need to vote first!\n");
                            j--;
                            break;
                        }
                    case 6:
                        //LOG OFF
                        system("cls||clear");
                        loggedin = false;
                        break;
            }
            }
            fclose(vts);
            fopen("Votestats.txt", "r+");
        }
        
    }
    for(int j=0; j<50; j++){
        votestatus[j]='A';
        vote2[j]='X';
    }
    fseek(vts,0,SEEK_SET);
    for (int i=0;i<50;i++){
        fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
    }
    fclose(vts);
    fopen("Votestats.txt", "r+");
        
        
        
    fclose(vts);
    fclose(in);
    system("cls||clear");
    printf("\nVoting ended!\n");
    
    if((yesvote >= (Usercount[0]/2)+1 || novote >= (Usercount[0]/2)+1) || votecount == Usercount[0]){
        
        if (yesvote > novote){
            printf("\nThe result is YES.\n");
        }else if (yesvote == novote){
            printf("\nVotes are equal.\n");
        }else{
            printf("\nThe result is NO.\n");
        }
    }
    printf("Votes: %d\n", votecount);
    printf("Yes Votes: %d\n", yesvote);
    printf("No Votes: %d\n", novote);
}
