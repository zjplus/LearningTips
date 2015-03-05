#include<iostream>
using namespace std;

struct Linklist
{	
	int data;
	Linklist* next;
};

void InitList(Linklist* &head,int n) //������Ϣ������ѭ������
{	
	head=new Linklist;
	head->next=head;
	Linklist* p=head;
	for(int i=0;i<n;i++)
	{
		Linklist* q=new Linklist;
		cout<<"�����"<<i+1<<"���˵�mֵ��";
		cin>>q->data;
		p->next=q;
		p=p->next;
	}
	p->next=head;
}

void Output(Linklist* h) //�������
{	
	Linklist* p=h->next;
	if(h->next==h)
		cout<<"����Ϊ��";
	else
		while(true)
		{
			cout<<p->data<<"  ";
			if(p->next==h) break;
			p=p->next;
		}
	cout<<endl;
}

void Deletenext(Linklist* head,Linklist* pre) //ɾ��head�����е� pre->next�ڵ�
{
	if(head->next!=head)
	{
		if(pre->next==head)
		{
			Linklist* d=head->next;
			head->next=d->next;
			delete d;
		}
		else
		{
			Linklist* d=pre->next;
			pre->next=d->next;
			delete d;
		}
	}
}

void Loop(Linklist* head,int m)
{
	Linklist* Pre=head;
	Linklist* P=new Linklist;
	P=Pre->next;
	int i=0;
	while(true)
	{
		i++;
//		cout<<"P->data="<<P->data<<"  i="<<i<<"  m="<<m<<endl;
		if(i==m)
		{
			i=0;
			m=P->data;
			Deletenext(head,Pre);
			P=Pre->next;
			cout<<"m="<<m<<endl;
//			cout<<"new list:";
//			Output(head);
		}
		else
		{
			Pre=Pre->next;
			P=Pre->next;
		}
		if(head->next==head) break;
		if(P==head)
		{
			Pre=Pre->next;
			P=Pre->next;
		}
	}
}

int main()
{
	Linklist* h;
	int n,m;
	cout<<"����������";
	cin>>n;
	InitList(h,n);
	cout<<endl<<"����m��ʼֵ��";
	cin>>m;
//	cout<<endl<<"����ѭ���������£�";
//	Output(h);
	Loop(h,m);
	return 0;
}
