/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *f(double x)
{
     return pow(x, 2);
}

double RecD(double *f, double a, double b, double n)
{
    double s, h;
    h=(b-a)/n;
    s=0;
    for(int i=0;i<n;i++)
          s+=f(a+i*h);
    return h*s;
}
int main()
{
    double a, b, n;
    a=2;
    b=3;
    n=3;
    RecD(f, a, b, n);
    printf("%lf", RecD(f, a, b, n));
}*/

#include <stdio.h>
#include <math.h>

int main()
{


double a,b,n,p,i=0,f,x,ex,cube;

printf("Quelles sont vos bornes d'integration?\n");
scanf("%lf",&a);
scanf("%lf", &b);
printf("Quel est le pas?\n");
scanf("%lf",&p);
for(x=a;x<b;x+=p)
{
x=a;
ex=(double)exp(-x);
cube=(x*x*x);
f=ex/cube;
printf("%lf\n",i);
i=i+(f*p);

}
printf("L'integrale vaut %lf",i);


return 0;
}

