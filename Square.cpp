#include <cstdio>
#include <cmath>
#include <cassert>
#include "input_output.h"
#include "test.h"
#include "solve_square.h"
#include "consts.h"

int main (void)
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, r = 0;
    int n_roots = 0;
    input_coeffs (&a, &b, &c);
    n_roots = solve_square (a, b, c, &x1, &x2);
    output_roots (n_roots, x1, x2);
    TestAll();
    return 0;
}
