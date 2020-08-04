/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file   stats.c
 * @brief  Statistic functions definitions
 *
 * This file contains the definitions of the functions
 * declared in stats.h. These are some functions that compute several statistics
 * on a data set, like average, minimum, maximum.
 *
 * @author Andra Ilie
 * @date   23.07.2020
 *
 */

#include <stdio.h>
#include <limits.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

#ifdef USE_ME
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("\n***Initial data set***\n");
  print_array(test, SIZE);

  printf("\n***Statistics***\n");
  print_statistics(test, SIZE);

  printf("\n***Sorted data set***\n");
  print_array(test, SIZE);
}
#endif

void print_statistics(unsigned char *data, unsigned int size) {

	PRINTF(" - Minimum value: %d\n", find_minimum(data, size));
	PRINTF(" - Maximum value: %d\n", find_maximum(data, size));
	PRINTF(" - Mean value: %d\n", find_mean(data, size));
	PRINTF(" - Median value: %d\n", find_median(data, size));
}

void print_array(unsigned char *data, unsigned int size) {

#ifdef VERBOSE
	PRINTF("[");
	for (int i = 0; i < size - 1; i++) {
		PRINTF("%d, ", data[i]);
	}
	
	PRINTF("%d]\n", data[size - 1]);	
#endif
}

unsigned char find_median(unsigned char *data, unsigned int size) {
	
	sort_array(data, SIZE);
	return (SIZE % 2) ? data[SIZE/2 + 1] : find_mean(data + SIZE/2 - 1, 2);
}


unsigned char find_mean(unsigned char *data, unsigned int size) {
	
	unsigned int sum = 0;
	for (int i = 0; i < size; i++)
		sum += data[i];

	return sum/size;
}

unsigned char find_maximum(unsigned char *data, unsigned int size) {
	
	unsigned char max_value = 0;
	
	for (int i = 0; i < size; i++) {
		if (data[i] > max_value)
			max_value = data[i];	
	}

	return max_value;
}

unsigned char find_minimum(unsigned char *data, unsigned int size) {
	
	unsigned char min_value = UCHAR_MAX;
	
	for (int i = 0; i < size; i++) {
		if (data[i] < min_value)
			min_value = data[i];	
	}

	return min_value;
}

/* Gets position of maximum element from a "slice" of the initial array */
unsigned int get_max_position(unsigned char *start, unsigned char *end) {
	
	unsigned char max_value = 0;
	unsigned int max_offset = 0;
	unsigned char *element = start;

	while (element <= end) {
		if (*element >= max_value) {
			max_value = *element;
			max_offset = element - start;
		}
		element++;
	}

	return max_offset;
}

void swap(unsigned char *a, unsigned char *b) {

	unsigned char tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Find the minimal elements and swap them to their corresponding final positions*/
void sort_array(unsigned char *data, const unsigned int size) {
	
	// selection sort
	unsigned int position = 0;

	for (unsigned int i = 0; i < size - 1; i++) {
		position = get_max_position(data + i, data + size - 1) + i;
		if (position != i) {
			swap(&data[i], &data[position]);
		}
	}
}