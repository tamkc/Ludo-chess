#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

char chess[16] = {};
char chessboard[11][11];
char base[4][4] = { { 'a', 'b', 'c', 'd' },
{ 'e', 'f', 'g', 'h' },
{ 'i', 'j', 'k', 'l' },
{ 'm', 'n', 'o', 'p' } };
char home[4][4] = {};
int Gameplayer = 2;
int Humanplayer = 2;
int Computerplayer;
int globaldic;
class mainop;
class menu;
class Ludo_broad;
class allmove;
void get_base(int a);
void returnmenu();
void start();
void settings();
void gamedemo();
void instructions();
void credits();
void exit();


// initial chessboard
void Set_Broad() {

for (int col = 0; col <= 10; col++) {
  for (int row = 0; row <= 10; row++) {
    chessboard[col][row] = '.';
  }
}
for (int i = 0; i < 16; i++)
  chess[i] = 97 + i;

for (int col = 1; col < 10; col++) {
  for (int row = 1; row < 10; row++) {

    chessboard[col][row] = ' ';

    if ((col == row) || ((col + row) == 10)) {
      chessboard[col][row] = '.';
    }
  }
}
chessboard[5][5] = 'X';
}

void Show_Broad() {

for (int col = 0; col <= 10; col++) {
  for (int row = 0; row <= 10; row++) {

    cout << chessboard[col][row] << " ";

  }cout << endl;
}
}


class Chess {
public:



Chess() {
  row = 0; col = 0;
};
void moveins(int a, int b, char player_choice, int dice, string v) {
 Odice=dice;
  while (dice != 0) {
    if (leaveB == 0 && dice != 6)break;
    if (leaveB == 0 && dice == 6) {
      leaveB = 1;

     for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
     if(base[i][j]==player_choice)base[i][j]=' ';

      row += a; col += b;

      chessboard[row][col] = player_choice;

      if (row == 0 && col == 0)TL = true;
      if (row == 0 && col == 10)TR = true;
      if (row == 10 && col == 10)BR = true;
      if (row == 10 && col == 0)BL = true;
      dice = 0; continue;
    }
    ox = row; oy = col;
    chessboard[row][oy] = '.';
    if(leaveB){
    while (dice != 0 && TL == true) {
      if (turn) {
       if(retu!=1){
       row++; col++; dice--;}
       else {row--;col--;dice++;}
       if (row==5&&col==5)retu=1;
       }
      else{
      col++; dice--;
      (row == 0 && col == 10) ? (TL = 0, TR = 1) : (TL = 1);
      turn = (row == a && col == b) ? 1 : 0;}
    }
    while (dice != 0 && TR == true) {
      if (turn) {
       if(retu!=1){row++; col--; dice--; }
     else {row--;col++;dice--;}
     if (row==5&&col==5)retu=1;
     }
      else{
      row++; dice--;
      (row == 10 && col == 10) ? (TR = 0, BR = 1) : (TR = 1);
      turn = (row == a && col == b) ? 1 : 0;
      }
    }
    while (dice != 0 && BR == true) {
      if (turn){ row--; col--; dice--; }
      else {
        col--; dice--;
        (row == 10 && col == 0) ? (BR = 0, BL = 1) : (BR = 1);
        turn = (row == a && col == b) ? 1 : 0;
      }
    }
    while (dice != 0 && BL == true)
   {if (turn) {
     if(retu!=1){
      row--; col++; dice--;}
      else {row++;col--;dice--;}
     if (row==5&&col==5)retu=1;
     }
      else{
      row--; dice--;
      (row == 0 && col == 0) ? (BL = 0, TL = 1) : (BL = 1);
      turn = (row == a && col == b) ? 1 : 0;
      }

    }
   retu=0;
    }
    
 for(int i=0;i<5;i++){
   if (chessboard[row][col]==v[i]&&chessboard[row][col]!=player_choice){
   cout<<"Over lap occured\nPlease choose other chess";
  cin>>New_choice;
  player_choice=New_choice;
   row=ox,col=oy;
  dice=Odice;break;
  }}
  } if(row==5&&col==5){
    row=(11+(player_choice-1)%4);col=(player_choice-1)%4;}
   if (leaveB)chessboard[row][col] = player_choice;
}

bool check(int player_num,int dice){

  ox=row;oy=col;

 if(player_num==1&&BL){ox-=dice;if(ox>10){oy+=(0-ox);ox=abs(ox);}
 if(chessboard[0][0]>='a'&&chessboard[0][0]<='d')return 0;
 }


 if(player_num==2&&TL){oy+=dice;if(oy>10){ox+=(oy-10);oy=abs(10-oy);}
 if (chessboard[0][0]>='e'&&chessboard[0][0]<='h')return 0;
 }

 if(player_num==3&&TR){ox+=dice;if(ox>10){oy-=(ox-10);ox=abs(10-ox);}
 if (chessboard[0][0]>='i'&&chessboard[0][0]<='l')return 0;
 }


 if(player_num==4&&BR){oy-=dice;if(oy<10){ox-=(0-oy);oy=abs(oy);}
 if (chessboard[0][0]>='m'&&chessboard[0][0]<='p')return 0;
 }


 ox=row;oy=col;
  if(leaveB){
 if(TL)oy+=dice;if(oy>10){ox+=(oy-10);oy=10;}
 if(TR)ox+=dice;if(ox>10){oy-=(ox-10);ox=10;}
 if(BR)oy-=dice;if(oy<10){ox-=(0-oy);oy=0;}
 if(BL)ox-=dice;if(ox>10){oy+=(0-ox);ox=0;}

    switch(player_num){
   case 1:if (chessboard[ox][oy]>='a'&&chessboard[ox][oy]<='d')return 0;break;
   case 2:if (chessboard[ox][oy]>='e'&&chessboard[ox][oy]<='h')return 0;break;
   case 3:if (chessboard[ox][oy]>='i'&&chessboard[ox][oy]<='l')return 0;break;
   case 4:if (chessboard[ox][oy]>='m'&&chessboard[ox][oy]<='p')return 0;break;
   }
 }

 if (!leaveB)
   switch(player_num){
   case 1:if (chessboard[0][0]>='a'&&chessboard[0][0]<='d')return 0;break;
   case 2:if (chessboard[0][10]>='e'&&chessboard[0][10]<='h')return 0;break;
   case 3:if (chessboard[10][10]>='i'&&chessboard[10][10]<='l')return 0;break;
   case 4:if (chessboard[10][0]>='m'&&chessboard[10][0]<='p')return 0;break;
   }
   return 1;
 }

private:
 int row, col, ox, oy,Odice;
 char New_choice;
 bool TL = 0, TR = 0, BL = 0, BR = 0, leaveB = 0, turn = 0,retu = 0;

};

