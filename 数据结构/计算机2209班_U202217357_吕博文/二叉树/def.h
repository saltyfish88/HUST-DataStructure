#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_SIZE 10000
typedef int status;
typedef int KeyType; 
typedef struct
{
    KeyType  key;
    char others[20];
} TElemType; //������������Ͷ���
typedef struct BiTNode//����������Ķ���
{
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
void visit(BiTree T){printf(" %d,%s",T->data.key,T->data.others);}//����visit������ 
void free0(void*p);
typedef struct//�������Ĺ����Ķ��塣 
{
	BiTree trees[MAX_SIZE];//������ָ�롣 
	char*name[MAX_SIZE];//���֡� 
	int len;
	const int listsize=MAX_SIZE;
}BiTrees;

