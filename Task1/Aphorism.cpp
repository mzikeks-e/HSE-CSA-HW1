//------------------------------------------------------------------------------
// Aphorism.cpp - �������� ��������� ��� ������ � ����������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "Aphorism.h"

//------------------------------------------------------------------------------
// ���� ���������� �������� �� ������
void In(Aphorism& a, FILE* file) {
    fscanf(file, "%s", &a.author);
}

// ��������� ���� ���������� ��������
void InRnd(Aphorism& a) {
    a.author = GenerateContent(Random(15));
}

//------------------------------------------------------------------------------
// ����� ���������� �������� � �����
void Out(Aphorism& a, FILE* file) {
    fprintf(file, "It is Aphorism. %s - says %s. Quotient = %a", a.content, a.author, Quotient(a));
}

