#include "stdio.h"
void main()
{
	int year;
	int k;
	int day=0;
	int week;
	printf("请输入一个年份");
	scanf("%d",&year);
	//求输入的年份与1900年之间的天数（1900年第一天是星期一）
	for(k=1900;k<year;k++)
	{
		if((k%4==0&&k%100!=0)||k%400==0)
			day=day+366;
		else
			day=day+365;
	}
	//那一年的第一天是星期week
	week=(day)%7+1;			


	//循环输出每个月的月历
	int i,j;						//i表示月份，j表示日
	for(i=1;i<13;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			day=31;					//1、3、5、7、8、10、12每月31天
		else if(i==4||i==6||i==9||i==11)
			day=30;					//4、6、9、11每月30天
		else if((year%4==0&&year%100!=0)||year%400==0)
		day=29;						//闰年二月29天
		else
			day=28;					//非闰年二月28天

		printf("\n========%2d月========\n",i);
		printf("日 一 二 三 四 五 六\n");

		//循环输出前面的空格
		int m=1;
		int n=week;
			for(m;m<=n;m++)
		{
			printf("   ");			//3空格
		}

		//循环输出每一天，week到7的时候换行
		for(j=1;j<day+1;j++)
		{	week=week%7;
			if(week!=0)
				printf("%2d ",j);
			else 
				printf("\n%2d ",j);
			week++;					//每输出一天week加一
			week=week%7;
		}
		printf("\n====================\n");
	}
}