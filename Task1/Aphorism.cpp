//------------------------------------------------------------------------------
// Aphorism.cpp - �������� ��������� ��� ������ � ����������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "Aphorism.h"

//------------------------------------------------------------------------------
// ���� ���������� �������� �� ������
void In(Aphorism& a, FILE* file) {
    fscanf(file, "%s", a.author);
}

// ��������� ���� ���������� ��������
void InRnd(Aphorism& a) {
    a.author = GenerateContent(Random(15));
}


