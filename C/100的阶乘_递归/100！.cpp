#include <stdio.h>

long fun(long n)
{
	if(1==n)
		return 1;
	else
		return fun(n-1)*n;
	//return fun(n-1)+n; //求1到n的和;
}

void main()
{
	long n;
	printf("请输入与一个数:");
	scanf("%d",&n);
	fun(n);
	printf("%d的阶乘是:%d\n",n,fun(n));
}