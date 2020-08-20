/*============================================================================
benchmain.c

A dodgy self contained benchmarking system for bsv.h

Copyright(c) 2019 HJA Bird

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
============================================================================*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* Functions to run tests for float and double types. */
void benchf(int (*test_fn)(float*), int repeats, char* name, float* rand_array);
void benchd(int (*test_fn)(double*), int repeats, char* name, double* rand_array);

/* Check that we want to run this benchmark from description string */
char test_types[2048], test_funcs[2048];
int test_repeats;
int parse_command_args(int argc, char* argv[]);
int should_run_test(char* name);
int token_in_string(char* token, char* ref_str);
/* Print the test results. Mincounts give indication of timing resolution. */
void print_test_res(char* name, double* times, long long int mincounts);

/* We write to volatile vars to try and stop the compiler optimising 
away the calcs we want to benchmark. */
volatile float sinkf;
volatile double sinkd;
/* We create a random array for input. */
#define RAND_ARRAY_LEN 1000000
int create_rand_array(float** randf, double** randd);

/* Include source for tests. */
#include "benchvec2f.h"
#include "benchvec2d.h"
#include "benchvec3f.h"
#include "benchvec3d.h"
#include "benchvec4f.h"
#include "benchvec4d.h"

#include "benchmat2f.h"
#include "benchmat2d.h"
#include "benchmat3f.h"
#include "benchmat3d.h"
#include "benchmat4f.h"
#include "benchmat4d.h"

int main(int argc, char* argv[]) {
	if (!parse_command_args(argc, argv)){
		return 0;
	};
	
	/* Setup big arrays of random numbers. */
	double *drand;
	float *frand;
	create_rand_array(&frand, &drand);
	
    benchVec2f(frand);
    benchVec2d(drand);
    benchVec3f(frand);
    benchVec3d(drand); 
	benchVec4f(frand);
	benchVec4d(drand);
	benchMat2f(frand);
	benchMat2d(drand);
	benchMat3f(frand);
	benchMat3d(drand);
	benchMat4f(frand);
	benchMat4d(drand);
	
	free(drand);
	free(frand);
	return 0;
}

/* Helper function impl. */
void benchf(int (*test_fn)(float*), int repeats, char* name, float* rand_array) {
	int i, j;
	long long int sum = 0, minc = 9999999999L;
	volatile long int sumwm = 0;
	double dmsecpc, *results;
	if (!should_run_test(name)) { return; }
	results = malloc(sizeof(double) * test_repeats);
#if _DEBUG
	repeats = repeats / 100;
#endif
	/* Warm up caches, avx or anything... */
	for (i = 0; i < 100; ++i) {
		sumwm += (*test_fn)(rand_array);
	}
	for (j = 0; j < test_repeats; ++j) {
		sum = 0;
		clock_t start = clock(), diff;
		for (i = 0; i < repeats; ++i) {
			sum += (*test_fn)(rand_array);
		}
		diff = clock() - start;
		double sec = (double)diff * 1000. / CLOCKS_PER_SEC;
		dmsecpc = sec / (double)sum;
		results[j] = dmsecpc;
		minc = minc < diff ? minc : diff;
	}
	print_test_res(name, results, minc);
	free(results);
	return;
}

void benchd(int (*test_fn)(double*), int repeats, char* name, double* rand_array) {
	int i, j;
	long long int sum = 0, minc = 9999999999L;
	volatile long int sumwm = 0;
	double dmsecpc, * results;
	if (!should_run_test(name)) { return; }
	results = malloc(sizeof(double) * test_repeats);
#if _DEBUG
	repeats = repeats / 100;
#endif
	/* Warm up caches */
	for (i = 0; i < 10; ++i) {
		sumwm += (*test_fn)(rand_array);
	}
	for (j = 0; j < test_repeats; ++j) {
		sum = 0;
		clock_t start = clock(), diff;
		for (i = 0; i < repeats; ++i) {
			sum += (*test_fn)(rand_array);
		}
		diff = clock() - start;
		double sec = (double)diff * 1000. / CLOCKS_PER_SEC;
		dmsecpc = sec / (double)sum;
		results[j] = dmsecpc;
		minc = minc < diff ? minc : diff;
	}
	print_test_res(name, results, minc);
	free(results);
	return;
}

