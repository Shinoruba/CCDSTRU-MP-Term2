/*
	CCDSTRU MP Term 2 2022-2023
	Homssi, Yazan M.
	S13
*/

/* 
	CCDSTRU difficult </33
*/

// --------------------------------------------------------

// Preprocessor Directive
#include <stdio.h>

// void functions
void printSquare(int square[][100], int n);
int isMagicSquare(int square[][100], int n);

int main() 
{
    int n = 3; // 3x3 board size

    int square[100][100]; // 2D integer array representing the magic square.
    int currentPlayer = 1; // Current Player in control
    int movesLeft = n * n; // Number of moves left for the players to make.
    
    // Initialize the square with all zeros
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            square[i][j] = 0;
        }
    }
    
    while (movesLeft > 0) // loop until all cells are filled
	{
        int row, col, num;
        printf("Player %d, enter your move (row, column, number): ", currentPlayer);
        scanf("%d %d %d", &row, &col, &num); // player inputs their move

        if (row < 0 || row >= n || col < 0 || col >= n || square[row][col] != 0) 
		{
            printf("Invalid move, try again.\n");
        } else {
            square[row][col] = num;
            movesLeft--;
            if (currentPlayer == 1) // change the current player
			{
                currentPlayer = 2;
            } else 
			{
                currentPlayer = 1;
            }
        }

        printf("Current state of the magic square:\n");
        printSquare(square, n); // print the current state of the square
    }
    
    if (isMagicSquare(square, n)) // check if the square is a magic square
	{
        printf("Congratulations, you have created a magic square!\n");
        printf("Player %d wins!\n", currentPlayer);
    } else 
	{
        printf("The square is not a magic square.\n");
    }

    return 0;
}


/*
takes in a 2D integer array square representing a magic square and its size n, 
and prints out the elements in the array to represent the magic square.
*/
void printSquare(int square[][100], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}


/*
takes in a 2D integer array square representing a magic square and its size n, 
and returns an integer value of 1 if the input square is a magic square, 
or 0 if it is not.
*/
int isMagicSquare(int square[][100], int n) 
{
    int sum = n * (n * n + 1) / 2;

    // Check rows
    for (int i = 0; i < n; i++) 
	{
        int rowSum = 0;
        for (int j = 0; j < n; j++) 
		{
            rowSum += square[i][j];
        }
        if (rowSum != sum) // if a row sum is not equal to the required sum, the square is not a magic square
		{
            return 0;
        }
    }

    // Check columns
    for (int j = 0; j < n; j++) 
	{
        int colSum = 0;
        for (int i = 0; i < n; i++) 
		{
            colSum += square[i][j];
        }
        if (colSum != sum) 
		{
            return 0;
        }
    }

    // Check diagonals
    int diag1Sum = 0;
    int diag2Sum = 0;
    for (int i = 0; i < n; i++) 
	{
        diag1Sum += square[i][i];
        diag2Sum += square[i][n - 1 - i];
    }
    if (diag1Sum != sum || diag2Sum != sum) 
	{
        return 0;
    }

    return 1;
}
