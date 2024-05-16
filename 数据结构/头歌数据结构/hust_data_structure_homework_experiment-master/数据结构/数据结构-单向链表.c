#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedlistNode
{
	int value;
	struct LinkedlistNode*next;
}Node;
void add(int number,Node**phead); 
int get(int index,Node**phead);
void insert(int value,int index,Node**phead);
void printall(Node**phead);
Node**create();
void deletenode(int index,Node**phead);
int search(int value,Node**phead);
void clearall(Node**phead);
int main()
{
	int n=0;
	Node*head=(Node*)malloc(sizeof(Node));//创建链表头部。 
	head->next=NULL;//初始化链表。 
	Node**phead=&head;//建立指向头部的指针。
	//Node**phead=create(); 
	add(10,phead);
	add(666,phead);
	add(777,phead);
	insert(999,2,phead);
	//deletenode(3,phead);
	n=search(777,phead);
	printf("%d\n",n);
	printall(phead);
	clearall(phead);
	return 0;
}
/*Node**create()
{
	Node*head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	Node**phead=&head;
	return phead;
}*/
void add(int number,Node**phead)//向链表最后添加数据。 
{
	Node*p=(Node*)malloc(sizeof(Node));//建立新的结点。 
	p->value=number;//给新节点赋值。 
	p->next=NULL;
	Node*last=*phead;//找链表的末端。 
	if(last->next)//如果是空的链表。 
	{
		while(last->next)
	    {
		    last=last->next;
	    }
	    last->next=p;
	}
	else{(*phead)->next=p;}
}
int get(int index,Node**phead)//根据索引返回数值。 
{
	int i=0;
	Node*get=*phead;
	for(i=0;i<=index;i++)
	{
		get=get->next;
		/*if(get==NULL){return -1;}*///索引越界的情况。 
	}
	return get->value;
}
void insert(int value,int index,Node**phead)//向非空的链表中插入数据，索引指向插入的前一个结点。 
{
	int i=0;
	Node*findl=NULL;//建立一个用于指向插入点后一个结点的指针。 
	Node*findf=*phead;//建立指向插入点前一个结点的指针。 
	Node*p=(Node*)malloc(sizeof(Node));//建立一个新结点。 
	p->value=value;
	p->next=NULL;
	for(i=0;i<index;i++)
	{
		findf=findf->next;
		/*if(findf->next==NULL){return -1;}*///索引越界的情况。 
	}
	findl=findf->next;
	findf->next=p;
	p->next=findl;
}
void printall(Node**phead)
{
	if((*phead)->next==NULL){return;}
	Node*tran=(*phead)->next;
	while(tran!=NULL)
	{
		printf("%d ",tran->value);
		tran=tran->next;
	}
}
void deletenode(int index,Node**phead)
{
	int i=0;
	Node*findl=NULL;
	Node*findf=*phead;
	for(i=0;i<index;i++)
	{
		findf=findf->next;
		/*if(findf->next==NULL){return -1;}*///索引越界的情况。 
	}
	findl=(findf->next)->next;
	free(findf->next);
	findf->next=findl;
}
int search(int value,Node**phead)
{
	int index=0,flag=0;
	Node*find=*phead;
	/*if(find->next==NULL){return -1;}*///空链表的情况。 
	while(find->next!=NULL)
	{
		find=find->next;
		if(find->value==value)
		{
			flag=1;
			break;
		}
		index++;
	}
	if(flag==1){return index;}
	else{return -1;}
}
void clearall(Node**phead)
{
	Node*trans=(*phead)->next;//释放内存。 
    Node*del=*phead;
    while(trans!=NULL)
    {
	    free(del);
	    del=trans;
	    trans=trans->next;
    }
    free(del);
}
