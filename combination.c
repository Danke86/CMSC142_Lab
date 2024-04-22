#include <stdio.h>
#include <stdlib.h>
#define N 3

int main(){
	int start, move;
	int nopts[N+2]; //array of top of stacks
	int option[N+2][N+2]; //array of stacks of options
	int i, candidate;

	move = start = 0; 
	nopts[start]= 1;
	option[1][1]=option[1][2]=option[1][3]=
	option[2][1]=option[2][2]=option[2][3]=
	option[3][1]=option[3][2] = option[3][3]=0;
	int count = 1;
	while (nopts[start] >0) //while dummy stack is not empty
	{
		
		printf("ITERATION COUNT %d\n",count);
		if(nopts[move]>0) 
		{
			move++;
			nopts[move]=0; //initialize new move

			if(move==N+1) //solution found!
			{
				printf("ANSWER:");
				for(i=1;i<move;i++)
					if (option[i][nopts[i]] != 0)
						printf("%2i",option[i][nopts[i]]);
				printf("\n");
			}
			else if(move == 1){
				for(candidate = N; candidate >=1; candidate --) 
				{
					nopts[move]++;
					option[move][nopts[move]] = candidate;
					// printf("nopts[move] %i candidate %i:\n", nopts[move], candidate);           
				}
			}
			else{
				// for(candidate = N; candidate >=1; candidate --) 
				// {
				// 	nopts[move]++;
				// 	option[move][nopts[move]] = candidate;
				// 	// printf("nopts[move] %i candidate %i:\n", nopts[move], candidate);           
				// }
				for(candidate=N;candidate>=1;candidate--)
				{
					for(i=move-1;i>=1;i--)
						if(candidate==option[i][nopts[i]]) break;
					if(!(i>=1))
						option[move][++nopts[move]] = candidate;
				}
			}
			printf("TOS: %d %d %d\n",nopts[1],nopts[2],nopts[3]);
			printf("%d %d %d\n", option[1][1],option[1][2],option[1][3]);
			printf("%d %d %d\n", option[2][1],option[2][2],option[2][3]);
			printf("%d %d %d\n", option[3][1],option[3][2],option[3][3]);
			printf("\n");
		}
		else 
		{
			printf("I BACKTRACKED\n");
			move--;
			nopts[move]--;

		}
		printf("MOVE IS AT %d\n", move);
		count++;
	}
}