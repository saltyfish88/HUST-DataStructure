#include "queue.h"

/**********************************************
*�������ƣ�InitQueue
*�������ܣ�����һ���ն���Q
*���������LinkQueue Q
*����ֵ������ִ��״̬����������ɹ�������OK
**********************************************/
Status InitQueue(LinkQueue & Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);						//�洢����ʧ��
	Q.front->next = NULL;
	return OK;
}

/**********************************************
*�������ƣ�DestroyQueue
*�������ܣ����ٶ���Q,Q���ٴ���
*���������LinkQueue Q
*����ֵ������ִ��״̬��������ٳɹ�������OK
**********************************************/
Status DestroyQueue(LinkQueue & Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

/**********************************************
*�������ƣ�ClearQueue
*�������ܣ�Q����ʱ����ն���Q
*���������LinkQueue Q
*����ֵ������ִ��״̬�������ճɹ�������OK��
���򷵻�ERROR
**********************************************/
Status ClearQueue(LinkQueue & Q)
{
	if (!Q.front) return ERROR;
	while (Q.front->next)
	{
		Q.rear = Q.front->next;
		Q.front->next = Q.front->next->next;
		free(Q.rear);
	}
	Q.rear = Q.front;
	return OK;
}

/***********************************************************
*�������ƣ�QueueLength
*�������ܣ�������д��ڣ����ض���Ԫ�ظ���
*���������LinkQueue Q
*����ֵ������Ԫ�ظ�����������в����ڣ�����INFEASIBLE
***********************************************************/
int QueueLength(LinkQueue Q)
{
	QueuePtr t; int i = 0;
	if (!Q.front) return INFEASIBLE;
	t = Q.front->next;
	while (t)
	{
		t = t->next;
		i++;
	}
	return i;
}

/**********************************************************************
*�������ƣ�EnQueue
*�������ܣ�������д��ڣ�����Ԫ��eΪQ���µĶ�βԪ��
*�������������LinkQueue Q��Ҫ�����Ԫ��QElemType e
*����ֵ������ִ��״̬���������ɹ�������OK��������в����ڣ�����ERROR
***********************************************************************/
Status EnQueue(LinkQueue & Q, QElemType e)
{
	QueuePtr p;
	if (!Q.front) return ERROR;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

/**********************************************************************
*�������ƣ�DeQueue
*�������ܣ������в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
*�������������LinkQueue Q��ɾ����Ԫ��QElemType e
*����ֵ������ִ��״̬�����ɾ���ɹ�������OK���������Ϊ�ջ򲻴��ڣ�����ERROR
***********************************************************************/
Status DeQueue(LinkQueue & Q, QElemType & e)
{
	QueuePtr p;
	if (Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

/**********************************************************************
*�������ƣ�QueueTraverse
*�������ܣ��������Ѵ����ҷǿգ���Ӷ�ͷ����β�����ζ�Q��ÿ������Ԫ��
���ú���visit()��һ��visit()ʧ�ܣ������ʧ��
*�������������LinkQueue Q������visit()
*����ֵ������ִ��״̬����������ɹ�������OK�����򷵻�ERROR
***********************************************************************/
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType))
{
	QueuePtr p;
	if (Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	return OK;
}
