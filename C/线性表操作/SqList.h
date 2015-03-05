#include<iostream>
using namespace std;

#define Maxsize 100
typedef char ElemtType;

class SqList
{
protected:
	int length;
	ElemtType data[Maxsize];
public:
	SqList() //线性表构造函数
	{
		length=0;
	}

	void ResetList() //线性表重置
	{
		length=0;
	}

	void InitList(int l,ElemtType d[])//初始化线性表内容
	{
		length=l;
		int i=0;
		while(i<length)
		{
			data[i]=d[i];
			i++;
		}
	}

	void DispList() //输出线性表内容
	{
		if(length!=0)
		{
			int i=0;
			while(i<length)
			{
				cout<<data[i]<<" ";
				i++;
			}
			cout<<endl;
		}
		else
			cout<<"该线性表无内容"<<endl;
	}

	int ListLength() //获取线性表长度
	{
		return length;
	}

	bool ListEmpty() //判断是否为空
	{
		if(length==0)
			return true;
  		else
			return false;
	}

	ElemtType GetElem(int i) //返回表中第i个元素的值
	{
		if(i<=length&&i>0)
			return data[i-1];
		else
		{
			cout<<"该元素超出表的长度。";
			return 0;
		}
	}

	int LocateElem(ElemtType i) //查找i在表中的第一个位置
	{
		int n=0;
		while(n<100)
		{
			if(data[n]==i)
				return n+1;
			n++;
		}
		return 0;
	}


	int InsertEnd(ElemtType i)//在末尾插入一个元素
	{
		if(length==Maxsize)
		{
			cout<<"线性表长度达到上限，无法添加。"<<endl;
			return 0;
		}
  		else
  		{
  			data[length]=i;
  			length++;
  			return 1;
		}
	}

	int insertElem(int n,ElemtType i) //在n处插入i
	{
		if(length==Maxsize)
		{
			cout<<"线性表长度达到上限，无法插入。"<<endl;
			return 0;
		}
		if(n>length)
		{
			cout<<"插入位置超过线性表长度，无法插入。"<<endl;
			return 0;
		}
  		else
  		{
   			for(int j=length;j!=n-1;j--)
  			{
				data[j]=data[j-1];
			}
			data[n-1]=i;
  			length++;
  			return 1;
		}
	}

	int DeleteElem(int i) //删除表中的第i个元素
	{
		if(length==0)
		{
			cout<<"线性表为空，无法删除元素"<<endl;
			return 0;
		}
  		else
  		{
   			for(int j=i-1;j<length;j++)
  			{
				data[j]=data[j+1];
			}
  			length--;
  			return 1;
		}
	}
};
