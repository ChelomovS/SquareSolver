#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>

#include "colors.h"
#include "consts.h"

/**
* @brief Функция очистки буфера
*/
void clear_buffer (void)
{
    while (getchar() != '\n');
}

/**
* @brief Функция, проверяющая введенные числа на infinite и NaN
*/
void check_numbers (double* a, double* b, double* c)
{
    if (isfinite(*a) && isfinite (*b) && isfinite(*c))
        return;
    else
        {
            printf (RED "Такие числа не подходят\n" RED);
            clear_buffer();
        }

    ASSERT (isnan (*a));
    ASSERT (isnan (*b));
    ASSERT (isnan (*c));
    ASSERT (isfinite(*a));
    ASSERT (isfinite(*b));
    ASSERT (isfinite(*c));
}

/**
* @brief Функция выбора способа ввода коэффициентов
* @return Возвращает true, если выбран ввод с клавиатуры. Возвращает false, если выбран ввод через файл
*/
bool select_input (void)
{
    int k = 0;
    printf("Выберите способ ввода коэффициентов\n"
           "1) ввод с клавиатуры 2) ввод из файла\n");
    while ((scanf ("%d", &k)!=1) || ((k!=1) && (k!=2)))
        {
            printf (CYAN "Попробуйте ещё раз\n" CYAN);
            clear_buffer();
        }
    if (k == 1)
        return true;
    else if (k == 2)
        return false;
}

/**
* @brief Функция ввода коэффициентов через клавиатуру
* @param [out] a, b, c - адреса переменных коэффициентов квадратного уравнения
*/
void input_coeffs_keyboard (double* a, double* b, double* c)
{

    ASSERT (a != NULL);
    ASSERT (b != NULL);
    ASSERT (c != NULL);

    printf ("Введите коэффициенты квадратного уравнения \n");

    while (scanf ("%lf %lf %lf", a, b ,c) != 3)
        {
            clear_buffer();
            printf (RED "Ошибка ввода. Введите коэффициенты еще раз \n" RED);
        }
    check_numbers(a, b, c);
}

/**
* @brief Функция ввода коэффициентов через файл
* @param [out] a, b, c - адреса переменных коэффициентов квадратного уравнения
*/
void input_coeffs_file (double* a, double* b, double* c)
{
    ASSERT (a != NULL);
    ASSERT (b != NULL);
    ASSERT (c != NULL);

    printf ("Введите имя файла\n");
    char name_of_file[NAME] = {};
    scanf("%s", name_of_file);
    FILE *file = fopen (name_of_file, "r");

    while(fscanf (file, "%lf %lf %lf", a, b, c)!=3)
    {
        printf(RED "Ошибка ввода\n" RED);
        printf (RED "Введите с клавиатуры\n" RED);
        input_coeffs_keyboard(a, b, c);
        return;
    }
    fclose(file);
    check_numbers(a, b, c);
}


/**
*@brief Функция вывода корней
*@param [in] n_roots - Количество корней квадратного уравнения
*@param [in]  x1, x2 - Первый и второй корни квадратного уравнения
*/
void output_roots (int n_roots, double x1, double x2)
{
    switch (n_roots)
    {
        case ZERO: printf(YELLOW "Нет действительных корней \n" YELLOW);
            break;

        case ONE: printf(YELLOW "Корень уравнения - %.2lf \n" YELLOW, x1);
            break;

        case TWO: printf(YELLOW "Корни квадратного уравнения %.2lf и %.2lf \n" YELLOW, x1, x2);
            break;

        case LINEAR: printf (YELLOW "Уравнение линейное, его корень %.2lf \n" YELLOW, x1);
            break;

        case INF_ROOTS: printf (YELLOW "У уравнения бесконечное множество корней \n" YELLOW);
            break;

        default: printf (RED "Error \n" RED);
    }
}
