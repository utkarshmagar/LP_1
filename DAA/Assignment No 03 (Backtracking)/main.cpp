#include <iostream>
using namespace std;

class nQueenSolution
{
private:
    void printBoard(int, int[]);
    bool isSafe(int, int, int[]);

public:
    bool n_Queen(int, int, int[]);
};

// function to print current queen position on board
void nQueenSolution::printBoard(int n, int col[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if column number matches with j, print current queen number a row number,else print 0
            if (col[i] == j)
                cout << i + 1 << " ";

            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

// function to check if Queen can be placed at current position safely
bool nQueenSolution::isSafe(int queen, int c, int col[])
{
    // iterate through column array
    for (int j = 0; j < queen; j++)
    {
        // if queen is present in same column, or diagonal, return flase
        if (col[j] == c || abs(col[j] - c) == abs(j - queen))
        {
            return false;
        }
    }
    // return true if current position is safe
    return true;
}

// function to place n Queens
// with parameters queen number, total no of queens &column array
bool nQueenSolution::n_Queen(int queen, int n, int col[])
{
    // f to check whether the queen can be placed in column
    int f = 0;
    // loop for all columns
    for (int i = 0; i < n; i++)
    {
        // check if queen can be placed in current column
        if (isSafe(queen, i, col))
        {
            // if true, assign the position in col array
            col[queen] = i;

            // print current state
            cout << "\nPlacing Queen" << queen + 1 << "\n";
            printBoard(n, col);

            // if all queens are placed. return true and end
            if (queen == n - 1)
                return true;

            // check if next queen can be placed in next row
            if (n_Queen(queen + 1, n, col))
                return true;

            // Backtracking if placing queen doesn't give a solution(all queens are not placed)
            // reset position
            col[queen] = -1;
            cout << "Backtracking Queen" << queen + 1 << endl;
            // print state
            printBoard(n, col);

            f = 1;
        }
    }
    // if cureent Queen doesn't get safe position
    if (!f)
        cout << "\nUnable to place Queen" << queen + 1 << "\n\n";

    return false;
}

int main()
{
    nQueenSolution sol;
    int n;
    bool t = true;
    // take input for chessboard size n x n
    cout << "Enter size of chessboard:";
    cin >> n;

    // check if chessboard size is greater than 3
    while (t)
    {
        t = false;
        if (n <= 3)
        {
            t = true;
            cout << "No of Queens must be greater than 3" << endl;
            cout << "Re-Enter no of Queens:";
            cin >> n;
        }
    }

    // col array to store col no of queen same as row number
    int col[n];
    for (int i = 0; i < n; i++)
        col[i] = -1;
    // call for n_Queen function to place all num Queens
    sol.n_Queen(0, n, col);

    return 0;
}

/* OUTPUT

Enter size of chessboard:4

Placing Queen1
1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Placing Queen2
1 0 0 0
0 0 2 0
0 0 0 0
0 0 0 0

Unable to place Queen3

Backtracking Queen2
1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Placing Queen2
1 0 0 0
0 0 0 2
0 0 0 0
0 0 0 0

Placing Queen3
1 0 0 0
0 0 0 2
0 3 0 0
0 0 0 0

Unable to place Queen4

Backtracking Queen3
1 0 0 0
0 0 0 2
0 0 0 0
0 0 0 0
Backtracking Queen2
1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Backtracking Queen1
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Placing Queen1
0 1 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Placing Queen2
0 1 0 0
0 0 0 2
0 0 0 0
0 0 0 0

Placing Queen3
0 1 0 0
0 0 0 2
3 0 0 0
0 0 0 0

Placing Queen4
0 1 0 0
0 0 0 2
3 0 0 0
0 0 4 0

*/