#ifndef ClearList_
#define ClearList_
status ClearList(LinkList &L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
	LNode*trans=NULL;
	if(L==NULL){return INFEASIBLE;}//�ձ� 
	trans=L->next;
	while(trans!=NULL)//�������ա� 
	{
		LNode*p=trans;
		trans=trans->next;
		free(p);
	}
	L->next=NULL;
	return OK;
}
#endif

