#include <iostream>
#define N 9
using namespace std;

bool isSafeVertical(int input[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (input[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeHorizontal(int input[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (input[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeGrid(int input[N][N], int row, int col, int num)
{
    int rowfactor = row - (row % 3);
    int colfactor = col - (col % 3);

    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if (input[rowfactor+a][colfactor+b] == num)
            {
                return false;
            }

        }
    }
    return true;
}

bool findspace(int input[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (input[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int input[N][N], int row, int col, int num)
{
    bool a = isSafeVertical(input, row, col, num);
    bool b = isSafeHorizontal(input, row, col, num);
    bool c = isSafeGrid(input, row, col, num);
    if (a && b && c)
    {
        return true;
    }
    return false;
}

bool solveSudoku(int input[N][N], int row, int col)
{

    if (!findspace(input, row, col))
    {
        return true;
    }

    // now row and col now contain the space to be filled

    for (int i = 1; i <= N; i++)
    {
        if (isSafe(input, row, col, i))
        {
            input[row][col] = i;

            if (solveSudoku(input, row, col))
            {
                return true;
            }

            input[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int input[N][N];
    cout<<" Enter empty 9x9 Sudoku grid: \n(Enter 0 inplace of empty positions)\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input[i][j];
        }
    }
    int row = 0, col = 0;
    bool evenPossible=solveSudoku(input, row, col);
    if (evenPossible)
    {
        // cout << "true"<<endl;
        cout<<"Here's the solved Sudoku: \n";
        for (int i = 0; i < N; i++)
        {
            if(i==3 || i==6)
                cout<< "------ ------ -------"<<endl;
            for (int j = 0; j < N; j++)
            {
                if(j==3 || j==6) cout<< "| ";
                cout << input[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "PLEASE ENTER A VALID EMPTY SUDOKU!!!\n"<< endl;
    }
    
}
/*
INPUT:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
======================
CORRECT OUTPUT:
9 4 1 3 2 6 7 5 8 
6 3 7 1 5 8 2 4 9 
8 2 5 4 9 7 6 1 3 
2 6 8 7 1 4 3 9 5 
1 7 4 5 3 9 8 6 2 
3 5 9 6 8 2 4 7 1 
4 1 3 2 6 5 9 8 7 
5 9 6 8 7 3 1 2 4 
7 8 2 9 4 1 5 3 6 
*/