#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// Переменные:
#define x 11
#define k 4
#define s 19

// Функции:
void fillArray(int** arr, size_t* n);
void writeArray(const int arr[], const size_t n);

void analyze(const int* arr, size_t n, int* min, int* max, long long* sum);
void filter(int** arr, size_t* n);
int maxSequentially(const int arr[], const size_t n);
int minSequentially(const int *a, size_t n);
void sort(int** arr, size_t n);

void output1(int* arr, size_t n);
void output2(int** arr, size_t* n);
void output3(int* arr, size_t n);
void output4(int* arr, size_t n);
void output5(int** arr, size_t* n);
void printMy();

#endif  