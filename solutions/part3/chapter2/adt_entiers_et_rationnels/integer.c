#include "integer.h"
#include <stdio.h>

Integer integer_new(const char* string) {
	bool sign =  !(string[0] == '-');
	Integer n = integer_new_b256(2, NULL, POSITIVE);

	Integer tmp = integer_new_b256(2, NULL, POSITIVE);
	uint32_t len = 0;
	while (*(string + len++));
	for (unsigned int i = !sign; i < len-1; i++) {
		if (string[i] != ' ') {
			tmp.weights[0] = 10;
			integer_mulm(&n, tmp);
			tmp.weights[0] = string[i] - 0x30; // chiffres ASCII entre 0x30 et 0x39
			integer_uaddm(&n, tmp);
		}

	}
	integer_destroy(tmp);
	n.sign = sign;
	return n;
}

Integer integer_new_b256(unsigned int length, uint8_t weights[], bool sign) {
	Integer i;
	i.length = length;
	i.weights = (uint8_t*)malloc(sizeof(uint8_t)*length);
	for (uint32_t c = 0; c < length; c++) {
		i.weights[length - c - 1] = (weights != NULL) ? weights[c] : 0;
	}
	i.sign = sign;
	return i;
}

Integer integer_copy(Integer i) {
	Integer j;
	j.length = i.length;
	j.weights = (uint8_t*)malloc(sizeof(uint8_t)*i.length);
	for (unsigned c = 0; c < i.length; c++) {
		j.weights[c] = i.weights[c];
	}
	j.sign = i.sign;
	return j;
}

void integer_set_bitm(Integer *n, uint32_t i, bool value) {
	uint32_t c = i / P;
	uint32_t b = i % P;

	if (value && c + 1 >= n->length) {
		uint8_t *weights = (uint8_t*)malloc(sizeof(uint8_t)*(c + 2));
		for (uint32_t j = 0; j < c+2; j++) {
			weights[j] = (j >= n->length) ? 0 : n->weights[j];
		}
		free(n->weights);
		n->weights = weights;
		n->length = c + 2;
	}
	n->weights[c] = (value) ? (n->weights[c] | (1 << b)) : (n->weights[c] & ((int8_t)(-1) ^ (1 << b)));
}

bool integer_test_bit(Integer n, uint32_t i) {
	uint32_t c = i / P;
	uint32_t b = i % P;
	if (c >= n.length) {
		return 0;
	}
	return (n.weights[c] >> b) & 1; 
}

Integer integer_sl(Integer n, uint32_t k) {
	uint32_t d = k / P;
	uint32_t s = k % P;
	uint32_t nl = integer_length(n);
	Integer m = integer_new_b256(d + nl + 2, NULL, n.sign);
	for (uint32_t i = nl-1; i + 1 > 0; i--) {
		m.weights[i + d + 1] = m.weights[i + d + 1] ^ (n.weights[i] >> (P - s));
		m.weights[i + d] = n.weights[i] << s;
	}
	return m;
}

void integer_slm(Integer *n, uint32_t k) {
	uint32_t d = k / P;
	uint32_t s = k % P;
	uint32_t nl = integer_length(*n);
	Integer m = integer_new_b256(d + nl + 2, NULL, n->sign);
	for (uint32_t i = nl-1; i + 1 > 0; i--) {
		m.weights[i + d + 1] = m.weights[i + d + 1] ^ (n->weights[i] >> (P - s));
		m.weights[i + d] = n->weights[i] << s;
	}
	free(n->weights);
	n->weights = m.weights;
	n->length = m.length;
}

Integer integer_sub(Integer a, Integer b) {
	b.sign = !b.sign;
	return integer_add(a, b);
}

void integer_destroy(Integer i) {
	free(i.weights);
}

uint32_t integer_length(Integer n) {
	for (uint32_t i = n.length - 1; i + 1 > 0; i--) {
		if (n.weights[i] != 0) {
			return i + 1;
		}
	}
	return 0;
}

