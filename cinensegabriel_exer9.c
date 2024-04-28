#include <stdio.h>
#include <stdlib.h>
#define N 4

//for printing matrix
int printMatrix(int array[][N+2]) {
	for(int i = 1; i < N+1; i++) {
		for(int j = 1; j < N+1; j++) {
			printf("%d ", array[i][j]);			
		}
		printf("\n");
	}
}

int main(){
	int start, move;
	int nopts[N+2]; //array of top of stacks
	int option[N+2][N+2]; //array of stacks of options

	int i, j, k, candidate, temp;

	start = 0; 
	move = N+1;
	// int count = 1;

	//set values of option all to 0
	for(int i = 0;i<N+2;i++){
		for(int j = 0;j<N+2;j++){
			option[i][j] = 0;		
		}
	}

	//initialize option with candidate values
	candidate = N;
	for(i = 1; i < N+1; i++){
		candidate = N;
		for(j = 1; j < N+1; j++){
			option[i][j] = candidate;
			candidate--; 
		}
	}

	//init top of stack
	candidate = N;
	for (i= 0; i < N+2; i++) {
		if (i == 0) nopts[i] = 1;	//start
		else {
			nopts[i] = candidate;
			candidate--;
		}
	}
	printf("N = %d\n", N);
	while (nopts[start] > 0) {
		//if TOS still has a value to print, print it and then decrement TOS
		if (nopts[move] > 0) {
			//print
			for (i = 1; i < N+1; i++) {
				if(option[move][nopts[i]] == 0) break;	//dont print if element is 0
				printf("%d ", option[move][nopts[i]]);
			}
			if (nopts[start+1] != 0) printf("\n");
			
			//repopulate if current TOS is 3 and above, succeeding TOSs is -1 the previous TOS.
			if (nopts[move] >= 3) {
				nopts[move]--;
				temp = nopts[move] - 1;
				while (temp != 0) {
					move++;
					nopts[move] = temp;
					temp = nopts[move] - 1;
				}
			}
			//TOS 2 and 1, no need to repopulate
			else nopts[move]--;
		}
		else {
			//backtrack
			move--;
		}
	}

	printf("-- end --");
}