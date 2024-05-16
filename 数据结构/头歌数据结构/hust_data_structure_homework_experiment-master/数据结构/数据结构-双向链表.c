#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedlistNode
{
	struct LinkedlistNode*next;
	struct LinkedlistNode*last;
	int value;
}Node;
void add(int control,int value,Node**phead,Node**ptail);//�������ĩβ���Ԫ�ء�����ѡ���ͷ��Ӵ�β��ӣ�β-1ͷ1��
void printall(int control,Node**phead,Node**ptail);//��������ڵ�����Ԫ�أ����������������-1��1�� 
int main()
{Node*head=(Node*)malloc(sizeof(Node));//����ͷָ�롣 
Node*tail=(Node*)malloc(sizeof(Node));//����βָ�롣 
Node**ptail=&tail;
Node**phead=&head;
tail->next=NULL;
tail->last=NULL;
head->last=NULL;
head->next=NULL;
add(1,1,phead,ptail);
add(1,2,phead,ptail);
printall(1,phead,ptail);
return 0;
}
void add(int control,int value,Node**phead,Node**ptail)
{
	Node*findlast=*phead;
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=value;
	p->next=NULL;
	if((*phead)->next==NULL)
	{
		(*phead)->next=p;
		(*ptail)->last=p;
		p->last=*phead;
		p->next=*ptail;
		return;
	}
	else if(control==-1)
	{
		Node*findlast=(*ptail)->last;
		(*ptail)->last=p;
		p->next=*ptail;
		findlast->next=p;
		p->last=findlast;
		return;
	}
	else if(control==1)
	{
		Node*findhead=(*phead)->next;
		(*phead)->next=p;
		p->next=findhead;
		findhead->last=p;
		p->last=*phead;
		return;
	}
}
void printall(int control,Node**phead,Node**ptail)
{
	if(control==-1)
	{
		/*if(tran->next==NULL){return:}*///������������
		Node*tran=(*phead)->next;
		while(tran->next!=NULL)
		{
			printf("%d ",tran->value);
			tran=tran->next;
		}
		return; 
	}
	else if(control==1)
	{
		/*if(tran->next==NULL){return;}*///������������ 
		Node*tran=(*ptail)->last;
		while(tran->last!=NULL)
		{
			printf("%d ",tran->value);
			tran=tran->last;
		}
		return;
	}
}
