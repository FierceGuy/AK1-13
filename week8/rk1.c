#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 10
#define DEL_VAL 0
#define DEL_MIN -10
#define DEL_MAX 0


int main() {
	int A[MAX_ROWS][MAX_COLS];
	int now_rows = MAX_ROWS;
	
	printf("Старая матрица:\n");

	srand(time(NULL));
	for(int i=0; i<now_rows; i++) {
		for(int j=0; j<MAX_COLS; j++) {
			A[i][j]=rand() % (DEL_MAX - DEL_MIN +1) + DEL_MIN;
			printf("%5d", A[i][j]);
		}	
		putchar('\n'); 
	}

	for(int i = 0; i<now_rows; i++) {
		for(int j =0; j < MAX_COLS; j++) {
			if (A[i][j] == DEL_VAL) {
				for(int k=i; k < now_rows - 1; k++) {
					for(int j = 0; j < MAX_COLS; j++) {
						A[k][j]=A[k+1][j];}
				}
			now_rows--;
			i--;
			break;	
			}
		}
				
	}
	

	printf("Новая матрица:\n");

	for(int i = 0; i < now_rows; i++) {
		for(int j = 0; j < MAX_COLS; j++) {
			printf("%5d", A[i][j]);			
		}	
		putchar('\n');
	}
	return 0;
}
