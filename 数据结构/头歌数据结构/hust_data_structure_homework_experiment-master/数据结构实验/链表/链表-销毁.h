#ifndef DestroyList_
#define DestroyList_
status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
	LNode*trans=L;
	if(L==NULL){return INFEASIBLE;}//���Ա�Ϊ�ա� 
	while(trans!=NULL)//�������Ա� 
	{
		LNode*p=trans;
		trans=trans->next;
		free(p);//�ͷŽڵ�Ŀռ䡣 
	}
	L=NULL;//ͷ�ڵ�ָ��ա� 
	return OK;
}
#endif
