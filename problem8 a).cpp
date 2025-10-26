#include <iostream>
#include <iomanip>
using namespace std;
string board[20][20];  // board
int pos[20];           // pos[row] = col where queen is placed
// check if placing a queen is safe
bool isSafe(int row, int col, int n) 
{
    for (int i = 0; i < row; i++) 
    {
        if (pos[i] == col || abs(pos[i] - col) == abs(i - row))
            return false;
    }
    return true;
}
void printBoard(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
            cout << setw(3) << board[i][j] << " ";
        cout << endl;
    }
    cout << "Positions: ";
    for (int i = 0; i < n; i++) 
    {
        cout << "Q" << i+1 << "->(" << i+1 << "," << pos[i]+1 << ") ";
    }
    cout << endl;
    cout << "-----------------" << endl;
}
void solveNQueens(int row, int n) 
{
    if (row == n) 
    {
        printBoard(n);
        return;
    }
    for (int col = 0; col < n; col++) 
    {
        if (isSafe(row, col, n)) 
        {
            pos[row] = col; 
            board[row][col] = "Q" + to_string(row+1);
            solveNQueens(row+1, n);
            board[row][col] = "."; // backtrack
        }
    }
}
int main() 
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = ".";
    cout << "Possible Solutions:" << endl;
    solveNQueens(0, n);
    return 0;
}
