#include <cstdio>
#include <cmath>
#include <cassert>

enum n_roots {ZERO = 0, ONE = 1, TWO = 2, INF_ROOTS= 8, LINEAR = 3 };

const double EPS = 0.0000001;

void clear_buffer (void)
{
    while (getchar() != '\n');
    printf ("Ошибка ввода, попробуйте еще раз \n");
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
    }
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

