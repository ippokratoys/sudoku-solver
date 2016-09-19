#ifndef __SUDOKUGAME
#define __SUDOKUGAME
#include <stdio.h>
#include <stdlib.h>

typedef struct sud *sudoku;
/*############### core functions ##############*/
sudoku initialize(); // initializes the board
void print(sudoku game); //prints the sudoku
int what(int i,int j,sudoku game); //returns what there is at i,j
int play(int i,int j,int x,sudoku game); //plays the x at i,j

/*############### helpfull functions ##############*/
int inrow(int i,int j,int x,sudoku game); //returns if x is in row i j is just to exist and be beutiful
int incol(int i,int j,int x,sudoku game); //returns if x is in column
int inbox(int i,int j,int x,sudoku game); //returns if x is in the 3x3 box

#endif
