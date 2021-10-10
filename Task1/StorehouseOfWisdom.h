#ifndef __StorehouseOfWisdom__
#define __StorehouseOfWisdom__

//------------------------------------------------------------------------------
// StorehouseOfWisdom.cpp - содержит процедуры связанные с обработкой 
// oбобщенного артефакта (Кладези мудрости)
// и создания произвольной альтернативы
//------------------------------------------------------------------------------

#include <cstring>
#include "stdio.h"
#include "Saying.h"
#include "Riddle.h"
#include "Aphorism.h"

const int MAX_CONTENT_SIZE = 4096;
const char PUNCTUATION_SYMBOLS[] { ',', '.', ';', '-', ':', '-', '?', '!' };

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся альтернативы (кладези мудрости)
struct StorehouseOfWisdom {
    // значения ключей для каждой из кладезей мудрости
    enum key { RIDDLE, APHORISM, SAYING };
    key k;

	char content[MAX_CONTENT_SIZE];

    // используемые альтернативы
    union { // используем простейшую реализацию
        Riddle& riddle;
        Aphorism& aphorism;
        Saying& saying;
    };
};

// Ввод обобщенной кладези мудрости
StorehouseOfWisdom* In(FILE* file, int k);

// Случайный ввод кладези мудрости
StorehouseOfWisdom* InRnd();

// Вывод обобщенной кладези мудрости
void Out(StorehouseOfWisdom& s, FILE* file);

// Вычисление частного знаков на длину кладези мудрости
double Quotient(StorehouseOfWisdom& s);

#endif