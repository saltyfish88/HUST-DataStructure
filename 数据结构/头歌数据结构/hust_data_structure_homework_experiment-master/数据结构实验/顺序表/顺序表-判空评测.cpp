#include "def.h"
#include "顺序表-判空.h"
int main() {
	SqList L;
	int i,j;
	scanf("%d",&i);
	if (i==2) { 
		L.elem=(ElemType *) malloc(sizeof(ElemType));
		L.length=0;
		j=ListEmpty(L);
		if (j==OK) printf("TRUE");
		else printf("未正确判空");
		free(L.elem);
    }
	else if(i==1) {
		L.elem=(ElemType *) malloc(sizeof(ElemType));
		L.length=1;
		j=ListEmpty(L);
		if (j==ERROR) printf("FALSE");
		else printf("未正确判空");
		free(L.elem);
    }
    else {
    	L.elem=NULL;
    	L.length=0;
		j=ListEmpty(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("可能会对不存在的线性表判空");
	}
	return 1;
}
