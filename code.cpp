
#include <iostream>
#include <string>
#include <array>
#include <stdlib.h>
#include <ctime>

#include "code.h"

using namespace std;



void Code::generateSecretCode()
{
  int i;
  int num;

  isSecret = true;

  for(i = 0; i < CODE_LENGTH; i++){
    num = rand() % 6;

    switch(num){
      case 0:
        pattern[i] = 'b';
        break;
      case 1:
        pattern[i] = 'w';
        break;
      case 2:
        pattern[i] = 'r';
        break;
      case 3:
        pattern[i] = 'g';
        break;
      case 4:
        pattern[i] = 'p';
        break;
      case 5:
        pattern[i] = 'y';
        break;
    }

  }
}

void Code::printSecret()
{
  int i;
  cout << "Secret code ";
  for(i = 0; i < CODE_LENGTH; i++){
    cout << pattern[i] << "  ";
  }
  cout << endl;
}


void Code::compareCodes(Code *c)
{
  int i, sCurr, gCurr;
  int sBlue, sRed, sGreen, sPurple, sYellow, sWhite;
  int gBlue, gRed, gGreen, gPurple, gYellow, gWhite;

  sBlue = 0;
  sRed = 0;
  sGreen = 0;
  sPurple = 0;
  sYellow = 0;
  sWhite = 0;

  gBlue = 0;
  gRed = 0;
  gGreen = 0;
  gPurple = 0;
  gYellow = 0;
  gWhite = 0;

  for(i = 0; i < CODE_LENGTH; i++){
    if(pattern[i] == c->pattern[i]){
      c->blackPegs++;
    }
    sCurr = pattern[i];
    gCurr = c->pattern[i];
    switch(sCurr){
      case 'b':
        sBlue++;
        break;
      case 'r':
        sRed++;
        break;
      case 'g':
        sGreen++;
        break;
      case 'p':
        sPurple++;
        break;
      case 'y':
        sYellow++;
        break;
      case 'w':
        sWhite++;
        break;
    }
    switch(gCurr){
      case 'b':
        gBlue++;
        break;
      case 'r':
        gRed++;
        break;
      case 'g':
        gGreen++;
        break;
      case 'p':
        gPurple++;
        break;
      case 'y':
        gYellow++;
        break;
      case 'w':
        gWhite++;
        break;
    }
  }


  c->whitePegs = compareColors(sBlue, gBlue) + compareColors(sRed, gRed) + compareColors(sGreen, gGreen)
                + compareColors(sPurple, gPurple) + compareColors(sYellow, gYellow) + compareColors(sWhite, gWhite);


  c->whitePegs -= c->blackPegs;
}


int Code::compareColors(int secretColor, int guessColor)
{
  if(secretColor > guessColor){
    return guessColor;
  }
  else if(secretColor < guessColor){
    return secretColor;
  }
  else{
    return guessColor;
  }

}
