#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BASE 256
#define P 8
#define BASE_T uint8_t

typedef enum Sign {
	NEGATIVE,
	POSITIVE
} Sign;

#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
#define MIN(X, Y) (((X) > (Y)) ? (Y) : (X))

typedef struct Integer {
	BASE_T *weights;
	uint32_t length;
	bool sign;
} Integer;

Integer integer_new_b256(unsigned int length, uint8_t weights[], bool sign);
void integer_display_b256(Integer n, char* buffer);

Integer integer_inverse(Integer n);
void integer_destroy(Integer i);
Integer integer_copy(Integer i);
uint32_t integer_length(Integer i); // taille du tableau *réellement* nécessaire

// unsigned cmp
int integer_ucmp(Integer a, Integer b); // 0 <=> a = b, -1 <=> a < b, 1 <=> a > b
// signed cmp
int integer_cmp(Integer a, Integer b); // 0 <=> a = b, -1 <=> a < b, 1 <=> a > b
bool integer_is_zero(Integer n);

void integer_set_bitm(Integer *n, uint32_t i, bool value);
bool integer_test_bit(Integer n, uint32_t i);
Integer integer_sl(Integer i, uint32_t k);
void integer_slm(Integer *i, uint32_t k);
Integer integer_usub(Integer a, Integer b); // (|a| > |b|)
Integer integer_uadd(Integer a, Integer b);
Integer integer_add(Integer a, Integer b);
Integer integer_sub(Integer a, Integer b);
Integer integer_uaddm(Integer *a, Integer b);
// void integer_usubml(Integer *a, Integer b); // a <- a - b
// void integer_usubmr(Integer a, Integer *b); // b <- b - a
void integer_addm(Integer *a, Integer b);
void integer_subm(Integer *a, Integer b);
Integer integer_mul(Integer a, Integer b);
void integer_mulm(Integer *a, Integer b);

void integer_div(Integer n, Integer d, Integer *q, Integer *r);
void integer_display(Integer n, char* buffer);
Integer integer_new(const char* string);

#endif