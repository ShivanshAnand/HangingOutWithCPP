/*Sudoku Solver using Backtracking Algorithm ( recursion )
  N = size of sudoku grid
  EMPTY_NUM = number to denote an empty space in the grid
  r = row in the grid
  c = column in the grid
  i, j = loop variables
  
  --by Shivansh Anand, done with help of youtuer Tim ( Tech with Tim ).
  His was in python, I followed it, understood it and wrote it in CPP*/


#include <iostream>
using namespace std;

const int N = 9;
const int EMPTY_NUM = 0;

int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                  {0, 5, 0, 0, 9, 0, 6, 0, 0},
                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                  {0, 0, 5, 2, 0, 6, 3, 0, 0} };

bool isMoveValid(int num, int r, int c)
{
    int i, j;
    for (i = 0; i < N; i++)
        if (grid[r][i] == num && i != c)
            return false;
    
    for (i = 0; i < N; i++)
        if (grid[i][c] == num && i != r)
            return false;

    int boxStartingRowIdx = ((int)(r / 3)) * 3;
    int boxStartingColIdx = ((int)(c / 3)) * 3;
    for (i = boxStartingRowIdx; i < boxStartingRowIdx + 3; i++)
    {
        for (j = boxStartingColIdx; j < boxStartingColIdx + 3; j++)
        {
            if (grid[i][j] == num && (i != r || j != c))
                return true;
        }
    }
    return true;
}

int* getEmptyLocation()
{
    int arr[2];
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == EMPTY_NUM)
            {
                arr[0] = i;
                arr[1] = j;
                return &arr[0];
            }
        }
    }
    return NULL;
}

void displayGrid()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "- - - - - - - - - - - -\n";
        }

        for (j = 0; j < N; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }

            if (grid[i][j] == 0)
            {
                cout << "_ ";
            }
            else
            {
                cout << grid[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

bool solve()
{
    int* location = getEmptyLocation();
    int i, r, c;
    if (location == NULL)
    {
        return true;
    }

    r = *location;
    c = *(location + 1);
    for (i = 1; i <= 10; i++)
    {
        if (isMoveValid(i, r, c))
        {
            grid[r][c] = i;

            if (solve())
                return true;

            grid[r][c] = EMPTY_NUM;
        }
    }

    return false;
}

int main()
{
    solve();
    cout << "\n";
    displayGrid();
    return 0;
}
