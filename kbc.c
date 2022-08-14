#include<stdio.h>
#include<math.h> //for power function
void safemoney(); //this function ascertains the money contesters gets on losing, keeping in mind the checkpoints they have crossed. 
void one(); //each function from one to twelve stands for a new question. There is one extra question inside int main(), making a total of thirteen questions in the programme. Also, each function follows the same logic. Hence, comments have been made only once and for the first question.
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void ten();
void eleven();
void twelve();
int i, n, flip, fifty, current, prize;
int main() //the main loop which has the first question.
{
printf("Deviyon aur Sajjanon!\nSwagat hai KBC mein!\nIt contains 12 questions. The prize money for each question is-\n");
printf("1st- 5000/-\n2nd- 10,000/-\n3rd- 20,000/- (checkpoint 1)\n4th- 40,000/-\n");
printf("5th- 80,000/-\n6th- 1,60,000/-\n7th- 3,20,000/- (checkpoint 2)\n8th- 6,40,000/-\n");
printf("9th- 12,80,000/-\n10th- 25,60,000/- (checkpoint 3)\n11th- 51,20,000/-\n12th- 1,02,40,000/- (grand prize)\n");
printf("You will have two lifelines-\nLifeline 1- 50-50 (two wrong options will be removed from the screen.)\nLifeline 2- Flip the Question (the entire question will replaced with a new one on the screen)\n");
printf("Both lifelines can be used only ONCE, and can ALSO be used in the SAME turn.\n");
printf("For lifeline 1 (50-50), type 'g'. For lifeline 2 (flip), type 'h'. To quit, type 'q'.\n\n");
printf("Press any key to continue.\n");
getchar(); //press any key to continue appears several times in the programme. It ensures regulated presentation of data.
n=1;
i=1;
flip=0;
fifty=0;
current=0;
prize=5000*pow(2,i-1); //"prize" is the reward for every question. It starts with 5000 rupees, and then keeps on doubling as the contester answers question correctly. If, however, they choose flip the question, then the reward money stays the same because in that case the value of i is not increased.
printf("Pehla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n",prize);
printf("Q%d\n",i);
printf("What was the symbol of the Nazis?\na. Cross\nb. Skull\nc. Bones\nd. Swastika\n");
if (flip==0) //flip and fifty are integer values which gets increased to 1 once their respective lifeline is used. After that, the programme only reads the else statement. This ensures that a lifeline is used only once.
  {printf("You have flip the question lifeline left (press h). ");
   if(fifty==0)
    {printf("You also have fifty-fifty lifeline left (press g). ");}
  }
else {
  if (fifty==0)
   {printf("You only have 50-50 lifeline left (press g). ");}
  else {printf("You have no lifelines left. ");}}
printf("To quit (press q). ");
while(n<2)
  {
char option;
printf("Please enter option\n"); //contestant inputs the letter corresponding to the option which is read by switch.
scanf(" %c",&option);
switch(option)
{
case 'A':
case 'a':
printf("Apsos...yeh galat uttar hai!\n");
safemoney(); //calculates the money a contestant deserves.
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1); //current is the money the contester has at the moment.
printf("You now have= %d\n", current);
i++; //increases the question number and the prize money.
printf("Press any key to continue:");
getchar();
printf("\n");
one();
break;
case 'g': //activated when a person uses "50-50" lifeline.
case 'G':
if (fifty==0) //first, the programme checks if the lifeline has already been used.
{printf("Options A and C are wrong. "); //if it hasn't, it displays two options that are wrong.
printf("50-50 lifeline has now been used.\n"); //and that it confirms that the 50-50 lifeline has been used.
fifty++; //here, the value of fifty has been increased.
break;
}
else
{printf("The 50-50 lifeline has already been used.\n"); //and since fifty's value has been increased, typing g again will keep turning up this option, and because the value of n hasn't increased, the loop will keep asking to enter a valid option.
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. "); //the same algorithm as in fifty-fifty lifeline has been used.
printf("Press any key to continue:\n");
int getchar();
getchar();
flip++;
n++;
one(); //since the question has been changed, the control moves into the "one()" function. And since the value of i hasn't been increased, the game still treates the next question as question one.
break;}
else{printf("Flip the Question lifeline has already been used.\n");
break;}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! "); //this is the quit option, using which the loop breaks, and the contester gets the "current" money. We didn't have to use safemoney() here.
n++;
i++; //we increase value of i to give the user the value of current they actually deserve.
break;
default: //reads all inapplicable options and repeats the loop.
printf("Ineligible answer. ");
break;
}
}
printf("Game over. ");
printf("Final prize %d\n",current); //shows the final price and end the game.
}

void safemoney()
{if (current<20000) //checkpoint1 is 20,000; checkpoint 2 is 3,20,000; checkpoint 3 is 25,60,000
 {current=0;}
else if(current>=20000&&current<320000)
 {current=20000;}
else if(current>=320000&&current<2560000)
 {current=320000;}
else{current=2560000;}
}

void one()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("Who is the head of RBI?\na. Finance Minister\nb. Revenue Secretary\nc. Governer\nd. Chief Manager\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). ");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left. ");}
else {printf("You have no lifelines left. ");}}
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'A':
case 'a':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'c':
case 'C':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue:");
getchar();
printf("\n");
two(); //takes control to the next question.
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options A and B  are wrong. ");
printf("50-50 lifeline has now been used.\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used.\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
printf("Press any key to continue:\n");
int getchar();
getchar();
flip++;
n++;
two();
break;}
else{printf("Flip the Question lifeline has already been used.\n");
break;}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible answer.  ");
break;
}
}
}

