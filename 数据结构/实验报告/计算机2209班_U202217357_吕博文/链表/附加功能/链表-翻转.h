#ifndef reverseList_
#define reverseList_
status reverseList(LinkList &L)
{
	LNode*pr=L;
	LNode*trans=NULL;
	LNode*re=NULL;
	if(L==NULL){return INFEASIBLE;}//�������ڡ� 
	if(L->next==NULL||L->next->next==NULL){return OK;}//�������ֻ����һ��Ԫ�ص����� 
	trans=L->next;
	re=L->next->next;
	while(trans!=NULL)
	{
		if(pr!=L){trans->next=pr;}//�ı�ָ�뷽��
		else{trans->next=NULL;}//��һ��Ԫ�ص�nextָ��NULL�� 
		pr=trans;//�ƶ�����һ��Ԫ�ء� 
		trans=re;
		if(re!=NULL){re=re->next;}
	}
	L->next=pr;
	return OK;
}
#endif
