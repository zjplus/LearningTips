#include"SqList.h"
#include<iostream>
using namespace std;

int main()
{
	cout<<"����SQList�����ʱ����list"<<endl;
	SqList* list=new SqList;
	cout<<"���Ա��ȣ�"<<list->ListLength()<<endl;
	cout<<"���list���ݣ�";
	list->DispList();
	
	cout<<endl<<"�ó���Ϊ10������initialData��ʼ�����Ա�"<<endl;
	ElemtType initialData[10]={'z','x','y','v','o','n','m','j','k','l'};
	list->InitList(10,initialData);
	cout<<"���Ա��ȣ�"<<list->ListLength()<<endl;
	cout<<"���list���ݣ�";
	list->DispList();
	
	cout<<endl<<"ĩβ����a,b,c,d,e��:"<<endl;
	list->InsertEnd('a');
	list->InsertEnd('b');
	list->InsertEnd('c');
	list->InsertEnd('d');
	list->InsertEnd('e');
	cout<<"���Ա��ȣ�"<<list->ListLength()<<endl;
	cout<<"���list���ݣ�";
	list->DispList();
	
	cout<<endl;
	cout<<"���е�3��Ԫ��:";
	cout<<list->GetElem(3)<<endl;
	
	cout<<endl<<"Ԫ��a��λ�ã�"<<list->LocateElem('a')<<endl;
	
	cout<<endl<<"��4λ�ò���f��"<<endl;
	list->insertElem(4,'f');
	cout<<"���Ա��ȣ�"<<list->ListLength()<<endl;
	cout<<"���list���ݣ�";
	list->DispList();
	
	cout<<endl<<"ɾ����3��Ԫ��"<<endl;
	list->DeleteElem(3);
	cout<<"���Ա��ȣ�"<<list->ListLength()<<endl;
	cout<<"���list���ݣ�";
	list->DispList();
	
	cout<<endl<<"����list,���տռ䡣"<<endl;
	delete list;
	return 0;
}
