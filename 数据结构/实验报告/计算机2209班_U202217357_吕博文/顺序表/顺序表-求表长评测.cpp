#include "def.h"
#include "˳���-���.h"
int main() {
	SqList L;
	int f,i,j,c=0;
	scanf("%d",&f);
	if (!f) {
		L.elem=NULL;
    	L.length=10;
		j=ListLength(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա����");
    }
    else {
    	L.elem=(ElemType *) malloc(sizeof(ElemType));
    	scanf("%d",&i);
     	while (i) {
         ++c;
         scanf("%d",&i);
		}
		L.length=c;
		j=ListLength(L);
		printf("%d", j);
		free(L.elem);
	}
	return 1;
}
