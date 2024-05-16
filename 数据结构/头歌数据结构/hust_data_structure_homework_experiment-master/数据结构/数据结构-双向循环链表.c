#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedlistNode
{
	int value;
	struct LinkedlistNode*last;
	struct LinkedlistNode*next;
}Node;
void add(int control,int value,Node**phead);//�����������Ԫ�أ����Դ�ͷ��ӻ��β��ӣ�β-1ͷ1�� 
void printall(int control,int index,Node**phead);//��ָ����������ʼ������������Ԫ�أ����������������-1��1�� 
void deletenode(int index,Node**phead);//ɾ����㣨֧����������
int main()
{
Node*head=(Node*)malloc(sizeof(Node));
head->last=NULL;
head->next=NULL;
Node**phead=&head;
add(1,0,phead);
add(-1,2,phead);
add(1,3,phead);
deletenode(2,phead);
printall(-1,0,phead);
}
void add(int control,int value,Node**phead)
{
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=value;
	p->next=NULL;
	if((*phead)->next==NULL)
	{
		p->last=p;
		(*phead)->next=p;
		p->next=p;
		return;
	}
	Node*findhead=(*phead)->next;
	Node*findlast=findhead->last;
	p->last=findlast;
	p->next=findhead;
	findhead->last=p;
	findlast->next=p;
	if(control==1){(*phead)->next=p;}
}
void printall(int control,int index,Node**phead)
{
	int i=0;
	/*if((*phead)->next==NULL){return;}*///����������� 
	Node*find=(*phead)->next;
	for(i=0;i<index;i++){find=find->next;}
	Node*tran=find;
	if(control==1)
	{
		do
	    {
		    printf("%d ",tran->value);
		    tran=tran->last;
	    }
	    while(tran!=find);
	}
	else if(control==-1)
	{
		do
		{
			printf("%d ",tran->value);
			tran=tran->next;
		}
		while(tran!=find);
	}
}
void deletenode(int index,Node**phead)
{
	int i=0;
	if(index>=0)
	{
		Node*find=(*phead)->next;
		for(i=0;i<index;i++){find=find->next;}
		Node*findlast=find->last;
		Node*findnext=find->next;
		findlast->next=findnext;
		findnext->last=findlast;
		if(index==0){(*phead)->next=find->next;}
		free(find);
		return;
	}
}
