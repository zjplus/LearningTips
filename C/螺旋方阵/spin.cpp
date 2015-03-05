#include <iostream>
#include <iomanip>
using namespace std;
#define N 3
int a[N][N];
int main()
{	int m=0;
	int i=0,j=0;
	for(int k=1;k<=N/2;k++)
	{	
		for(j;j<=N-k-1;j++)
		{
			m++;
			a[i][j]=m;
		}
			
		for(i;i<=N-k-1;i++)
		{
			m++;
			a[i][j]=m;
		}

		for(j;j>=k;j--)
		{
			m++;
			a[i][j]=m;
		}
		for(i;i>=k;i--)
		{
			m++;
			a[i][j]=m;
		}
		i++;
		j++;
	}
	//判断奇数的时候单独赋值中间的值
	if(N%2==1){
		m++;
		a[i][j]=m;
	}


	//循环输出数组
	for(int x=0;x<N;x++)
	{
		for(int y=0;y<N;y++)
		{
			cout<<setw(5)<<a[x][y];
			if(y==N-1)
				cout<<endl;
		}
	}
	return 0;
}