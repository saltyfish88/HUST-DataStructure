#include "def.h"
#include "˳���-�п�.h"
int main() {
	SqList L;
	int i,j;
	scanf("%d",&i);
	if (i==2) { 
		L.elem=(ElemType *) malloc(sizeof(ElemType));
		L.length=0;
		j=ListEmpty(L);
		if (j==OK) printf("TRUE");
		else printf("δ��ȷ�п�");
		free(L.elem);
    }
	else if(i==1) {
		L.elem=(ElemType *) malloc(sizeof(ElemType));
		L.length=1;
		j=ListEmpty(L);
		if (j==ERROR) printf("FALSE");
		else printf("δ��ȷ�п�");
		free(L.elem);
    }
    else {
    	L.elem=NULL;
    	L.length=0;
		j=ListEmpty(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա��п�");
	}
	return 1;
}
