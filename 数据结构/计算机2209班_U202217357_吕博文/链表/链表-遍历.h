#ifndef ListTraverse_
#define ListTraverse_
status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    trans=L->next;
    while(trans!=NULL)//������ 
    {
    	printf("%d",trans->data);
    	trans=trans->next;
    	if(trans){printf(" ");}
	}
	return OK;
}
#endif
