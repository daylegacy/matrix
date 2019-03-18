#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrix.h"
#define MIN_SIZE 10
void transpose(int *a, int *b, int n) {
	int h = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[j*n + i] = a[i*n + j];
		}
	}
}

void transpose_CO(int *a, int *b, int n, int orgn_n) {
	if (n > MIN_SIZE && n%2==0) {
		transpose_CO(a, b, n / 2, orgn_n);
		transpose_CO(a + n / 2, b + orgn_n * n / 2, n / 2, orgn_n);
		transpose_CO(a + orgn_n * n / 2, b + n / 2, n / 2, orgn_n);
		transpose_CO(a + orgn_n * n / 2 + n / 2, b + orgn_n * n / 2 + n / 2, n / 2, orgn_n);
		//|AB|->|~A|~C|
		//|CD|  |~B|~D|
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[j*orgn_n + i] = a[i*orgn_n + j];
			}
		}
	}
}


int main(void) {
	int m, n; 
	int *a, *b;
	double t = 0, t1=0;

	printf("input n(try 10240, 16384, 20000, 32768): ");
	if (scanf("%d", &n)) { ; }
	m = n;

	if (!(a = (int*)malloc(n*m * sizeof(int)))) {
		printf("Not enough memory!\n");
		return 2;
	}
	if (!(b = (int*)malloc(n*m * sizeof(int)))) {
		printf("Not enough memory!\n");
		return 2;
	}
	
	init_matrix(a, n, m);
	printf("Matrix A: \n");
	print_matrix(a, n, m);
	t1 = clock();
	transpose(a, b, n);
	t1 = (clock() - t) / CLOCKS_PER_SEC;
	t = clock();
	transpose_CO(a,b, n, n);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Matrix B: \n");
	print_matrix(b, n, m);
	printf("\n");
	printf("Matrix size = %.2lfMB\n", n*n*sizeof(int)/(1024*1024.));
	printf("Elapsed simple transpose: %.2lf\n\tCO transpose: %.2lf\n", t1, t);
	//if (scanf("%d", &n)) { ; }
	
	return 0;
}