void two()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("What is the system of governance in China?\na. Communism\nb. Socialism\nc. Monarchy\nd. Democracy\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). ");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}}
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
printf("Press any key to continue:");
int getchar();
getchar();
printf("\n");
i++;
three();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options C and D are wrong ");
printf("50-50 lifeline has now been used.\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used.\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
three();
break;}
else{printf("Flip the Question lifeline has already been used.\n");
break;}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible answer. \n");
break;
}
}
}

void three()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("How many rings does the Olympic logo have?\na. 3\nb. 2\nc. 6\nd. 5\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g).\n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue:");
int getchar();
getchar();
printf("\n");
four();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options A and B are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
four();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void four()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("What is the name of Lord Rama's mother?\na. Yashoda\nb. Kaushalya\nc. Kaikai\nd. Sumitra\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). ");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'b':
case 'B':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
five();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options C and D are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
five();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void five()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("Solid Carbon-dioxide is also called:\na. Solid Carbon\nb. White Carbon\nc. Dry Ice\nd. Charcoal\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). \n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'c':
case 'C':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
six();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options B and D are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
six();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void six()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("Which of the following is not an example of an OS?\na. MS Office\nb. Windows Vista\nc. Windows XP\nd. Ubuntu Linux\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). \n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
seven();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options C and D are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
seven();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void seven()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("Which place is known as the birth place of Jesus Christ?\na. Haifa\nb. Bethlehem\nc. Jerusalem\nd. Acre\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). \n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'b':
case 'B':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
eight();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options A and D are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
eight();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void eight()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("Which country is known as the 'Land of the Rising Sun'?\na. New Zealand\nb. Israel\nc. Japan\nd. Argentina\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g). \n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'c':
case 'C':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
nine();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options B and D are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
nine();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void nine()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("In which year was the United Nations founded?\na. 1948\nb. 1946\nc. 1947\nd. 1945\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g).\n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
ten();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options A and C are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
ten();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void ten()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("What is the capital of Turkey?\na. Antalya\nb. Istanbul\nc. Izmir\nd. Ankara\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g).\n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
eleven();
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options A and C are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
eleven();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void eleven()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("Which is the deepest point in the Indian Ocean?\na. Kankyakumari Trench\nb. Java Trench\nc. Khandala Trench\nd. Edward Trench\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g).\n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g).\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'b':
case 'B':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
if (current<10000000){
printf("You now have= %d\n", current);
i++;
printf("Press any key to continue\n");
int getchar();
getchar();
twelve();
break;}
else if(current>10000000){
printf("Mubarkein!! Aap ban gaye hain Crorepati!\n");
i++;
break;}
case 'g':
case 'G':
if (fifty==0)
{printf("Options A and C are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
if (flip==0)
{printf("Flip the question lifeline is now going to be used. ");
flip++;
n++;
printf("Press any key to continue:\n");
int getchar();
getchar();
twelve();
break;}
else{printf("Flip the Question lifeline has already been used\n");}
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}

void twelve ()
{int getchar();
getchar();
prize= 5000*pow(2,i-1);
printf("\nAgla sawaal...%d rupay ke liye...aapke saamne yeh raha!\n", prize);
printf("Question number %d\n",i);
n=1;
printf("The largest earthquake till date, of a  magnitude 9.5, by magnitude occured in which country?\na. Valdivia, Chile (1960)\nb. Chittagong, Bangladesh (1872)\nc. Prince William Sound, Alask, United States (1964) \nd. Pacific Ocean, Tohuku region, Japan (2011)\n");
if (flip==0)
{printf("You have flip the question lifeline left (press h). ");
if(fifty==0)
{printf("You also have fifty-fifty lifeline left (press g).\n");}
}
else {
if (fifty==0)
{printf("You only have 50-50 lifeline left (press g)\n");}
else {printf("You have no lifelines left\n");}} 
if (current>=20000&&current<320000)
{printf("Also, you have cleared checkpoint 1 of 20,000/-. Next checkpoint at 3,20,000.\n");}
else if (current>=320000&&current<2560000)
{printf("Also, you have cleared checkpoint 2 of 3,20,000/. Next checkpoint at 25,00,000.\n");}
else if(current>=2560000)
{printf("Checkpoint 3 of 25,60,000 has been cleared. Final prize 102,40,00,000/-\n");} 
printf("To quit (press q). ");
while(n<2)
{
printf("Please enter option\n");
char option;
scanf(" %c",&option);
switch(option)
{
case 'c':
case 'C':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'B':
case 'b':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'd':
case 'D':
printf("Apsos...yeh galat uttar hai!\n");
safemoney();
n++;
break;
case 'a':
case 'A':
printf("Ek dum sahi jawab! ");
n++;
current=5000*pow(2,i-1);
printf("Mubarakein! Aap ban gaye hain Crorepati! ");
i++;
break;
case 'g':
case 'G':
if (fifty==0)
{printf("Options B and D are wrong\n");
printf("50-50 lifeline has now been used\n");
fifty++;
break;
}
else
{printf("The 50-50 lifeline has already been used\n");
break;}
case 'h':
case 'H':
n++;
i++;
break;
case 'q':
case 'Q':
printf("Humein aapke jaane ka khed hai! ");
n++;
i++;
break;
default:
printf("Ineligible option. \n");
break;
}
}
}
