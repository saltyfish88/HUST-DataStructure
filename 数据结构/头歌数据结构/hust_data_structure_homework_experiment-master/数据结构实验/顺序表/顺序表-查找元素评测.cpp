#include "def.h"
#include "˳���-����Ԫ��.h"
int main() {
	SqList L;
	int f,i,j,e;
	scanf("%d",&f);
	if (!f) {
		L.elem=NULL;
		L.length=3;
		j=LocateElem(L,e); 
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա����Ԫ��");
		
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
		j=LocateElem(L,e);
		if(j==ERROR) printf("ERROR");
		else printf("%d",j);
		free(L.elem);
	}
	return 1;
}
