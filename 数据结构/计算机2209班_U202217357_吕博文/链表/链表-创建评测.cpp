#include "def.h"
#include "����-����.h"
int main() {
	LinkList L;
	int i,j;
	scanf("%d",&i);
	if (!i) { 
		L = NULL;
		j = InitList(L);
 		if (L==NULL) printf("����û����ȷ�����ͷ�ڵ�ռ�");
		if (L->next!=NULL) printf("��ͷ�ڵ����û����ȷ��ʼ��");
		if (j==OK) printf("OK");
    }
	else {
		L=(LinkList)malloc(sizeof(LNode));
		j=InitList(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
		else printf("���ܻ���Ѿ����ڵ����Ա��ʼ��");
		free(L);
	}
	return 1;
}
