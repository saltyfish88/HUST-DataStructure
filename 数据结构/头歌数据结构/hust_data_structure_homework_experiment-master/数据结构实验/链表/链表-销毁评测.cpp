#include "def.h"
#include "string.h"
#include "ctype.h"
#define free free0
#include "����-����.h"
#undef free
struct ptr{
    void *pused[100],*pfree[100];
    int len_used,len_free;
    } pm;
void free0(void *p)
{
    pm.pfree[pm.len_free++]=p;
    memset(p,0,sizeof(LNode));
    free(p);
}


int main()
{
	LinkList L,tail;
	int f,i,j;
	scanf("%d",&f);
	if (f==0)
	{
		L=NULL;
		j=DestroyList(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
		else printf("���ܶԲ����ڵ����Ա�������ٲ�����");
	}
	else
     {
		pm.pused[pm.len_used++]=tail=L=(LinkList) malloc(sizeof(LNode));
        scanf("%d",&f);
		while (f)
        {
            pm.pused[pm.len_used++]=tail->next=(LNode*) malloc(sizeof(LNode));
            tail=tail->next;
            tail->data=f;
            scanf("%d",&f);
        }
		tail->next=NULL;
		j=DestroyList(L);
		if (j==OK && !L)
        {
            for(i=0;i<pm.len_used;i++)
            {
                for(j=0;j<pm.len_free;j++)
                    if (pm.pused[i]==pm.pfree[j])
                        break;
                if (j>=pm.len_free)
                {
                    printf("δ��ȷ�ͷ�����Ԫ�ؿռ�");
                    return 1;
                }
            }
            printf("OK");
        }
        else printf("ERROR!");
     }
	return 1;
}

