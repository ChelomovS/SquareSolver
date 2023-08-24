#include <cstdio>
#include <cassert>
#include <cmath>

enum n_roots {ZERO = 0, ONE = 1, TWO = 2, INF_ROOTS= 8, LINEAR = 3};
const double EPS = 0.0000001;

int solve_linear_square (double b, double c, double* x1)
{
    if (b != 0)
    {
        *x1 = -c/b;
        return LINEAR;
    }
    else return ZERO;
}

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

bool is_Zero (double n)
{
    if (fabs(n) < EPS)
       return true;
    else return (false);
}

int solve_square (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    double tmp = 0;
    double d = b*b - 4*a*c;

    if (a == 0 and b == 0 and c != 0)
        return ZERO;
    else if (a == 0 and b == 0 and c == 0)
        return INF_ROOTS;
    else if (a == 0)
        {
            tmp = solve_linear_square(b, c, x1);
            return tmp;
        }

    if (d < 0)
        return ZERO;
    else if (is_Zero(d))
        {
            *x1 = (-b + sqrt(d))/(2*a);
            return ONE;
        }
    else if (d > 0)
        {
            *x1 = (-b - sqrt(d))/(2*a);
            *x2 = (-b + sqrt(d))/(2*a);
            sort_roots(x1, x2);
            return TWO;
        }
}
