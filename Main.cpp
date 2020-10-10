#include "Grid.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
  Grid* gMain;
  Game* game;
  int userInput;
  int genCount =0;

  cout<<"If you would like to insert your own file, enter 1. If you would like a random assignment, enter 2."<<endl;
  cin>>userInput;
  while(cin.fail()){
    cout<<"Error: Enter 1 for input or Enter 2 for a random assignment."<<endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin>>userInput;
  }

//User chooses what mode they want to play (classic, Doughnut or mirror)
  int userMode = 0;
  cout<<"Choose your game mode.\n Press 1 for Classic mode.\n Press 2 for Doughnut mode.\n Press 3 for Mirror mode." <<endl;
  cin>>userMode;
  while(cin.fail()){
    cout<<"Error: Press 1 for Classic Mode, 2 for Doughnut mode, or 3 for Mirror mode.";
    cin.clear();
    cin.ignore(256, '\n');
    cin>>userMode;
  }
  //generation generator 
  while(genCount < 10){
    game = new Game(gMain,userMode);
    gMain = new Grid(userInput);
    gMain->printGrid();
    cout<<"Generation Count: "<<genCount<<endl;
    gMain->printGrid();
    genCount++;
  }
}
