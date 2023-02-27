#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

const int board_size = 5;

//checks if the next spot is in bounds AND if it is empty
bool in_bounds(int board[][board_size], int new_row, int new_col) {
  if (new_row >= 0 && new_row < board_size && new_col >= 0 && new_col < board_size) {
      if (board[new_row][new_col] == 0) {
        return true;
      }
  }
  return false;
}

//can we replace the 5 with a var?
void print_board(int board[][board_size], int size){
  std::cout << "[0;0H\n";

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] < 10) {
        std::cout << board[i][j] << "  ";
      } else {
        std::cout << board[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
}

void solve(int board[][board_size], int size, int counter, int row, int col,bool &solved) {
  if (counter == board_size*board_size+1) {
    solved = true;
    return;
  }

  if (in_bounds(board, row, col)) {
    board[row][col] = counter;
    counter++;
    usleep(35000);
    print_board(board,size);
  } else {
    return;
  }

  if (!solved) solve(board,size,counter,row-2,col+1, solved);
  if (!solved) solve(board,size,counter,row-1,col+2, solved);
  if (!solved) solve(board,size,counter,row+1,col+2, solved);
  if (!solved) solve(board,size,counter,row+2,col+1, solved);
  if (!solved) solve(board,size,counter,row+2,col-1, solved);
  if (!solved) solve(board,size,counter,row+1,col-2, solved);
  if (!solved) solve(board,size,counter,row-1,col-2, solved);
  if (!solved) solve(board,size,counter,row-2,col-1, solved);

  if (!solved) board[row][col] = 0;
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
  solve(board,lines,1,0,0,solved);
  return 0;
}
