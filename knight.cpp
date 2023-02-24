#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int board_size = 5;
int me = 1;

bool completed_board(int board[][5], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == 0) {
        return false; //if there is a 0, the board is not complete
      }
    }
  }
  return true;
}

//can we replace the 5 with a var?
void print_board(int board[][5], int size){
  std::cout << "[0;0H\n";

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << board[i][j] << "  ";
    }
    std::cout << "\n";
  }
}

void solve(int board[][5], int size, int row, int col,bool &solved) {
  if (me == board_size*board_size+1) {
    solved = true;
    return;
  }

  if (row < 0 || row > size || col < 0 || col > size) {
    return;
  }

  if (board[row][col] == 0) {
    board[row][col] = me;
    me++;
    usleep(130000);
    print_board(board,size);
  }

  if (!solved) solve(board,size,row+1,col+2, solved);
  if (!solved) solve(board,size,row+2,col+1, solved);
  if (!solved) solve(board,size,row-1,col+2, solved);
  if (!solved) solve(board,size,row-2,col+1, solved);
  if (!solved) solve(board,size,row-2,col-1, solved);
  if (!solved) solve(board,size,row-1,col-2, solved);
  if (!solved) solve(board,size,row+1,col-2, solved);
  if (!solved) solve(board,size,row+2,col-1, solved);

  //if (!solved)  board[row][col] = visited;
}

int main()
{
  int board[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = 0;
    }
  }
  int lines = 5;
  bool solved = false;

  print_board(board, lines);
  solve(board,lines,0,0,solved);
  return 0;
}
