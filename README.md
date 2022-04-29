# CMPE140Project2

## Level 1

In Project 2 Level 1, the goal is to make a voting process with 2 possible answers (yes or no) with a number of participants and to decide which vote has been given more than the other. The participants must be determined with usernames and passwords before beginning the voting process and every participant have only one right to vote. We make that happen with firstly assigning 0 value to every participants voting situation (isvoted). 	At the same time we determine 5 participants’ usernames and passwords in 2 different “char” variables. Also, we define selectvote, yesvote, novote and votecount integers. 

A while loop that continues while votecount is not equal to 5, includes asking the username password part and a for loop. In the for loop that continues while the i is smaller than 5, there is an if function that checks if the username and password is determined before. In that if function there is another. That checks if the user who is just logged in is already voted or not by checking the isvoted variable. If the user’s isvoted variable is 0 then it continues to the voting part. In the voting part program asks the user to vote. Pressing 1 means yes and pressing 2 means no. Then it scans the answer and writes it to selectvote. Then the switch part includes two cases according to the number of possible answers. In case 1 which becomes active when 1 is pressed, program says “Your YES vote is saved” and records that you voted with writing 1 instead of 0 in the isvoted variable. In case 2 which becomes active when 2 is pressed, program says “Your NO vote is saved” and does the same thing to isvoted variable. 

In the last part, an if function checks that number of yes votes are bigger than 3 or number of no votes bigger than 3 or number of total votes is equal to 5. Then every time that a user votes the other if functions check that whether yes is more than no, no is more than yes then if one of the both options ends up being true, the program shows the results. 

----------
## Level 2

--> We create a structure that contains username, password, isvotedstatus and vote. We will use these sequences to read the articles on the files in order to be able to perform the operation. 

--> We are creating arrays again so that we can easily make changes to them. Before requesting user input, the program scans the files, transfers them to the arrays, and restores them to their former state. 

--> We're looking at whether more than half of those used in the While cycle voted yes or no.

--> Then, we are logging in as a user and we have written an if command so that the fields designated with X are not considered users in the file in which the users are registered. 

--> An admin panel has been created that can add new users and manage the current voting status. 

--> If the entered username and password match the one registered in the system, the login is accepted. From the menu that meets the user, the user can vote, change the password, change the vote he/she has given, see the results and log out. 

--> When voting, it is checked whether this user has voted before or not. If the user has not voted before, "your vote has been saved" is printed on the screen and the user's given vote is changed in the corresponding variable as yes or no. The user's voting status is changed via the corresponding array, and the entire array is printed to the file from the very beginning.

--> In the password change section, first the user is asked to enter a new 6-charactered password. The saved password in the array is changed and the entire array is printed to the file from the very beginning. 

--> When the user presses the option to see the votes, they can see the votes cast up to that moment. 

--> To change the vote, it is first checked whether the user voted or not, then if he voted yes, the program asks if he wants to change the vote to no. At the same time, the user has the right to delete the vote. The same applies for a no vote. When the vote is changed, the new vote is changed on the corresponding array and the entire array is printed to the file from the beginning. 

--> After the voting is over, the program shows the voting status on the screen and resets the file containing the voting status. 

--> If the yes vote is more, the result is shown as yes, and if the no vote is more, the result is shown as no. 

--> User login is not allowed after the result of the vote is clearly visible or after everyone has voted. And the program ends.

### Update
These X's in the users.txt and Votestats.txt are not needed for now because without them the program does not write weird things in blank areas like before. These weird things was like that: random combination of strings and numbers, 0, /System/Library/Application Support, etc. 

