#ifndef ListEmpty_
#define ListEmpty_
status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(L==NULL){return INFEASIBLE;}//�ձ� 
	if(L->next==NULL){return TRUE;}
	else{return FALSE;}
}
#endif

