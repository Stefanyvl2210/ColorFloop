#include<stdio.h>
#include<windows.h>
#include <conio.h>
#include "_conio.h"
#include <time.h>
#include <stdlib.h>

void color(int x){
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,x);
}

int cargar(int mat[50][50]){
	int x,y;
	srand(time(NULL));
	for(x=0;x<20;x++){
		for(y=0;y<20;y++){
			mat[x][y]=rand()%6+1;					
		}
	}
}

void imprimir(int mat[50][50],int random,int &n){
	int x,y,mov;
	for(x=0;x<n;x++){		
		for(y=0;y<n;y++){
			mat[0][0]=8;	
		
			if(	mat[x][y]==1 ){	
				color(11*16+0);
				printf("   ",mat[x][y]);			
			}	
			else if(mat[x][y]==2  ){
				color(12*16+0);
				printf("   ",mat[x][y]);				
			}
			else if(mat[x][y]==3 ){
				color(13*16+0);
				printf("   ",mat[x][y]);				
			}
			else if(mat[x][y]==4 ){
				color(14*16+0);
				printf("   ",mat[x][y]);				
			}
			else if(mat[x][y]==5 ){
				color(15*16+0);
				printf("   ",mat[x][y]);				
			}
			else if(mat[x][y]==6){
				color(10*16+0);
				printf("   ",mat[x][y]);			
			}	
			else if(mat[0][0]==8){
				color(random*16+0);
				printf("   ",mat[0][0]);
			}							
		}
		printf("\n");							
	}
	printf("\n");
	color(11*16+0);
	printf("\t");
	color(12*16+0);
	printf("\t");
	color(13*16+0);
	printf("\t");
	color(14*16+0);
	printf("\t");
	color(15*16+0);
	printf("\t");
	color(10*16+0);
	printf("\t");
	color(012);	
	printf("\n 1:Blue  2:Red  3:Pink  4:Yellow  5:White  6:Green\n");
	printf("\n Movimientos: \n");
	printf("\n presione 0 para volver al menu");
}
bool ganar(int mat[50][50],int &n){
	int x,y;
	int cont_8=0;
	bool band=false;
	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			if(mat[x][y]==8){
				cont_8++;
			}
			else{
				band=false;
				break;
			}				
		}
	}
	if(cont_8==n*n){
		return true;
	}
	return false;
}

void jugar(int mat[50][50],int random,int &n){
	int tecla;
	int mov;
	int x,y;
	int cont_8=1;
	char band;		
	srand(time(NULL));
	random=rand()%5+10;//colores aleatorios
	if(n==10){
		mov=25;
	}
	else{
		mov=40;
	}
	
	do{
		system("CLS");	
		mat[0][0]=8;
	
		for(x=0;x<n;x++){ // comprobar si hay el mismo color al rededor
			for(y=0;y<n;y++){																					
				if(mat[x][y]==8 && random==11){
				
					if(mat[x][y+1]==1 ){						
						mat[x][y+1]=8;										
					}
					 if(mat[x][y-1]==1){									
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==1){									
						mat[x+1][y]=8;
					}
					 if(mat[x-1][y]==1){											
						mat[x-1][y]=8;										
					}																										
				}
				else if(mat[x][y]==8 && random==12){
					
					if(mat[x][y+1]==2){
						mat[x][y+1]=8;									
					}
					 if(mat[x][y-1]==2){
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==2){
						mat[x+1][y]=8;									
					}
					 if(mat[x-1][y]==2){
						mat[x-1][y]=8;									
					}																									
				}
				else if(mat[x][y]==8 && random==13){

					if(mat[x][y+1]==3){
						mat[x][y+1]=8;								
					}
					 if(mat[x][y-1]==3){
						mat[x][y-1]=8;								
					}
					 if(mat[x+1][y]==3){
						mat[x+1][y]=8;										
					}
					 if(mat[x-1][y]==3){
						mat[x-1][y]=8;									
					}																										
				}
				else if(mat[x][y]==8 && random==14){
			
					if(mat[x][y+1]==4){
						mat[x][y+1]=8;									
					}
					 if(mat[x][y-1]==4){
						mat[x][y-1]=8;								
					}
					 if(mat[x+1][y]==4){
						mat[x+1][y]=8;								
					}
					 if(mat[x-1][y]==4){
						mat[x-1][y]=8;									
					}																									
				}
				else if(mat[x][y]==8 && random==15){
			
					if(mat[x][y+1]==5){
						mat[x][y+1]=8;									
					}
					 if(mat[x][y-1]==5){
						mat[x][y-1]=8;							
					}
					 if(mat[x+1][y]==5){
						mat[x+1][y]=8;							
					}
					 if(mat[x-1][y]==5){
						mat[x-1][y]=8;										
					}																									
				}
				else if(mat[x][y]==8 && random==10){
						
					if(mat[x][y+1]==6){
						mat[x][y+1]=8;										
					}
					 if(mat[x][y-1]==6){
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==6){
						mat[x+1][y]=8;									
					}
					 if(mat[x-1][y]==6){
						mat[x-1][y]=8;									
					}																									
				}
			}
		}			
		imprimir(mat,random,n);
		if(n==10){
			gotoxy(14,14);
			printf("%d   ",mov);
		}
		else if(n==20){
			gotoxy(14,24);
			printf("%d   ",mov);
		}			
		
		if(mov<=0){
			printf("\n USTED ES UN LOSER");
			getch();
			break;
		}	
		if(ganar(mat,n)==true){
			printf("\n GG IZI PIZI ");
			getch();
			break;
		}		
		
		scanf("%d",&tecla);	
		if(tecla>0 && tecla<7){
			mov=mov-1;
		}
			
		for(x=0;x<n;x++){
			for(y=0;y<n;y++){																		
				if(tecla==1 && mat[x][y]==8){
					random=11;				
					if(mat[x][y+1]==1 ){						
						mat[x][y+1]=8;											
					}
					 if(mat[x][y-1]==1){									
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==1){									
						mat[x+1][y]=8;								
					}
					 if(mat[x-1][y]==1){											
						mat[x-1][y]=8;								
					}																										
				}
				else if(tecla==2 && mat[x][y]==8){
					random=12;				
					if(mat[x][y+1]==2){
						mat[x][y+1]=8;    										
					}
					 if(mat[x][y-1]==2){
						mat[x][y-1]=8;								
					}
					 if(mat[x+1][y]==2){
						mat[x+1][y]=8;									
					}
					 if(mat[x-1][y]==2){
						mat[x-1][y]=8;							
					}																									
				}
				else if(tecla==3 && mat[x][y]==8){
					random=13;			
					if(mat[x][y+1]==3){
						mat[x][y+1]=8;									
					}
					 if(mat[x][y-1]==3){
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==3){
						mat[x+1][y]=8;									
					}
					 if(mat[x-1][y]==3){
						mat[x-1][y]=8;									
					}																										
				}
				else if(tecla==4 && mat[x][y]==8){
					random=14;		
					if(mat[x][y+1]==4){
						mat[x][y+1]=8;										
					}
					 if(mat[x][y-1]==4){
						mat[x][y-1]=8;					
					}
					 if(mat[x+1][y]==4){
						mat[x+1][y]=8;								
					}
					 if(mat[x-1][y]==4){
						mat[x-1][y]=8;									
					}																									
				}
				else if(tecla==5 && mat[x][y]==8){
					random=15;		
					if(mat[x][y+1]==5){
						mat[x][y+1]=8;										
					}
					 if(mat[x][y-1]==5){
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==5){
						mat[x+1][y]=8;							
					}
					 if(mat[x-1][y]==5){
						mat[x-1][y]=8;									
					}																									
				}
				else if(tecla==6 && mat[x][y]==8){
					random=10;		
					if(mat[x][y+1]==6){
						mat[x][y+1]=8;											
					}
					 if(mat[x][y-1]==6){
						mat[x][y-1]=8;									
					}
					 if(mat[x+1][y]==6){
						mat[x+1][y]=8;									
					}
					 if(mat[x-1][y]==6){
						mat[x-1][y]=8;
					}																									
				}
			}							
		}
					
	}while(tecla>0 || tecla<7);
	system("CLS");
}

