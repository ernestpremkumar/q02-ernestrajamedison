#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/

using namespace std;

void Piezas::toggleTurn()
{
  if(this->turn == X)
  {
    this->turn = O;
  }
  else if(this->turn == O)
  {
    this->turn = X;
  }
}


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  board.resize(BOARD_ROWS);
  for(int i=0; i<BOARD_ROWS; i++)
  {
    board[i].resize(BOARD_COLS);
    for(int j=0; j<BOARD_COLS;j++)
    {
      board[i][j] = Blank;
    }
  }
  this->turn = X;
}


/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  for(int i=0; i<BOARD_ROWS; i++)
  {
    for(int j=0; j<BOARD_COLS;j++)
    {
      board[i][j] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  if(column > 3 || column < 0)
  {
    toggleTurn();
    return Invalid;
  }
  for(int i=0; i<BOARD_ROWS; i++)
  {
    if(board[i][column] == Blank)
    {
      board[i][column] = turn;
      Piece temp = turn;
      toggleTurn();
      return temp;
    }
  }
  toggleTurn();
  return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(row > 2 || row < 0 || column > 3 || column < 0)
  {
    return Invalid;
  }
  else return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  bool board_full = true;
  for(int i=0; i<BOARD_ROWS; i++)
  {
    for(int j=0; j<BOARD_COLS;j++)
    {
      if(board[i][j] == Blank)
      {
        board_full = false;
      }
    }
  }
  if(board_full == false)
  {
    return Invalid;
  }

  int X_count = 0;
  int max_X = 0;
  int O_count = 0;
  int max_O = 0;

  for(int i=0; i<BOARD_ROWS; i++)
  {
    for(int j=0; j<BOARD_COLS;j++)
    {
      if(board[i][j] == X)
      {
        X_count++;
        if(X_count > max_X)
        {
          max_X = X_count;
        }
        O_count = 0;
      }
      else if(board[i][j] == O)
      {
        O_count++;
        if(O_count > max_O)
        {
          max_O = O_count;
        }
        X_count = 0;
      }
    }
  }
 
  O_count = 0;
  X_count = 0;
//  max_O = 0;
//  max_X = 0;

  for(int i=0; i<BOARD_COLS; i++)
  {
    for(int j=0; j<BOARD_ROWS;j++)
    {
      if(board[j][i] == X)
      {
        X_count++;
        if(X_count > max_X)
        {
          max_X = X_count;
        }
        O_count = 0;
      }
      else if(board[j][i] == O)
      {
        O_count++;
        if(O_count > max_O)
        {
          max_O = O_count;
        }
        X_count = 0;
      }
    }
  }

  if(max_X > max_O)
  {
    return X;
  }

  else if(max_O > max_X)
  {
    return O;
  }

  return Blank;
}
