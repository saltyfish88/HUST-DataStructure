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
typedef struct  //˳���˳��ṹ���Ķ���
{
ElemType * elem;//Ԫ�ء� 
int length;//���� 
int listsize;//��󳤶ȡ� 
}SqList;
typedef struct{  //���Ա�Ĺ������
    struct//���ֺ����Ա� 
	{
		char name[30];
    	SqList L;	
    }elem[10];
    int length;//������� 
    int listsize;//�������󳤶ȡ� 
}LISTS;

