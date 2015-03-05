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
	SqList() //���Ա��캯��
	{
		length=0;
	}

	void ResetList() //���Ա�����
	{
		length=0;
	}

	void InitList(int l,ElemtType d[])//��ʼ�����Ա�����
	{
		length=l;
		int i=0;
		while(i<length)
		{
			data[i]=d[i];
			i++;
		}
	}

	void DispList() //������Ա�����
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
			cout<<"�����Ա�������"<<endl;
	}

	int ListLength() //��ȡ���Ա���
	{
		return length;
	}

	bool ListEmpty() //�ж��Ƿ�Ϊ��
	{
		if(length==0)
			return true;
  		else
			return false;
	}

	ElemtType GetElem(int i) //���ر��е�i��Ԫ�ص�ֵ
	{
		if(i<=length&&i>0)
			return data[i-1];
		else
		{
			cout<<"��Ԫ�س�����ĳ��ȡ�";
			return 0;
		}
	}

	int LocateElem(ElemtType i) //����i�ڱ��еĵ�һ��λ��
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


	int InsertEnd(ElemtType i)//��ĩβ����һ��Ԫ��
	{
		if(length==Maxsize)
		{
			cout<<"���Ա��ȴﵽ���ޣ��޷���ӡ�"<<endl;
			return 0;
		}
  		else
  		{
  			data[length]=i;
  			length++;
  			return 1;
		}
	}

	int insertElem(int n,ElemtType i) //��n������i
	{
		if(length==Maxsize)
		{
			cout<<"���Ա��ȴﵽ���ޣ��޷����롣"<<endl;
			return 0;
		}
		if(n>length)
		{
			cout<<"����λ�ó������Ա��ȣ��޷����롣"<<endl;
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

	int DeleteElem(int i) //ɾ�����еĵ�i��Ԫ��
	{
		if(length==0)
		{
			cout<<"���Ա�Ϊ�գ��޷�ɾ��Ԫ��"<<endl;
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
