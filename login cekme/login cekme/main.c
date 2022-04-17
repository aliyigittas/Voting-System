//
//  main.c
//  login cekme
//
//  Created by Ali Yiğit Taş on 16.04.2022.
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
    char isvotedstatus[50][10];
    char vote[50][4];
    
} list;


int main() {
    
    FILE *in, *vts, *tmpin;
    
    if ((in = fopen("users.txt", "r+")) == NULL) {
        fputs("Cannot open users.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    if ((vts = fopen("Votestats.txt", "r+")) == NULL) {
        fputs("Cannot open Votestats.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    if ((tmpin = fopen("tmpin.txt", "w+")) == NULL) {
        fputs("Cannot open tmpin.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    
    
    int secimoy, changevote, yesvote = 0, novote = 0, votecount = 0;
    char username2[12];
    char password2[12];
    char username3[10][12];
    char password3[10][12];
    char isvotedstatus3[10][1];
    char vote3[10][1];
    char votestatus[10]; //A notvoted , B voted
    char vote2[10]; //X not voted, Y yes, N no
    bool loggedin = false;
    
    //burada oy durumunu dosyadan alıyor
    for (int j=0;j<10;j++){
        fscanf(in, "%11s%*[ \t]%99s ", list.username[j], list.password[j]);
        memcpy(username3[j], list.username[j], sizeof(username3[j]));
        memcpy(password3[j], list.password[j], sizeof(password3[j]));
        fscanf(vts, "%9s%*[ \t]%4s ", list.isvotedstatus[j], list.vote[j]);
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
    while(votecount!=6){
        printf("Enter your username: ");
        scanf("%s",username2);
        for (int j=0;j<10;j++){
            if (strcmp(username2,username3[j])==0){
                printf("Enter Your password: ");
                scanf("%s",password2);
                if (strcmp(password2,password3[j])==0){
                    loggedin = true;
                    char newpass[100];
                    printf("\nWelcome %s!\n",username3[j]);
                    printf("Menu:\n");
                    printf("1. Vote Yes\n");
                    printf("2. Vote No\n");
                    printf("3. Change Password\n");
                    printf("4. Results\n");
                    printf("5. Save votes\n");
                    printf("6. Change Vote\n");
                    printf("7. Log off\n");
                    printf("Your Selection: ");
                    scanf("%d",&secimoy);
                    switch(secimoy){
                        case 1:
                            if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                                printf("You have already voted YES!\n");
                                break;
                            }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                                printf("You have already voted NO!\n");
                                break;
                            }else{
                                printf("Your YES vote is saved!\n");
                                yesvote = yesvote + 1;
                                votecount = votecount + 1;
                                votestatus[j] = 'B';
                                vote2[j] = 'Y';
                                fseek(vts,0,SEEK_SET);
                                for (int i=0;i<10;i++){
                                    fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                                }
                                //dosyaya yaz burda
                                printf("Votes saved!\n");
                                break;
                            }
                        case 2:
                            if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                                printf("You have already voted YES!\n");
                                break;
                            }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("N", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                                printf("You have already voted NO!\n");
                                break;
                            }else{
                                printf("Your No vote is saved!\n");
                                novote = novote + 1;
                                votecount = votecount + 1;
                                votestatus[j] = 'B';
                                vote2[j] = 'N';
                                fseek(vts,0,SEEK_SET);
                                for (int i=0;i<10;i++){
                                    fprintf(vts,"%c %c\n", votestatus[i],vote2[i]);
                                }
                                
                                //fclose(vts);
                                //remove(tmpvts);
                                //rename("tmpvt.txt","Votestats.txt");
                                //remove("tmpvt.txt");
                                //dosyaya yaz burda
                                printf("Votes saved!\n");
                                break;
                            }
                        case 3:
                            //fseek(in, 12, SEEK_SET);
                            //fseek(in, list.password, SEEK_SET);
                            //list.password yerini long int olarak al yaz buraya
                            printf("Enter your new password: ");
                            scanf("%s", newpass);
                            if (strlen(newpass) == 6){
                                //fprintf(in, "%s ", newpass);
                                //fclose(in);
                                //printf("Your password is changed. Restart the program to apply changes!\n");
                                break;
                            }else{
                                printf("Your new password have to 6 characters long!\n");
                                break;
                            }
                            
                        case 4:
                            printf("Votes: %d\n", votecount);
                            printf("Yes Votes: %d\n", yesvote);
                            printf("No Votes: %d\n", novote);
                            break;
                        case 5:
                            /*for (int i=0;i<10;i++){
                                fprintf(tmpvts,"%c %c\n", votestatus[i],vote2[i]);
                            }
                            fclose(tmpvts);
                            remove("Votestats.txt");
                            rename("tempvt.txt","Votestats.txt");
                            printf("Votes saved!\n");*/
                            //fprintf(tmpvts,"%c %c", votestatus[j],vote2[j]);
                            //fclose(tmpvts);
                            //burada for döngüsü ile dosyaya yaz
                            break;
                        case 6:
                            if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'Y')){
                                printf("You voted YES already, are you sure to change your vote to NO?\n");
                                printf("1. Yes\n");
                                printf("2. Delete my vote\n");
                                printf("3. No\n");
                                scanf("%d",&changevote);
                                switch(changevote){
                                    case 1:
                                        printf("You changed your vote to NO!\n");
                                        yesvote--;
                                        novote++;
                                        vote2[j] = 'N';
                                        break;
                                    case 2:
                                        printf("Your vote is deleted\n");
                                        yesvote--;
                                        votecount--;
                                        vote2[j] = 'X';
                                        votestatus[j] = 'A';
                                        break;
                                    case 3:
                                        printf("Operation cancelled by user.\n");
                                        break;
                                }
                                
                            }else if ((strcmp("B", list.isvotedstatus[j]) == 0 && strcmp("Y", list.vote[j]) == 0) || (votestatus[j] == 'B' && vote2[j] == 'N')){
                                printf("You voted NO already, are you sure to change your vote to YES?\n");
                                printf("1. Yes\n");
                                printf("2. Delete my vote\n");
                                printf("3. No\n");
                                scanf("%d",&changevote);
                                switch(changevote){
                                    case 1:
                                        printf("You changed your vote to YES!\n");
                                        yesvote++;
                                        novote--;
                                        vote2[j] = 'Y';
                                        break;
                                    case 2:
                                        printf("Your vote is deleted\n");
                                        novote--;
                                        votecount--;
                                        vote2[j] = 'X';
                                        votestatus[j] = 'A';
                                        break;
                                    case 3:
                                        printf("Operation cancelled by user.\n");
                                        break;
                                }
                                
                            }else{
                                printf("You need to vote first!\n");
                                break;
                            }
                        case 7:
                            break;
                }
                }else {
                    printf("Wrong password!\n");
                    break;
                }
                
            }
        }
        fclose(vts);
        fopen("Votestats.txt", "r+");
    }
    printf("\nVoting ended!\n");
    printf("Votes: %d\n", votecount);
    printf("Yes Votes: %d\n", yesvote);
    printf("No Votes: %d\n", novote);


    if (loggedin == false){
        printf("Wrong username!\n");
    }
    
    
    
}
