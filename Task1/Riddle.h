#ifndef __Riddle__
#define __Riddle__

//-------------------------------------------------------------------------------------
// Riddle.h - содержит описание альтернативы "Загадки" и её интерфейса
//-------------------------------------------------------------------------------------

#include "StorehouseOfWisdom.h"
#include "stdio.h"
#include "random.h"

// Загадка
struct Riddle {
    char answer[]; // ответ
};

// Ввод параметров загадки из файла
void In(Riddle& с, FILE * file);

// Случайный ввод загадки
void InRnd(Riddle& с);

// Вывод параметров загадки в форматируемый поток
void Out(Riddle& с, FILE* file);

#endif //__Riddle__
