#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
}BTNode;

//����������
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

//���ҽڵ�
 BTNode *FindNode(BTNode *b,ElemType x)	//����data��Ϊx�Ľڵ�ָ��
{
	BTNode *p;
	if (b==NULL)
	     return NULL;
	else if (b->data==x)
	     return b;
	else
	{	
		p=FindNode(b->lchild,x);
		if (p!=NULL) 
			return p;
		else 
			return FindNode(b->rchild,x);
	}
}
BTNode *LchildNode(BTNode *p)	//����*p�ڵ�����ӽڵ�ָ��
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)	//����*p�ڵ���Һ��ӽڵ�ָ��
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b)	//�������b�����
{
   	int lchilddep,rchilddep;
   	if (b==NULL) 
		return(0); 							//�����ĸ߶�Ϊ0
   	else  
	{	
		lchilddep=BTNodeDepth(b->lchild);	//���������ĸ߶�Ϊlchilddep
	  	rchilddep=BTNodeDepth(b->rchild);	//���������ĸ߶�Ϊrchilddep
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
   	}
}

int BTWidth(BTNode *b)  //�������b�Ŀ��
{
	struct 
	{
		int lno;		//�ڵ�Ĳ�α��
		BTNode *p;		//�ڵ�ָ��
	} Qu[MaxSize];		//����˳���ѭ������
	int front,rear;							//������׺Ͷ�βָ��
	int lnum,max,i,n;
	front=rear=0;							//�ö���Ϊ�ն�
    if (b!=NULL) 
	{
		rear++;	
		Qu[rear].p=b;						//���ڵ�ָ�����
		Qu[rear].lno=1;						//���ڵ�Ĳ�α��Ϊ1
		while (rear!=front)					//���в�Ϊ��
		{
			front++;
			b=Qu[front].p;					//��ͷ����
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)			//�������
			{
				rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)			//�Һ������
			{
				rear++;
				Qu[rear].p=b->rchild;
				Qu[rear].lno=lnum+1;
			}
		}
		max=0;lnum=1;i=1;
		while (i<=rear)
		{
			n=0;
			while (i<=rear && Qu[i].lno==lnum) 
			{
				n++;i++;
			}
			lnum=Qu[i].lno;
			if (n>max) max=n;
		}
		return max;
	}
	else
		return 0;
}
int Nodes(BTNode *b)	//�������b�Ľڵ����
{
	int num1,num2;
    if (b==NULL) 
		return 0;
    else if (b->lchild==NULL && b->rchild==NULL) 
		return 1;
    else
    {
        num1=Nodes(b->lchild);
        num2=Nodes(b->rchild);
        return (num1+num2+1);
	}
}
int LeafNodes(BTNode *b)	//�������b��Ҷ�ӽڵ����
{
	int num1,num2;
    if (b==NULL) 
		return 0;
    else if (b->lchild==NULL && b->rchild==NULL) 
		return 1;
    else
    {
        num1=LeafNodes(b->lchild);
        num2=LeafNodes(b->rchild);
        return (num1+num2);
	}
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


//main(void)
//{
//	BTNode * a;
//	CreatBTNode(a,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
//	Disp(a);
//}
main(void )
{	BTNode *b,*p,*lp,*rp;;
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("�������Ļ�����������:\n");
	printf("  (1)���������:");Disp(b);printf("\n");
	printf("  (2)H�ڵ�:");
	p=FindNode(b,'H');
	if (p!=NULL)
	{	lp=LchildNode(p);
		if (lp!=NULL) 
			printf("����Ϊ%c ",lp->data);
		else
			printf("������ ");
		rp=RchildNode(p);
		if (rp!=NULL)
			printf("�Һ���Ϊ%c",rp->data);
		else
			printf("���Һ��� ");
	}
	printf("\n");
	printf("  (3)������b�����:%d\n",BTNodeDepth(b));
	printf("  (4)������b�Ŀ��:%d\n",BTWidth(b));
	printf("  (5)������b�Ľڵ����:%d\n",Nodes(b));
	printf("  (6)������b��Ҷ�ӽڵ����:%d\n",LeafNodes(b));
	printf("  (7)�ͷŶ�����b\n");
	DestroyBTNode(b);
}
