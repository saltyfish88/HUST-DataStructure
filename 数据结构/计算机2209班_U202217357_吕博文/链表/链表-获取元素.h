#ifndef GetElem_
#define GetElem_
status GetElem(LinkList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	LNode*trans=L;
	if(L==NULL){return INFEASIBLE;}//�ձ� 
	if(i<=0){return ERROR;}//����Խ�硣 
	while(1)//Ѱ��Ԫ�ء� 
	{
		trans=trans->next;
		i--;
		if(trans==NULL){return ERROR;}//����Խ�硣 
		if(i==0)
		{
			e=trans->data;
			return OK;
		}
	}	
}
#endif

