#include <stdio.h>
#include <math.h>

double f( double x)
{
     return pow(x,2)/2;
}

double RectangleDroite(double(*f)(double), double a, double b, double n)
{
     double h=(b-a)/n;
     double s=0;
     double x=a;
             for(int i=0;i<n;i++)
             {
                   s+=f(x);
                   x+=h;
             }
     return (s*h);
}

double RectangleGauche(double(*f)(double), double a, double b, double n)
{
     double h=(b-a)/n;
     double s=0;
     double x=a+h;
             for(int i=0;i<n-1;i++)
             {
                   s+=f(x);
                   x+=h;
             }
     return (s*h);
}

double Trapeze(double(*f)(double), double a, double b, double n)
{
     double h=(b-a)/n;
     double k=0.5*(f(a)+f(b));
     double x=a+h;
     for(int i = 1; i < n;i++)
     {
        k=k+f(x);
        x+=h;
     }
     return h*k;
}

double Simpson(double(*f)(double), double a, double b , double n)
{
    double h =(b-a)/n;
    double x=a+h;
    double k=a+h/2;
    double s1=0;
    double s2=f(k);
    for (int i = 1;i< n;i++)
    {
        k+=h;
        s1+=f(x);
        s2+=f(k);
        x+=h;
    }
    return (h/6)*(f(a)+f(b)+2*s1+4*s2);
        
}
int main()
{
int a,b,n;
printf("Donner les bornes et le pas:\n");
printf("a:\t");
scanf("%d", &a);
printf("\n");
printf("b:\t");
scanf("%d", &b);
printf("\n");
printf("n:\t");
scanf("%d", &n);
printf("\n");
printf("%lf\n", RectangleDroite(f, a, b, n));
printf("\n");
printf("%lf\n", RectangleGauche(f, a, b, n));
printf("\n");
printf("%lf\n", Trapeze(f, a, b, n));
printf("\n");
printf("%lf\n", Simpson(f, a, b, n));
printf("\n");


return 0;
}

