#include "def.h"
#include "����-��ȡԪ��.h"
int main() {
	LinkList L;
	int f,i,j,e;
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=GetElem(L,2,e);
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
		scanf("%d",&i);
		j=GetElem(L,i,e);
		if(j==OK) printf("OK\n%d",e);
		if(j==ERROR) printf("ERROR");
	}
	return 1;
}
