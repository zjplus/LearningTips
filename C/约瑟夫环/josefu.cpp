#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode
{
	int num,pasw;
	struct LNode * next;
}LinkList;

//β�巨����ѭ��������
void CreatListR(LinkList * &L,ElemType a[],int n)
{
	LinkList * s,* r;
	int i;
	L=(LinkList *)malloc(sizeof(LinkList));//����ͷ���
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

//�����������
void DispList(LinkList *& L,int m)//m��¼����
{
	LinkList * p=L->next;//pָ���׽ڵ㣬��ָ��ͷ���L
	LinkList * q,* r;
	while(p->next!=p)
	{
		for(int i=1;i<m;i++)
		{
			q=p;
			p=p->next;
		}
		printf("��%d���˳��� ��������Ϊ%d\n",p->num,p->pasw);
		m=p->pasw;
		r=p;
		q->next=p->next;
		p=q->next;//����p
		free(r);
	}
	printf("��%d���˳��� ��������Ϊ%d\n",p->num,p->pasw);
	free(p);
}

void main()
{
	ElemType a[]={5,35,24,15,61,57};//��ʼ������ṹ�������
	LinkList * L;
	CreatListR(L,a,6);//������������
	DispList(L,20);//��ʼ������20
}