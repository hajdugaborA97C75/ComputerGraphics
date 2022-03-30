#include "matrix.h"

#include <stdio.h>

void init_zero_matrix(float matrix[3][3]){
	int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0;
        }
	}
}

void print_matrix(float matrix[3][3]){
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%g ", matrix[i][j]);
        }
        printf("\n");
    }
	printf("\n");
	printf("\n");
}


void add_matrices(float a[3][3], float b[3][3], float c[3][3]){
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix (float matrix[3][3]){
	int i;
	int j;
	
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if(i==j){
				matrix[i][j]=1.0;
			}
			else{
				matrix[i][j]=0.0;
			}
        }
  }	
}

void scalar_multiply(float matrix[3][3], int num){
	
	int i;
	int j;
	
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			matrix[i][j]=matrix[i][j]*num;		
		}
	}
}

void multiply_matrices(float a[3][3], float b[3][3], float matrix[3][3]) {
	
	int i, j, k;
	float sum;
    for(i = 0; i < 3; i++)
    {
            for(j = 0; j < 3; j++)
            {
                    for(k = 0; k < 3; k++)
                    {
                            sum +=  (a[i][k] *  b[k][j]);
                    }
					matrix[i][j] = sum;
					sum = 0;
            }
    }
	
}



