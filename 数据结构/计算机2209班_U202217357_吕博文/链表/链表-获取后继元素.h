#ifndef NextElem_
#define NextElem_
status NextElem(LinkList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    if(L->next==NULL){return ERROR;}//���һ��Ԫ���޺�̡� 
    trans=L->next;
    while(trans->next!=NULL&&e!=trans->data){trans=trans->next;}//Ѱ��Ԫ��e�� 
    if(trans->next==NULL){return ERROR;}//δ�ҵ�Ԫ��e�� 
    else
    {
    	next=trans->next->data;
    	return OK;
	}
}
#endif

