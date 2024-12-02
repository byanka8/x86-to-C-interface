#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100 // Maximum number of points

void generate_random(double* arr, int size, double min, double max);
double compute(double x1, double y1, double x2, double y2);
extern double testing();

int main() {
	
	int size, exponent, i, j;
	// double x1[MAX][2], y1[MAX][2], x2[MAX][2], y2[MAX][2];
	// double z[MAX];
	// double m[MAX];

	double min = 1.0;    // Minimum value
    double max = 99.0;   // Maximum value
	
	printf("input vector length: ");
	scanf("%d", &exponent);

	size = pow(2, exponent);

	double x1[size], y1[size], x2[size], y2[size];
	double z[size];
	double m[size];
	
	// size = 4;
	// double x1[] = {1.5, 4.0, 3.5, 2.0};
    // double x2[] = {3.0, 2.5, 2.5, 1.0};
    // double y1[] = {4.0, 3.0, 3.5, 3.0};
    // double y2[] = {2.0, 2.5, 1.0, 1.5};

	generate_random(x1, size, min, max);
	generate_random(x2, size, min, max);
	generate_random(y1, size, min, max);
	generate_random(y2, size, min, max);
	
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

// Function to generate random double values in a specified range
void generate_random(double* arr, int size, double min, double max) {
	int i;

    for (i = 0; i < size; i++) {
        double scale = rand() / (double)RAND_MAX; // Scale: 0.0 to 1.0
        arr[i] = min + scale * (max - min);       // Scale to desired range
    }
}




