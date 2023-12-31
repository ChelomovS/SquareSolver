#ifndef SOLVE_SQUARE_H
#define SOLVE_SQUARE_H

int solve_linear (double b, double c, double* x1);
int solve_square (double a, double b, double c, double* x1, double* x2);
void sorting_roots (double* x1, double* x2);
bool compare_numbers(double n1, double n2);
void check_numbers (double* a, double* b, double* c);

#endif
