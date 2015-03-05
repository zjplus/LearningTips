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

//建立二叉树
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

//输出二叉树
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

//查找节点
 BTNode *FindNode(BTNode *b,ElemType x)	//返回data域为x的节点指针
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
BTNode *LchildNode(BTNode *p)	//返回*p节点的左孩子节点指针
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)	//返回*p节点的右孩子节点指针
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b)	//求二叉树b的深度
{
   	int lchilddep,rchilddep;
   	if (b==NULL) 
		return(0); 							//空树的高度为0
   	else  
	{	
		lchilddep=BTNodeDepth(b->lchild);	//求左子树的高度为lchilddep
	  	rchilddep=BTNodeDepth(b->rchild);	//求右子树的高度为rchilddep
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
   	}
}

int BTWidth(BTNode *b)  //求二叉树b的宽度
{
	struct 
	{
		int lno;		//节点的层次编号
		BTNode *p;		//节点指针
	} Qu[MaxSize];		//定义顺序非循环队列
	int front,rear;							//定义队首和队尾指针
	int lnum,max,i,n;
	front=rear=0;							//置队列为空队
    if (b!=NULL) 
	{
		rear++;	
		Qu[rear].p=b;						//根节点指针入队
		Qu[rear].lno=1;						//根节点的层次编号为1
		while (rear!=front)					//队列不为空
		{
			front++;
			b=Qu[front].p;					//队头出队
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)			//左孩子入队
			{
				rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)			//右孩子入队
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
int Nodes(BTNode *b)	//求二叉树b的节点个数
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
int LeafNodes(BTNode *b)	//求二叉树b的叶子节点个数
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
	printf("二叉树的基本运算如下:\n");
	printf("  (1)输出二叉树:");Disp(b);printf("\n");
	printf("  (2)H节点:");
	p=FindNode(b,'H');
	if (p!=NULL)
	{	lp=LchildNode(p);
		if (lp!=NULL) 
			printf("左孩子为%c ",lp->data);
		else
			printf("无左孩子 ");
		rp=RchildNode(p);
		if (rp!=NULL)
			printf("右孩子为%c",rp->data);
		else
			printf("无右孩子 ");
	}
	printf("\n");
	printf("  (3)二叉树b的深度:%d\n",BTNodeDepth(b));
	printf("  (4)二叉树b的宽度:%d\n",BTWidth(b));
	printf("  (5)二叉树b的节点个数:%d\n",Nodes(b));
	printf("  (6)二叉树b的叶子节点个数:%d\n",LeafNodes(b));
	printf("  (7)释放二叉树b\n");
	DestroyBTNode(b);
}
