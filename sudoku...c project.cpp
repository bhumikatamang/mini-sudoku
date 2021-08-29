#include <stdio.h>
#define SIZE 4

void readBoard(int [][SIZE]);
void printBoard(int [][SIZE]);
void solve(int [][SIZE]);
int anotherRound(int [][SIZE]);
void checkBox(int [][SIZE], int, int, int, int);

int main(void) 
{
 int board[SIZE][SIZE];

 printf("-------MINI SUDOKU SOLVER-------");
 
 printf("\n\nEnter 4*4 sudoku puzzle (0 for blank cell):\n");
 readBoard(board);

 solve(board); 

 printf("Sudoku puzzle solved:\n");
 printBoard(board);

 return 0;
}

// To read a 4*4 integer array 
void readBoard(int board[][SIZE]) 
{
 int r, c;
 for (r = 0; r < SIZE; r++) 
 {
  for(c = 0; c < SIZE; c++)
   scanf("%d", &board[r][c]);
 }
}

// To print the 4*4 Sudoku board.
void printBoard(int board[][SIZE]) 
{
 int r, c;

 for (r = 0; r < SIZE; r++) 
 {
  for (c = 0; c < SIZE; c++)
  printf("%d ", board[r][c]);
  printf("\n");
 }
}

void solve(int board[][SIZE]) 
{
 int blankCellFound; // indicate whether there is still some blank cell

 do 
 {
  blankCellFound = anotherRound(board);
 } 
 while (blankCellFound);
}

int anotherRound(int board[][SIZE]) 
{
 int r, c,sum,  // Sum of elements in a row or column
  countZero;  // Number of zeroes in a row or column

 // Check every row
 for (r = 0; r < SIZE; r++) 
 {
  sum = 0;
  countZero = 0;

  for (c = 0; c < SIZE; c++) 
  {
   if (board[r][c] == 0)
    countZero++;
   else
    sum += board[r][c];
  }
  if (countZero == 1) 
  {   // A single zero is present
   for (c = 0; c < SIZE; c++) 
   { // To find the position of the single zero
    if (board[r][c] == 0) 
	{
     board[r][c] = 10 - sum;  // Replace the single zero with the obvious value
     break;
    }
   }
  }
 }
 // Check every column
 for (c = 0; c < SIZE; c++) 
 {
  sum = 0;
  countZero = 0;

  for (r = 0; r < SIZE; r++) 
  {
   if (board[r][c] == 0)
    countZero++;
   else
    sum += board[r][c];
  }
  if (countZero == 1) 
  {   // A single zero is present
   for (r = 0; r < SIZE; r++) 
   { // To find the position of the single zero
    if (board[r][c] == 0) 
	{
     board[r][c] = 10 - sum;  // Replace the single zero with the obvious value
     break;
    }
   }
  }
 }
 // Check every box
 checkBox(board, 0, 2, 0, 2);
 checkBox(board, 0, 2, 2, 4);
 checkBox(board, 2, 4, 0, 2);
 checkBox(board, 2, 4, 2, 4);

 // Check if there are any blank cells
 for (r = 0; r < SIZE; r++) 
 {
  for (c = 0; c < SIZE; c++) 
  {
   if (board[r][c] == 0)   // Blank cell found
    return 1;
  }
 }
 return 0;  // No blank cell
}
// This function checks a 2*2 box if there is a single zero.
// If so, it replaces the zero with the obvious value.
// Precond: lrow <= urow, lcol <= ucol, 0 <= lrow, urow, lcol, ucol <= SIZE
void checkBox(int board [][SIZE], int lrow, int urow, int lcol, int ucol) 
{
 int r, c,
  sum = 0,  // Sum of elements in the 2*2 box
  countZero = 0;  // Number of zeroes in the 2*2 box

 for (r = lrow; r < urow; r++) 
 {  // lrow and urow are the lower and upper limits of the rows 
  for (c = lcol; c < ucol; c++) 
  { // lcol and ucol are the lower and upper limits of the columns
   if (board[r][c] == 0)
    countZero++;
   else
    sum += board[r][c];
  }
 }
 if (countZero == 1) 
 {   // A single zero is present
  for (r = lrow; r < urow; r++) 
  {
   for (c = lcol; c < ucol; c++) 
   { // To find the position of the single zero
    if (board[r][c] == 0) 
	{
     board[r][c] = 10 - sum;  // Replace the single zero with the obvious value
     break;
    }
   }
  }
 }
}



