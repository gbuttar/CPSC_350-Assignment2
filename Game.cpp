//rules are one method, doing each calculation
#include <iostream>
#include "Game.h"
#include "Grid.h"

using namespace std;

Game::Game(Grid* gMain, int userMode){
  //current generation grid, make grid copy into next generation
 gridTwo = gMain->returnGrid();
 gridCopy = new Grid(gMain->numRows,gMain->numColumns);
 //classic mode
    for(int i = 0; i < gMain->numRows; ++i){
      for(int j = 0; j < gMain->numColumns; ++j){

        countNeighbor += gMain->checkGrid(i-1,j-1,userMode);
        countNeighbor += gMain->checkGrid(i-1,j,userMode);
        countNeighbor += gMain->checkGrid(i-1,j+1,userMode);
        countNeighbor += gMain->checkGrid(i,j-1,userMode);
        countNeighbor += gMain->checkGrid(i,j+1,userMode);
        countNeighbor += gMain->checkGrid(i+1,j-1,userMode);
        countNeighbor += gMain->checkGrid(i+1,j,userMode);
        countNeighbor += gMain->checkGrid(i+1,j+1,userMode);

        if(countNeighbor < 2){
          gridCopy->gGrid[i][j] = '-';
        }
        else if(countNeighbor == 3){
          gridCopy->gGrid[i][j] = 'X';
        }
        else if(countNeighbor >= 4){
          gridCopy->gGrid[i][j] = '-';
        }
        else{
          if(gridTwo[i][j] = 'X')
            gridCopy->gGrid[i][j] = 'X';
          else
            gridCopy->gGrid[i][j] = '-';
        }
         countNeighbor =0;
      }
    }
  for(int i = 0; i < gMain->numRows; ++i){
    for(int j =0; j < gMain->numColumns; ++j){
      gridTwo[i][j] = gridCopy->gGrid[i][j];
        }
    }
}
