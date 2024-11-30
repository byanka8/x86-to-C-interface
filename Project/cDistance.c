#include <stdio.h>
#include <math.h>

#define MAX 100 // Maximum number of points

double compute(double x1, double y1, double x2, double y2);
extern double testing();

int main() {
	
	int size, i, j;
	double x1[MAX][2], y1[MAX][2], x2[MAX][2], y2[MAX][2];
	double z[MAX];
	double m[MAX];
	
	printf("input vector length: ");
	scanf("%d", &size);
	
	// input x1 points values
	printf("Enter x1 values: ");
	for (i=0 ; i<size; i++) {
		scanf("%lf", &x1[i][0]);
	}
	
	printf("Enter x2 values: ");
	// input x2 points values
	for (i=0 ; i<size; i++) {
		scanf("%lf", &x2[i][0]);
	}
	
	// input y1 points values
	printf("Enter y1 values: ");
	for (i=0 ; i<size; i++) {
		scanf("%lf", &y1[i][1]);
	}
	
	// input y2 points values
	printf("Enter y2 values: ");
	for (i=0 ; i<size; i++) {
		scanf("%lf", &y2[i][1]);
	}
	
	for (i=0 ; i<size; i++) {
			// compute distance of each point
			z[i] = compute(x1[i][0], y1[i][1], x2[i][0], y2[i][1]);
			m[i] = testing(x1[i][0], y1[i][1], x2[i][0], y2[i][1]);
	}
	
	// output first 10 elements of z
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






