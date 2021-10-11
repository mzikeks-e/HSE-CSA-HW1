//--------------------------------------------------------------------------------------
// StorehouseOfWisdom.cpp - содержит процедуры св€занные с обработкой кладези мудрости
// и создани€ произвольной кладези
//--------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <random.h>
#include "StorehouseOfWisdom.h"

//------------------------------------------------------------------------------
// ¬вод параметров обобщенной фигуры из файла
StorehouseOfWisdom* In(FILE* file, int k) {
    StorehouseOfWisdom* s = new StorehouseOfWisdom;
    char* content = new char[MAX_CONTENT_SIZE];
    fscanf(file, "%s", content);
    s->content = content;

    switch (k) {
    case 0:
        s->k = StorehouseOfWisdom::RIDDLE;
        In(s->Type.riddle_, file);
        return s;
    case 1:
        s->k = StorehouseOfWisdom::APHORISM;
        In(s->Type.aphorism_, file);
        return s;
    case 2:
        s->k = StorehouseOfWisdom::SAYING;
        In(s->Type.saying_, file);
        return s;
    default:
        return 0;
    }
}


// —лучайный ввод обобщенной кладези
StorehouseOfWisdom* InRnd() {
    StorehouseOfWisdom* s = new StorehouseOfWisdom;
    auto type_number = rand() % 3;
    char* content = GenerateContent(rand() % 50);
    s->content = content;

    switch (type_number) {
    case 0:
        s->k = StorehouseOfWisdom::RIDDLE;
        InRnd(s->Type.riddle_);
        return s;
    case 1:
        s->k = StorehouseOfWisdom::APHORISM;
        InRnd(s->Type.aphorism_);
        return s;
    case 2:
        s->k = StorehouseOfWisdom::SAYING;
        InRnd(s->Type.saying_);
        return s;
    default:
        return 0;
    }
}


//------------------------------------------------------------------------------
// ¬ывод параметров кладези в поток
void Out(StorehouseOfWisdom& s, FILE* file) {
    switch (s.k)
    {
    case StorehouseOfWisdom::RIDDLE:
        fprintf(file, "It is Riddle. Question %s. Answer: %s. Quotient = %a", s.content, s.Type.riddle_.answer, Quotient(s));
        break;
    case StorehouseOfWisdom::APHORISM:
        fprintf(file, "It is Aphorism. %s - says %s. Quotient = %a", s.content, s.Type.aphorism_.author, Quotient(s));
        break;
    case StorehouseOfWisdom::SAYING:
        fprintf(file, "It is Saying from . %s - %s. Quotient = %a", s.Type.saying_.country, s.content, Quotient(s));
        break;
    default:
        fprintf(file, "Incorrect Storehouse of Wisdom!");
        break;
    }
}

// ¬ычисление частного знаков на длину кладези мудрости
double Quotient(StorehouseOfWisdom& s) {
    int punctuaton_count = 0;

    for (int i = 0; i < (sizeof(s.content) / sizeof(*s.content)); i++) {
        for (int j = 0; j < (sizeof(PUNCTUATION_SYMBOLS) / sizeof(*PUNCTUATION_SYMBOLS)); j++) {
            if (s.content[i] == PUNCTUATION_SYMBOLS[j]) {
                punctuaton_count++;
                break;
            }
        }
    }

    return punctuaton_count / (double)(sizeof(s.content) / sizeof(*s.content));
}