int main(){
	int mat[50][50],x,y,op,menu,color,random,n;
	int dificultad;
	
	gotoxy(35,1);
	system("color a");
	printf("COLOR FLOOP");
	gotoxy(30,3);
	printf("1.INICIAR NUEVO JUEGO");
	gotoxy(30,5);
	printf("2.INSTRUCCIONES");
	gotoxy(30,7);
	printf("3.CREDITOS ");
	gotoxy(30,9);
	printf("4.SALIR ");
	scanf(" %d",&op);
	cargar(mat);
	
	do{	
		switch(op){					
				case 1:
					system("CLS");
					gotoxy(30,3);
					printf("DIFICULTAD");
					gotoxy(30,5);
					printf("1.FACIL");
					gotoxy(30,7);
					printf("2.DIFICIL  ");
					scanf("%d",&dificultad);
					if(dificultad==1){
						n=10;
					}
					else if(dificultad==2){
						n=20;
					}
				
					jugar(mat,random,n);					
					main();	
						
					break;					
				case 2:
					system("CLS");
					printf("\n1) El objetivo principal del juego es cambiar los colores hasta que el tablero de papel se inunda con un solo color.");
					printf("\n2) Se puede lograr esto, a partir de la esquina superior izquierda, mediante la seleccion de un color a juego alrededor de los limites.");
					printf("\n3) Asi que en cada juego, podras cambiar el color del territorio conquistado en el interior del tablero.");
					printf("\n4) Los limites se definen en la parte superior, inferior, izquierda y derecha de cada bloque.");
					printf("\n\nPresione 0 para volver al menu");
										
					do{
						scanf(" %d",&menu);
						if(menu==0){
							system("CLS");
							main();
						}
						else printf("tecla invalida ");
					}while(menu!=0);
					break;
				case 3:
					system("CLS");
					
					system("color b");
					for(x=0;x<10;x++){
						Sleep(80);
						system("CLS");
						gotoxy(x,5);
						printf("Stefany Vega Lopez CI:25377585");
						
					}
					gotoxy(1,20);
					printf("Presione 0 para volver al menu");								
					do{
						scanf(" %d",&menu);
						if(menu==0){
							system("CLS");
							main();
						}
						else printf("tecla invalida ");
					}while(menu!=0);
						
					break;	
				case 4:
					system("CLS");
					gotoxy(20,10);
					printf("SALIENDO");
					for(x=0;x<10;x++){
						gotoxy(28+x,10);
						printf(".");
						Sleep(300);
					}
					gotoxy(39,10);
					printf(":D");
					break;				
		}				
	}while(op<1 && op>4);
	
	getch();
	return 0;
}
