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
	L=(LinkList *)malloc(sizeof(LinkList));//创建头结点
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
      while (p!=NULL)		//扫描所有的结点
      {	q=p->next;		//让q指向*p结点的下一个结点
	p->next=L->next;	//总是将*p结点作为第一个数据结点
	L->next=p;
	p=q;			//让p指向下一个结点
    }
}

void main(){
	ElemType a []={1,2,3,4,5,6};
	LinkList * L;
	CreatListR(L,a,6);
	printf("初始链表:\n");
	DispList(L);
	Reverse(L);
	printf("\n逆置之后的链表:\n");
	DispList(L);
	printf("\n");
}