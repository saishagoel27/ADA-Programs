#include <iostream>
#include <iomanip>
using namespace std;
int main() 
{
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;
    int m = X.length(), n = Y.length();
    int L[m+1][n+1];    // DP matrix for lengths
    char dir[m+1][n+1]; // direction matrix: 'd' = diagonal, 'u' = up, 'l' = left
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                L[i][j] = 0;
                dir[i][j] = '0';
            } 
            else if (X[i-1] == Y[j-1]) 
            {
                L[i][j] = L[i-1][j-1] + 1;
                dir[i][j] = 'd';
            } 
            else if (L[i-1][j] >= L[i][j-1]) 
            {
                L[i][j] = L[i-1][j];
                dir[i][j] = 'u';
            } 
            else 
            {
                L[i][j] = L[i][j-1];
                dir[i][j] = 'l';
            }
        }
    }
    cout << "\nArrows Legend: '\\' = diagonal (match), '^' = up, '<' = left\n";
    // Print DP matrix
    cout << "\n    ";
    for (int j = 0; j < n; j++) 
        cout << "  " << Y[j] << " ";
    cout << endl;
    for (int i = 0; i <= m; i++) {
        if (i == 0) cout << "  "; 
        else cout << X[i-1] << " ";
        for (int j = 0; j <= n; j++) {
            cout << setw(3) << L[i][j];
            if (dir[i][j] == 'd') cout << "\\ ";
            else if (dir[i][j] == 'u') cout << "^ ";
            else if (dir[i][j] == 'l') cout << "< ";
            else cout << "  ";}
        cout << endl;
    }
    // Construct LCS 
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (dir[i][j] == 'd') 
        {
            lcs = X[i-1] + lcs;
            i--; j--;
        } else if (dir[i][j] == 'u') i--;
        else j--;
    }
    cout << "\nLongest Common Subsequence: " << lcs << endl;
    return 0;
}
