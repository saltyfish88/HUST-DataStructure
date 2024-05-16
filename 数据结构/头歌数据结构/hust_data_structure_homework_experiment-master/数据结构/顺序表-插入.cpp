#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
{ElemType *elem;
int length;
int listsize;
}SqList;
int insert(SqList &L,ElemType x); 
int main()
{
    SqList L;
    ElemType x;
    int i;
    L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    scanf("%d",&x);
    while (x)
    {
        L.elem[L.length++]=x;
        scanf("%d",&x);
    }
    scanf("%d",&x);
    insert(L,x);
    for(i=0;i<L.length;i++)
        printf("%8d",L.elem[i]);
    if (L.length>L.listsize) printf("\n程序未处理溢出");
	return 0;
}
int insert(SqList &L,ElemType x)
{
	int i=0,find=0;
	L.elem=(int*)realloc(L.elem,(1+L.length)*sizeof(int));
	L.listsize=1+L.length;
	for(i=0;i<L.length;i++){if(L.elem[find]<x){find++;}}
	for(;i>=find;i--){L.elem[1+i]=L.elem[i];}
	i++;
	L.elem[i]=x;
	L.length++;
}
