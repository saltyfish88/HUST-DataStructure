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
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode  //��������ʽ�ṹ�����Ķ���
{  
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
typedef struct LinkLists  //���Ա�Ĺ������Ķ��� 
{
	char name[20];//���֡� 
	LinkList heads;//�����ͷ�ڵ㡣 
	struct LinkLists*next;
}LinkLists;
void free0(void *p);
