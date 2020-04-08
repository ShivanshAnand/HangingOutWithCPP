/*traditional tic-tac-toe game
 * with ASCII art
 * made by Shivansh Anand
 */

#include <iostream>
#include <cmath>
using namespace std;

char board[3][3];
int hplmx; // human player last move x
int hplmy; // human player last move y
int choice;
int won = 0;
int con = 1;

void initBoard(void);
void displayBoard(int);
void getPlayer1Move(void);
void getPlayer2Move(void);
void getCompMove(void);
int avgBrain(void);
void printCenteredMenu(char[], int, int);
void delay(int);
void showWinScreen(int);
bool calcWin(int);
bool matchDraw(void);
void menuScreen(void);


void delay(int length)
{
	double step = 0.04;
	double i;
	for (i = 0; i < length; i += step);
}

void printCenteredMenu(char msg[], int baseLength, int t)
{
	if (t == 1)
		cout << "\t";

	int n = (int)((baseLength - strlen(msg)) / 2);
	int i;

	for (i = 0; i < n; i++)
		cout << " ";

	cout << msg << "\n";
}

void menuScreen()
{
	char msgs[][100] = {
		"Yet Another Tic Tac Toe Game",
		"made by Shivansh Anand",
		"1. Human VS. Human",
		"2. Human VS. Computer",
		"3. Exit"
	};
	char mainLogo[][100] = {
		"***  ***   ***     ********     ********     ********",
		" **  **   ** **   **********   **********   **********",
		"  ****   *******      **           **           **",
		"  **    **     **     **           **           **",
		" **    **       **    **           **           **"
	};

	int len = strlen(mainLogo[4]);
	int i;

	system("cls");
	for (i = 0; i < 5; i++)
	{
		cout << "\t" << mainLogo[i] << "\n";
		delay(1250000);
	}

	int spLen = (int)((len - strlen(msgs[0])) / 2);

	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 2)
			cout << "\n";
		printCenteredMenu(msgs[i], len, 1);
		delay(1000000);
	}

	cin >> choice;
	if (choice == 3)
	{
		exit(0);
	}
	else if (choice == 1 || choice == 2)
	{
		initBoard();
		displayBoard(2);
	}
	else
	{
		cout << "Invalid choice";
		exit(0);
	}
}

void initBoard()
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = '0' + (i * 3 + j + 1);
}

void displayBoard(int playerWhichMovedLast)
{
	system("CLS");
	cout << "Enter the cell-number to input your character (-1 to quit) \n\n";
	int i, j;
	for (i = 0; i < 3; i++)
	{	
		cout << '\t';
		for (j = 0; j < 3; j++)
		{
			cout << board[i][j];
			if (j != 2)
				cout << "|";
		}
		cout << "\n\n";
		if (i != 2)
			cout << "\t-----\n";
	}

	if (calcWin(playerWhichMovedLast) && won == 0) {
		won = 1;
		displayBoard(playerWhichMovedLast);
	}


	if (won)
	{
		if (choice == 1)
		{
			showWinScreen(playerWhichMovedLast);
		}
		else
		{
			if (playerWhichMovedLast == 1)
			{
				showWinScreen(playerWhichMovedLast);
			}
			else
			{
				showWinScreen(3);
			}
		}
	}

	if (matchDraw())
	{
		showWinScreen(4);
	}


	if (playerWhichMovedLast == 1)
	{
		if (choice == 1)
		{
			getPlayer2Move();
		}
		else
		{
			getCompMove();
		}
	}
	else if(playerWhichMovedLast == 2)
	{
		getPlayer1Move();
	}
	else if (playerWhichMovedLast == 0)
	{
		cout << "Game Over !";
	}
}

bool matchDraw()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] < 58)
				return false;
		}
	}
	return true;
}

