#ifndef GLIBC_FPDEBUG_H
#define GLIBC_FPDEBUG_H

#include "/home/shijia/Public/fpdebug-valgrind-3.12/valgrind/fpdebug/fpdebug.h"
#include <stdio.h>
#include <stdlib.h>

static inline int reduceSeqs[1000];
static inline int seqCount;

static inline void setReducePrecSeq(int n) {
	reduceSeqs[seqCount] = n;
	seqCount++;
	if (seqCount == 1000) {
		seqCount = 0;
        printf("Reduce sequence limit exceed!");
	}
}

static inline void getFpdebugSeq() {
	int input;
    seqCount = 0;
//	while(1) {
//		scanf("%d", &input);
//		if (input == -1) break;
//		setReducePrecSeq(input);
//	}
}

static inline void clearFpdebugSeq() {
	seqCount = 0;
}

static inline void printReducePrecSeq() {
	int i;
	for(; i < seqCount; i++) {
		printf("%d\n", reduceSeqs[i]);
	}
}

static inline void computeErrd(const char * name, double * var, int n) {
	VALGRIND_PRINT_ERROR(name, var);
}

static inline void computeErrf(const char * name, float * var, int n) {
	VALGRIND_PRINT_ERROR(name, var);
}

static inline void computeErrl(const char * name, long double * var, int n) {
	VALGRIND_PRINT_ERROR(name, var);
}

static inline int seqContains(int n) {
	int i = 0;
	for(; i < seqCount; i++) {
		if (reduceSeqs[i] == n) return 1;
	}
	return 0;
}

static inline void reducePrecd(double * var, int n) {
	setReducePrecSeq(n); 
	if (seqContains(n)) {
		VALGRIND_INSERT_SHADOW(var);
		printf("reduce at %d\n", n);
	}
}

static inline void reducePrecf(float * var, int n) {
	setReducePrecSeq(n);
	if (seqContains(n)) {
		VALGRIND_INSERT_SHADOW(var);
		printf("reduce at %d\n", n);
	}
}

static inline void reducePrecl(long double * var, int n) {
	setReducePrecSeq(n);
	if (seqContains(n)) {
		VALGRIND_INSERT_SHADOW(var);
		printf("reduce at %d\n", n);
	}
}

static inline void resumePrecd(double * var, int n) {
	if (seqContains(n)) {
		VALGRIND_ORIGINAL_TO_SHADOW(var);
		printf("resume at %d\n", n);
	}
}

static inline void resumePrecf(float * var, int n) {
	if (seqContains(n)) {
		VALGRIND_ORIGINAL_TO_SHADOW(var);
		printf("resume at %d\n", n);
	}
}

static inline void resumePrecl(long double * var, int n) {
	if (seqContains(n)) {
		VALGRIND_ORIGINAL_TO_SHADOW(var);
		printf("resume at %d\n", n);
	}
}

static inline void FPshadowToOriginal(double * var, int n) {
	if (seqContains(n)) {
		VALGRIND_SHADOW_TO_ORIGINAL(var);
	}
}

static inline void FPoriginalToShadow(double * var, int n) {
	if (seqContains(n)) {
		VALGRIND_ORIGINAL_TO_SHADOW(var);
	}
}

static inline void FPsetOriginal(double * var, double * value, int n) {
	if (seqContains(n)) {
		VALGRIND_SET_ORIGINAL(var, value);
	}
}

static inline void FPsetShadow(double * var, double * value, int n) {
	if (seqContains(n)) {
		VALGRIND_SET_SHADOW_BY(var, value);
	}
}
#endif
