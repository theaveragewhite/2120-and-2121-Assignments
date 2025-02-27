/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 11/18/2023
 * Lab Section: 007
 * Assignment Name: Lab 9
 */

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& placement, int row, int col)
{
    for (int prevRow = 0; prevRow < row; ++prevRow)
    {
        int prevCol = placement[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col))
        {
            return false;
        }
    }
    return true;
}

int nQueensHelper(int n, int row, vector<int>& placement)
{
    if (row == n)
    {
        //Reached the end of the board, a solution is found
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(placement, row, col))
        {
            placement[row] = col;
            count += nQueensHelper(n, row + 1, placement);
        }
    }

    return count;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions

    vector<int> placement(n, -1);
    return nQueensHelper(n, 0, placement);
}

/*int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}*/
