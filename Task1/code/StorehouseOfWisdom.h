#ifndef __StorehouseOfWisdom__
#define __StorehouseOfWisdom__

//------------------------------------------------------------------------------
// StorehouseOfWisdom.cpp - �������� ��������� ��������� � ���������� 
// o���������� ��������� (������� ��������)
// � �������� ������������ ������������
//------------------------------------------------------------------------------

#include "Saying.h"
#include "Riddle.h"
#include "Aphorism.h"


const char PUNCTUATION_SYMBOLS[]{ ',', '.', ';', '-', ':', '-', '?', '!' };
const int MAX_CONTENT_SIZE = 4096;
const int MAX_AUTHOR_SIZE = 512;
const int MAX_COUNTRY_SIZE = 512;
const int MAX_ANSWER_SIZE = 1024;   

//------------------------------------------------------------------------------
// ���������, ���������� ��� ��������� ������������ (������� ��������)
struct StorehouseOfWisdom {
    // �������� ������ ��� ������ �� �������� ��������
    enum key { RIDDLE, APHORISM, SAYING };
    key k;

	char* content;

    // ������������ ������������
    union alternatives {
        Riddle riddle_;
        Aphorism aphorism_;
        Saying saying_;
    };

    alternatives Type;
};

// ���� ���������� ������� ��������
StorehouseOfWisdom* In(FILE* file, int k);

// ��������� ���� ������� ��������
StorehouseOfWisdom* InRnd();

// ����� ���������� ������� ��������
void Out(StorehouseOfWisdom& s, FILE* file);

// ���������� �������� ������ �� ����� ������� ��������
double Quotient(StorehouseOfWisdom& s);

#endif
