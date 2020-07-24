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
 * @file   stats.h
 * @brief  Header file containing the declarations of several statistical
 * functions.
 *
 * @author Andra Ilie
 * @date   23.07.2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__ 

/**
 * @brief Prints statistics about a set of numbers
 *
 * A function that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 */
void print_statistics(unsigned char *data, unsigned int size);

/**
 * @brief Prints an array to the screen
 *
 * A function that receives a data set and a length and prints
 * the data to the screen.
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 */
void print_array(unsigned char *data, unsigned int size);

/**
 * @brief Computes median value of a data set
 *
 * A function that receives a data set and a length and computes
 * the median value of the array, which is the middle value separating
 * the lower and the upper half. If there is an even number of items 
 * in the data set, then the median is found by taking the mean 
 * of the two middlemost numbers
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 * @return The median value of numbers provided
 */
unsigned char find_median(unsigned char *data, unsigned int size);

/**
 * @brief Computes mean value of a data set
 *
 * A function that receives a data set and a length and computes
 * the arithmetic mean value of data.
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 * @return The mean value of numbers provided
 */
unsigned char find_mean(unsigned char *data, unsigned int size);

/**
 * @brief Computes maximum value of a data set
 *
 * A function that receives a data set and a length and computes
 * the maximum value of the array.
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 * @return Maximum value of the numbers provided
 */
unsigned char find_maximum(unsigned char *data, unsigned int size);

/**
 * @brief Computes minimum value of a data set
 *
 * A function that receives a data set and a length and computes
 * the minimum value of the array.
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 * @return Minimum value of the numbers provided
 */
unsigned char find_minimum(unsigned char *data, unsigned int size);

/**
 * @brief Sorts an array in descendent order
 *
 * Given an array of data and a length, sorts the array from largest to smallest,
 * using selection sort.
 *
 * @param data Pointer to a data set
 * @param size Number of elements in data set
 *
 */
void sort_array(unsigned char *data, unsigned int size);

#endif /* __STATS_H__ */
