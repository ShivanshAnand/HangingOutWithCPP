/* Traditional Tic-Tac-Toe program
    --- Made by Shivansh Anand
*/
#include <iostream>
using namespace std;

char board[3][3];

void initBoard(void);
void displayBoard(void);
void getPlayer1Move(void);
void getPlayer2Move(void);
void getCompMove(void);
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
		getPlayer2Move();
	else
		getPlayer1Move();
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
		}
		else if (m < 7)
		{
			board[1][--m - 3] = 'x';
		}
		else
		{
			board[2][--m - 6] = 'x';
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
		cout << "Player " << whichPlayerWon << " won !!! ";
		for (double j = 0; j < 1000000; j += 0.01);
		system("cls");
		for (double j = 0; j < 1000000; j += 0.01);
	}
	exit(0);
}

int main()
{
	initBoard();
	displayBoard(2);
	return 0;
}
