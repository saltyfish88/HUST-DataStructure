#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef  struct  Dnode
{
ElemType data;
struct  Dnode *prior,*next;
} *DuLinkList;
void  adjust(DuLinkList  L);
int main()
{
    DuLinkList L,p,tail;
    int n,i;
    L=tail=(DuLinkList)malloc(sizeof(struct Dnode));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        p=(DuLinkList)malloc(sizeof(struct Dnode));
        scanf("%d",&p->data);
        tail->next=p;
        p->prior=tail;
        tail=p;
    }
    L->prior=tail;
    tail->next=L;
    adjust(L);
    p=L->next;
    while(p!=L)
    {
        printf(" %d",p->data);
        p=p->next;
    }
}
void  adjust(DuLinkList  L)
{
	int i=1,len=0;
	DuLinkList trans=L->next;
	int a[1000];
	while(trans!=L)
	{
	    a[i]=trans->data;
		trans=trans->next;
		i++;
	}
	len=i-1;
	trans=L->next;
	i=1;
	for(i=1;i<=len;i+=2)
	{
		trans->data=a[i];
		trans=trans->next;
	}
	if(len%2!=0){i=len-1;}
	else{i=len;}
	for(;i>0;i-=2)
	{
		trans->data=a[i];
		trans=trans->next;
	}
} 

