#include "def.h"
#include "����-�ļ�����.h"
#include "string.h"

int main() {
	LinkList L;
	int f,i=0,j,e;
	FILE *fp;
	char FileName[30];
	strcpy(FileName,"");
	scanf("%d",&f);
	if (!f) {
		L=NULL;
		j=SaveList(L,"savetest.txt");
		if (j==INFEASIBLE) printf("INFEASIBLE\n");
    	else printf("���ܶԲ����ڵ����Ա����д�ļ�������\n");
    	
    	L=(LinkList) malloc(sizeof(LNode));
    	L->next=NULL;
        j=LoadList(L,"");
        if (j==INFEASIBLE) printf("INFEASIBLE\n");
        else printf("���ܶ��Ѵ��ڵ����Ա����д����������Ḳ��ԭ���ݣ�������ݶ�ʧ\n");
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
		j=SaveList(L,"savetest.txt");
		if(j==OK) printf("OK\n");
    	while(L)
    	{
        	s = L->next;
            L->data=0;
        	free(L);
        	L = s;
    	}
		j=LoadList(L,"savetest.txt");
		if(j==OK) printf("OK\n");
		for(s=L->next;s;s=s->next)
			printf("%d ",s->data);
	}
	return 1;
}
