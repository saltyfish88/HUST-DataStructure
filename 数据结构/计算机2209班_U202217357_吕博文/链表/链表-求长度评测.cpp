#include "def.h"
#include "����-�󳤶�.h"
int main() {
	LinkList L;
	int f,i,j;
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=ListLength(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա����");
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
		j=ListLength(L);
		printf("%d", j);
	}
	return 1;
}
