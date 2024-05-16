#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedlistNode
{
	struct LinkedlistNode*next;
	struct LinkedlistNode*last;
	int value;
}Node;
void add(int control,int value,Node**phead,Node**ptail);//在链表的末尾添加元素。可以选择从头添加从尾添加（尾-1头1）
void printall(int control,Node**phead,Node**ptail);//输出链表内的所有元素，可以正反输出（正-1反1） 
int main()
{Node*head=(Node*)malloc(sizeof(Node));//建立头指针。 
Node*tail=(Node*)malloc(sizeof(Node));//建立尾指针。 
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
		/*if(tran->next==NULL){return:}*///空链表的情况。
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
		/*if(tran->next==NULL){return;}*///空链表的情况。 
		Node*tran=(*ptail)->last;
		while(tran->last!=NULL)
		{
			printf("%d ",tran->value);
			tran=tran->last;
		}
		return;
	}
}
