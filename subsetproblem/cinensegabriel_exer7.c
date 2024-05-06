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

int main(){
    int *s; //set
    int k; //target
    int n; //num of elements

    FILE * fp;

    fp = fopen ("input.txt", "r");
    fscanf(fp, "%d", &k);
    printf("%d \n", k);

    int temp = 0;
    while(fscanf(fp,"%d ", &temp)){
        printf("%d ",temp);
        n++;
    }

    //sort set
    // qsort(&s, sizeof(s)/sizeof(int), sizeof(int), cmpfunc);

    // int **mat = (int** )malloc(n*sizeof(int *));
    // for(int i = 0; i<n; i++){
    //     mat[i] = (int *)malloc((k+1)*sizeof(int));
    //     mat[i][0] = 1;
    // }

    // for(int i = 0; i<n; i++){
    //     for (int j = 1; j<(k+1); j++){
    //         //special case if first element
    //         if (i == 0) {
    //             if(j == s[i]) mat[i][j] = 1;
    //             else mat[i][j] = 0;
    //         }
    //         else{
    //             if (mat[i-1][j] == 1){
    //                 mat[i][j] = 1;
    //             }else{
    //                 if(mat[i-1][j-s[i]] == 1 && s[i]<=j){
    //                     mat[i][j] = 1;
    //                 }else{
    //                     mat[i][j] = 0;
    //                 }
    //             }
    //         }
    //     }
    // }
    // printMatrix(mat,n,k+1);

    // int temp1 = n-1;
    // printf("Solution: ");
    // if (mat[temp1][k] == 0) printf("No solution");
    // else {
    //     for (int i = k; i > 0;) {
    //         if (temp1 == 0 && mat[temp1][i] == 1) {
    //             printf("%d ", s[temp1]);
    //             i = 0;
    //         }
    //         else if (mat[temp1][i] == 1 && mat[temp1-1][i] == 0) {
    //             printf("%d ", s[temp1]);
    //             temp1--;
    //             i -= s[temp1+1];
    //         }
    //         else if(mat[temp1][i] == 1 && mat[temp1-1][i] == 1) {
    //             temp1--;
    //         }
    //         else if(mat[temp1][i] == 0 && temp1 != 0) {
    //             temp1--;
    //         }
    //     }
    // }
}