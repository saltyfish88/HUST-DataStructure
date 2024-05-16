//
// tree.h
//
// Description
// ���պ��ӱ�ʾ��������һ������

#pragma once

#ifndef _TREE_H
#define _TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stack>

#define MAX_TREE_SIZE 1000
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;
typedef char * TElemType;
// - - - - - ���ĺ�������洢��ʾ - - - - -
typedef struct CTNode		//���ӽ��
{
	int child;
	CTNode * next;
}*ChildPtr;
typedef struct
{
	TElemType data;
	int indent;				//�ý��ĺ���Ҫ���ӵ�������
	ChildPtr firstchild;	//��������ͷ���
}CTBox;
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;				//������͸���λ��
}CTree;

Status InitTree(CTree & T);
Status InsertChild(CTree & T, int p, int i, CTree c);
Status GetParent(CTree T, int child, int & parent);
Status TraverseTree(CTree T, Status(*visit)(TElemType, int));

#endif // !_TREE_H

