#ifndef LocateElem_
#define LocateElem_
status LocateElem(LinkList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
	int ret=1;
	LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    trans=L->next;
    while(trans!=NULL)//Ѱ��Ԫ��e�� 
    {
    	if(e==trans->data){return ret;}
    	ret++;
    	trans=trans->next;
	}
	return ERROR;
}
#endif

