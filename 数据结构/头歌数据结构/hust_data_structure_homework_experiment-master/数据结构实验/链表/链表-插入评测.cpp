#include "def.h"
#include "����-����.h
int main() {
	LinkList L;
	int f,i,j,e,next;
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=ListInsert(L,1,1);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܶԲ����ڵ����Ա���в��������");
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
		scanf("%d%d",&i,&e);
		j=ListInsert(L,i,e);
		printf("%s\n", j==OK? "OK" : j==ERROR? "ERROR" : "");
		for(s=L->next;s;s=s->next)
			printf("%d ",s->data);
	}
	return 1;
}
