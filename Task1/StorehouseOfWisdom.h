#ifndef __StorehouseOfWisdom__
#define __StorehouseOfWisdom__

//------------------------------------------------------------------------------
// StorehouseOfWisdom.cpp - �������� ��������� ��������� � ���������� 
// o���������� ��������� (������� ��������)
// � �������� ������������ ������������
//------------------------------------------------------------------------------

#include <cstring>
#include "stdio.h"
#include "Saying.h"
#include "Riddle.h"
#include "Aphorism.h"

const int MAX_CONTENT_SIZE = 4096;
const char PUNCTUATION_SYMBOLS[] { ',', '.', ';', '-', ':', '-', '?', '!' };

//------------------------------------------------------------------------------
// ���������, ���������� ��� ��������� ������������ (������� ��������)
struct StorehouseOfWisdom {
    // �������� ������ ��� ������ �� �������� ��������
    enum key { RIDDLE, APHORISM, SAYING };
    key k;

	char content[MAX_CONTENT_SIZE];

    // ������������ ������������
    union { // ���������� ���������� ����������
        Riddle& riddle;
        Aphorism& aphorism;
        Saying& saying;
    };
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