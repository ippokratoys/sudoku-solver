#include "sudokugame.h"
#define playref(i,j,x,boa) play((i),(j),(x),(boa));refresh((i),(j),(x));moves(0,1);
int possible[9][9][10];

 
void moves(int i,int j);
sudoku read();
void charow(int gram,int sthl,int arith,int mporei);
void chacol(int gram,int sthl,int arith,int mporei);
void chabox(int gram,int sthl,int arith,int mporei);
void prnt(int pin[9][9][9]);
void refresh(int i,int j,int x);

int canbepalyed(int i,int j,int x){
	return possible[i][j][x];
}


void moves(int i,int j){
	int k;
	printf("|Possible for(%d,%d):",i,j);
	for(k=1;k<=9;k++){
		if (possible[i][j][k]==1)printf("%d ",k);
	}
	printf("|\n");
}

sudoku read(){
	FILE *inp;
	int i,j;
	int x=0;
	sudoku sudfile=NULL;
	sudfile=initialize();
	inp=fopen("input1.sud","r");
	int ch;
	ch=getc(inp);
	while(ch!=EOF){
		if(ch<='9' && ch>='1'){
			ch=ch-'0';
			i=x/9;
			j=x%9;
			playref(i,j,ch,sudfile);
			x++;
		}else if(ch=='\n'){
			
		}else if(ch==' '){
			x++;
		}
		ch=getc(inp);
	}
	
	fclose(inp);
	return sudfile;
}

void charow(int gram,int sthl,int arith,int mporei){
	int i,j,k;
	for(j=0;j<9;j++){
		possible[gram][j][arith]=mporei;
	}
}

void chacol(int gram,int sthl,int arith,int mporei){
	int i,j,k;
	for(i=0;i<9;i++){
		possible[i][sthl][arith]=mporei;
	}
}

void chabox(int gram,int sthl,int arith,int mporei){
	int i,j,k;
	for(i=(gram/3)*3;i<(gram/3)*3+3;i++){
		for(j=(sthl/3)*3;j<(sthl/3)*3+3;j++){
			possible[i][j][arith]=mporei;
		}
	}
}

