#include "def.h"
#include "˳���-����.h"
int main() {
	SqList L;
	int f,i,j;
	scanf("%d",&f);
	if (!f) {
		L.elem=NULL;
		j=ListTraverse(L); 
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա���б���������");
	}
	else {
		L.elem=(ElemType *) malloc(sizeof(ElemType)*10);
		L.length=0;
		L.listsize= 10;
		scanf("%d",&i);
		while (i) {
			L.elem[L.length++]=i;
			scanf("%d",&i);
		}
		j=ListTraverse(L);
		if(j==OK && !L.length) printf("�����Ա�\n");
		free(L.elem);
	}
	return 1;
}
