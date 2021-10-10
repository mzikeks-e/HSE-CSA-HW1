//------------------------------------------------------------------------------
// Riddle.cpp - содержит процедуры для работы с загадками
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "Riddle.h"

//------------------------------------------------------------------------------
// Ввод параметров загадки из потока
void In(Riddle& r, FILE* file) {
    fscanf(file, "%s", &r.answer);
}

// Случайный ввод параметров загадки
void InRnd(Riddle& r) {
    r.answer = GenerateContent(Random(10));
}

//------------------------------------------------------------------------------
// Вывод параметров загадки в поток
void Out(Riddle& r, FILE* file) {
    fprintf(file, "It is Riddle. Question %s. Answer: %s. Quotient = %a", r.content, r.answer, Quotient(r));
}

