#include<iostream>
using namespace std;
char t='X';
int ch;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool draw=false;
void display()
{
	system("cls");
	system("Color 7C");
	cout<<"\******************************* TIC  TAC  TOE  GAME ********************************************\n\n";
	cout<<"\t\t\tPLAYER1 [X]\n \t\t\tPLAYER2 [O] \n\n\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"  \n";
	cout<<"\t\t\t     |     |     \n";	
}

void turn()
{
	int r,c;
	if(t=='X')
	cout<<"\n PLAYER1 [X] turn:\n";
	if(t=='O')
	cout<<"\n PLAYER2 [O] turn:\n";
	cin>>ch;
	switch(ch)
	{
		case 1: r=0,c=0;
		        break;
		case 2: r=0,c=1;
		        break;
		case 3: r=0,c=2;
		        break;		
		case 4: r=1,c=0;
		        break;
		case 5: r=1,c=1;
		        break;
		case 6: r=1,c=2;
		        break;		
		case 7: r=2,c=0;
		        break;
		case 8: r=2,c=1;
		        break;
		case 9: r=2,c=2;
		        break;	
	    default:cout<<"\n invalid choice !!!";		
	}	
	if(t=='X'&& a[r][c]!='X' && a[r][c]!='O')
	{
		a[r][c]='X';
		t='O';
	}
	else if(t=='O' && a[r][c]!='X' && a[r][c]!='O')
	{
		a[r][c]='O';
		t='X';
	}
	else
	{
		cout<<"\n This box is already filled !!! please try again";
		turn();
		display();
		
	}
}
bool over()
{
	if(a[0][0]==a[1][1] && a[0][0]==a[2][2] || a[0][2]==a[1][1] && a[0][2]==a[2][0])
	return false;
	
	for(int i=0;i<3;i++) //comparing all 3 rows *checking either 1 or 2 player win or not
		if(a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[0][i]==a[1][i] && a[0][i]==a[2][i])
			return false;
			
	for(int i=0;i<3;i++)  //checking if any column still have number if have then game is not over *game is running
		for(int j=0;j<3;j++) 
			if(a[i][j] !='X' && a[i][j] != 'O')
		return true;
	
	
	draw=true;
	return false; 	
}

int main(void)
{
	while(over())
	{
		display();
		turn();	
	}
if(t=='X' && draw==false)
	cout<<"\n PLAYER2 [O] Wins!!! Congratulations";	
else if(t=='O' && draw==false)
	cout<<"\n PLAYER1 [X] Wins!!! Congratulations";	
else
 cout<<"\n GAME DRAW!!!";
return 0;
}

/*
******************************* TIC  TAC  TOE  GAME ********************************************

                        PLAYER1 [X]
                        PLAYER2 [O]


******************************* TIC  TAC  TOE  GAME ********************************************

                        PLAYER1 [X]
                        PLAYER2 [O]


                             |     |
                          X  |  O  |  3
                        _____|_____|_____
                             |     |
                          O  |  X  |  6
                        _____|_____|_____
                             |     |
                          7  |  8  |  9
                             |     |

 PLAYER1 [X] turn:
9

 PLAYER1 [X] Wins!!! Congratulations
PS C:\Users\HP\PROGRAMS\mycpp>

*/



