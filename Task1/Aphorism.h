#ifndef __Aphorism__
#define __Aphorism__

//-------------------------------------------------------------------------------------
// Aphorism.h - �������� �������� ������������ "�������" � � ����������
//-------------------------------------------------------------------------------------

#include "StorehouseOfWisdom.h"
#include "stdio.h"
#include "random.h"

//�������
struct Aphorism : StorehouseOfWisdom{
	char* author; // ����� ��������
};

// ���� ���������� �������� �� �����
void In(Aphorism& �, FILE* file);

// ��������� ���� ��������
void InRnd(Aphorism& �);

// ����� ���������� �������� � ������������� �����
void Out(Aphorism& �, FILE* file);

#endif //__Aphorism__
