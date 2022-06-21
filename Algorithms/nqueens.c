#define
#include
N8
<stdbool.h>
#include
void printSolution(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (   1) printf(   ); else
        printf("| _ | ");
    } printf("\n");
  }
}
bool isSafe(int board[N][N], int row, int col) {
  int i, j;
// row on left side
  for (i = 0; i < col; i++) if (   [row][i])
      false;
//upper diagonal on left side
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) if (   [i][j])
      false;
//lower diagonal on left side
  for (i = row, j = col; j >= 0 && i < N; i++, j--) if (   [i][j])
      false; return true;
}
bool solveNQUtil(int board[N][N], int col) {
  if (col >= N) return true;
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      board[i][j] ==
      "| Q | "
      <stdio.h>
      board
      return
        board
        return

          board
          return

            if (
              (board, col + 1))
              solveNQUtil
              return
                true;
      board[i][col] = 0; // BACKTRACK }
    }
    return false;
  }
  bool solveNQ()
  {
    int board[N][N] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    };
    if ( printf(
           false;
  }
     (
       , 0) == false) {
       );
    solveNQUtil
    (board); true;
  }
  int main() {
    (); 0;
  }