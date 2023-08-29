#include <cstdio>
#include <cassert>
#include <cmath>

#include "solve_square.h"
#include "consts.h"
#include "colors.h"

/**
* @brief Структура, используемая для хранения информации, связанных с тестами
*/
struct TestData
{
    double a, b, c;      ///< Коэффициенты квадратного уравнения
    double x1ref, x2ref; ///< Ожидаемые корни квадратного уравнения
    int n_rootsref;      ///< Ожидаемое количество решений квадратного уравнения
    const char* name;    ///< Имя теста
};

/**
* @brief Структура, используемая для хранения ожидаемых решений квадратного уравнения
*/
struct TestData allData [N_TESTS] =
{
    {.a = 0, .b = 0,  .c = 0,  .x1ref = 0,      .x2ref = 0, .n_rootsref = INF_ROOTS, .name = "Inf_Test"},
    {.a = 1, .b = 0,  .c = -4, .x1ref =  -2,    .x2ref = 2, .n_rootsref = TWO,       .name = "B_zero_Test"},
    {.a = 0, .b = 4,  .c = 5,  .x1ref  = -1.25, .x2ref = 0, .n_rootsref = LINEAR,    .name = "Linear_Test"},
    {.a = 4, .b = -9, .c = -9, .x1ref = -0.75,  .x2ref = 3, .n_rootsref = TWO,       .name = "Normal_Test"},
    {.a = 0, .b = 0,  .c = 0,  .x1ref = 0,      .x2ref = 0, .n_rootsref = INF_ROOTS, .name = "Zero_Test"},
};

/**
*@brief Тест, проверяющий правильность вычисляемых корней квадратного уравнения
*@param [in] const struct TestData* coeffs - Ссылка на массив структур
*@return Возвращает 0, если тест не выполнился. Возвращает 1 если тест выполнился
*/
int Test_one (const struct TestData* coeffs)
{

    double x1 = 0, x2 = 0;
    int n_roots = solve_square (coeffs -> a, coeffs -> b, coeffs -> c, &x1, &x2);
    int n_rootsref = coeffs -> n_rootsref;
    const char* name = coeffs -> name;
    double x1ref = coeffs -> x1ref;
    double x2ref = coeffs -> x2ref;
    if (!(compare_numbers (x1, x1ref)) || !(compare_numbers(x2, x2ref)) || n_roots!=n_rootsref)
        {
            printf (RED "%s FAILED: x1 = %lf, x2 = %lf, n_roots = %d\n" RED, name, x1, x2, n_roots);
            printf(RED "\t  EXPECTED: x1ref = %lf, x2ref = %lf, n_rootsref = %d \n" RED, x1ref, x2ref, n_rootsref);
            return 0;
        }
    else
        {
            printf (GREEN "Test %s ok \n" GREEN, name);
            return 1;
        }
}
/**
*@brief Считает количество выполненных тестов и печатает их количество
*/

int Test_all (void)
{
    int number_ok_tests = 0;

    for (int i = 0; i < N_TESTS; i++)
        number_ok_tests += Test_one (&allData[i]);
    printf (PURPLE "Удачных тестов: %d из %d \n" PURPLE , number_ok_tests, N_TESTS);
    return 0;
};