void prnt(int pin[9][9][9]){
	int i,j,k;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			for(k=1;k<=9;k++){
				printf("%d ",pin[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void refresh(int i,int j,int x){
	int k;
	for(k=1;k<=9;k++){
		possible[i][j][k]=0;
	}
	charow(i,j,x,0);
	chacol(i,j,x,0);
	chabox(i,j,x,0);
}

int main(void){
	int arxi,arxj;
	int synti1,synti2,synti3;
	int syntj1,syntj2,syntj3;
	int i,j,k,ch,stuck;
	int kin,plith,pith;
	int betapith[3];
	int ii,jj,kk;
	sudoku test=NULL;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			possible[i][j][0]=0;
			for(k=1;k<=9;k++){
				possible[i][j][k]=1;//arxikopoihsh pinaka pithanwn lusewn
			}
		}
	}
	test=read();
	print(test);

/*TEST:	
	printf("\npossibles\n");
	while(1){
		ch=getchar();
		if(ch=='\n')ch=getchar();
		if(ch==' ')break;
		for(j=0;j<9;j++){
			moves(ch-'0',j);printf("\n");
		}
		printf("------");
	}	
*/

	printf("\n----START SOLVING---\n");
	
	while( !full(test) ){
		stuck=1;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				kin=what(i,j,test);
				if(kin==0){
					pith=0;
					plith=0;
					for(k=1;k<=9;k++){
						if(possible[i][j][k]==1){
							pith=k;
							plith++;
						}
					}
					if(plith==1){
						moves(i,j);
						printf("it will play at(%d,%d) : %d\n",i,j,pith);
						playref(i,j,pith,test);stuck=0;
						print(test);
						getchar();
					}
				}
			}
		}
		//an o parapanw tropos bgazei se adieksodo
		if(stuck==1){
			//orizontia
			printf("stuck1\n");
			for(i=0;i<9;i++){
				for(k=1;k<=9;k++){
					plith=0;
					pith=0;
					for(j=0;j<9;j++){
						kin=what(i,j,test);
						if(kin==0 && canbepalyed(i,j,k)){
							plith++;
							pith=j;
						}
					}
					if(plith==1){
						moves(i,pith);
						printf("it will play at(%d,%d) : %d\n",i,pith,k);
						playref(i,pith,k,test);stuck=0;
						print(test);
						getchar();
					}
				}
			}
		}
		
		if(stuck==1){
			//katheta
			printf("stuck2\n");
			for(j=0;j<9;j++){
				for(k=1;k<=9;k++){
					plith=0;
					pith=0;
					for(i=0;i<9;i++){
						kin=what(i,j,test);
						if(kin==0 && canbepalyed(i,j,k)){
							plith++;
							pith=i;
						}
					}
					if(plith==1){
						moves(pith,j);
						printf("it will play at(%d,%d) : %d\n",pith,j,k);
						playref(pith,j,k,test);stuck=0;
						print(test);
						getchar();
					}
				}
			}
		}
		
		if(stuck==1){
			//ana kouti
			printf("stuck3\n");
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					for(k=1;k<=9;k++){
						plith=0;
						pith=0;
						for(ii=i*3;ii<i*3+3;ii++){
							for(jj=j*3;jj<j*3+3;jj++){
								kin=what(ii,jj,test);
								if(kin==0 && canbepalyed(ii,jj,k)){
									plith++;
									pith=ii*9+jj;
								}
							}
						}
						if(plith==1){
							moves(pith/9,pith%9);
							printf("BOX it will play at(%d,%d) : %d\n",pith/9,pith%9,k);
							playref(pith/9,pith%9,k,test);stuck=0;
							print(test);
							getchar();
							
						}
					}
				}
			}
			
		}
		
		if(stuck==1){
			printf("|beta stuck col|\n");
			for(j=0;j<9;j++){
				for(k=1;k<=9;k++){
					plith=0;
					
					for(i=0;i<9;i++){
						kin=what(i,j,test);
						if(kin==0 && canbepalyed(i,j,k)){
							betapith[plith]=i;
							plith++;
						}
					}
					if(plith==2){
						if(betapith[0]/3==betapith[1]/3){
							chabox(betapith[0],j,k,0);
							possible[betapith[0]][j][k]=1;
							possible[betapith[1]][j][k]=1;
							printf("true%d(%d)\n",k,j);
						}
					}else if(plith==3){
						if(betapith[0]/3==betapith[1]/3 && betapith[1]/3==betapith[2]/3){
							chabox(betapith[0],j,k,0);
							possible[betapith[0]][j][k]=1;
							possible[betapith[1]][j][k]=1;
							possible[betapith[2]][j][k]=1;
							printf("3true%d(%d)\n",k,j);
						}
					}
				}
			}
		}

		if(stuck==1){
			printf("|beta stuck row|\n");
			for(i=0;i<9;i++){
				for(k=1;k<=9;k++){
					plith=0;
					
					for(j=0;j<9;j++){
						kin=what(i,j,test);
						if(kin==0 && canbepalyed(i,j,k)){
							betapith[plith]=j;
							plith++;
						}
					}
					if(plith==2){
						if(betapith[0]/3==betapith[1]/3){
							chabox(i,betapith[0],k,0);
							possible[i][betapith[0]][k]=1;
							possible[i][betapith[1]][k]=1;
							printf("2true%d(%d)\n",k,i);
						}
					}else if(plith==3){
						if(betapith[0]/3==betapith[1]/3 && betapith[1]/3==betapith[2]/3){
							chabox(i,betapith[0],k,0);
							possible[i][betapith[0]][k]=1;
							possible[i][betapith[1]][k]=1;
							possible[i][betapith[2]][k]=1;
							printf("3true%d(%d)\n",k,i);
						}
					}
				}
			}
		}
		if(stuck==1){
			printf("|beta stuck box|\n");
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					for(k=1;k<=9;k++){
						plith=0;
						for(ii=i*3;ii<i*3+3;ii++){
							for(jj=j*3;jj<j*3+3;jj++){
								kin=what(ii,jj,test);
								if(kin==0 && canbepalyed(ii,jj,k)){
									betapith[plith]=ii*9+jj;
									plith++;
								}
							}
						}
						if(plith==2){
							synti1=betapith[0]/9;
							syntj1=betapith[0]%9;
							
							synti2=betapith[1]/9;
							syntj2=betapith[1]%9;
							if(synti1==synti2){//an idia seira
								charow(synti1,0,k,0);
								possible[synti1][syntj1][k]=1;
								possible[synti2][syntj2][k]=1;
								printf("2true%d(--%d)\n",k,synti1);
							}else if(syntj1==syntj2){//an idia sthlh
								chacol(0,syntj1,k,0);
								possible[synti1][syntj1][k]=1;
								possible[synti2][syntj2][k]=1;
								printf("3true%d(||%d)\n",k,syntj1);
							}
						}else if(plith==3){
							synti1=betapith[0]/9;
							syntj1=betapith[0]%9;
							
							synti2=betapith[1]/9;
							syntj2=betapith[1]%9;
							
							synti3=betapith[2]/9;
							syntj3=betapith[2]%9;

							if(synti1==synti2 && synti1==synti3){//an idia seira
								charow(synti1,0,k,0);
								possible[synti1][syntj1][k]=1;
								possible[synti2][syntj2][k]=1;
								possible[synti3][syntj3][k]=1;
								printf("3true%d(--%d)\n",k,synti1);
							}else if(syntj1==syntj2 && syntj2==syntj3){//an idia sthlh
								chacol(0,syntj1,k,0);
								possible[synti1][syntj1][k]=1;
								possible[synti2][syntj2][k]=1;
								possible[synti3][syntj3][k]=1;
								printf("3true%d(||%d)\n",k,syntj1);
							}
						}
					}
				}
			}
		}
		printf("enter ' '\n");
		ch=getchar();
//		if(ch==' ') goto TEST;
	}
	



//	prnt(possible);
	return 0;
}
