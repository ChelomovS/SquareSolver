#include <stdio.h>
#include <iso646.h>
#include <math.h>
double discr (double a, double b,double c)
{
  double d=b*b-4*a*c;
  return d;
}
void root1 (double a,double b,double c)
{
  double d=discr(a,b,c);
  double r1= (-b + sqrt(d) )/(2*a);
  printf ("First root: %.3lf \n", r1) ;
}
void root2 (double a,double b,double c)
{
  double d= discr (a, b, c);
  double r2= (-b - sqrt(d))/(2*a);
  printf ("Second root: %.3lf \n", r2);
}
void input (double* a, double* b, double* c)
{
  double pa,pb,pc;
  scanf ("%lf", &pa);
  *a=pa;
  scanf ("%lf", &pb);
  *b=pb;
  scanf ("%lf", &pc);
  *c=pc;
}
void output (double a, double b, double c)
{
  if (a==0 and b==0 and c!=0)
   printf ("The equation has no solutions \n");
  else if (a==0 and b==0 and c==0)
   printf ("An infinite number of solutions \n");
  else if (a==0)
   printf ("Root: %.3lf", -c/b);
  else if (discr (a, b, c)<0)
   printf ("The equation has no solutions \n");
  else if (discr (a, b, c)==0)
   root1(a,b,c);
  else if (discr (a, b, c)>0)
   {
    root1(a,b,c);
    root2(a,b,c);
   }
}

int main (void)
{
  double a, b, c;
  input (&a, &b, &c);
  output(a,b,c);
  return 0;
}


