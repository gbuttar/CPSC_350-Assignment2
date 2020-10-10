#include <iostream>
#ifndef GRID_H
#define GRID_H
using namespace std;

class Grid{
public:
  Grid();
  Grid(int userInput); //user choice to pick how to input file
  Grid(int r, int c); //empty board 
  char** returnGrid(); //returns the grid
  void printGrid(); //prints the grid
  int checkGrid(int checkRow, int checkColumn, int checkMode); //checkGrid-basically rules for each mode
//variables
  int numRows;
  int numColumns;
  float initialPop;
  char occupiedCell;
  char emptyCell;
  string strRows;
  string strColumns;
  string userFile;
  string tempLine;
  string stringFile;
  string randRows;
  string randColumns;
  float randDensity;
  int checkRow;
  int checkColumn;
  int checkMode;
  char** gGrid;
};
#endif
