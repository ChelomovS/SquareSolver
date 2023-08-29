//-------------------------------------------------------------------------------------------------------------------------------
//! @mainpage Программа, решающая квадратные уравнения и выводящая ответ на экран
//! @par Сначала необходимо ввести аргумент командной строки:
//! @par -h - аргумент, вызывающий расшифровку каждого аргумента
//! @par -t - запуск тестов
//! @par -n - обычный запуск программы
//! @par Программа может считывать коффициенты как с клавиатуры, так и из файла, который должен находиться в папке с программой
//! @par Если выбран ввод из файла, нужно ввести его название с расширением
//! @par Для запуска программы нужно ввести в командную строку имя файла, -n и другие аргументы
//! @par WARNING Если не ввести аргумент -n программа работать не будет!
//-------------------------------------------------------------------------------------------------------------------------------

#include <cstdio>
#include <cmath>
#include <cassert>
#include <string.h>

#include "input_output.h"
#include "test.h"
#include "solve_square.h"
#include "consts.h"

int main (int argc, char* argv[])
{
    double a = 0, b = 0, c = 0; ///< коэффициенты квадратного уравнения
    double x1 = 0, x2 = 0; ///< корни квдратного уравненния
    int number = 0; ///< количество корней уравнения //энам

    for (int i=1; i<argc; i++)
    {
        if ((argv[i][1] == 'n') && (argv [i][0] == '-'))
            {
                if (select_input())
                    input_coeffs_keyboard (&a, &b, &c);
                else
                    input_coeffs_file (&a, &b, &c);
            number = solve_square (a, b, c, &x1, &x2);
            output_roots (number, x1, x2);
        }
        if ((argv[i][1] == 't') && (argv[i][0] == '-'))
            {
                Test_all();
            }
        if ((argv[i][1] == 'h') && (argv[i][0] == '-'))
            {
                printf ("Аргументы командной строки:\n");
                printf ("1) -h - вызывает описание аргументов командной строки\n");
                printf ("2) -t - включает вывод тестов\n");
                printf ("3) -n - вызывает обычный запуск программы\n");
                return 0;
            }
    }
}
