#include "Grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Grid::Grid(){
   numRows = 8;
   numColumns= 8;
   initialPop = 0.5;
   occupiedCell = 'X';
   emptyCell = '-';
   gGrid = new char*[numRows];
//default grid
   for(int i = 0; i < numRows; ++i){
     gGrid[i] = new char[numColumns];
     for(int j = 0; j < numColumns; ++j){
       if (j%2 ==0){ // checks if its an even number
         gGrid[i][j] = emptyCell;
       }
       else{
        gGrid[i][j] = occupiedCell;
       }
     }
   }
}
//Empty board created for copying the board for future purposes
Grid::Grid(int r, int c){
  gGrid = new char*[r];
  for(int i = 0; i < r; ++i){
    gGrid[i] = new char[c];
    for(int j = 0; j < c; ++j){
      gGrid[i][j] = '-';
      }
    }
  }
  //classic mode boundaries check to make sure that the cells do not go beyond the size of grid
int Grid::checkGrid(int checkRow, int checkColumn, int checkMode){
    if(checkMode == 1){
      if(checkRow == -1 || checkColumn == -1 || checkRow >= numRows || checkColumn >= numColumns){
        return 0;
      }
      else if(gGrid[checkRow][checkColumn] == 'X'){
        return 1;
      }
      else if(gGrid[checkRow][checkColumn] == '-'){
        return 0;
      }
      else{
        exit(1);
      }
   }
   if(checkMode == 2){ //doughnut mode- check to make sure that it follows the rule for doughnut mode
     if(checkRow == numRows-1){
       checkRow = 0;
     }
     if(checkRow == -1){
       checkRow = numRows-1;
     }
     if(checkColumn == numColumns-1){
       checkColumn = 0;
     }
     if(checkColumn == -1){
       checkColumn = numColumns-1;
     }
     else if(gGrid[checkRow][checkColumn] == 'X'){
       return 1;
     }
     else{
       return 0;
     }
  }
  if(checkMode == 3){ //mirror mode- checks to make sure mirror mode rules are followed
      if(checkRow == numRows){
        checkRow--;
      }
       if(checkRow == -1){
        checkRow++;
      }
       if(checkColumn == numColumns){
        checkColumn--;
      }
       if(checkColumn == -1){
        checkColumn++;
      }
      else if(gGrid[checkRow][checkColumn] == 'X'){
        return 1;
      }
      else{
        return 0;
      }
    }
  }
Grid::Grid(int userInput){
  if(userInput == 1){ //User decided to enter their own file (option 1)
    cout<<"Enter file:"<<endl;
    cin >> userFile;

  ifstream inputFile; //commandLine file turns into inputFile
    inputFile.open(userFile,ios::in); // opens the inputted CommandLineFile
    if(inputFile.is_open()){
      cout<<"File was succesfully opened!"<<endl;
    }
    else{
      cout<<"Error: file did not open. Please try again."<<endl;
      exit(1);
    }
    int count;
    while(!inputFile.eof()){ //gets user inputted files
      if(count == 0){
        getline(inputFile, strRows);//this gets a blank string from input file
        getline(inputFile,strColumns);
        count++;
      }
      else{
        getline(inputFile,tempLine);
        stringFile.append(tempLine);
      } //stringFile is the appended file, where there is only one line of the inputted text
    }
    cout << strRows <<endl;
    cout << strColumns << endl;
    try {
      numRows = stoi(strRows); //string to int
      numColumns = stoi(strColumns);
    }
    catch(const std::invalid_argument e) {
      cout<<"Error."<<endl;
      exit(1);
    }
    gGrid = new char*[numRows];
    for(int i = 0; i < numRows; ++i){
      gGrid[i] = new char[numColumns];
      for(int j = 0; j < numColumns; ++j){
        gGrid[i][j] = '-';
      }
    }
    int columnCount = 0;
    for(int i=0; i < numRows; ++i){
      for(int j =0; j < numColumns; ++j){
        gGrid[i][j]= stringFile[columnCount];
        columnCount++;
      }
    }
  }
  else{ //random file generator
        cout<<"You have choosen to generate a random file."<<endl;
        cout<<"Please enter a number of rows"<<endl;
        cin>>randRows;
        cout<<"Please enter a number of columns"<<endl;
        cin>>randColumns;
        cout<<"Enter the initial population density of the world."<<endl;
        cin>>randDensity;
      try {
          numRows = stoi(randRows); //string to int
          numColumns = stoi(randColumns);
        }
        catch(const std::invalid_argument e) {
          cout<<"Error"<<endl;
          exit(1);
        }
    gGrid = new char*[numRows]; //size
      for(int i = 0; i < numRows; ++i){
        gGrid[i] = new char[numColumns];
        for(int j = 0; j < numColumns; ++j){
          gGrid[i][j] = '-';
      }
    }
    //generates the random grid for user
    cout<<randDensity<<endl;
    gGrid = new char*[numRows]; //size
      for(int i = 0; i < numRows; ++i){
        gGrid[i] = new char[numColumns];
        for(int j = 0; j < numColumns; ++j){
          float randNum = (float)rand() / RAND_MAX;
          if(randNum <= randDensity){
            gGrid[i][j] = 'X';
          }
          else{
            gGrid[i][j] = '-';
        }
      }
    }
  }
}
void Grid::printGrid(){
  for(int i = 0; i < numRows; ++i){
    for(int j = 0; j < numColumns; ++j){
      cout<<gGrid[i][j]<<"";
    }
    cout<<endl;
  }
}
char**Grid::returnGrid(){
  return gGrid;
}
