#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node * next;
}NODE,* PNODE;

//��������
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

	printf("��������Ҫ���ɽڵ�ĸ�����len=",);
	scanf("%d",&len);

	for(i=0;i<len;i++){
		printf("������%d���ڵ��ֵ��",i+1);
		scanf("%d",&val);

	}

}

void traverse_list(PNODE pHead){

}
	