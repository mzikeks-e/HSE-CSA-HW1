//------------------------------------------------------------------------------
// Riddle.cpp - �������� ��������� ��� ������ � ���������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "Riddle.h"

//------------------------------------------------------------------------------
// ���� ���������� ������� �� ������
void In(Riddle& r, FILE* file) {
    fscanf(file, "%s", &r.answer);
}

// ��������� ���� ���������� �������
void InRnd(Riddle& r) {
    r.answer = GenerateContent(Random(10));
}

//------------------------------------------------------------------------------
// ����� ���������� ������� � �����
void Out(Riddle& r, FILE* file) {
    fprintf(file, "It is Riddle. Question %s. Answer: %s. Quotient = %a", r.content, r.answer, Quotient(r));
}

