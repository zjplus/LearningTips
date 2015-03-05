#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode
{
	int num,pasw;
	struct LNode * next;
}LinkList;

//尾插法创建循环单链表
void CreatListR(LinkList * &L,ElemType a[],int n)
{
	LinkList * s,* r;
	int i;
	L=(LinkList *)malloc(sizeof(LinkList));//创建头结点
	r=L;
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->num=i+1;
		s->pasw=a[i];
		r->next=s;
		r=s;
	}
	r->next=L->next;
}

//创建输出函数
void DispList(LinkList *& L,int m)//m记录密码
{
	LinkList * p=L->next;//p指向首节点，不指向头结点L
	LinkList * q,* r;
	while(p->next!=p)
	{
		for(int i=1;i<m;i++)
		{
			q=p;
			p=p->next;
		}
		printf("第%d个人出列 他的密码为%d\n",p->num,p->pasw);
		m=p->pasw;
		r=p;
		q->next=p->next;
		p=q->next;//后移p
		free(r);
	}
	printf("第%d个人出列 他的密码为%d\n",p->num,p->pasw);
	free(p);
}

void main()
{
	ElemType a[]={5,35,24,15,61,57};//初始化链表结构里的密码
	LinkList * L;
	CreatListR(L,a,6);//数组六个密码
	DispList(L,20);//初始密码是20
}