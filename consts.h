#ifndef CONST_H
#define CONST_H

#include <cstdio>
#include <cmath>

#define ASSERT(a)                                   \
    if (!(a))                                       \
        {                                           \
            printf ("Ошибка! \n");                  \
            printf ("В файле: %s \n", __FILE__);    \
            printf ("В строке: %d \n", __LINE__);   \
            exit (0);                               \
        }

/**
*@brief Возможное число корней уравнения
*/
enum n_roots
{
    ZERO = 0,      //< У уравнения нет действительных корней
    ONE = 1,       //< У уравнения один дейссвительный корень
    TWO = 2,       //< У уравнения два действительных корня
    INF_ROOTS= 8,  //< Уравнение имеет бесконечное количество корней
    LINEAR = 3     //< Уравнение является линейным и имеет один корень
};

const double EPS = 0.0000001;
const int N_TESTS = 5;  //< Число тестов
const int NAME = 50; //< Размер имени файла

#endif
