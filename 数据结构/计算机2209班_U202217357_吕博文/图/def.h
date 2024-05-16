#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_SIZE 100
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct 
{
    KeyType  key;
    char others[20];
}VertexType; //�������Ͷ���
typedef struct ArcNode //�������Ͷ���
{         
   	int adjvex;              //����λ�ñ�� 
    struct ArcNode  *nextarc;	   //��һ������ָ��
}ArcNode;
typedef struct VNode//ͷ��㼰���������Ͷ���
{
   	VertexType data;       	//������Ϣ
    ArcNode *firstarc;      	 //ָ���һ����
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct //�ڽӱ�����Ͷ���
{
    AdjList vertices;     	 //ͷ�������
    int vexnum,arcnum;   	  //������������
    GraphKind  kind;        //ͼ������
}ALGraph;
void visit(VertexType v){printf(" %d %s",v.key,v.others);}
void free0(void  *p);
typedef struct//ͼ�Ĺ����Ķ��塣 
{
	ALGraph graphs[MAX_SIZE];
	char*name[MAX_SIZE];
	int len;
	const int listsize=MAX_SIZE;
}ALGraphs;
int book[MAX_VERTEX_NUM]={0};

