#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int printMatrix(int **array, int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", array[i][j]);			
		}
		printf("\n");
	}
}

int printArray(int *array, int n) {
    printf("Array: ");
    for(int i =0;i < n; i++){
        printf("%d ", array[i]);		
    }
    printf("\n");
}

int main(){
    int* s; //set
    int k; //target
    int n = 0; //num of elements
    int capacity = 10;

    FILE * fp;

    fp = fopen ("input.txt", "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return 1;
    }
    fscanf(fp, "%d", &k);
    printf("Target: %d \n", k);

    s = (int *)malloc(capacity * sizeof(int));

    int temp = 0;
    while(fscanf(fp,"%d ", &temp) == 1){
        if (n >= capacity){
            capacity += 1;
            s = (int *)realloc(s, capacity * sizeof(int));
        }
        s[n++] = temp;
        // printf("%d ",temp);
    }
    printArray(s, n);

    // sort set
    qsort(s, n, sizeof(int), cmpfunc);
    printf("Sorted ");
    printArray(s, n);

    int **mat = (int** )malloc(n*sizeof(int *));
    for(int i = 0; i<n; i++){
        mat[i] = (int *)malloc((k+1)*sizeof(int));
        for(int j = 0;j<n;j++){
            mat[i][j] = 0;
        }
        mat[i][0] = 1;
    }
    // printMatrix(mat,n,k+1);
    
    for(int i = 0; i<n; i++){
        for (int j = 1; j<(k+1); j++){
            //special case if first element
            if (i == 0) {
                if(j == s[i]) mat[i][j] = 1;
                else mat[i][j] = 0;
            }
            else{
                if (mat[i-1][j] == 1){
                    mat[i][j] = 1;
                }else{
                    if(mat[i-1][j-s[i]] == 1 && s[i]<=j){
                        mat[i][j] = 1;
                    }else{
                        mat[i][j] = 0;
                    }
                }
            }
        }
        // printMatrix(mat,n,k+1);
    }
    printMatrix(mat,n,k+1);

    int temp1 = n-1;
    printf("Solution: ");
    if (mat[temp1][k] == 0) printf("No solution");
    else {
        for (int i = k; i > 0;) {
            if (temp1 == 0 && mat[temp1][i] == 1) {
                printf("%d ", s[temp1]);
                i = 0;
            }
            else if (mat[temp1][i] == 1 && mat[temp1-1][i] == 0) {
                printf("%d ", s[temp1]);
                temp1--;
                i -= s[temp1+1];
            }
            else if(mat[temp1][i] == 1 && mat[temp1-1][i] == 1) {
                temp1--;
            }
            else if(mat[temp1][i] == 0 && temp1 != 0) {
                temp1--;
            }
        }
    }
}