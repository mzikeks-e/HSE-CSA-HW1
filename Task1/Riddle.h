#ifndef __Riddle__
#define __Riddle__

//-------------------------------------------------------------------------------------
// Riddle.h - �������� �������� ������������ "�������" � � ����������
//-------------------------------------------------------------------------------------

#include "StorehouseOfWisdom.h"
#include "stdio.h"
#include "random.h"

// �������
struct Riddle : StorehouseOfWisdom {
    char* answer; // �����
};

// ���� ���������� ������� �� �����
void In(Riddle& �, FILE * file);

// ��������� ���� �������
void InRnd(Riddle& �);

// ����� ���������� ������� � ������������� �����
void Out(Riddle& �, FILE* file);

#endif //__Riddle__
