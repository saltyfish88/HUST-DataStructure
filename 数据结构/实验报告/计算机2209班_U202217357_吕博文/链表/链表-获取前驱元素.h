#ifndef PriorElem_
#define PriorElem_
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    if(L->next==NULL){return ERROR;} 
    trans=L->next;
    while(trans->next!=NULL&&trans->next->data!=e){trans=trans->next;}//Ѱ��Ԫ��e��ǰ���� 
    if(trans->next==NULL){return ERROR;}//��ǰ���� 
    else
    {
    	pre=trans->data;
    	return OK;
	}
}
#endif