class Player {
public:
Player(int a) {
  switch (a)
  {
  case 1: x = 0, y = 0; v = base[0]; break;

  case 2: x = 0, y = 10; v = base[1]; break;

  case 3: x = 10, y = 10; v = base[2]; break;

  case 4: x = 10, y = 0; v = base[3]; break;
  default: cout << "wrong";
    break;
  }
};

Chess A, B, C, D;
void move(char j, int k) {

  int P = 1 + (j - 97) % 4;
  if (P == 1)     A.moveins(x, y, j, k, v);
  else if (P == 2)B.moveins(x, y, j, k, v);
  else if (P == 3)C.moveins(x, y, j, k, v);
  else if (P == 4)D.moveins(x, y, j, k, v);

}
void check_move(int player_num,int dice){
list[0]=A.check(player_num,dice)?'a'+(player_num-1)*4:' ';
list[1]=B.check(player_num,dice)?'b'+(player_num-1)*4:' ';
list[2]=C.check(player_num,dice)?'c'+(player_num-1)*4:' ';
list[3]=D.check(player_num,dice)?'d'+(player_num-1)*4:' ';

for(int i=0;i<4;i++)
cout<<list[i]<<" ";
}
private:
int x, y;
char c1;
char list[4];
string v;
};

class mainop {
public:

void welcome() {
  cout << "*********************************\n";
  cout << "*********************************\n";
  cout << "* Welcome to our Ludo Game!!!!! *\n";
  cout << "*    Hope you enjoy this!!!!    *\n";
  cout << "*********************************\n";
  cout << "*********************************\n";
  cout << "\n";
  return;
}

void menu() {
  do {
    cout << "* Game Menu *" << endl;
    cout << "[1] Start Game" << endl;
    cout << "[2] Settings" << endl;
    cout << "[3] Game Demo" << endl;
    cout << "[4] Instructions" << endl;
    cout << "[5] Credits" << endl;
    cout << "[6] Exit" << endl;
    cout << "Option (1 - 6): ";
    cin >> choice;
    cout << "\n";


    switch (choice) {
    case 1: start();        break;
    case 2: settings();     break;
    case 3: gamedemo();     break;
    case 4: instructions(); break;
    case 5: credits();      break;
    case 6: exit();         break;
    default: {
      system("clear");
      cout << "Please enter a number from 1 to 6!!!" << endl;
      system("pause");
      system("clear"); break;
    }
    }

  } while (choice != 6);
  system("clear");
  return;
}

void gameover() {
  cout << "*********************************\n";
  cout << "*********************************\n";
  cout << "*         Game Over!!!!         *\n";
  cout << "*    Hope you enjoy this!!!!    *\n";
  cout << "*          Bye Bye!!!!          *\n";
  cout << "*********************************\n";
  cout << "*********************************\n";
  cout << "*********************************\n";
  return;
}

private:
int choice;

friend class mainop;
};