int integer_ucmp(Integer a, Integer b) {
	uint32_t al = integer_length(a);
	uint32_t bl = integer_length(b);
	unsigned int i = (bl > al) ? (bl - 1) : (al - 1);
	if (bl > al) {
		for (; i >= al; i--) {
			if (b.weights[i] > 0) {
				return -1;
			}
		}
	}
	if (bl < al) {
		for (; i >= bl; i--) {
			if (a.weights[i] > 0) {
				return 1;
			}
		}
	}
	// al == bl
	for (; i >= 0 && i < bl; i++) {
		if (a.weights[i] > b.weights[i]) {
			return 1;
		}
		if (a.weights[i] < b.weights[i]) {
			return -1;
		}
	}
	return 0;
}

int integer_cmp(Integer a, Integer b) {
	if (a.sign != b.sign) {
		return a.sign - b.sign;
	}
	int c = integer_ucmp(a, b);
	return (a.sign == NEGATIVE) ? (-c) : c; // négatif inverse le sens de l'inégalité
}

Integer integer_uadd(Integer a, Integer b) {
	// calcul du nombre réel de cases utilisés permet d'éviter l'explosion spatiale par additions successives
	uint32_t al = integer_length(a);
	uint32_t bl = integer_length(b);
	uint32_t minl = (((al < bl) ? al : bl));
	uint32_t maxl = (((al > bl) ? al : bl));
	Integer sum = integer_new_b256(maxl+2, NULL, POSITIVE);
	uint32_t r = 0;
	uint32_t i = 0;
	for (; i <= minl; i++) {
		sum.weights[i] = (a.weights[i] + b.weights[i] + r) % BASE;
		r = (a.weights[i] + b.weights[i] + r) / BASE;
	}
	for (; i < maxl; i++) {
		int16_t b_value = (maxl == bl ? b.weights[i] : 0);
		int16_t a_value = (maxl == al ? a.weights[i] : 0);
			
		sum.weights[i] = (a_value + b_value + r) % (1 << P);
		r = (a_value + b_value + r) / (1 << P);
	}
	return sum;
}

Integer integer_uaddm(Integer *a, Integer b) {
	// calcul du nombre réel de cases utilisés permet d'éviter l'explosion spatiale par additions successives
	uint32_t al = integer_length(*a);
	uint32_t bl = integer_length(b);
	uint32_t minl = (((al < bl) ? al : bl));
	uint32_t maxl = (((al > bl) ? al : bl));
	uint8_t *weights = malloc(sizeof(uint8_t) * (maxl + 2));
	for (unsigned int i = 0; i < (maxl + 2); i++) {
		weights[i] = 0;
	}
	uint32_t r = 0;
	uint32_t i = 0;
	for (; i <= minl; i++) {
		weights[i] = (a->weights[i] + b.weights[i] + r) % (1 << P);
		r = (a->weights[i] + b.weights[i] + r) / (1 << P);
	}
	for (; i < maxl; i++) {
		int16_t b_value = (maxl == bl ? b.weights[i] : 0);
		int16_t a_value = (maxl == al ? a->weights[i] : 0);

		weights[i] = (a_value + b_value + r) % (1 << P);
		r = (a_value + b_value + r) / (1 << P);
	}
	free(a->weights);
	a->weights = weights;
	a->length = maxl + 2;
	a->sign = POSITIVE;
}

// on suppose |a| > |b|
Integer integer_usub(Integer a, Integer b) {
	int16_t* weights = (int16_t*)malloc(sizeof(int16_t) * a.length);

	for (unsigned int i = a.length - 1; i+1 > 0; i--) {
		weights[i] = (i >= b.length) ? (int16_t)(a.weights[i]) : ((int16_t)a.weights[i] - (int16_t)b.weights[i]);
		// on assure que tous les coefficients sont positifs
		for (unsigned int j = i; weights[j] < 0; j++) {
			weights[j] += BASE;
			weights[j+1]--;
		}
	}
	Integer r = integer_new_b256(a.length, NULL, POSITIVE);
	for (unsigned int i = 0; i < a.length; i++) {
		r.weights[i] = (uint8_t)weights[i];
	}
	free(weights);
	return r;
}

