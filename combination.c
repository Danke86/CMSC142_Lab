#include <stdio.h>
#include <stdlib.h>
#define N 3

int main(){
	int start, move;
	int nopts[N+2]; //array of top of stacks
	int option[N+2][N+2]; //array of stacks of options
	option[1][1]=option[1][2]=option[1][3]=
	option[2][1]=option[2][2]=option[2][3]=
	option[3][1]=option[3][2] = option[3][3]=0;

	int i, candidate;

	move = start = 0; 
	nopts[start]= 1;
	
	int count = 1;

	//initialize
	candidate = N;
	for(int j = 1; j < N+1; j++){
		for(int k = 1; k < N+1; k++){
			option[k][j] = candidate; 
		}
		candidate --;
	}

	while (nopts[start] >0) //while dummy stack is not empty
	{
		
		printf("ITERATION COUNT %d\n",count);
		if(nopts[move]>0) 
		{	
			//if soemthing
			move++;
			nopts[move]=0; //initialize new move

			
			
			
			
		}
		else 
		{
			printf("I BACKTRACKED\n");
			move--;
			nopts[move]--;

		}
		printf("TOS: %d %d %d\n",nopts[1],nopts[2],nopts[3]);
		printf("%d %d %d\n", option[1][1],option[1][2],option[1][3]);
		printf("%d %d %d\n", option[2][1],option[2][2],option[2][3]);
		printf("%d %d %d\n", option[3][1],option[3][2],option[3][3]);
		printf("\n");
		printf("MOVE IS AT %d\n", move);
		count++;
	}
}