int main() {

mainop showmessage;
showmessage.welcome();
showmessage.menu();
showmessage.gameover();

return 0;
}

void returnmenu() {
mainop returnmain;
returnmain.welcome();
returnmain.menu();
return;
}
void get_base(int row) {
for (int i = 0; i <= 3; i++) {
  cout << base[row-1][i] << " ";
}
cout << endl;
}
void start() {
system("clear");
Set_Broad();
Show_Broad();
int win = 1;
bool check_chess=0;
srand(time(0));

Player P1(1), P2(2), P3(3), P4(4);

system("clear");
int dice;
while (win == 1) {

  for (int i = 1; i <= Gameplayer; i++) {
			system("clear");
dice = 1 + rand() % 6;
    char player_choice;
   do {

    Show_Broad();

    cout << "Player " << i << " roll a dice \n";
  
    cout << "Base:  ";get_base(i);
     cout << "Home:  \n";
   cout << "you got " << dice << endl << "Moveable Chess :";

    if (i == 1)P1.check_move(i, dice);
    if (i == 2)P2.check_move(i, dice);
    if (i == 3)P3.check_move(i, dice);
    if (i == 4)P4.check_move(i, dice);

   cout<<"\nChoose a chess to move : ";
    check_chess=0;

    cin >> player_choice;

     if(player_choice>='a'+(i-1)*4&&player_choice<='d'+(i-1)*4)
     check_chess=1;
  
    if (check_chess==1)break;
     system("clear");
    cout<<"It is not your chess !!!\nPlease enter again :\n";
  }while(check_chess!=1);

    if (i == 1)P1.move(player_choice, dice);
    if (i == 2)P2.move(player_choice, dice);
    if (i == 3)P3.move(player_choice, dice);
    if (i == 4)P4.move(player_choice, dice);
  }
}
system("pause");
system("clear");
returnmenu();
return;
}


