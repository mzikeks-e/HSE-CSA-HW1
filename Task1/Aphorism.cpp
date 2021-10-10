//------------------------------------------------------------------------------
// Aphorism.cpp - содержит процедуры для работы с афоризмами
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "Aphorism.h"

//------------------------------------------------------------------------------
// Ввод параметров афоризма из потока
void In(Aphorism& a, FILE* file) {
    fscanf(file, "%s", &a.author);
}

// Случайный ввод параметров афоризма
void InRnd(Aphorism& a) {
    a.author = GenerateContent(Random(15));
}

//------------------------------------------------------------------------------
// Вывод параметров афоризма в поток
void Out(Aphorism& a, FILE* file) {
    fprintf(file, "It is Aphorism. %s - says %s. Quotient = %a", a.content, a.author, Quotient(a));
}

