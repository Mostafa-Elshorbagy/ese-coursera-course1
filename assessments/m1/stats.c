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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {
printf("testing111\n");
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

print_array(test, SIZE);
printf("\n***********************************************\n");
sort_array(test, SIZE);
print_array(test, SIZE);
printf("\n***********************************************\n");
print_statistics(test, SIZE);

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}
void print_array (unsigned char arr[], int size) {
  printf("[");
  for(int i=0; i<size; i++){
    if(i == size-1){
      printf("%d]",arr[i]);
      break;
    }
    else{
    printf("%d, ",arr[i]);
    }
  }
}

/* Add other Implementation File Code Here */
void sort_array(unsigned char arr[], int size){
  int temp;
  for(int i=0;i<size;i++){
    int champ=i;
      for(int j=i;j<size;j++){
        if(arr[champ]<arr[j]){
          champ=j;
        }
      }
      temp = arr[i];
      arr[i] = arr[champ];
      arr[champ] = temp;
  }
}

unsigned char find_minimum (unsigned char arr[], int size){
  int champ = 0;
  for(int i=1;i<size;i++){
    if (arr[champ]> arr[i]){
      champ = i;
    }
  }
  return arr[champ];
}
unsigned char find_maximum (unsigned char arr[], int size){
  int champ = 0;
  for(int i=1;i<size;i++){
    if (arr[champ]< arr[i]){
      champ = i;
    }
  }
  return arr[champ];
}
unsigned char find_mean (unsigned char arr[], int size){
  int sum = 0;
  for(int i=0;i<size;i++){
    sum+= arr[i];
  }
  return sum/size;
}

unsigned char find_median (unsigned char arr[], int size){
  sort_array(arr, size);
  if (size%2==0){
    char M1 = arr[size/2];
    char M2 = arr[size/2 +1];
    return (M1 + M2)/2;
  }
  else{
    return arr[size/2];
  }
}

 void print_statistics (unsigned char arr[], int size){

printf("Max:%d",find_maximum(arr, size));
printf("\n***********************************************\n");
printf("Min:%d",find_minimum(arr, size));
printf("\n***********************************************\n");
printf("Mean:%d",find_mean(arr, size));
printf("\n***********************************************\n");
printf("Median:%d",find_median(arr, size));
 }

