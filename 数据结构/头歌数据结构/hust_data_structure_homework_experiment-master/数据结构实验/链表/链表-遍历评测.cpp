#include "def.h"
#include "����-����.h"

int main() {
	LinkList L;
	int f,i,j,e;
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=ListTraverse(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա���б���������");
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
		j=ListTraverse(L);
		if(j==OK && L->next==NULL) printf("�����Ա�");
	}
	return 1;
}
