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
        double X[N], T[N][N], factor, I[N][N], IT[N][N], Y[N];
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
	
	}
        
        for(i=0;i<n;i++)
        {
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
        printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	        	printf("%lf\t", c[i][j]);
                printf("\n");
	}
        /*Transpose*/
        printf("T: \n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        T[i][j]=c[j][i];
                        printf("%lf\t", T[i][j]);
               
                }
                printf("\n");
        }
        /*Inverse of c matrix*/
        for(i=0;i<n;i++)
	 {
         	  for(j=0;j<n;j++)
		  {
         		   if(i==j)
			   {
			    	c[i][j+n] = 1;
			   }
			   else
			   {
			    	c[i][j+n] = 0;
			   }
		  }
	 }
         for(i=0;i<n;i++)
       	{
		  for(j=0;j<n;j++)
		  {
			   if(i!=j)
			   {
				    factor= c[j][i]/c[i][i];
				    for(k=0;k<2*n;k++)
				    {
				     	c[j][k] = c[j][k] - factor*c[i][k];
				    }
			   }
		  }
	 }
         for(i=0;i<n;i++)
	{
		  for(j=n;j<2*n;j++)
		  {
		   	I[i][j] = c[i][j]/c[i][i];
		  }
	 }
           
         printf("\nInverse Matrix c is:\n");
	 for(i=0;i<n;i++)
	 {
		  for(j=n;j<2*n;j++)
		  {
		   	printf("%lf\t",I[i][j]);
		  }
		  printf("\n");
	 }
         /*Inverse of T matrix*/
         for(i=0;i<n;i++)
         {
                  for(j=0;j<n;j++)
                  {
                           if(i==j)
                           {
                                T[i][j+n] = 1;
                           }
                           else
                           {
                                T[i][j+n] = 0;
                           }
                  }
         }
         for(i=0;i<n;i++)
        {
                  for(j=0;j<n;j++)
                  {
                           if(i!=j)
                           {
                                    factor= T[j][i]/T[i][i];
                                    for(k=0;k<2*n;k++)
                                    {
                                        T[j][k] = T[j][k] - factor*T[i][k];
                                    }
                           }
                  }
         }
         for(i=0;i<n;i++)
        {
                  for(j=n;j<2*n;j++)
                  {
                        IT[i][j] = T[i][j]/T[i][i];
                  }
         }
         printf("\nInverse Matrix T is:\n");
         for(i=0;i<n;i++)
         {
                  for(j=n;j<2*n;j++)
                  {
                        printf("%lf\t",T[i][j]);
                  }
                  printf("\n");
         }
         /*Resulotion of the system*/
         printf("Y=I*B:\n");
         Y[0]=B[0]*I[0][0];
 
         for(i=1;i<n;i++)
         {
              double s=0;
              for(j=0;j<i;j++)
                         s+=c[i][j]*Y[j];
              Y[i]=(B[i]-s)*I[i][i];
         }
         for(i=0;i<n;i++)
                  printf("%lf\t", Y[i]);
         printf("\n");
         Y[0]=B[0]/c[0][0];
         for(i=1;i<n;i++)
         {
                double s=0;
                for(j=0;j<i;j++)
                {
                      s+=c[i][j]*Y[j];
                }
                Y[i]=(B[i]-s)/c[i][i];
         }
        for(i=0;i<n;i++)
        {
               printf("Y[%d]=%lf\t", i, Y[i]);
        }
        X[n-1]=Y[n-1]/T[n-1][n-1];
	for(int i=n-2;i>=0;i--)
	{
		s=0;
		for(int j=i;j<n;j++)
			s=s+T[i][j]*X[j];
		X[i]=(Y[i]-s)/T[i][i];
      	}
     
         for(i=0;i<n;i++)
         {
               printf("X[%d]=%lf\t", i, X[i]);
         }

/*I tried two methods for the resolution but none of them gives me the correct X vector, I don't know why*/

	 return(0);
  
}

