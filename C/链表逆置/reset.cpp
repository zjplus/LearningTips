#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LinkList;

void CreatListR(LinkList * &L,ElemType a[],int n)
{
	LinkList * s,* r;
	int i;
	L=(LinkList *)malloc(sizeof(LinkList));//����ͷ���
	r=L;
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

void DispList(LinkList *L)
{
	LinkList *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void Reverse(LinkList *&L)
{     LinkList *p=L->next,*q;
       L->next=NULL;
      while (p!=NULL)		//ɨ�����еĽ��
      {	q=p->next;		//��qָ��*p������һ�����
	p->next=L->next;	//���ǽ�*p�����Ϊ��һ�����ݽ��
	L->next=p;
	p=q;			//��pָ����һ�����
    }
}

void main(){
	ElemType a []={1,2,3,4,5,6};
	LinkList * L;
	CreatListR(L,a,6);
	printf("��ʼ����:\n");
	DispList(L);
	Reverse(L);
	printf("\n����֮�������:\n");
	DispList(L);
	printf("\n");
}