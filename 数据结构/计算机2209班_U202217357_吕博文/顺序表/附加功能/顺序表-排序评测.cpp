#include "../def.h"
#include "˳���-����.h"
int main()
{
SqList L;
int f,i,j;
scanf("%d",&f);
if (!f)
	{
	    L.elem=NULL;
        j=sortList(L);
        if (j==INFEASIBLE) printf("INFEASIBLE");
        else printf("���ܶԲ����ڵ����Ա�������������");
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
     j=sortList(L);
     printf("%s\n", j==OK?"OK":"ERROR");
     for(i=0;i<L.length;i++)
        printf("%d ",L.elem[i]);
     }
return 1;
}
