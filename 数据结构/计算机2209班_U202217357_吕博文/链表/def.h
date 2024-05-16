#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode  //单链表（链式结构）结点的定义
{  
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
typedef struct LinkLists  //线性表的管理表结点的定义 
{
	char name[20];//名字。 
	LinkList heads;//链表的头节点。 
	struct LinkLists*next;
}LinkLists;
void free0(void *p);
