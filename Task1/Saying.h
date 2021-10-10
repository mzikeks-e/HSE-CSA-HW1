#ifndef __Saying__
#define __Saying__

//-------------------------------------------------------------------------------------
// Saying.h - �������� �������� ������������ "��������� � ����������" � � ����������
//-------------------------------------------------------------------------------------

#include "StorehouseOfWisdom.h"
#include "stdio.h"
#include "random.h"

// ��������� � ���������
struct Saying : StorehouseOfWisdom {
	char* country; // ������
};

// ���� ���������� ���������/��������� �� �����
void In(Saying& �, FILE* file);

// ��������� ���� ���������/���������
void InRnd(Saying& �);

// ����� ���������� ���������/��������� � ������������� �����
void Out(Saying& �, FILE* file);

#endif //__Saying__