void settings() {
	system("clear");

	int Set_Opt;

	do {
		system("clear");
		cout << setw(18) << setfill(' ') << " Settings Menu " << setw(4) << setfill(' ') << "\n";
		cout << "[1] Number of players\n";
		cout << "[2] Number of human players\n";
		cout << "[3] Return to Game Menu\n";
		cout << setw(23) << setfill('*') << " \n";
		cout << "Option (1 - 3):";
		cin >> Set_Opt;

		switch (Set_Opt) {
		case 1:
			system("clear");
			do {
				system("clear");
				if (Gameplayer < 2 || Gameplayer>4) {
					Gameplayer = 2;
				}
				cout << "We have " << Gameplayer << " players now!!!" << endl;
				cout << "Please enter the new number of players from 2 to 4: ";
				cin >> Gameplayer;
				if (Gameplayer < 2 || Gameplayer>4) {
					system("clear");
					cout << "Please enter a number from 2 to 4!!!" << endl;
					system("pause");
					system("clear");

				}
				else {
					settings();
					break;
				}
			} while (Gameplayer < 2 || Gameplayer>4);
			break;
			system("pause");
			break;
		case 2:
			do {
				system("clear");
				if ((Humanplayer < 0 || Humanplayer>4) && Humanplayer > Gameplayer) {
					Humanplayer = 2;
				}
				cout << "We have " << Humanplayer << " human players now!!!" << endl;
				cout << "Please enter the new number of human players from 2 to 4: ";
				cin >> Humanplayer;
				if ((Humanplayer < 0 || Humanplayer>4) && Humanplayer > Gameplayer) {
					system("clear");
					cout << "Please enter a number from 1 to 4!!!" << endl;
					cout << "Please be careful that the number of human player" << endl << "cannot exceed the number of game player!!!" << endl;
					system("pause");
					system("clear");
				}
				else {
					system("clear");
					Computerplayer = Gameplayer - Humanplayer;
					cout << "There are " << Humanplayer << " human player(s) and " << Computerplayer << " computer player(s) now!!!" << endl;
					system("pause");
					settings();
					break;
				}
			} while ((Humanplayer < 0 || Humanplayer>4) && Humanplayer > Gameplayer);
			break;
		case 3:
			system("clear");
			returnmenu();
			system("pause");
			break;
		default: {
			system("clear");
			cout << "Please enter a number from 1 to 3!!!" << endl;
			system("pause");
			break;
		}
		}

	} while (Set_Opt != 3 && (Gameplayer < 2 || Gameplayer>4));

	system("pause");
	system("clear");
	returnmenu();
	return;
}

void gamedemo() {
system("clear");

cout << "This is game demo!" << endl;

system("pause");
system("clear");
returnmenu();
return;
}

void instructions() {
system("clear");

cout << "Instruction" << endl << endl
  << "This Ludo game accepts 2 to 4 players. To set the number of player, go to [2] Setting in the main menu." << endl
  << "Each player has four chesses. All chesses are at their starting location “Base” from each player. In every turns, each player rolls a die which is generating a random number from 1 to 6 and move the chesses in clockwise. " << endl
  << "To have a chess leaving “Base” and entering the game board, a player must roll ‘6’. If the player has no chess on the game board and fails to roll ‘6’, the turn passes to the next player." << endl
  << "If a player has one or more chess to move, he chooses a movable chess from the given list and moves the chess along the path by the number of positions according to the rolling result. " << endl
  << "If a player rolls a ‘6’, he gets a bonus turn. If the bonus turn rolls a ‘6’ again, he gets one more bonus turn. If he rolls a ‘6’ once again, there is no more bonus turn; after his move the turn passes to the next player. " << endl
  << "A player cannot move a chess into a location that is occupied by other chesses of that player." << endl
  << "If a chess ends on a position occupied by an opponent’s chess, the opponent chessis sent back to the opponent’s “Base”. Any chess that has reached “Home”should be “safe” from being sent back." << endl
  << "A chess can reach “Home” only if it exactly steps on ‘X’. If the rolling value       exceeds the number of steps required, the chess should move backward for the     remaining steps." << endl
  << "The total number of steps for each chess is 45 steps. The first player who sends all four chesses to” Home” will win the game." << endl;


system("pause");

system("clear");
returnmenu();
return;
}

void credits() {
system("clear");

cout << "Credits" << endl

  << "17175676A\tTamKamChuen\t104C" << endl;
  

system("pause");
system("clear");
returnmenu();
return;
}

void exit() {
	char x;
	system("clear");
	cout << "Exit or not? \nY or N? ";
	cin >> x;

	if (x == 'Y' || x == 'y') {
		return;
	}
	else if (x == 'n' || x == 'N') {
		system("clear");
		return returnmenu();
	}
	else {
		system("clear");
		cout << "Confirm you input again!!\n";
		system("pause");
		system("clear");
		return exit();
	}

	system("clear");
	return;
}
