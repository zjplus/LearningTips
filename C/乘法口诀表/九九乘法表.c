#include "stdio.h"
void main()
{
	int i,j;
	int a;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			a=i*j;
			printf("%2dX%d=%2d ",i,j,a);
		}
			printf("\n");
	}
	
}
