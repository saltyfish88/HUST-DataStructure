#include "def.h"
#include "˳���-����ǰ��Ԫ��.h"
int main() {
	SqList L;
	int f,i,j,e,pre;
	scanf("%d",&f);
	if (!f) {
		L.elem=NULL;
		L.length=3;
		j=PriorElem(L,e,pre); 
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա����ǰ��Ԫ��");
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
		scanf("%d",&e);
		j=PriorElem(L,e,pre);
		if(j==ERROR) printf("ERROR");
		if(j==OK) printf("OK\n%d",pre);
		free(L.elem);
	}
	return 1;
}
