#include "code.h"

#define GUESS_LIMIT 12

class Board
{
public:
  Code guesses[GUESS_LIMIT];

  void printBoard(int);
};
