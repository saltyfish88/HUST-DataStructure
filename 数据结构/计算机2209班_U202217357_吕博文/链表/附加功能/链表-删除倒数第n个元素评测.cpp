#include "../def.h"
#include "链表-删除倒数第n个元素.h"
int main() {
	LinkList L;
	int f,i,j,e;
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=RemoveNthFromEnd(L,1);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("可能会对不存在的线性表进行删除。");
    }
    else {
    	L=(LinkList) malloc(sizeof(LNode));
		L->next=NULL;
		LNode *s,*r=L;
    	scanf("%d",&i);
     	while (i) {
			s=(LNode*) malloc(sizeof(LNode));
			s->data=i;
			r->next=s;
			r=s;
			scanf("%d",&i);
		}
		scanf("%d",&e);
		r->next=NULL;
		j==RemoveNthFromEnd(L,e);
		r=L->next;
		while(r)
		{
			printf("%d ",r->data);
			r=r->next;
		}
	}
	return 1;
}
