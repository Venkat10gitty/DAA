#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fac(int x)
{
	int i,fac=1;
	for(i=1;i<=x;i++)
		fac=fac*i;
	return fac;
}

int main()
{
	float x,Q,sum=0;
	int i,j,limit,limit_trial;
	
	scanf("%d",&limit_trial);
	scanf("%f",&x);

    limit = limit_trial+1;

	Q=x;
	for(i=1,j=1;i<=limit;i++,j=j+2)
	{
		if(i%2!=0)
		{
			sum=sum+pow(x,j)/fac(j);
		}
		else
			sum=sum-pow(x,j)/fac(j);
	}
	
	printf("%.2f", ((signed long)(sum * 100) * 0.01f));
	return 0;
}