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
	// double z[MAX];
	// double m[MAX];

	double min = 1.0;    // Minimum value
    double max = 99.0;   // Maximum value
	
	printf("input vector length: ");
	scanf("%d", &exponent);

	size = pow(2, exponent);

	printf("size: %d\n", size);
	double x1[size], y1[size], x2[size], y2[size];
	double z[size];
	double m[size];
	
	// variables for time
    clock_t c_start, c_end, asm_start, asm_end;
    double c_cpu_time_used, asm_cpu_time_used;
	
	// size = 4;
	// double x1[] = {1.5, 4.0, 3.5, 2.0};
    // double x2[] = {3.0, 2.5, 2.5, 1.0};
    // double y1[] = {4.0, 3.0, 3.5, 3.0};
    // double y2[] = {2.0, 2.5, 1.0, 1.5};

	generate_random(x1, size, min, max);
	generate_random(x2, size, min, max);
	generate_random(y1, size, min, max);
	generate_random(y2, size, min, max);
	
	c_start = clock();
	for (i=0 ; i<size; i++) {
			// compute distance of each point c
			z[i] = compute(x1[i], y1[i], x2[i], y2[i]);
	}
	c_end = clock();
	c_cpu_time_used = ((double) (c_end - c_start)) / CLOCKS_PER_SEC * 1000.0;
	
	printf("Execution time of C: %f ms\n", c_cpu_time_used);
	
	// output first 10 elements of z
	for (i=0 ; i<size && i<10; i++) {
		// compute distance of each point
		printf("%.2f", z[i]);
		if (i<size-1 && i<9) {
			printf(", ");
		} 
	}

	printf("\n");

	asm_start = clock();
	for (i=0 ; i<size; i++) {
			// compute distance of each point asm
			m[i] = compute(x1[i], y1[i], x2[i], y2[i]);
	}
	asm_end = clock();
	asm_cpu_time_used = ((double) (asm_end - asm_start)) / CLOCKS_PER_SEC * 1000.0;
	
	printf("Execution time of Assembly: %f ms\n", asm_cpu_time_used);

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
        double scale = rand() / (double)RAND_MAX; 
        arr[i] = min + scale * (max - min);       
    }
}




