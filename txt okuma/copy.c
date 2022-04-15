//
//  copy.c
//  txt okuma
//
//  Created by Ali Yiğit Taş on 14.04.2022.
//
while (fscanf(in, "%d %11s %99s %9s %4s[^\n]", &list.sirano, list.username, list.password, list.isvotedstatus, list.vote) != EOF) {
            if (strcmp(username2, list.username) == 0 && strcmp(password2, list.password) == 0) {
                if (strcmp(list.isvotedstatus, "voted") == 0) {
                    printf("You have already voted.\n");
                    isVoted = true;
                }
                else {
                    printf("Oy ver:\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("3. Results\n");
                    scanf("%d",&secimoy);
                    switch(secimoy){
                        case 1:
                            yesvote++;
                            strcpy(list.isvotedstatus, "voted");
                            strcpy(list.vote, "yes");
                            break;
                        case 2:
                            novote++;
                            strcpy(list.isvotedstatus, "voted");
                            strcpy(list.vote, "no");
                            break;
                        case 3:
                            printf("Yes: %d\n", yesvote);
                            printf("No: %d\n", novote);
                            break;
                    }
                }
            }
        }
