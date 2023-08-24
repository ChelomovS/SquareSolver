#include <cstdio>
#include <cmath>
#include <cassert>
#include "consts.h"

void clear_buffer (void)
{
    while (getchar() != '\n');
}

void input_coeffs (double* a, double* b, double* c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    printf ("Введите коэффициенты квадратного уравнения \n");
    while (scanf ("%lf %lf %lf", a, b ,c) !=3)
    {
         clear_buffer();
         printf ("Ошибка ввода. Введите коэффициенты еще раз \n");
    }
    if (isfinite(*a) || isfinite (*b) || isfinite(*c))
         return;
    else
         printf ("Числа слишком большие\n");

    assert (isfinite(*a));
    assert (isfinite(*b));
    assert (isfinite(*c));
}

void output_roots (int n_roots, double x1, double x2)
{
    switch (n_roots)
    {
    case ZERO: printf("Нет действительных корней \n");
          break;

    case ONE: printf("Корень уравнения - %.2lf \n", x1);
          break;

    case TWO: printf("Корни квадратного уравнения %.2lf и %.2lf \n", x1, x2);
          break;

    case LINEAR: printf ("Уравнение линейное, его корень %.2lf \n", x1);
          break;

    case INF_ROOTS: printf ("У уравнения бесконечное множество корней \n");
          break;

    default: printf ("Error \n");
    }
}

