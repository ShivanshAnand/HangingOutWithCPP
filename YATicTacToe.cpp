/*traditional tic-tac-toe game
 * with ASCII art
 * made by Shivansh Anand
 */

#include <iostream>
using namespace std;

char board[3][3];
int hplmx; // human player last move x
int hplmy; // human player last move y

void initBoard(void);
void displayBoard(int);
void getPlayer1Move(void);
void getPlayer2Move(void);
int getCompMove(void);
void showWinScreen(int);
bool calcWin(int);

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

	if (calcWin(playerWhichMovedLast)) {
		showWinScreen(playerWhichMovedLast);
	}

	if (playerWhichMovedLast == 1)
	{
		getCompMove();
		displayBoard(2);
	}
	else
	{
		getPlayer1Move();
	}
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

bool calcWin(int player)
{
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return true;

	for (int i = 0; i < 3; i++)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return true;

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;

	if (board[0][1] == board[1][1] && board[1][1] == board[2][0])
		return true;

	return false;
}

void showWinScreen(int whichPlayerWon)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\nPlayer " << whichPlayerWon << " won !!! ";
		for (double j = 0; j < 1000000; j += 0.01);
		//system("cls");
		for (double j = 0; j < 1000000; j += 0.01);
	}
	exit(0);
}

void menuScreen()
{
	cout << "\t***  ***   ***     ********     ********     ********  \n";
	cout << "\t **  **   ** **   **********   **********   ********** \n";
	cout << "\t  ****   *******      **           **           **     \n";
	cout << "\t  **    **     **     **           **           **     \n";
	cout << "\t **    **       **    **           **           **     \n";

	cout << "\t\tYet Another Tic Tac Toe Game\n\t\tmade by Shivansh Anand\n\n\t\t1. Human VS. Human\n\t\t2. Human VS. Computer\n\t\t3. Any other integer to exit";
	int choice;
	cin >> choice;
	if (choice > 0)
	{
		initBoard();
		displayBoard(2);
	}
	else
	{
		exit(0);
	}
}


int getCompMove()
{
	int i;
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
			for (int j = 0; j < 3; j++)
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
			for (int j = 0; j < 3; j++)
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


	for (int i = 0; i < 3; i++)
	{
		if (board[i][i] == 'x')
			count++;
		if (count == 2)
		{
			for (i = 0; i < 3; i++)
			{
				if (board[i][i] != 'x' && board[i][i] != 'o')
				{
					board[i][i] = 'o';
					return 5;
				}
			}
		}
	}

	count = 0;

	for (int i = 2; i >=0; i--)
	{
		if (board[i][i] == 'x')
			count++;
		if (count == 2)
		{
			for (i = 0; i < 3; i++)
			{
				if (board[i][i] != 'x' && board[i][i] != 'o')
				{
					board[i][i] = 'o';
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
		for (int j = 0; j < 3; j++)
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

int main()
{
	//menuScreen();
	initBoard();
	displayBoard(2);
	return 0;
}
