#ifndef ListDelete_
#define ListDelete_
status ListDelete(LinkList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    LNode*trans=L;
    LNode*pr=NULL;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    if(i<=0){return ERROR;}
    while(trans!=NULL&&i>0)//Ѱ��ǰ���� 
    {
    	pr=trans;
    	trans=trans->next;
    	i--;
	}
	if(trans==NULL){return ERROR;}//δ�ҵ��� 
	pr->next=trans->next;//ɾ���� 
	e=trans->data;
	free(trans);
	return OK;
}
#endif

