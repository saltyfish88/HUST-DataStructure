#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define YES 1
#define NO 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int KeyType; 
typedef struct
{
KeyType  key;
char others[20];
}TElemType; //二叉树结点类型定义
typedef struct BiTNode{  //二叉链表结点的定义
TElemType  data;
struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
typedef struct 
{
int pos;
TElemType data;
}DEF;
status JudgeBiTree(BiTree T);
status CreateBiTree(BiTree &T,DEF definition[]);
int main()
{
DEF definition[100];
BiTree T;
int ans,i=0;
do {
	scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
} while (definition[i++].pos);
CreateBiTree(T,definition);
if (JudgeBiTree(T))
	   printf("YES");
else 	printf("NO");
return 1;
}
status JudgeBiTree(BiTree T)
//判断二叉树T是否为二叉排序树
{
	if(T==NULL){return 1;}
	if(T->lchild==NULL&&T->rchild==NULL){return 1;}
	else if(T->rchild==NULL)
	{
		if(T->lchild->data.key<T->data.key)
		{
			BiTNode*trans=T->lchild;
			while(trans->rchild!=NULL){trans=trans->rchild;}
			if(T->data.key<trans->data.key){return 0;}
			return JudgeBiTree(T->lchild);
		}
		else{return 0;}
	}
	else if(T->lchild==NULL)
	{
		if(T->rchild->data.key>T->data.key)
		{
			BiTNode*trans=T->rchild;
			while(trans->lchild!=NULL){trans=trans->lchild;}
			if(T->data.key>trans->data.key){return 0;}
			return JudgeBiTree(T->rchild);
		}
		else{return 0;}
	}
	else
	{
		if(T->lchild->data.key<T->data.key&&T->rchild->data.key>T->data.key)
		{
			BiTNode*trans=T->rchild;
			while(trans->lchild!=NULL){trans=trans->lchild;}
			if(trans->data.key<T->data.key){return 0;}
			trans=T->lchild;
			while(trans->rchild!=NULL){trans=trans->rchild;}
			if(T->data.key<trans->data.key){return 0;}
			return JudgeBiTree(T->lchild)&&JudgeBiTree(T->rchild);
		}
		else{return 0;}
	}
}
status CreateBiTree(BiTree &T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	 p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	   else      p[j/2]->lchild=p[j];
       i++;
    }
    T=p[1];
    return OK;
}
