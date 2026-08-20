/*******************************************************************************
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
 * @file course1.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */

#include <stdint.h>
#include <stddef.h>
#include "course1.h"
#include "platform.h"
#include "memory.h"
#include "data.h"
#include "stats.h"
#include <stdlib.h>
#include <stdint.h>
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t count = 0;

    // 1. Handle Negative Numbers
    if (data < 0) {
        *ptr = '-';
        ptr++;
        count++;
        data = -data;
    }

    // Mark where digits begin (after the minus sign, if any)
    uint8_t *first = ptr;

    // 2. Handle Zero Case
    if (data == 0) {
        *ptr = '0';
        ptr++;
        count++;
    }

    // 3. Extract Digits (Written sequentially into ptr)
    while (data > 0) {
        *ptr = baseConvert(data % base, base);
        ptr++;
        count++;
        data /= base;
    }

    // Mark where digits end (one byte back from current ptr)
    uint8_t *last = ptr - 1;

    // 4. Place Null Terminator
    *ptr = '\0';
    count++; // Include '\0' in return length

    // 5. Reverse digits in-place
    while (first < last) {
        uint8_t temp = *first;
        *first = *last;
        *last = temp;

        first++; // Step forward
        last--;  // Step backward
    }

    return count;
} //i answered this myself but used AI at the end to clean it up

    


char baseConvert (uint8_t num,uint32_t base){
   char temp = num % base;
   if(temp>9){
    switch (temp) {
        case 10: temp = 'A'; break;
        case 11: temp = 'B'; break;
        case 12: temp = 'C'; break;
        case 13: temp = 'D'; break;
        case 14: temp = 'E'; break;
        case 15: temp = 'F'; break;
    }
   }
   else{
    temp+= '0';
   }
   return temp;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int is_negative = 0;

    // 1. Check for negative sign
    if (*ptr == '-') {
        is_negative = 1;
        ptr++;
        digits--; // Decrement remaining characters to process
    }

    // 2. Loop through the remaining digit characters
    while (digits > 0 && *ptr != '\0') {
        uint8_t val = 0;

        // Convert ASCII character byte to numerical value
        if (*ptr >= '0' && *ptr <= '9') {
            val = *ptr - '0';
        } else if (*ptr >= 'A' && *ptr <= 'F') {
            val = *ptr - 'A' + 10;
        } else if (*ptr >= 'a' && *ptr <= 'f') {
            val = *ptr - 'a' + 10;
        }

        // Multiply existing result by base and add the new digit
        result = (result * base) + val;

        ptr++;    // Move pointer to next character
        digits--; // Decrement character count
    }

    // 3. Apply negative sign if needed
    if (is_negative) {
        result = -result;
    }

    return result;
} //i answered this myself but used AI at the end to clean it up