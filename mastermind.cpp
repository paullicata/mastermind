/* -------------------------------------------------------------------------
 * This program is a basic interpretation of the popular board game 'Mastermind'.
 * It is single player, with the secret code being generated randomly at the start.

 * Name              : mastermind.cpp
 * Authors           : Paul Licata
 * Language          : C++
 * Latest Revision   : 5/12/2020
 * -------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <ctime>


#include "board.h"

#define BOARD_LENGTH 12

using namespace std;

Code secretCode;
Board board;
int guessCount;

void printIntro();
void initialize();
void runGame();

int main()
{
  srand(time(NULL));
  char input;
  printIntro();
  cin >> input;
  if(input == 'y'){
    cout << "Generating code... " << endl;
    initialize();
    runGame();
  }

  secretCode.printSecret();
  return 0;
}


void printIntro()
{
  cout << "Welcome to Mastermind!" << endl
          << "Rules: You have 12 guesses to pick the correct code. To guess, enter 4 colors consecutively." << endl
          << "Key:\n\tBlue: 'b' White: 'w' Red: 'r' Green: 'g' Purple: 'p' Yellow: 'y'" << endl
          << "\nPress 'y' to start: ";
}


void initialize()
{
  srand(time(NULL));
  secretCode.generateSecretCode();

  guessCount = 0;
}

int processGuess(string guess)
{
  int i;
  for(i = 0; i < CODE_LENGTH; i++){
    board.guesses[guessCount].pattern[i] = guess[i];
  }

  secretCode.compareCodes(&board.guesses[guessCount]);

  if(board.guesses[guessCount].blackPegs == 4){
    return 1;
  }

  return 0;


}
void runGame(){
  string guess;
  int win;

  while(guessCount < GUESS_LIMIT){
    cout << "Guess #" << guessCount + 1 << " > ";
    cin >> guess;
    win = processGuess(guess);
    board.printBoard(guessCount);
    if(win == 1){
      cout << "YOU GUESSED THE CORRECT CODE! CONGRATULATIONS!" << endl;
      return;
    }
    guessCount++;
  }
}
