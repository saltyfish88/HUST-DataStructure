#include "../def.h"
#include "˳���-��Ϊk�����������.h"
int main()
{
SqList L;
int f,i,j,e; 
scanf("%d",&f);
if (!f)
	{
	    L.elem=NULL;
        j=SubArrayNum(L,0);
        if (j==INFEASIBLE) printf("INFEASIBLE");
        else printf("���ܶԲ����ڵ����Ա���к�Ϊk�����������������");
	}

else
     {
     L.elem=(ElemType *) malloc(sizeof(ElemType)*10);
     L.length=0;
     L.listsize= 10;
     scanf("%d",&i);
     while (i)
     {
         L.elem[L.length++]=i;
         scanf("%d",&i);
     }
     scanf("%d",&e);
     j=SubArrayNum(L,e);
     printf("%d\n",j);
     }
return 1;
}
