#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for printing matrix
void printMatrix(int** array, int N) {
	for(int i = 1; i < N+1; i++) {
		for(int j = 1; j < N+1; j++) {
			printf("%d ", array[i][j]);			
		}
		printf("\n");
	}
}

void printVector(int* array, int count) {
	for(int i = 0; i < count; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

//verify sum
int checkSum(int* values, int count, int target) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += values[i];
	}

	if (sum == target) return 1;
	else return 0;
}

int main(){
	//read input.txt
	FILE* fp;
	char text[1000]; // max # of chars it can read per line
	fp = fopen("input.txt", "r");
	
	fgets(text, 100, fp); // get # of sets
	int sets = atoi(text);
	int* values = (int*) malloc(sizeof(int) * 100); // create a values array, max 100 values because realloc doesn't like big numbers
	for (int setnum = 0; setnum < sets; setnum++) { // do all this per set
		fgets(text, 100, fp); // get target sum
		int target = atoi(text);

		fgets(text, 100, fp); // get values of the subset
		char* token = strtok(text, " "); // tokenize
		// dynamically create an array based on the tokens
		int size = 0;
		while (token) {
			size++;
			// values = realloc(values, size); //reallocating higher values doesn't work very well
			values[size-1] = atoi(token);
			token = strtok(NULL, " ");
		}
	
		int N = size;

		int nopts[N+2]; //array of top of stacks
		int option[N+2][N+2]; //array of stacks of options

		int i, j, k, candidate, temp, start, move, hasSubset, subsetCount;
		hasSubset = 0;
		subsetCount = 0;
		start = 0; 
		move = N+1;
		printf("Set %d: ", setnum+1);
		printVector(values, size);

		//set values of option all to 0
		for(int i = 0;i<N+2;i++){
			for(int j = 0;j<N+2;j++){
				option[i][j] = 0;		
			}
		}

		//initialize option with candidate values
		for(i = 1; i < N+1; i++){
			temp = N-1;
			for(j = 1; j < N+1; j++){
				option[i][j] = values[temp];
				temp--; 
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
		printf("Subsets: \n");
		while (nopts[start] > 0) {
			//if TOS still has a value to print, print it and then decrement TOS
			if (nopts[move] > 0) {
				//print
				size = 0;
				for (i = 1; i < N+1; i++) {
					if(option[move][nopts[i]] == 0) break;	//dont print if element is 0
					// printf("%d ", option[move][nopts[i]]);
					values[size] = option[move][nopts[i]];
					size++;
				}
				//verify subset
				if (nopts[start+1] != 0) {
					if (checkSum(values, size, target)) {
						printVector(values, size);
						hasSubset = 1;
						subsetCount++;
					}
				}
				
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

		if (hasSubset) printf("Number of subsets found: %d\n", subsetCount);
		else printf("No valid subset has been found.\n");

	}
	printf("-- end --");
}