#include "stdio.h"
void main()
{
	int year;
	int k;
	int day=0;
	int week;
	printf("������һ�����");
	scanf("%d",&year);
	//������������1900��֮���������1900���һ��������һ��
	for(k=1900;k<year;k++)
	{
		if((k%4==0&&k%100!=0)||k%400==0)
			day=day+366;
		else
			day=day+365;
	}
	//��һ��ĵ�һ��������week
	week=(day)%7+1;			


	//ѭ�����ÿ���µ�����
	int i,j;						//i��ʾ�·ݣ�j��ʾ��
	for(i=1;i<13;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			day=31;					//1��3��5��7��8��10��12ÿ��31��
		else if(i==4||i==6||i==9||i==11)
			day=30;					//4��6��9��11ÿ��30��
		else if((year%4==0&&year%100!=0)||year%400==0)
		day=29;						//�������29��
		else
			day=28;					//���������28��

		printf("\n========%2d��========\n",i);
		printf("�� һ �� �� �� �� ��\n");

		//ѭ�����ǰ��Ŀո�
		int m=1;
		int n=week;
			for(m;m<=n;m++)
		{
			printf("   ");			//3�ո�
		}

		//ѭ�����ÿһ�죬week��7��ʱ����
		for(j=1;j<day+1;j++)
		{	week=week%7;
			if(week!=0)
				printf("%2d ",j);
			else 
				printf("\n%2d ",j);
			week++;					//ÿ���һ��week��һ
			week=week%7;
		}
		printf("\n====================\n");
	}
}