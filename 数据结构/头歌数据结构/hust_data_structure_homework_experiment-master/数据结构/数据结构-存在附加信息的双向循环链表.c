#include<stdio.h>
#include<stdlib.h>
#define LIST_MAX 10000
typedef struct LinkedlistNode//����Ľ�� 
{
	int value;
	struct LinkedlistNode*last;
	struct LinkedlistNode*next;
}Node;
typedef struct Linkedlistinfo//�����������Ϣ 
{
	int number;//���ĸ��� 
	Node**phead;//�����ͷָ�� 
	Node*indexlist[LIST_MAX];//�������� 
}List;
void add(int control,int value,List*plist);//�����������Ԫ�أ����Դ�ͷ��ӻ��β��ӣ�β-1ͷ1�� 
void printall(int control,int index,List*plist);//��ָ����������ʼ������������Ԫ�أ����������������-1��1��
void deletenode(int index,List*plist);//ɾ����㣨֧���������� 
int main()
{List list0;
List*plist=&list0;
Node*head=(Node*)malloc(sizeof(Node));
head->last=NULL;
head->next=NULL;
list0.number=0;
list0.phead=&head;//��ʼ������ 
add(1,0,plist);
add(-1,2,plist);
add(1,3,plist);
printall(-1,0,plist);
}
void add(int control,int value,List*plist)
{
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=value;
	p->next=NULL;
	if((*plist->phead)->next==NULL)
	{
		p->last=p;
		(*(plist->phead))->next=p;
		p->next=p;
		plist->indexlist[0]=p;
		plist->number=1;
		return;
	}
	Node*findhead=(*(plist->phead))->next;
	Node*findlast=findhead->last;
	p->last=findlast;
	p->next=findhead;
	findhead->last=p;
	findlast->next=p;
	plist->indexlist[plist->number]=p;
	plist->number++;
	if(control==1){(*(plist->phead))->next=p;}
}
void printall(int control,int index,List*plist)
{
	int i=0;
	/*if((*phead)->next==NULL){return;}*///����������� 
	Node*find=plist->indexlist[index];
	//Node*find=(*phead)->next;
	//for(i=0;i<index;i++){find=find->next;}
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
void deletenode(int index,List*plist)
{
	if(index>=0)
	{
		if(index==0){*(plist->phead)->next=plist->indexlist[]
		Node*find=plist->indexlist[index]
		Node*findlast=find->last;
		Node*findnext=find->next;
		findlast->next=findnext;
		findnext->last=findlast;
		free(find);
		return;
	}
}
