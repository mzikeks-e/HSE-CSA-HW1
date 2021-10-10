//--------------------------------------------------------------------------------------
// StorehouseOfWisdom.cpp - содержит процедуры св€занные с обработкой кладези мудрости
// и создани€ произвольной кладези
//--------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "random.h"
#include "StorehouseOfWisdom.h"

//------------------------------------------------------------------------------
// ¬вод параметров обобщенной фигуры из файла
StorehouseOfWisdom* In(FILE* file, int k) {
    StorehouseOfWisdom* s = new StorehouseOfWisdom;
    char content;
    fscanf(file, "%s", &content);
    s->content = content;

    switch (k) {
    case 0:
        s->k = StorehouseOfWisdom::RIDDLE;
        In(s->riddle, file);
        return s;
    case 1:
        s->k = StorehouseOfWisdom::APHORISM;
        In(s->aphorism, file);
        return s;
    case 2:
        s->k = StorehouseOfWisdom::SAYING;
        In(s->saying, file);
        return s;
    default:
        return 0;
    }
}


// —лучайный ввод обобщенной кладези
StorehouseOfWisdom* InRnd() {
    StorehouseOfWisdom* s = new StorehouseOfWisdom;
    auto type_number = rand() % 3;
    char content[] = GenerateContent(rand() % 50);
    s->content = content;

    switch (type_number) {
    case 0:
        s->k = StorehouseOfWisdom::RIDDLE;
        InRnd(s->riddle);
        return s;
    case 1:
        s->k = StorehouseOfWisdom::APHORISM;
        InRnd(s->aphorism);
        return s;
    case 2:
        s->k = StorehouseOfWisdom::SAYING;
        InRnd(s->saying);
        return s;
    default:
        return 0;
    }
}

//------------------------------------------------------------------------------
// ¬ывод параметров текущей кладези в поток
void Out(StorehouseOfWisdom& s, FILE* file) {
    switch (s.k) {
    case StorehouseOfWisdom::RIDDLE:
        Out(s.riddle, file);
        break;
    case StorehouseOfWisdom::APHORISM:
        Out(s.aphorism, file);
        break;
    case StorehouseOfWisdom::SAYING:
        Out(s.saying, file);
        break;
    default:
        fprintf(file, "Incorrect Storehouse of Wisdom!");
        return;
    }

    fprintf(file, s.content);
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
