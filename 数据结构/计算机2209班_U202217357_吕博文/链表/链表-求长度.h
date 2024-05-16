#ifndef ListLength_
#define ListLength_
int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
	int len=0;
	LNode*trans=NULL;
	if(L==NULL){return INFEASIBLE;}//空表。 
	trans=L->next;
	while(trans!=NULL)//遍历求表长。 
	{
		trans=trans->next;
		len++;
	}
	return len;
}
#endif

