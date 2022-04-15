//
//  main.c
//  txt okuma
//
//  Created by Ali Yiğit Taş on 11.04.2022.
// txt sadece ilk satırı okuyor şu anda, isvoted boolu kişiye özel yap, fpirntf kişinin yanında yazmalı şu an altında yazıyor!

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    bool isVoted = false;
    int secimoy,yesvote = 0,novote = 0, votecount = 0;
    int status = EXIT_SUCCESS;
    FILE* in;

    struct userlist {
        int sirano;
        char username[12];
        char password[100];
        char isvotedstatus[9];
        char vote[4];
        
    } list;

    if ((in = fopen("users.txt", "r+")) == NULL) {
        fputs("Cannot open users.txt file\n", stderr);
        return EXIT_FAILURE;
    }

    do {
        char username2[12];
        char password2[100];
        
        while (fscanf(in, "%d%11s%*[ \t]%99s%*[ \t]%9s%*[ \t]%4s ", &list.sirano, list.username, list.password, list.isvotedstatus, list.vote) !=EOF){
            while (votecount!= 5){
                printf("Enter your username: ");
                scanf("%11s", username2);
                printf("Enter Your password: ");
                scanf("%99s", password2);
                if (strcmp(username2, list.username) == 0 && strcmp(password2, list.password)==0) {
                    char newpass[100];
                    printf("Menu:\n");
                    printf("1. Vote Yes\n");
                    printf("2. Vote No\n");
                    printf("3. Change Password\n");
                    printf("4. Results\n");
                    printf("5. Log off\n");
                    printf("Your Selection: ");
                    scanf("%d",&secimoy);
                    switch(secimoy){
                        case 1:
                            if (strcmp("1", list.isvotedstatus) == 0 || isVoted == true){
                                printf("You have already voted!\n");
                                break;
                            }else{
                                printf("Your YES vote is saved!\n");
                                yesvote = yesvote + 1;
                                votecount = votecount + 1;
                                isVoted = true;
                                fseek(in, 21, SEEK_SET);
                                fprintf(in, isVoted ? "1 " : "0 ");
                                fclose(in);
                                break;
                            }
                        case 2:
                            if (strcmp("voted", list.isvotedstatus) == 0 || isVoted == true){
                                printf("You have already voted!\n");
                                break;
                            }else{
                                printf("Your No vote is saved!\n");
                                novote = novote + 1;
                                votecount = votecount + 1;
                                isVoted = true;
                                fseek(in, 21, SEEK_SET);
                                fprintf(in, "%s", isVoted ? "1 ":"0 ");
                                fclose(in);
                                break;
                            }
                        case 3:
                            fseek(in, 14, SEEK_SET);
                            //fseek(in, fscanf(in, "%*d%*11s%*[ \t]%99s%*[ \t]%*9s%*[ \t]%*4s ", list.password), SEEK_SET);
                            printf("Enter your new password: ");
                            scanf("%s", newpass);
                            if (strlen(newpass) == 6){
                                fprintf(in, "%s ", newpass);
                                fclose(in);
                                printf("Your password is changed. Restart the program to apply changes!\n");
                                break;
                            }else{
                                printf("Your new password have to 6 characters long!\n");
                                break;
                            }
                            
                        case 4:
                            printf("Votes: %d\n", votecount);
                            printf("Yes Votes: %d\n", yesvote);
                            printf("No Votes: %d\n", novote);
                        case 5:
                            break;
                }
                }else{
                    printf("Incorrect username or password!\n");
                    
                }
                }
        }
        // else if (n != EOF) {
      //      fputs("Failed to read data\n", stderr);
      //      status = EXIT_FAILURE;
     //       break;
     //   }
     //   else {
     //       break;
     //   }
    }
    while (1);

        // if (fclose(in) == EOF) {
          //  fputs("Failed to close file\n", stderr);
        //    status = EXIT_FAILURE;
       // }
         return status;
    
    }
