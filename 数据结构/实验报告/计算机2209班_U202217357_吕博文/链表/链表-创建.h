#ifndef InitList_
#define InitList_
status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
	if(L!=NULL){return INFEASIBLE;}//���Ա�Ϊ�ա� 
	L=(LNode*)malloc(sizeof(LNode));//����ͷ�ڵ㡣 
	L->next=NULL;
	return OK;
}
#endif
