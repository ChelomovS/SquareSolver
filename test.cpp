#include <cstdio>
#include <cassert>
#include <cmath>
#include "solve_square.h"

enum n_roots {ZERO = 0, ONE = 1, TWO = 2, INF_ROOTS = 8, LINEAR = 3 };
const double EPS = 0.000001;
const int N_TESTS = 5;

struct TestData
{
    double a, b, c;
    double x1ref, x2ref;
    int n_rootsref;
    const char* name;
};

struct TestData allData [N_TESTS] =
{
    {.a = 0, .b = 0, .c = 0, .x1ref = 0, .x2ref = 0, .n_rootsref = INF_ROOTS, .name = "Inf_Test"},
    {.a = 1, .b = 0, .c = -4, .x1ref =  -2, .x2ref =  2, .n_rootsref =  TWO, .name = "B_zero_Test"},
    {.a = 0, .b = 4, .c = 5, .x1ref  = -1.25, .x2ref = 0, .n_rootsref = LINEAR, .name = "Linear_Test"},
    {.a = 4, .b = -9, .c = -9, .x1ref = -0.75, .x2ref = 3, .n_rootsref = TWO, .name = "Normal_Test"},
    {.a = 0, .b = 0, .c = 0, .x1ref = 0, .x2ref = 0, .n_rootsref = INF_ROOTS, .name = "Zero_Test"},
};


int Test_one (const struct TestData* allData)
{
    double x1 = 0, x2 = 0;
    double a = 0, b = 0, c = 0;
    int n_roots = solve_square (allData->a, allData->b, allData->c, &x1, &x2);
    double d = b*b - 4*a*c;
    int n_rootsref = allData->n_rootsref;
    const char* name = allData -> name;
    double x1ref = allData -> x1ref;
    double x2ref = allData -> x2ref;
    if (fabs(x1 - x1ref)>EPS or fabs(x2-x2ref)>EPS or n_roots!=n_rootsref)
        {
            printf ("%s FAILED: x1 = %lf, x2 = %lf, n_roots = %d, EXPECTED: x1ref = %lf, x2ref = %lf, n_rootsref = %d \n", name, x1, x2, n_roots, x1ref, x2ref, n_rootsref);
            return 0;
        }
    else
        {
            printf ("Test %s ok \n", name);
            return 1;
        }
}

int TestAll (void)
{
    int number_ok_tests = 0;

    for (int i = 0; i < N_TESTS; i++)
    number_ok_tests += Test_one (&allData[i]);
    printf ("Удачных тестов: %d из %d \n", number_ok_tests, N_TESTS);
    return 0;
};
