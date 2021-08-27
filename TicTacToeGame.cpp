#include<iostream>
using namespace std;

//TIC-TAC-TOE GAME

char board[3][3]={{'1','2','3'}, {'4','5','6'},{'7','8','9'}};
char p1[10];
char p2[10];
bool turn;
bool tie;


void reset()  // resets the board and other variables 
{
 board[0][0] = '1';
 board[0][1] = '2'; 
 board[0][2] = '3';
 board[1][0] = '4';
 board[1][1] = '5';
 board[1][2] = '6';
 board[2][0] = '7';
 board[2][1] = '8';
 board[2][2] = '9';
 
 //turn=0 means player 1's turn & turn=1 means player 2's turn 
 turn = 0; // initially turn is of player 1 

 tie = 0; // intially match is not tied so bool variable 'tie' is set to false
}


void displayboard() // displays the board
{
system("cls");

cout<<"-------------------------------------------------------------";
cout<<"\n\n\t\t      TIC-TAC-TOE GAME\n\n";
cout<<"-------------------------------------------------------------\n\n";

cout<<"  Player1 [X]: "<<p1<<endl;
cout<<"  Player2 [O]: "<<p2;
cout<<"\n\n";

cout<<"\t\t     |     |     "<<endl;
cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
cout<<"\t\t_____|_____|_____"<<endl;

cout<<"\t\t     |     |     "<<endl;
cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
cout<<"\t\t_____|_____|_____"<<endl;

cout<<"\t\t     |     |     "<<endl;
cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
cout<<"\t\t     |     |     "<<endl;

}


void playerturn() // takes input from players and marks 'X' on the board for player 1 and 'O' for player 2. 
{
int n,r,c;     //'n' is choice of the player
               //'r' and 'c' represents the row and column of 'n' on the board (i.e., [r][c] is the index of 'n' )
cout<<"\n\n\t";                       

a:
if(turn==0) 
{cout<<"\t"<<p1<<"'s turn: "; }                       

if(turn==1)
{cout<<"\t"<<p2<<"'s turn: "; }

cin>>n;
                                             
 switch(n)
 {                                        

  case 1:  r=0; c=0; break;                                                                              
  case 2:  r=0; c=1; break;                  // n-                 corresponding index [r][c]-
  case 3:  r=0; c=2; break;                         
  case 4:  r=1; c=0; break;                  // 1   2   3          [0][0]   [0][1]   [0][2] 
  case 5:  r=1; c=1; break;                  // 4   5   6          [1][0]   [1][1]   [1][2] 
  case 6:  r=1; c=2; break;                  // 7   8   9          [2][0]   [2][1]   [2][2]
  case 7:  r=2; c=0; break;
  case 8:  r=2; c=1; break;
  case 9:  r=2; c=2; break;
  
  default:
  cout<<"\t\tInvalid choice!\n";
  goto a;
 }
 
if((turn==0) && (board[r][c] != 'X') && (board[r][c] != 'O'))  //if turn is of player 1 and board[r][c] is empty then mark it 'X'
 { 
   board[r][c] = 'X';
   turn = 1; // turn toggled     
 }

else if((turn==1) && (board[r][c] != 'X') && (board[r][c] != 'O'))  //if turn is of player 2 and board[r][c] is empty then mark it 'O'
 { 
   board[r][c] = 'O';
   turn = 0; // turn toggled 
 }
else
{cout<<"\t\tInvalid choice!\n";
 goto a;
}

displayboard(); // this function is called to display the updated board
}


bool check() // check if the game is over or not ( check() = 0 means that game the is over & check() = 1 means that the game is still going on)
{
 //case-1 
 //p1 or p2 wins
 
 for(int i=0; i<3; i++)
  { if( (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) )
    return 0;
  }

 for(int i=0; i<3; i++)
  { if( (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) )
    return 0;
  }

 if( (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) )
    return 0;
  
 if( (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) )
    return 0;
 

 //case-2 
 //game is still going on
 
 for(int i=0; i<3; i++)
 { for (int j=0; j<3; j++)
   {
     if(board[i][j] != 'X' && board[i][j] != 'O' )   // if any 'board[i][j]' is neither marked with 'X' nor 'O'. then it means that the game is not over yet
     return 1;
   }
 }


 //case-3
 //game tied

 tie = 1;     //bool variable set to 1(true) to indicate that match has tied
 return 0;    
 
 }



int main()
{
char a;  //variable for play again option

do
{
 reset(); // this function is called to reset the game

 cout<<"-------------------------------------------------------------";
 cout<<"\n\n\t\t      TIC-TAC-TOE GAME\n\n";
 cout<<"-------------------------------------------------------------\n\n";
 
 cout<<"\tEnter player1 [X] name: ";
 cin>>p1;
 cout<<endl;
 cout<<"\tEnter player2 [O] name: ";
 cin>>p2;
 
while(check()) // this loop keep executing until 'check()' is not equal to zero.
{
 displayboard();
 playerturn();
}

cout<<"\n\n";

cout<<"-------------------------------------------------------------\n";

if(turn==1 && tie == 0)           // if turn is of player 2 and bool variable 'tie'= false , implies that player 1 won
{ cout<<"\t\t"<<p1<<" Wins!!\n";}

else if(turn==0 && tie == 0)     // if turn is of player 1 and bool variable 'tie'= false , implies that player 2 won
{ cout<<"\t\t"<<p2<<" Wins!!\n";}

else
{ cout<<"\t\tMatch tied!!\n";}

cout<<"-------------------------------------------------------------\n";
cout<<"\n\t\tThanks for playing!!\n\n";
cout<<"-------------------------------------------------------------\n\n";


cout<<"\t  Press 'y' to play again.\n";
cout<<"\t  Press any key to exit.\n\n";

cout<<"\tEnter your choice: ";
cin>>a;
}
while(a=='y' || a=='Y'); // body of 'do' loop runs again if 'while' conditon is true (i.e., user can play again if they press 'y' or 'Y')
 
return 0;
}