// calcul c = a + b
Integer integer_add(Integer a, Integer b) {
	if (a.sign == b.sign) {
		Integer r = integer_uadd(a, b);
		r.sign = a.sign;
		return r;
	}

	Integer r;
	if (a.sign > b.sign) { // => a >= b car POSITIVE = 1 et NEGATIVE = 0
		if (integer_ucmp(a, b) == 1) { // |a| > |b|
			r = integer_usub(a, b);
			r.sign = POSITIVE;
		} else { // |a| <= |b| et b - a <= 0
			r = integer_usub(b, a);
			r.sign = NEGATIVE;
		}
	} else { // b > a
		if (integer_ucmp(b, a) == 1) { // |b| > |a|
			r = integer_usub(b, a);
			r.sign = POSITIVE;
		} else {
			r = integer_usub(a, b);
			r.sign = NEGATIVE;
		}
	}

	return r;
}

void integer_usubml(Integer *a, Integer b) { // on suppose |a| >= |b|
	uint32_t al = integer_length(*a); // al >= bl avec a.weights[al-1] >= b.weights[al-1]
	int16_t* weights = (int16_t*)malloc(sizeof(int16_t) * al);

	for (unsigned int i = al - 1; i+1 > 0; i--) {
		weights[i] = (i >= b.length) ? (uint16_t)(a->weights[i]) : ((int16_t)a->weights[i] - (int16_t)b.weights[i]);
		// on assure que tous les coefficients sont positifs
		for (unsigned int j = i; weights[j] < 0; j++) {
			weights[j] += BASE;
			weights[j+1]--;
		}
	}
	for (unsigned int i = 0; i < al; i++) {
		a->weights[i] = (uint8_t)weights[i];
	}
	a->sign = POSITIVE;
	free(weights);
}

void integer_usubmr(Integer a, Integer *b) {
	int16_t* weights = (int16_t*)malloc(sizeof(int16_t) * a.length);

	for (unsigned int i = a.length - 1; i+1 > 0; i--) {
		weights[i] = (i >= b->length) ? (uint16_t)(a.weights[i]) : ((int16_t)a.weights[i] - (int16_t)b->weights[i]);
		// on assure que tous les coefficients sont positifs
		for (unsigned int j = i; weights[j] < 0; j++) {
			weights[j] += BASE;
			weights[j+1]--;
		}
	}
	free(b->weights);
	b->weights = (int8_t*)malloc(sizeof(int8_t) * a.length);
	b->sign = NEGATIVE;
	b->length = a.length;
	for (unsigned int i = 0; i < a.length; i++) {
		b->weights[i] = (uint8_t)weights[i];
	}
	free(weights);
}

// calcul a = a + b
void integer_addm(Integer *a, Integer b) {
	if (a->sign == b.sign) {
		integer_uaddm(a, b);
		a->sign = b.sign;
		return;
	}

	if (a->sign > b.sign) {
		if (integer_ucmp(*a, b) == 1) { // |a| > |b|
			integer_usubml(a, b); // a = |a| - |b|
			a->sign = POSITIVE;
		} else {
			integer_usubmr(b, a); // |b| >= |a| et b - a <= 0
			a->sign = NEGATIVE;
		}
	} else { // a < 0, b > 0, a + b = b - |a| = |b| - |a|
		if (integer_ucmp(b, *a) == 1) { // |b| > |a|
			integer_usubmr(b, a);
			a->sign = POSITIVE;
		} else { // |a| > |b|
			integer_usubml(a, b); // a + b = -(|a| - |b|)
			a->sign = NEGATIVE;
		}
	}
}

void integer_subm(Integer *a, Integer b) {
	b.sign = !b.sign;
	integer_addm(a, b);
}

Integer integer_inverse(Integer n) {
	n.sign = !n.sign;
	return n;
}

