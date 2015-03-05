#include <stdio.h>
void Hanoi(int n,char x,char y,char z)
{
	//如果是一个盘子，直接将X柱子上的盘子移到Z
		//直接将A 柱子上的盘子移动到C
	//否则
		//先将A柱子上的n-1个盘子借助C移动到B
		//再将A柱子上的盘子移到C
		//最后将B柱子上的n-1个盘子借助A移动到C
	if(1==n)
		printf("将%d号盘从%c柱移到%c柱\n",n,x,z);
	else
	{
		Hanoi(n-1,x,z,y);//将A上的n-1个盘移到B
		printf("将%d号盘从%c柱移到%c柱\n",n,y,z);
		Hanoi(n-1,y,x,z);//将B上的n-1移到C
	}
}

int main()
{
	char ch1='A';
	char ch2='B';
	char ch3='C';
	int n;
	printf("请输入要移动的盘子个数:");
	scanf("%d",&n);
	Hanoi(n,'A','B','C');
}
