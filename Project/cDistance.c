#include <stdio.h>
#include <math.h>

#define MAX 100 // Maximum number of points

double compute(double x1, double y1, double x2, double y2);
extern double testing();

int main() {
	
	int size, i, j;
	// double x1[MAX][2], y1[MAX][2], x2[MAX][2], y2[MAX][2];
	double z[MAX];
	double m[MAX];
	
	printf("input vector length: ");
	scanf("%d", &size);
	
	size = 4;
	double x1[] = {1.5, 4.0, 3.5, 2.0};
    double x2[] = {3.0, 2.5, 2.5, 1.0};
    double y1[] = {4.0, 3.0, 3.5, 3.0};
    double y2[] = {2.0, 2.5, 1.0, 1.5};
	
	for (i=0 ; i<size; i++) {
			// compute distance of each point c
			z[i] = compute(x1[i], y1[i], x2[i], y2[i]);
	}
	
	// output first 10 elements of z
	for (i=0 ; i<size && i<10; i++) {
		// compute distance of each point
		printf("%.2f", z[i]);
		if (i<size-1 && i<9) {
			printf(", ");
		} 
	}

	printf("\n");

	for (i=0 ; i<size; i++) {
			// compute distance of each point asm
			m[i] = compute(x1[i], y1[i], x2[i], y2[i]);
	}

	// output first 10 elements of mm
	for (i=0 ; i<size && i<10; i++) {
		// compute distance of each point
		printf("%.2f", m[i]);
		if (i<size-1 && i<9) {
			printf(", ");
		} 
	}
	
	return 0;
	
}

double compute(double x1, double y1, double x2, double y2) {
	
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1,2));
}






