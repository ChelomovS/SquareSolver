#include <TXLib.h>
#include <stdio.h>
#include <iso646.h>
#include <math.h>

double discr (double a, double b,double c)
{
    double d=b*b-4*a*c;
    return d;
}
double root1 (double a,double b,double c)
{
    double d=discr(a,b,c);
    double r1= (-b + sqrt(d) )/(2*a);
    return r1;
}
double root2 (double a,double b,double c)
{
    double d= discr (a, b, c);
    double r2= (-b - sqrt(d))/(2*a);
    return r2;
}
void input (double* a, double* b, double* c)
{
    printf ("Введите коэффициенты квадратного уравненния \n");
    scanf ("%lf %lf %lf", a, b ,c);
}
void two_roots (double a, double b, double c)
{
    printf ("Первый корень квадратного уравнения - %.2lf \nВторой корень квадратного уравнения -  %.2lf \n", root1(a, b, c), root2(a, b, c));
}
void one_root (double a, double b, double c)
{
    printf ("Единственный корень квадратного уравнения - %.2lf \n", root1(a, b, c));
}
void linear (double b, double c)
{
    printf ("Корень линейного уравнения - %.2lf \n", -c/b);
}
void infinite (void)
{
    printf ("Уравнение имеет бесконечное количество решений \n");
}
void no_roots (void)
{
    printf ("Нет действительных решений \n");
}
void output (double a, double b, double c)
{
    if (a==0 and b==0 and c!=0)
        no_roots();
    else if (a==0 and b==0 and c==0)
        infinite();
    else if (a==0)
        linear(b, c);
    else if (discr (a, b, c)<0)
        no_roots();
    else if (discr (a, b, c)==0)
        one_root(a, b, c);
    else if (discr (a, b, c)>0)
        two_roots(a, b, c);
}

int main (void)
{
    double a, b, c;
    input (&a, &b, &c);
    output (a,b,c);
    return 0;
}
