#include <stdio.h>
void Hanoi(int n,char x,char y,char z)
{
	//�����һ�����ӣ�ֱ�ӽ�X�����ϵ������Ƶ�Z
		//ֱ�ӽ�A �����ϵ������ƶ���C
	//����
		//�Ƚ�A�����ϵ�n-1�����ӽ���C�ƶ���B
		//�ٽ�A�����ϵ������Ƶ�C
		//���B�����ϵ�n-1�����ӽ���A�ƶ���C
	if(1==n)
		printf("��%d���̴�%c���Ƶ�%c��\n",n,x,z);
	else
	{
		Hanoi(n-1,x,z,y);//��A�ϵ�n-1�����Ƶ�B
		printf("��%d���̴�%c���Ƶ�%c��\n",n,y,z);
		Hanoi(n-1,y,x,z);//��B�ϵ�n-1�Ƶ�C
	}
}

int main()
{
	char ch1='A';
	char ch2='B';
	char ch3='C';
	int n;
	printf("������Ҫ�ƶ������Ӹ���:");
	scanf("%d",&n);
	Hanoi(n,'A','B','C');
}
