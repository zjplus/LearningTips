#include <stdio.h>

long fun(long n)
{
	if(1==n)
		return 1;
	else
		return fun(n-1)*n;
	//return fun(n-1)+n; //��1��n�ĺ�;
}

void main()
{
	long n;
	printf("��������һ����:");
	scanf("%d",&n);
	fun(n);
	printf("%d�Ľ׳���:%d\n",n,fun(n));
}