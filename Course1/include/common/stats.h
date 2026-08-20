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
 * @file stats.h
 * @brief Declaration File for functionality and definitions of all functions used in stats.c file
 *
 * <Add Extended Description Here>
 *
 * @author Mostafa Elshorbagy
 * @date 24/7/2026
 *
 */

#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>
#include <stddef.h>
/* Add Your Declarations and Function Comments here */ 






void print_array (unsigned char arr[], int size);
/**
 * @brief prints given array
 *
 * Loops through the array printing every element is passes by
 *
 * @param arr  unsigned character array to be printed
 * @param size size of array
 *
 * @return function does not return anything but rather prints onto the output directly
 */

void sort_array(unsigned char arr[], int size);
/**
 * @brief sorts given array
 *
 * Loops through the array and places current element into its correct location at the end of iteration. (Insertion Sort)
 *
 * @param arr  unsigned character array to be sorted
 * @param size size of array
 *
 * @return function does not return anything but rather alters the array given to it
 */
 void print_statistics (unsigned char arr[], int size);

 /**
 * @brief prints data of given array
 *
 * Provides Minimum, Maximum, Mean, and Median of given array
 *
 * @param arr  unsigned character array to be shown data of
 * @param size size of array
 *
 * @return function does not return anything but rather prints data onto the output directly
 */

unsigned char find_minimum (unsigned char arr[], int size);
 /**
 * @brief returns minimum of array
 *
 * Loops through the array comparing each element with the current smallest until it reaches the end and returns the smallest of the entire set
 *
 * @param arr  unsigned character array to extract from
 * @param size size of array
 *
 * @return returns smallest char within array
 */

unsigned char find_maximum (unsigned char arr[], int size);
/**
 * @brief returns maximum of array
 *
 * Loops through the array comparing each element with the current largest until it reaches the end and returns the largest of the entire set
 *
 * @param arr  unsigned character array to extract from
 * @param size size of array
 *
 * @return returns largest char within array
 */


unsigned char find_mean (unsigned char arr[], int size);


 /**
 * @brief returns average of array
 *
 * Loops through the array adding each element together then finally dividing with the size of the array
 *
 * @param arr  unsigned character array to extract from
 * @param size size of array
 *
 * @return returns average of all characters within array
 */


unsigned char find_median (unsigned char arr[], int size);

 /**
 * @brief returns median of array
 *
 * if odd then returns element located in the middle of the entire array, if even then returns the average of the two middle elements
 *
 * @param arr  unsigned character array to extract from
 * @param size size of array
 *
 * @return returns middle char within array
 */

#endif /* __STATS_H__ */
