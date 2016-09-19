#include "sudokugame.h"

struct sud{
	int **board;//9 x 9 int board that contains the game board
	int size;   //for future use 
	int empty;  //if the board is empty is 1 else is 0
	int full;   //if the board is full is 1 else is 0
};

sudoku initialize(){
	int i,j;
	sudoku newgame;
	newgame=malloc(sizeof(struct sud));
	
	newgame->size=9;
	newgame->board=malloc(newgame->size*sizeof(int *));
	for(i=0;i<newgame->size;i++){
		newgame->board[i]=malloc(newgame->size*sizeof(int));

		for(j=0;j<newgame->size;j++){
			newgame->board[i][j]=0;
		}
	}
	newgame->full=0;
	newgame->empty=1;
	
	return newgame;
}

int play(int i,int j,int x,sudoku game){
	if(game==NULL) return 5;
	if(i<0 || i>=game->size) return 1;
	if(j<0 || j>=game->size) return 2;
	if(x<=0 || x>game->size) return 3;
	if(game->board[i][j]==0){
		game->empty=0;
		game->board[i][j]=x;
	}else{
		return 4;
	}
	return 0;
}

void print(sudoku game){
	int i,j,k;
	printf("   ");
	for(i=0;i<game->size;i++){
		printf(" %d  ",i);
	}
	printf("\n  ");
	for(i=0;i<game->size;i++){
		printf("  | ");
	}
	printf("\n");
	for(i=0;i<game->size;i++){
		printf("%d-|",i);
		for(j=0;j<game->size;j++){
			if(game->board[i][j]!=0){
				printf(" %d |",game->board[i][j]);
			}else{
				printf("   |");
			}
		}
		printf("\n  ");
		for(k=0;k<game->size;k++){
			printf("----");
		}
		printf("-\n");
	}
}

int inrow(int i,int j,int x,sudoku game){
	int ii,jj;
	if(i==-1)return 0;
	for(jj=0;jj<game->size;jj++){
		if(game->board[i][jj]==x) return 1;
	}
	return 0;
}

int incol(int i,int j,int x,sudoku game){
	int ii,jj;
	if(j==-1)return 0;
	for(ii=0;ii<game->size;ii++){
		if(game->board[ii][j]==x) return 1;
	}
	return 0;
}

int inbox(int i,int j,int x,sudoku game){
	int ii,jj;
	for(ii=(i/3)*3;ii<(i/3)*3+3;ii++){
		for(jj=(j/3)*3;jj<(j/3)*3+3;jj++){
			if(game->board[ii][jj]==x)return 1;
		}
	}
	return 0;
}

int full(sudoku game){
	int i,j;
	if(game->full==1)return 1;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if (game->board[i][j]==0){
				game->full=0;
				return 0;
			}
		}
	}
	game->full=1;
	return 1;
}

int what(int i,int j,sudoku game){
	return game->board[i][j];
}
