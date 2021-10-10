#ifndef __Aphorism__
#define __Aphorism__

//-------------------------------------------------------------------------------------
// Aphorism.h - содержит описание альтернативы "Афоризм" и её интерфейса
//-------------------------------------------------------------------------------------

#include "StorehouseOfWisdom.h"
#include "stdio.h"
#include "random.h"

//Афоризм
struct Aphorism : StorehouseOfWisdom{
	char* author; // автор афоризма
};

// Ввод параметров афоризма из файла
void In(Aphorism& с, FILE* file);

// Случайный ввод афоризма
void InRnd(Aphorism& с);

// Вывод параметров афоризма в форматируемый поток
void Out(Aphorism& с, FILE* file);

#endif //__Aphorism__
