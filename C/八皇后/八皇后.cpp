#include <stdio.h>
#include <stdlib.h>
const int N=20;      	//���ʺ����
int q[N];            	//��Ÿ��ʺ����ڵ��к�
int count=0;          	//��Ž����
void print(int n)    	//���һ����
{
	count++;
	int i;
	int x=0;
	printf("  ��%d���⣺\n",count);
	for (i=1;i<=n;i++)
	{
		for(x=0;x<=n;x++)
		{
		//printf("(%d,%d) ",i,q[i]);
		if(x==q[i])
			printf(" # ");
		else
			printf("   ");
		}
		printf("\n");
	}
	printf("\n");
}
int place(int k,int j) 	//����(k,j)λ���ܷ�ڷŻʺ�
{
	int i=1;
	while (i<k)       	//i=1��k-1���ѷ����˻ʺ����
	{
	    if ((q[i]==j) || (abs(q[i]-j)==abs(i-k)))
		    return 0;
	    i++;
	}
	return 1;
}
void queen(int k,int n)			//����1-k�Ļʺ�
{
	int j;
	if (k>n) 
		print(n);         		//���лʺ���ý���
	else
		for (j=1;j<=n;j++) 		//�ڵ�k�������ÿһ��λ��
		    if (place(k,j))		//�ڵ�k�����ҵ�һ������λ��(k,j)
			{
				q[k]=j;
				queen(k+1,n);
     		}
}
void main()
{
	int n;     					//n���ʵ�ʻʺ����
	printf(" �ʺ�����(n<20) n=");
	scanf("%d",&n);
	if (n>20)
		printf("nֵ̫��,�������\n");
	else
	{
		printf(" %d�ʺ�����������£�\n",n);
		queen(1,n);
		printf("\n");
    }
}