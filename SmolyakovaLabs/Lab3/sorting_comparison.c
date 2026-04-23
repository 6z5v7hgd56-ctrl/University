#include "algorithms.h"

// 20 массив из случайных чисел с неравномерным распределением
// 31 массив с равномерно распределёнными повторениями
// 28 массив с чередующимися возрастающими и убывающими сериями
// 6 почти отсортированный массив (несколько элементов переставлены)
// 44 массив, где каждый следующий элемент отличается на небольшую величину

// Элементы массива в диапазоне от 0..10000

// ! Автоматически считать анализ и сделать таблицы для 50, 100, 500 и 1000 элементов
// Анализ алгоритмов
//// Поправить вывод




int main(void) // Вариант 20
{
    int length;
    int *genArrNRA, *genArrAWUR, *genArrASA, *genArrNSA, *genArrLVA;

    length = 0;

    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    writePurpose();

    length = scanInt(1, 1000, "Введите длину: ");

    genArrNRA = generateNonuniformRandomArray(length);
    genArrAWUR = generateArrayWithUniformRepetitions(length);
    genArrASA = generateAlternatingSeriesArray(length);
    genArrNSA = generateNearlySortedArray(length);
    genArrLVA = generateLowVarianceArray(length);

    printTableOnNonuniformGeneratedArray(genArrNRA, length);
    printTableOnArrayWithUniformRepetitions(genArrAWUR, length);
    printTableOnAlternatingSeriesArray(genArrASA, length);
    printTableOnNearlySortedArray(genArrNSA, length);
    printTableOnLowVarianceArray(genArrLVA, length);

    generateAndAnalyze();

    free(genArrNRA);
    free(genArrAWUR);
    free(genArrASA);
    free(genArrNSA);
    free(genArrLVA);
    
    return 0;
}



