#ifndef RemoveNthFromEnd_
#define RemoveNthFromEnd_
RemoveNthFromEnd(LinkList &L,int n)
{
	int len=0;
	LNode*trans=NULL;
	LNode*locate=L;
	if(L==NULL){return INFEASIBLE;}//�ձ� 
	trans=L->next;
	while(trans!=NULL)
	{
		trans=trans->next;
		len++;
	}
	if(n>len){return ERROR;}//����Խ�硣 
	while(len>n)//Ѱ��Ԫ�ء� 
	{
		len--;
		locate=locate->next;
	}
	LNode*p=locate->next;//ɾ���� 
	locate->next=p->next;
	free(p);
	return OK;
}
#endif
