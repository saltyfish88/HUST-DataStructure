#ifndef ListInsert_
#define  ListInsert_
status ListInsert(LinkList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	LNode*trans=L;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    if(i<=0){return ERROR;}//����Խ�硣 
    while(trans!=NULL&&i>1)//Ѱ�ҵ�i��Ԫ�ء� 
    {
    	i--;
    	trans=trans->next;
	}
	if(trans==NULL){return ERROR;}//����Խ�硣 
	LNode*p=(LNode*)malloc(sizeof(LNode));//����ռ䡣 
	p->next=trans->next;//���롣 
	p->data=e;
	trans->next=p;
	return OK;
}
#endif

