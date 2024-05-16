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
} TElemType; //二叉树结点类型定义
typedef struct BiTNode//二叉链表结点的定义
{
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
void visit(BiTree T){printf(" %d,%s",T->data.key,T->data.others);}//遍历visit函数。 
void free0(void*p);
typedef struct//二叉树的管理表的定义。 
{
	BiTree trees[MAX_SIZE];//二叉树指针。 
	char*name[MAX_SIZE];//名字。 
	int len;
	const int listsize=MAX_SIZE;
}BiTrees;

