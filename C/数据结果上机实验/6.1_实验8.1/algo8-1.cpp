//�ļ���:algo8-1.cpp
#include <stdio.h>
#include <malloc.h>
#include "graph.h"
//-------------------------------------
//--------����Ȩͼ���㷨-----------------
//-------------------------------------
void MatToList(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<g.n;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0)		//�ڽӾ���ĵ�ǰԪ�ز�Ϊ0
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
				p->adjvex=j;
				p->nextarc=G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void ListToMat(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	//g.edges[i][j]����ֵ0
	   	for (j=0;j<G->n;j++)
			g.edges[i][j]=0;
	for (i=0;i<G->n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=1;
		    p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}
void DispMat(MGraph g)		//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)	//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
//-------------------------------------
//--------��Ȩͼ���㷨-----------------
//-------------------------------------
void MatToList1(MGraph g,ALGraph *&G)
//���ڽӾ���gת�����ڽӱ�G
{
	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<g.n;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)	//����һ����
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//��*p���������
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void ListToMat1(ALGraph *G,MGraph &g)
//���ڽӱ�Gת�����ڽӾ���g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)      	//g.edges[i][j]����ֵ0
	   	for (j=0;j<G->n;j++)
			if (i==j)
				g.edges[i][j]=0;
			else
				g.edges[i][j]=INF;
	for (i=0;i<G->n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;
		    p=p->nextarc;
		}
	}
	g.n=G->n;g.e=G->e;
}
void DispMat1(MGraph g)
//����ڽӾ���g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","��");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj1(ALGraph *G)
//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d(%d)",p->adjvex,p->info);
			p=p->nextarc;
		}
		printf("\n");
	}
}
int visited[MAXV]={0};
void DFS(ALGraph *G,int v,int path[],int d)  
{  
	ArcNode *p; int w,i;
	visited[v]=1; 				//���ѷ��ʱ��
	d++;path[d]=v;
	p=G->adjlist[v].firstarc;  //pָ�����һ�߽��
	while (p!=NULL) 
	{  
		w=p->adjvex;
		if (visited[w]==0) 
		{
			if (w!=v)
			{
				printf("%3d:",w);
				for (i=0;i<=d;i++)
					printf("%3d",path[i]);
				printf("%3d\n",w);
			}
			DFS(G,w,path,d);         	//��w����δ���ʣ��ݹ������
		}
		p=p->nextarc;           //pָ�򶥵�v����һ�����Ļ�ͷ���
	}
	visited[v]=0;
}

/*void main()
{
	ALGraph *G;
	MGraph g;
	int path[MAXV],i,j,v=0;
	g.n=7;g.e=6;
	int A[MAXV][MAXV]={
		{0,1,2,3,INF,INF,INF},
		{1,0,INF,INF,2,3,INF},
		{2,INF,0,INF,INF,INF,INF},
		{3,INF,INF,0,INF,INF,INF},
		{INF,2,INF,INF,0,INF,4},
		{INF,3,INF,INF,INF,0,INF},
		{INF,INF,INF,INF,4,INF,0}};	
	for (i=0;i<g.n;i++)	
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList1(g,G);
	printf("ͼG���ڽӱ�:\n");DispAdj1(G);	//����ڽӱ�
	printf("�Ӷ���%d�������������·��:\n",v);
	DFS(G,v,path,-1);
	printf("\n");
}*/
