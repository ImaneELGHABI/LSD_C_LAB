#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f( double x)
{
    return exp((-pow(x,2))/2);
}

double Trapeze(double(*f)(double),double a,double  b ,int n)
{

    double h = (b -a )/n;
    double z = 0.5 * (f(a ) + f(b));
    int i;
    for (i = 1; i < n;i++)
        z = z +f(a + i * h);
    return h * z;
}

double Romberg(double(*f)(double), double a, double b, double Err, int nmax)
{
    int i, k;
    double R[nmax][nmax];
    for(i=0;i<nmax;i++)
    {
        int N=pow(2,i);
        R[i][0]=Trapeze(f,a,b,N);
        for(k=0;k<i;k++)
        {
            double n=k+2;
            R[i][k+1]= 1.0/(pow(4,n-1)-1)*(pow(4,n-1)*R[i][k]-R[i-1][k]);
            if(i>0)
            {
                 if(abs(R[i][k+1]-R[i][k])<Err)
                      return R[i][k+1];
            }
         }
        
    }
    return R[i][k+1];
}


int main()
{
     int a=0;
     int b=1;
     double Err=pow(10, -9);
     int nmax=3;
     printf("%lf\n", Romberg(f, a, b, Err, nmax));
     return 0;
}