Integer integer_mul(Integer a, Integer b) {
	bool sign = !(a.sign ^ b.sign);
	Integer p = integer_new_b256(1, NULL, POSITIVE);
	a.sign = b.sign = POSITIVE;
	if (a.length > b.length) {
		for (unsigned int j = 0; j < b.length * P; j++) {
			if (integer_test_bit(b, j)) {
				Integer shifted = integer_sl(a, j);
				integer_uaddm(&p, shifted);
				integer_destroy(shifted);
			}
		}
	} else {
		for (unsigned int j = 0; j < a.length * P; j++) {
			if (integer_test_bit(a, j)) {
				Integer shifted = integer_sl(b, j);
				integer_uaddm(&p, shifted);
				integer_destroy(shifted);
			}
		}
	}
	p.sign = sign;
	return p;
}

void integer_mulm(Integer *a, Integer b) {
	bool sign = !(a->sign ^ b.sign);
	Integer p = integer_new_b256(2, NULL, POSITIVE);
	a->sign = POSITIVE;
	b.sign = POSITIVE;
	if (a->length > b.length) {
		for (unsigned int j = 0; j < b.length * P; j++) {
			if (integer_test_bit(b, j)) {
				Integer shifted = integer_sl(*a, j);
				integer_uaddm(&p, shifted);
				integer_destroy(shifted);
			}
		}
	} else {
		for (unsigned int j = 0; j < a->length * P; j++) {
			if (integer_test_bit(*a, j)) {
				Integer shifted = integer_sl(b, j);
				integer_uaddm(&p, shifted);
				integer_destroy(shifted);
			}
		}
	}
	free(a->weights);
	a->weights = p.weights;
	a->length = p.length;
	a->sign = sign;
}


bool integer_is_zero(Integer n) {
	for (unsigned int i = 0; i < n.length; i++) {
		if (n.weights[i] != 0) {
			return false;
		}
	}
	return true;
}

void integer_div(Integer n, Integer d, Integer *q, Integer *r) {
	if (integer_is_zero(d)) {
		int* z = NULL;
		z[0] = 0;
	}
	uint32_t l = integer_length(n);

	*q = integer_new_b256(2, NULL, !(n.sign ^ d.sign));
	*r = integer_new_b256(2, NULL, POSITIVE);
	for (unsigned int i = l * P - 1; i + 1 > 0; i--) {
		integer_slm(r, 1);
		integer_set_bitm(r, 0, integer_test_bit(n, i));
		if (integer_ucmp(*r, d) >= 0) {
			integer_usubml(r, d);
			integer_set_bitm(q, i, 1);
		}
	}
	if (integer_ucmp(*r, d) >= 0) {
		Integer un = integer_new_b256(2, (uint8_t[]){0, 1}, POSITIVE);
		integer_usubml(r, d);
		integer_uaddm(q, un);
	}
}

void integer_display_b256(Integer n, char* buffer) {
	if (n.sign == NEGATIVE) {
		buffer += sprintf(buffer, "-(");
	}
	buffer += sprintf(buffer, "%u", n.weights[0]);
	for (unsigned int p = 1; p < n.length; p++) {
		buffer += sprintf(buffer, " + %u * (%u**%u)", n.weights[p], BASE, p);
	}
	if (n.sign == NEGATIVE) {
		buffer += sprintf(buffer, ")");
	}
	*buffer = 0;
}

void integer_display(Integer n, char* buffer) {
	if (integer_is_zero(n)) {
		*buffer++ = 0x30;
		*buffer = 0;
		return;
	}
	if (n.sign == NEGATIVE) {
		*buffer++ = '-';
	}
	char *start = buffer;
	Integer dix = integer_new_b256(1, (uint8_t[]){10}, POSITIVE);
	Integer q;
	Integer r;
	while (!integer_is_zero(n)) {
		integer_div(n, dix, &q, &r);
		*buffer++ = (r.weights[0] % 10) + 0x30;
		n = integer_copy(q);
		integer_destroy(q);
	}
	integer_destroy(n);
	*buffer-- = 0;
	while (start < buffer) {
		char tmp = *start;
		*start = *buffer;
		*buffer = tmp;
		start++;
		buffer--;
	}
}