#ifndef __random__
#define __random__

#include <cstdlib>

//------------------------------------------------------------------------------
// random.h - �������� ��������� ��������� ����� � ��������� �� 1 �� 20
//------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 50;
}

inline auto GenerateContent(int length) {
    char string[MAX_CONTENT_SIZE];

    for (int i = 0; i < length; i++) {
        string[i] = rand() % 93 + 32; // ��������� ������ � ������� �� 32 �� 125
    }

    return string;
}

#endif //__random__