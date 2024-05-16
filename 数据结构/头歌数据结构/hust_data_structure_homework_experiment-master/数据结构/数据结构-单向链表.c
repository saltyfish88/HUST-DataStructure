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
	Node*head=(Node*)malloc(sizeof(Node));//��������ͷ���� 
	head->next=NULL;//��ʼ������ 
	Node**phead=&head;//����ָ��ͷ����ָ�롣
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
void add(int number,Node**phead)//���������������ݡ� 
{
	Node*p=(Node*)malloc(sizeof(Node));//�����µĽ�㡣 
	p->value=number;//���½ڵ㸳ֵ�� 
	p->next=NULL;
	Node*last=*phead;//�������ĩ�ˡ� 
	if(last->next)//����ǿյ����� 
	{
		while(last->next)
	    {
		    last=last->next;
	    }
	    last->next=p;
	}
	else{(*phead)->next=p;}
}
int get(int index,Node**phead)//��������������ֵ�� 
{
	int i=0;
	Node*get=*phead;
	for(i=0;i<=index;i++)
	{
		get=get->next;
		/*if(get==NULL){return -1;}*///����Խ�������� 
	}
	return get->value;
}
void insert(int value,int index,Node**phead)//��ǿյ������в������ݣ�����ָ������ǰһ����㡣 
{
	int i=0;
	Node*findl=NULL;//����һ������ָ�������һ������ָ�롣 
	Node*findf=*phead;//����ָ������ǰһ������ָ�롣 
	Node*p=(Node*)malloc(sizeof(Node));//����һ���½�㡣 
	p->value=value;
	p->next=NULL;
	for(i=0;i<index;i++)
	{
		findf=findf->next;
		/*if(findf->next==NULL){return -1;}*///����Խ�������� 
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
		/*if(findf->next==NULL){return -1;}*///����Խ�������� 
	}
	findl=(findf->next)->next;
	free(findf->next);
	findf->next=findl;
}
int search(int value,Node**phead)
{
	int index=0,flag=0;
	Node*find=*phead;
	/*if(find->next==NULL){return -1;}*///������������ 
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
	Node*trans=(*phead)->next;//�ͷ��ڴ档 
    Node*del=*phead;
    while(trans!=NULL)
    {
	    free(del);
	    del=trans;
	    trans=trans->next;
    }
    free(del);
}
