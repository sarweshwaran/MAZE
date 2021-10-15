#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int x=0, y, stepDown, finish;

int path[10],chk[10];

bool gameOver=false, win=false;
char a[9][22];
void initialize();

void display();

void answer();

void game();

void answer()
{
	
	int check,temp,idx1=1,idx2=1;
	
	a[0][path[0]]='I';
	
	stepDown=path[0];
	
	for(int i=1; i<8; i=i+2)
	{
		if(chk[idx1])
		{
				temp=path[idx2];
			
				for(int j=temp; j<=stepDown; j++)
				{
					a[i][j]='*';
				}
				
				stepDown=temp;
				a[i+1][stepDown]='*';
		}
		else
		{
			temp=path[idx2];
			
			for(int j=stepDown; j<=temp; j++)
			{
				a[i][j]='*';
			}
			stepDown=temp;
			a[i+1][stepDown]='*';
		}
		idx1++;
		idx2++;
	}
	
	a[8][stepDown]='H';
	
	for(int i=1; i<8; i++)
	{
		for(int j=1; j<21; j++)
		{
			if(a[i][j]=='0' || a[i][j]=='I')
			{
				a[i][j]=' ';
			}
			
		}
	}
	
	display();
}




void initialize()
{
	for(int i=1; i<8; i++)
	{
		for(int j=1; j<21; j++)
		{
			if(rand()%2)
			{
				a[i][j]='-';
			}
			else
			{
				a[i][j]=' ';
			}
		}
	}
	
	for(int i=0; i<9; i++)
	{
		a[i][0]='|';
		a[i][21]='|';
	}
	
	
	y=rand()%20+1;
	
	stepDown=y;
	path[0]=y;
	
	a[0][y]='I';
	
	for(int j=1; j<21; j++)
	{
			if(j!=y)
			{
				a[0][j]='-';
			}
			
			a[8][j]='-';
		
	}
	
	
	int check,temp,idx1=1,idx2=1;
	
	for(int i=1; i<8; i=i+2)
	{
		check=rand()%2;
		chk[idx1]=check;
		if(check)
		{
				temp=(rand()%stepDown)+1;
				path[idx2]=temp;
				for(int j=temp; j<=stepDown; j++)
				{
					a[i][j]=' ';
				}
				stepDown=temp;
				a[i+1][stepDown]=' ';
		}
		else
		{
			temp=(rand()%(20-stepDown+1))+stepDown;
			path[idx2]=temp;
			for(int j=stepDown; j<=temp; j++)
			{
				a[i][j]=' ';
			}
			stepDown=temp;
			a[i+1][stepDown]=' ';
		}
		idx1++;
		idx2++;
	}
	
	a[8][stepDown]='H';
	finish=stepDown;
	
	

	
	
}




void display()
{
	system("cls");
	
	cout<<"\n======================";
	cout<<"\n\tTHE MAZE";
	cout<<"\n======================"<<endl<<endl;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<22; j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
}

void game()
{
	display();
	char ch;
	enter:
		cout<<"\n\nENTER YOUR MOVE (4|6|2|0) : ";
		ch=getch();
		switch(ch)
		{
			case '2':
				if(a[x+1][y]!='-')
				{
					a[x+1][y]='I';
					a[x][y]='0';
					x++;
					
					if(x==8 && y==finish)
					{
						win=true;
						gameOver=true;
					}	
				}
				else
				{
					cout<<"\nTHERE ISA WALL!!! DON'T GUIDE ME WRONG :\\ "<<endl;
					goto enter;
				}
				break;
				
			case '4':
				
				if(a[x][y-1]==' ')
				{
					a[x][y-1]='I';
					a[x][y]='0';
					y--;
				
				}
				else if(a[x][y+1]=='0')
				{
					cout<<"\nI CAN'T MOVE BACK";
					goto enter;
				}
				else
				{
					cout<<"\nTHERE ISA WALL!!! DON'T GUIDE ME WRONG :\\ "<<endl;
					goto enter;
				}
				break;
				
			case '6':
				
				if(a[x][y+1]==' ')
				{
					a[x][y+1]='I';
					a[x][y]='0';
					y++;
				}
				else if(a[x][y+1]=='0')
				{
					cout<<"\nI CAN'T MOVE BACK";
					goto enter;
				}
				else
				{
					cout<<"\nTHERE ISA WALL!!! DON'T GUIDE ME WRONG :\\ "<<endl;
					goto enter;
				}
				break;
				
			case '0':
				
				answer();
				gameOver=true;
				break;
				
			default:
				
				cout<<"\n\nINVALID MOVE PLEASE ENTER A VALID MOVE..."<<endl;
				goto enter;
				break;
				
			
		}
		
		if(a[x][y-1]!=' ' && a[x][y+1]!=' ' && a[x+1][y]!=' ')
		{
			gameOver=true;
		}
}

int main()
{
	srand(time(NULL));
	
	cout<<"Hello! CAN YOU PLEASE GET ME TO MY HOME?\n\nI'M SARWESH, I LOST MY WAY.\nSINCE, I WAS A SMALL BOY I FORGOT MY WAY TO HOME :(  \nPLEASE GET ME TO MY HOME...";
	
	cout<<"\n\nNOTE:\nI CAN ONLY ABLE MOVE IN EMPTY SPACES.\nI CAN'T MOVE BACKWARD OR UPWARD.\n\nIN MAZE \n\"I\"  \t\tWILL REPRESENTS ME.\n\"H\"   \t\tWILL REPRESENTS MY HOME.\n\"-\"  &  \"|\"  \tWILL REPRESENT THE WALLS.";
	
	cout<<"\n\nKEY MAP:\n 2 --> TO MOVE DOWN\n 4 --> TO MOVE LEFT\n 6 --> TO MOVE RIGHT\n 0 --> TO SEE THE SOLUTION"<<endl;
	
	initialize();
	
	cout<<"\n\nPress \"ENTER\" to continue...";
	cin.get();
	
	
	
	display();
	
	while(!gameOver)
	{
		game();
	}
	
	if(win)
	{
		display();
		cout<<"\n\nTHANK YOU VERY MUCH FOR GUIDE ME TO MY HOME !!!"<<endl;
	}
	else
	{
		display();
		cout<<"\n\n THANKS FOR YOUR TRY!!!";
	}
	
	
	
}
