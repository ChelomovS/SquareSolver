#include <cstdio>
#include <cassert>
#include <cmath>

#include "consts.h"

/**
* @brief Сравнивает два числа типа double
* @param [in] n1, n2 - сравниваемые числа
* @return Возвращает значние false, если числа равны или true, если они не равны
*/
bool compare_numbers(double n1, double n2)
{

    ASSERT (isfinite( n1));
    ASSERT (isfinite (n1));


    if (fabs (n1-n2) < EPS)
        return true;
    else
        return false;
};

/**
* @brief Решает линейное уравнение
* @param [in] b, c - коэффициенты линейного уравнения;
* @param [out] x1 - адрес первого корня
* @return Возвращает количество корней
*/
int solve_linear (double b, double c, double* x1)
{
    if (compare_numbers(b, 0))
        return ZERO;
    else
        {
            *x1 = -c/b;
            return LINEAR;
        }
}
/**
*@brief Сортирует корни по возрастанию
*@param [out] x1, x2  адреса корней квадратного уравнения
*/
void sort_roots (double* x1, double* x2 )
{
    double tmp = 0;
    if (*x1 > *x2)
        {
            tmp = *x1;
            *x1 = *x2;
            *x2 = tmp;
        }
}
/**
* @brief Решает квадратное уравнение
* @param [in]  a, b, c - коэффициенты квадратного уравнения
* @param [out] x1, x2 - адреса первого и второго корней
* @return Возвращает количество корней
*/

int solve_square (double a, double b, double c, double* x1, double* x2)
{

    ASSERT (isfinite (a));
    ASSERT (isfinite (b));
    ASSERT (isfinite (c));
    ASSERT (x1 != NULL);
    ASSERT (x2 != NULL);


    double tmp = 0;
    double d = b*b - 4*a*c;

    if (compare_numbers(a, 0) && compare_numbers(b, 0) && !(compare_numbers(c, 0)))
        return ZERO;
    else if (compare_numbers(a, 0) && compare_numbers(b, 0) && compare_numbers(c, 0))
        return INF_ROOTS;
    else if (a == 0)
        {
            tmp = solve_linear(b, c, x1);
            return tmp;
        }

    if (compare_numbers(d, 0))
        {
            *x1 = (-b + sqrt(d))/(2*a);
            return ONE;
        }
    else if (d < 0)
            return ZERO;

    else if (d > 0)
        {
            double j = sqrt (d);
            *x1 = (-b - j)/(2*a);
            *x2 = (-b + j)/(2*a);
            sort_roots(x1, x2);
            return TWO;
        }
    return 0;
}
