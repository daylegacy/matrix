#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 6
int read_matrix(int *a, int n, int m, const char * name) {
	int len = n * m;
	FILE *fp;
	if (!(fp = fopen(name, "r"))) return 0;
	for (int i = 0; i < len; i++) {
		if (fscanf(fp, "%d", a + i) != 1) {
			fclose(fp); return -2;
		}
	}
	fclose(fp);
	return 0;
}

int f(int i, int j) {
	return fabs(i - j);
}
int g(int i) {
	return i;
}
int h(int i) {
	return i % 2; //01010
}

void init_matrix(int *a, int n, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i*n + j] = g(i);
			//printf("i=%d, j=%d,f=%lf\n",i,j,f(i,j));
		}
	}
}

void print_matrix(int *a, int n, int m) {
	int i, j, l = 0;
	if (m >= MAX) {l = 1; }
	for (i = 0; i < (m > MAX ? MAX : m); i++) {
		for (j = 0; j < (n > MAX ? MAX : n); j++) {
			printf("%d\t", a[i*n + j]);

		}
		if (l == 1) printf("...");
		printf("\n");
	}
}

void printf_vec(int *x, int m)
{
	int l = 0;
	if (m >= MAX) { m = MAX; l = 1; }
	for (int i = 0; i < m; i++)
	{
		printf("%*.2d ", 7, x[i]);
	}
	if (l == 1)printf("...");
	printf("\n");
}

void init_vec(int *x, int len)
{
	for (int i = 0; i < len; i++)
		x[i] = g(i);
}

int read_vector(int *a, int len, const char * name) {
	FILE *fp;
	if (!(fp = fopen(name, "r"))) return 0;
	for (int i = 0; i < len; i++) {
		if (fscanf(fp, "%d", a + i) != 1) {
			fclose(fp); return -2;
		}
	}
	fclose(fp);
	return 0;
}

void vec_copy(int *a, int *b, int len) {
	for (int i = 0; i < len; i++) {
		b[i] = a[i];
	}
}

int sc_product(int *a, int *b, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}