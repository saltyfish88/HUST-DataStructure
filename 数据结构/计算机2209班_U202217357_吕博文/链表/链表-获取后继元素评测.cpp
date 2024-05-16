#include "def.h"
#include "链表-获取后继元素.h"
int main() {
	LinkList L;
	int f,i,j,e,next;
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=NextElem(L,e,next); 
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("可能会对不存在的线性表求表长");
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
		r->next=NULL;
		scanf("%d",&e);
		j=NextElem(L,e,next);
		if(j==ERROR) printf("ERROR");
		if(j==OK) printf("OK\n%d",next);
	}
	return 1;
}
