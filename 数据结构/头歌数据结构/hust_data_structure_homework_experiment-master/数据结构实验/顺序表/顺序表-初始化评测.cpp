#include "def.h"
#include "˳���-��ʼ��.h"
int main()
{
SqList L;
int i,j;
scanf("%d",&i);
if (!i)
	{ 
	L.elem=NULL;
	j=InitList(L);
    if (L.elem==NULL)
    	printf("����û����ȷ����Ԫ�ؿռ�");
    if (L.length)
    	printf("δ��ȷ����Ԫ�ظ�����ʼֵ");
    if (L.listsize!=LIST_INIT_SIZE)
    	printf("δ��ȷ����Ԫ�ؿռ�����");
    if (j==OK) {
               printf("OK");
               L.elem[0]=1;
               L.elem[L.listsize-1]=2;
               }
    }
else
     {
     L.elem=(ElemType *) malloc(sizeof(ElemType));
 	 j=InitList(L);
     if (j==INFEASIBLE) printf("INFEASIBLE");
     else printf("���ܻ���Ѿ����ڵ����Ա��ʼ��");
     free(L.elem);
     }
return 1;
}

