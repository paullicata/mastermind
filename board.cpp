#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "board.h"
#include "color.h"


using namespace std;


void Board::printBoard(int count)
{
  int i, j;
  int color;
  cout << "--------------------------" << endl;
  for(i = 0; i < CODE_LENGTH; i++){
    color = guesses[count].pattern[i];
    switch(color){
      case 'b':
        cout << Color::FG_BLUE << "B" << "   ";
        break;
      case 'w':
        cout << Color::FG_WHITE << "W" << "   ";
        break;
      case 'r':
        cout << Color::FG_RED<< "R" << "   ";
        break;
      case 'g':
        cout << Color::FG_GREEN << "G" << "   ";
        break;
      case 'p':
        cout << Color::FG_MAGENTA << "P" << "   ";
        break;
      case 'y':
        cout << Color::FG_YELLOW << "Y" << "   ";
      break;
      default:
        cout << Color::FG_DEFAULT << endl << "Color number " << i + 1 << " is not valid." << endl;
        //return -1;
    }
  }
  cout << Color::FG_DEFAULT;
  int k, l;
  for(k = 0; k < guesses[count].whitePegs; k++){
    cout << "W";
  }
  for(l = 0; l < guesses[count].blackPegs; l++){
    cout << "B";
  }
  cout << endl << "--------------------------" << endl;
}
