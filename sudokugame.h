#ifndef __SUDOKUGAME
#define __SUDOKUGAME
#include <stdio.h>
#include <stdlib.h>
typedef struct sud *sudoku;
sudoku initialize();
void print(sudoku game);
int what(int i,int j,sudoku game);
int play(int i,int j,int x,sudoku game);
int inrow(int i,int j,int x,sudoku game);
int incol(int i,int j,int x,sudoku game);
int inbox(int i,int j,int x,sudoku game);
#endif
