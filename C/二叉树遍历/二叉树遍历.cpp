#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ������
	struct node *rchild;		//ָ���Һ���
} BTNode;

void CreateBTNode(BTNode * & b,char * str)
{
	BTNode * St[MaxSize],* p;
	int top =-1,k,j=0;
	char ch;
	b=NULL;
	ch=str[j];
	while (ch!='\0')
	{
		switch(ch)
		{
		case'(':top++;St[top]=p;k=1;break;
		case')':top--;break;
		case',':k=2;break;
		default:p=(BTNode *)malloc(sizeof(BTNode));
			p->data=ch;p->lchild=p->rchild=NULL;
			if(b==NULL)
				b=p;
			else
			{
				switch(k)
				{
				case 1:St[top]->lchild=p;break;
				case 2:St[top]->rchild=p;break;
				}
			}
		}
		j++;
		ch=str[j];
	}
}

//���������
void Disp(BTNode * b)
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		if(b->lchild!=NULL||b->rchild!=NULL)
		{
			printf("(");
			Disp(b->lchild);
			if(b->rchild!=NULL)
				printf(",");
			Disp(b->rchild);
			printf(")");
		}
	}
}

void PreOrder(BTNode *b)  		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		printf("%c ",b->data);	//���ʸ��ڵ�
		PreOrder(b->lchild);	//�ݹ����������
		PreOrder(b->rchild);	//�ݹ����������
	}
}
void PreOrder1(BTNode *b) 		//��������ķǵݹ��㷨
{
	BTNode *St[MaxSize],*p;
    int top=-1;
    if (b!=NULL) 
    {
        top++;						//���ڵ���ջ
        St[top]=b;
        while (top>-1)				//ջ��Ϊ��ʱѭ��
        {
            p=St[top];				//��ջ�����ʸýڵ�
            top--;
            printf("%c ",p->data);
            if (p->rchild!=NULL)	//�Һ�����ջ
			{
               top++;
               St[top]=p->rchild;
			}
            if (p->lchild!=NULL)	//������ջ
			{
               top++;
               St[top]=p->lchild;
			}
		}
		printf("\n");
	}
}
void InOrder(BTNode *b)   		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		InOrder(b->lchild);		//�ݹ����������
		printf("%c ",b->data);	//���ʸ��ڵ�
		InOrder(b->rchild);		//�ݹ����������
	}
}
void InOrder1(BTNode *b) 		//��������ķǵݹ��㷨
{
	BTNode *St[MaxSize],*p;
	int top=-1;
	if (b!=NULL)
	{
		p=b;
		while (top>-1 || p!=NULL)
		{
			while (p!=NULL)
			{
				top++;
				St[top]=p;
				p=p->lchild;
			}
			if (top>-1)
			{
				p=St[top];
				top--;
				printf("%c ",p->data);
				p=p->rchild;
			}
		}
		printf("\n");
	}
}
void PostOrder(BTNode *b) 		//��������ĵݹ��㷨
{
	if (b!=NULL)  
	{	
		PostOrder(b->lchild);	//�ݹ����������
		PostOrder(b->rchild);	//�ݹ����������
		printf("%c ",b->data);	//���ʸ��ڵ�
	}
}
void PostOrder1(BTNode *b) 		//��������ķǵݹ��㷨
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag,top=-1;						//ջָ���ó�ֵ
	if (b!=NULL)
	{
		do
		{
			while (b!=NULL)					//��t��������ڵ���ջ
			{
				top++;
				St[top]=b;
				b=b->lchild;
			}
			p=NULL;							//pָ��ǰ�ڵ��ǰһ���ѷ��ʵĽڵ�
			flag=1;	
			while (top!=-1 && flag)
			{
				b=St[top];					//ȡ����ǰ��ջ��Ԫ��
				if (b->rchild==p)			//�����������ڻ��ѱ�����,����֮
				{
					printf("%c ",b->data);	//����*b�ڵ�
					top--;
					p=b;					//pָ���򱻷��ʵĽڵ�
				}
				else
				{
					b=b->rchild;			//tָ��������
					flag=0;	
				}
			}
		} while (top!=-1);
		printf("\n");
	} 
}
void TravLevel(BTNode *b) 		//��α��� 
{
	BTNode *Qu[MaxSize];				//����ѭ������
	int front,rear;						//������׺Ͷ�βָ��
	front=rear=0;						//�ö���Ϊ�ն���
    if (b!=NULL) 
		printf("%c ",b->data);
    rear++;								//�ڵ�ָ��������
	Qu[rear]=b;
    while (rear!=front)					//���в�Ϊ��
    {
		front=(front+1)%MaxSize;
		b=Qu[front];					//��ͷ������
		if (b->lchild!=NULL)			//�������,�������
		{
			printf("%c ",b->lchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)			//����Һ���,�������
		{
			printf("%c ",b->rchild->data);
			rear=(rear+1)%MaxSize;
			Qu[rear]=b->rchild;
		}
	} 
	printf("\n");
}

void DestroyBTNode(BTNode *&b)
{
	if (b!=NULL)
	{
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
main(void)
{
	BTNode *b;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"); 
	printf("������b:");Disp(b);printf("\n");
	printf("��α�������:");
	TravLevel(b);
	printf("�����������:\n");
	printf("    �ݹ��㷨:");PreOrder(b);printf("\n");
	printf("  �ǵݹ��㷨:");PreOrder1(b);
	printf("�����������:\n");
	printf("    �ݹ��㷨:");InOrder(b);printf("\n");
	printf("  �ǵݹ��㷨:");InOrder1(b);
	printf("�����������:\n");
	printf("    �ݹ��㷨:");PostOrder(b);printf("\n");
	printf("  �ǵݹ��㷨:");PostOrder1(b);
	DestroyBTNode(b);
}
