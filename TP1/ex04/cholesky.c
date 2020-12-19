#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int main()
{
  /* 
  ** What are you looking for ? \
  ** go ahead and code the solution by yourself. \
  ** you can always ask for help on slack.
  */
  /*Of course I will code the solution by myself*/
  int i, j, k, n;
	printf("Donner la taille de la matrice: ");
	scanf("%d", &n);
	double c[N][N], A[N][N], B[N], s, s1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("A[%d][%d]: ", i, j);
			scanf("%lf", &A[i][j]);
		}
		printf("B[%d]: ", i);
		scanf("%lf", &B[i]);
	}
	c[0][0]=sqrt(A[0][0]);
	for(i=1;i<n;i++)
		c[i][0]=A[i][0]/c[0][0];
	for(j=1;j<n;j++)
	{
		for(i=0;i<j - 1;i++)
			c[i][j]=0;
		s = 0.0;
		for(k=0;k<j;k++)
	        	s+=pow(c[j][k], 2);
		c[j][j]=sqrt(A[j][j]-s);
		for(i=j + 1;i<n;i++)
		{
			s1 = 0.0;
			for(k=0;k<j;k++)
				s1+=c[i][k]*c[j][k];
			c[i][j]=(1.0/c[j][j])*(A[i][j]-s1);
		}
	}
        printf("The c matrix:\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        printf("%lf\t", c[i][j]);
                 printf("\n");
        }
        printf("The T matrix: \n");

      
        /*transpose*/
      /*
        double T[N][N];
        for(i=0;i<n;i++)
        {
             for(j=0;j<n;j++)
                  T[i][j]=c[j][i];
        }
        printf("\n");
        printf("The c matrix:\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                        printf("%lf\t", c[i][j]);
                 printf("\n");
        }
        printf("The T matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	        	printf("%lf\t", T[i][j]);
                 printf("\n");
	}*/
        /*the inverse of c*/
   /*     double det=0;
        int r, h;
        if(k==1)
              return c[0][0];
        else
        {
             for(int a=0,a<k,a++)
             {
                 r=0;
                 h=0;
                 for(i=0;i<k;i++)
                 {
                   
                      for(j=0;j<k;j++)
                      {
                           b[i][j]=0;
                           if(j=0;j<k;j++)
                            {
                              
                            } 
                      }
                 } 
             }
        }
        */
        
  return (0);
}
