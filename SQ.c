#include <stdio.h>
#include <iso646.h>
#include <math.h>
double a, b, c;

double discr (double a, double b,double c)
{
double d;
d=b*b-4*a*c;
return d;
}
void root1 (double a,double b,double c)
{
 double r1;
 double d;
 d=discr(a,b,c);
 r1= (-b + sqrt(d) )/(2*a);
 printf ("First root: %.3lf \n", r1) ;
}
void root2 (double a,double b,double c)
{
 double r2;
 double d;
 d= discr (a, b, c)  ;
 r2= (-b - sqrt(d))/(2*a);
 printf ("Second root: %.3lf \n", r2);
}


int main (void)
{
double a, b, c;

printf ("Enter odds \n");
    scanf ("%lf", &a);
    scanf ("%lf", &b);
    scanf ("%lf", &c);
if (a==0 and b==0 and c!=0)
printf ("The equation has no solutions \n");
else
if (a==0)
printf ("Root: %lf", -c/b);
else
if (discr (a, b, c)<0)
printf ("The equation has no solutions \n");
else
if (discr (a, b, c)==0)
root1(a,b,c);
else
if (discr (a, b, c)>0)
{
root1(a,b,c);
root2(a,b,c);
}

return 0;
}

