#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int* selectionSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);
int* insertionSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);
int* bubbleSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);

void swap(int *arr, int i, int j);

int* generateNonuniformRandomArray(size_t length);
int* generateArrayWithUniformRepetitions(size_t length);
int* generateAlternatingSeriesArray(size_t length);
int* generateNearlySortedArray(size_t length);
int* generateLowVarianceArray(size_t length);

void printTableOnNonuniformGeneratedArray(int* arr, int length);
void printTableOnArrayWithUniformRepetitions(int* arr, int length);
void printTableOnAlternatingSeriesArray(int* arr, int length);
void printTableOnNearlySortedArray(int* arr, int length);
void printTableOnLowVarianceArray(int* arr, int length);

int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[]);
void writeArray(const int *arr, const size_t n);
void swap(int *arr, int i, int j);

void printAnalysis();
void writePurpose();
void generateAndAnalyze();

#endif 