int parse_command_args(int argc, char* argv[]) {
	char available_types[] = "V2f V3f V4f V2d V3d V4d M2f M3f M4f M2d M3d M4d";
	char available_funcs[] = "abs cross det div dot identity inv minus mmult "
		"mult norm ones plus rotation scale transpose uminus unit vmult zero";

	test_repeats = 1;
	strcpy(test_types, "");
	strcpy(test_funcs, "");

	int i = 1, tmpi;
	int good = 1;
	char tmpc[2048];
	while(argc > i) {
		/* Set the types that are investigated */
		if (!strcmp(argv[i], "-types")) {
			++i;
			for (; i < argc; ++i) {
				if (argv[i][0] == '-') {
					break;
				}
				else if(token_in_string(argv[i], available_types)){
					strcat(test_types, argv[i]);
					strcat(test_types, " ");
				}
				else {
					printf("Unknown type %s. Known types are %s.\n",
						argv[i], available_types);
					good = 0; break;
				}
			}
		}
		/* Set the functions that are run */
		else if (!strcmp(argv[i], "-funcs")) {
			++i;
			for (; i < argc; ++i) {
				if (argv[i][0] == '-') {
					break;
				}
				else if (token_in_string(argv[i], available_funcs)) {
					strcat(test_funcs, argv[i]);
					strcat(test_funcs, " ");
				}
			}
		}
		/* Set the number of repeats of each benchmark */
		else if (!strcmp(argv[i], "-repeats")) {
			++i;
			if(i < argc){
				if (sscanf(argv[i], "%i%1s", &tmpi, tmpc) < 1) {
					good = 0; break;
				}
				test_repeats = tmpi;
				if (test_repeats < 1) {
					printf("Test repeats must be more than 0.");
					good = 0; break;
				}
				++i;
			}
			else { good = 0; break; }
		}
		else {
			good = 0;
			break;
		}
	}

	if (good != 1) {
		printf("Bad arguments!\n"
			"Expecting to see:\n"
			"\tbsv_bench -repeats 7 -types V3f V2f V4f V2d (etc) "
			"-funcs abs unit zero (etc)\n\n");
	}
	return good;
}

int should_run_test(char* name) {
	char* token;
	char workspace[2048];	/* strtok modifies reference string. */
	int yes = 1;
	/* Format: "TYPE FUNC VARIATION" */
	strcpy(workspace, name);
	token = strtok(workspace, " ");
	if (strlen(test_types) > 0) {		/* Nothing means yes automatically */
		if (!token_in_string(token, test_types)) { yes = 0; }
	}
	token = strtok(NULL, " ");
	if (yes && strlen(test_funcs) > 0) {/* Nothing means yes automatically */
		if (!token_in_string(token, test_funcs)) { yes = 0; }
	}
	return yes;
}

int token_in_string(char* token, char* ref_str) {
	int i = 0;
	if (strstr(ref_str, token) != NULL) {
		i = 1;
	}
	return i;
}

void print_test_res(char* name, double* times, long long int mincounts) {
	double min, max, mean;
	int i;
	min = max = mean = times[0];
	for (i = 1; i < test_repeats; ++i) {
		min = min > times[i] ? times[i] : min;
		max = max < times[i] ? times[i] : max;
		mean += times[i];
	}
	mean /= (double)test_repeats;
	printf("%-35s Min: %.3es   Max: %.3es   Mean: %.3es   MinCounts: %lli\n",
		name, min, max, mean, mincounts);
	return;
}

int create_rand_array(float** frand, double** drand) {
	*drand = malloc(sizeof(double) * RAND_ARRAY_LEN);
	*frand = malloc(sizeof(float) * RAND_ARRAY_LEN);
	double dr;
	int i;
	for (i = 0; i < RAND_ARRAY_LEN; ++i) {
		dr = (double)rand() / RAND_MAX * 200.0 - 100.0;
		(*frand)[i] = (float)dr;
		(*drand)[i] = dr;
	}
	return 0;
}
