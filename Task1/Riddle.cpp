//------------------------------------------------------------------------------
// Riddle.cpp - �������� ��������� ��� ������ � ���������
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "Riddle.h"

//------------------------------------------------------------------------------
// ���� ���������� ������� �� ������
void In(Riddle& r, FILE* file) {
    fscanf(file, "%s", r.answer);
}

// ��������� ���� ���������� �������
void InRnd(Riddle& r) {
    r.answer = GenerateContent(Random(10));
}



