#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 5000
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
{ElemType *elem;
int length;
int listsize;
}SqList;
void  TriSqList(SqList  &A,SqList  B,SqList  C);
int main()
{
    SqList L[3];
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
    	L[i].elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    	L[i].length=0;
    	L[i].listsize=LIST_INIT_SIZE;
    	scanf("%d",&x);
    	while (x)
    	{
        	L[i].elem[L[i].length++]=x;
        	scanf("%d",&x);
    	}
    }
    TriSqList(L[0],L[1],L[2]);
    for(i=0;i<L[0].length;i++)
        printf(" %d",L[0].elem[i]);
	return 0;
}
void TriSqList(SqList  &A,SqList  B,SqList  C)
{
	int i=0,j=0;
	int num[1000];
	for(i=0;i<1000;i++){num[i]=0;}
	for(i=0;i<C.length;i++){num[C.elem[i]]++;}
	for(i=0;i<B.length;i++){num[B.elem[i]]++;}
	j=0;
	i=0;
	while(j<A.length)
	{
		if(num[A.elem[j]]==2){j++;}
		else
		{
			A.elem[i]=A.elem[j];
			j++;
			i++;
		}
	}
	A.length=i;
}

