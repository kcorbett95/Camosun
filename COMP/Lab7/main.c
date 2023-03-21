
/* 
 * File:   main.c
 * Author: C0527059
 *
 * Created on March 14, 2023, 8:51 a.m.
 */


#include "pointers.h"

int main() {
    WORD nums[N_NUMS];
    for (int i = 0; i < N_NUMS; i++) {
        nums[i] = START + i;
    }

    printf("Original Vector:\n");
    printVector(nums, N_NUMS);

    for (int i = 0; i < N_NUMS - 1; i += 2) {
        swap(nums+i, nums+i+1);
    }
    printf("Adjacent words swapped:\n");
    printVector(nums, N_NUMS);

    for (int i = 0; i < N_NUMS - 1; i += 2) {
        swap(&nums[i], &nums[i + 1]);
    }
    printf("Words swapped back:\n");
    printVector(nums, N_NUMS);

    printf("Data Bytes:\n");
    printBytes(nums, N_NUMS);

    printf("Word bytes with endian reversal:\n");
    printBytesReverseEndian(nums, N_NUMS);

    return 0;
}

/* Swap the two values pointed at by x and y (no loop here) */
void swap(WORD *x, WORD *y) {
    WORD temp = *x;
    *x = *y;
    *y = temp;
}

/* Print all of the values in a 1-D array where the array size is N
 * and WORD_FORMAT has been #define'd */
void printVector(const WORD *vec, const int N) {
    for (int i = 0; i < N; i++) {
        printf(WORD_FORMAT, *vec++);
    }
    printf("\n");
}

/* Print all of the values in a 1-D array one byte at a time where the
 * array size is N.
 * Prints an extra space after each word */
void printBytes(const WORD *vec, const int N) {
    for (int k = 0; k < N; k++) {
        const unsigned char *p = (const unsigned char *) (vec+k);
        for (int i = 0; i < sizeof (WORD); i++) {
            printf("%d ", *(p++));
        }
        printf("  ");
    }
    printf("\n");
}

/* Print all of the values in a 1-D array one byte at a time in reverse
 * byte order for each word where the array size is N.
 * Prints an extra space after each word */
void printBytesReverseEndian(const WORD *vec, const int N) {
    for (int k = 0; k < N; k++) {
        const unsigned char *p = (const unsigned char *) (vec+k+1);
        for (int i = 0; i < sizeof (WORD); i++) {
            printf("%d ", *(--p));
        }
        printf("  ");
    }
    printf("\n");
}

