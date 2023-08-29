#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

void clear_buffer (void);
void sorting_roots (double* x1, double* x2);
void input_coeffs_file (double* a, double* b, double* c);
void input_coeffs_keyboard (double* a, double* b, double* c);
void output_roots (int n_roots, double x1, double x2);
int select_input (void);

#endif
