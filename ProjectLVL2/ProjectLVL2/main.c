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
    
    int secimoy, changevote, secimadmin, yesvote = 0, novote = 0, votecount = 0;
    char username2[12];
    char password2[12];
    char username3[50][12];
    char password3[50][12];
    char newpass[100];
    char newusername[12];
    char isvotedstatus3[50][1];
    char vote3[50][1];
    char votestatus[50]; //A means notvoted , B means voted
    char vote2[50]; //X means not voted, Y means yes, N means no
    bool loggedin = false;
    bool Adminloggedin = false;
    int Usercount[1];
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
    
    
    while (votecount !=Usercount[0]){
        
        printf("Enter your username: ");
        scanf("%s",username2);
        printf("Enter Your password: ");
        scanf("%s",password2);
        
        for (int j=0;j<50;j++){
            if (strcmp(username2,"XXXXXXXXXXX")==0 && strcmp(password2,"XXXXXX")==0){
                break;
            }else if (strcmp(username2,"admin")==0 && strcmp(password2,"admin1")==0){
                Adminloggedin = true;
                if(Adminloggedin== true){
                    printf("Admin Panel\n");
                    printf("1.Add User\n");
                    printf("2.Reset Vote Stats\n");
                    printf("3.Exit\n");
                    printf("Your selection: ");
                    scanf("%d",&secimadmin);
                    switch(secimadmin){
                        case 1:
                            //ADD USER
                            printf("Enter username to register: ");
                            scanf("%s",newusername);
                            printf("Enter a password: ");
                            scanf("%s",newpass);
                            if (strlen(newusername)==11 && strlen(newpass)==6){
                                strcpy(username3[Usercount[0]],newusername);
                                strcpy(password3[Usercount[0]],newpass);
                                printf("Username is Saved!\n");
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
                            printf("Votes deleted succesfully! Restart the program to apply changes!\n");
                            break;
                            
                        case 3:
                            Adminloggedin = false;
                            break;
                            //LOG OFF
                    }
                    break;
                }
            }
            if (strcmp(username2,username3[j])==0 && strcmp(password2,password3[j])==0){
                
                loggedin = true;
            }
            if (loggedin == true){
                printf("\nWelcome %s!\n",username3[j]);
                printf("Menu:\n");
                printf("1. Vote Yes\n");
                printf("2. Vote No\n");
                printf("3. Change Password\n");
                printf("4. See Results\n");
                printf("5. Change Vote\n");
                printf("6. Log off\n");
                printf("Your Selection: ");
                scanf("%d",&secimoy);
                switch(secimoy){
                    case 1:
                        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                            printf("You have already voted YES!\n");
                            j--;
                            break;
                        }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                            printf("You have already voted NO!\n");
                            j--;
                            break;
                        }else{
                            printf("Your YES vote is saved!\n");
                            yesvote = yesvote + 1;
                            votecount = votecount + 1;
                            votestatus[j] = 'B';
                            vote2[j] = 'Y';
                            fseek(vts,0,SEEK_SET);
                            for (int i=0;i<50;i++){
                                fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                            }
                            j--;
                            break;
                        }
                    case 2:
                        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                            printf("You have already voted YES!\n");
                            j--;
                            break;
                        }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                            printf("You have already voted NO!\n");
                            j--;
                            break;
                        }else{
                            printf("Your No vote is saved!\n");
                            novote = novote + 1;
                            votecount = votecount + 1;
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
                        printf("Enter your new password: ");
                        scanf("%s", newpass);
                        if (strlen(newpass)==6){
                            strcpy(password3[j],newpass);
                            printf("Your password is changed!\n");
                            fseek(in,0,SEEK_SET);
                            for (int i=0;i<50;i++){
                                fprintf(in,"%s %s\n", username3[i],password3[i]);
                            }
                            fclose(in);
                            fopen("users.txt", "r+");
                        }else {
                            printf("Your password must be 6 characters long!\n");
                        }
                        j--;
                        break;
                        
                    case 4:
                        printf("Votes: %d\n", votecount);
                        printf("Yes Votes: %d\n", yesvote);
                        printf("No Votes: %d\n", novote);
                        j--;
                        break;
                        
                    case 5:
                        if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                            printf("You voted YES already, are you sure to change your vote to NO?\n");
                            printf("1. Yes\n");
                            printf("2. Delete my vote\n");
                            printf("3. No\n");
                            printf("Your Selection: ");
                            scanf("%d",&changevote);
                            switch(changevote){
                                case 1:
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
                                    printf("Operation cancelled by user.\n");
                                    j--;
                                    break;
                            }
                            
                        }else{
                            printf("You need to vote first!\n");
                            j--;
                            break;
                        }
                    case 6:
                        loggedin = false;
                        break;
            }
            }
            fclose(vts);
            fopen("Votestats.txt", "r+");
        }
        
    }
        
        
        
    fclose(vts);
    fclose(in);
    
    printf("\nVoting ended!\n");
    if(votecount == Usercount[0]){
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
