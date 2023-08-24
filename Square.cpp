#include <cstdio>
#include <cmath>
#include <cassert>
#include "input_output.h"
#include "test.h"
#include "solve_square.h"

enum n_roots {ZERO = 0, ONE = 1, TWO = 2, INF_ROOTS= 8, LINEAR = 3};
const double EPS = 0.0000001;

int main (void)
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, r = 0;
    int n_roots = 0;
    input_coeffs (&a, &b, &c);
    double d = b*b - 4*a*c;
    n_roots = solve_square (a, b, c, &x1, &x2);
    output_roots (n_roots, x1, x2);
    TestAll();
    return 0;
}
