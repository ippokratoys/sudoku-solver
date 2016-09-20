# sudoku-solver
Is an application in C that solves sudoku(famous game)

How it works:

  INPUT:
  
    It takes input from a text file(for now with name"input1.sud" 
    that has the 9x9 board: if there is a number you enter 
    the number, else you enter a space.

  OUTPUT:
  
    It prints every time you press enter a move(it was for debug reasons)
    until the board is full.

  Behind the codes:
  
    I use a board that has the possibles number for each box and then by the
    rules it delete what can't be used. Then starts "thinking" if a number can't 
    be entered somewhere elese in the box/line/column. If it stucks after some 
    moves it guess (in a box with two choises or three or minimum number).
    Here starts the recursion, until the puzzle is full or can't be full because the
    move was wrong. It goes back to where the recursion start and say if the number 
    can or can't be entered in the box. Then goes back to the logic part

Small story:

    I started creating this app in my first summer after i joined the university
    just to see if i can do somthing that is not an excercise for university.
