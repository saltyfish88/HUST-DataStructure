//
// stack.h
//
// Description
// ������һ��˳��ջ��

#pragma once

#ifndef _STACK_H
#define _STACK_H

#include<stdlib.h>
#include<malloc.h>
#include"tree.h"

#define OK 1
#define ERROR 0
typedef int Status;
typedef CTree * SElemType;
// - - - - - ջ��˳��洢��ʾ - - - - -
#define STACK_INIT_SIZE 100		//�洢�ռ��ʼ������
#define STACKINCREMENT 10		//�洢�ռ��������
typedef struct
{
	SElemType * base;			//��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType * top;			//ջ��ָ��
	int stacksize;				//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

Status InitStack(SqStack &S);
Status GetTop(SqStack S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
#endif // !_STACK_H