void getPlayer1Move() {
	cout << "Player 1, make your move : ";
	int m;
	cin >> m;
	if (m < 1 || m > 9)
		exit(0);
	else {
		if (m < 4)
		{
			board[0][--m] = 'x';
			hplmx = 0;
			hplmy = m;
		}
		else if (m < 7)
		{
			board[1][--m - 3] = 'x';
			hplmx = 1;
			hplmy = m-3;
		}
		else
		{
			board[2][--m - 6] = 'x';
			hplmx = 2;
			hplmy = m - 6;
		}
		
	}

	displayBoard(1);
}

void getPlayer2Move() {
	cout << "Player 2, make your move : ";
	int m;
	cin >> m;
	if (m < 1 || m > 9)
		exit(0);
	else {
		if (m < 4)
		{
			board[0][--m] = 'o';
		}
		else if (m < 7)
		{
			board[1][--m - 3] = 'o';
		}
		else
		{
			board[2][--m - 6] = 'o';
		}
	}
	displayBoard(2);
}

void getCompMove()
{
	avgBrain();
	displayBoard(2);
}


int avgBrain()
{
	int i, j;
	int count = 0;
	for (i = 0; i < 3; i++)
	{
		if (board[i][0] == 'x')
			count++;
		if (board[i][1] == 'x')
			count++;
		if (board[i][2] == 'x')
			count++;

		if (count == 2)
		{
			for (j = 0; j < 3; j++)
			{
				if (board[i][j] != 'x' && board[i][j] != 'o')
				{
					board[i][j] = 'o';
					return 5;
				}
			}
		}
		count = 0;
	}

	for (i = 0; i < 3; i++)
	{
		if (board[0][i] == 'x')
			count++;
		if (board[1][i] == 'x')
			count++;
		if (board[2][i] == 'x')
			count++;

		if (count == 2)
		{
			for (j = 0; j < 3; j++)
			{
				if (board[j][i] != 'x' && board[j][i] != 'o')
				{
					board[j][i] = 'o';
					return 5;
				}
			}
		}

		count = 0;
	}

	for (i = 0; i < 3; i++)
	{
		if (board[i][i] == 'x')
			count++;
		if (count == 2)
		{
			for (j = 0; j < 3; j++)
			{
				if (board[j][j] != 'x' && board[j][j] != 'o')
				{
					board[j][j] = 'o';
					return 5;
				}
			}
		}
	}
	count = 0;

	for (i = 0; i < 3; i++)
	{
		if (board[i][2-i] == 'x')
			count++;
		if (count == 2)
		{
			for (j = 0; j < 3; j++)
			{
				if (board[j][j] != 'x' && board[j][j] != 'o')
				{
					board[j][j] = 'o';
					return 5;
				}
			}
		}
	}
	count = 0;

	for (i = 0; i < 3; i++)
	{
		if (board[i][hplmy] != 'x' && board[i][hplmy] != 'o')
		{
			board[i][hplmy] = 'o';
			return 4;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if (board[hplmx][i] != 'x' && board[hplmx][i] != 'o')
		{
			board[hplmx][i] = 'o';
			return 4;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] != 'x' && board[i][j] != 'o')
			{
				board[i][j] = 'o';
				return 3;
			}
		}
	}

	return -1;
}

bool calcWin(int player)
{
	player--;
	char arr[] = { 'x', 'o' };
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && arr[player] == board[i][2])
			return true;

	for (int i = 0; i < 3; i++)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && arr[player] == board[2][i])
			return true;

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && arr[player] == board[2][2])
		return true;

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && arr[player] == board[2][0])
		return true;

	return false;
}

void showWinScreen(int whichPlayerWon)
{
	char msgs[][50] = {
		"Player 1 won !!!",
		"Player 2 won !!!",
		"Computer won !!!",
		"It's a draw ;|"
	};
	
	--whichPlayerWon;

	int i;

	cout << "\n";
	for (i = 0; i < strlen(msgs[whichPlayerWon]); i++)
	{
		cout << msgs[whichPlayerWon][i];
		delay(1000000);
	}
	cout << "\n1. Restart \n3. Quit";
	int c;
	cin >> c;
	if (c == 1)
	{
		won = 0;
		menuScreen();
	}
	else
	{
		exit(0);
	}

}

int main()

{
	menuScreen();
	return 0;
}
