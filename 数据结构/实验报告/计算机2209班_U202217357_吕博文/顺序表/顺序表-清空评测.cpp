#include "def.h"
#include "˳���-���.h"
int main() {
	SqList L;
	int i,j;
	scanf("%d",&i);
	if (!i) { 
		L.elem=NULL;
		j=ClearList(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա����");
    }
	else {
		L.elem=(ElemType *) malloc(sizeof(ElemType));
        L.length = 1;
		j=ClearList(L);
		if (L.length) printf("δ��ȷ���");
		if (!L.elem)  printf("�����ͷ�Ԫ�ؿռ�");
		if (j==OK) printf("OK");
		free(L.elem);
    }
	return 1;
}
