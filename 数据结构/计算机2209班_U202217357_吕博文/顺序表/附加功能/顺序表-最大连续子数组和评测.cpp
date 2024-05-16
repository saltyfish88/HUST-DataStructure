#include "../def.h"
#include "顺序表-最大连续子数组和.h"
int main()
{
SqList L;
int f,i,j;
scanf("%d",&f);
if (!f)
	{
	    L.elem=NULL;
        j=MaxSubArray(L);
        if (j==INFEASIBLE) printf("INFEASIBLE");
        else printf("不能对不存在的线性表进行最大连续子数组和操作！");
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
     j=MaxSubArray(L);
     printf("%d\n",j);
     }
return 1;
}
