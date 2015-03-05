#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node * next;
}NODE,* PNODE;

//函数声明
PNODE creat_list(void);

void main(){
	PNODE pHead=NULL;
	pHead=creat_list();
	traverse_list(pHead);
}
PNODE creat_list(void){
	int len;
	int i;
	int val;

	printf("请输入需要生成节点的个数：len=",);
	scanf("%d",&len);

	for(i=0;i<len;i++){
		printf("请输入%d个节点的值：",i+1);
		scanf("%d",&val);

	}

}

void traverse_list(PNODE pHead){

}
	