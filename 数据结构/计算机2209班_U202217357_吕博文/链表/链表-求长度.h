#ifndef ListLength_
#define ListLength_
int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
	int len=0;
	LNode*trans=NULL;
	if(L==NULL){return INFEASIBLE;}//�ձ� 
	trans=L->next;
	while(trans!=NULL)//��������� 
	{
		trans=trans->next;
		len++;
	}
	return len;
}
#endif

