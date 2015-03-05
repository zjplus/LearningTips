#include"SqList.h"
#include<iostream>
using namespace std;

int main()
{
	cout<<"建立SQList类的临时对象list"<<endl;
	SqList* list=new SqList;
	cout<<"线性表长度："<<list->ListLength()<<endl;
	cout<<"输出list内容：";
	list->DispList();
	
	cout<<endl<<"用长度为10的数组initialData初始化线性表"<<endl;
	ElemtType initialData[10]={'z','x','y','v','o','n','m','j','k','l'};
	list->InitList(10,initialData);
	cout<<"线性表长度："<<list->ListLength()<<endl;
	cout<<"输出list内容：";
	list->DispList();
	
	cout<<endl<<"末尾插入a,b,c,d,e后:"<<endl;
	list->InsertEnd('a');
	list->InsertEnd('b');
	list->InsertEnd('c');
	list->InsertEnd('d');
	list->InsertEnd('e');
	cout<<"线性表长度："<<list->ListLength()<<endl;
	cout<<"输出list内容：";
	list->DispList();
	
	cout<<endl;
	cout<<"表中第3个元素:";
	cout<<list->GetElem(3)<<endl;
	
	cout<<endl<<"元素a的位置："<<list->LocateElem('a')<<endl;
	
	cout<<endl<<"在4位置插入f："<<endl;
	list->insertElem(4,'f');
	cout<<"线性表长度："<<list->ListLength()<<endl;
	cout<<"输出list内容：";
	list->DispList();
	
	cout<<endl<<"删除第3个元素"<<endl;
	list->DeleteElem(3);
	cout<<"线性表长度："<<list->ListLength()<<endl;
	cout<<"输出list内容：";
	list->DispList();
	
	cout<<endl<<"销毁list,回收空间。"<<endl;
	delete list;
	return 0;
}
