#ifndef RemoveNthFromEnd_
#define RemoveNthFromEnd_
RemoveNthFromEnd(LinkList &L,int n)
{
	int len=0;
	LNode*trans=NULL;
	LNode*locate=L;
	if(L==NULL){return INFEASIBLE;}//空表。 
	trans=L->next;
	while(trans!=NULL)
	{
		trans=trans->next;
		len++;
	}
	if(n>len){return ERROR;}//索引越界。 
	while(len>n)//寻找元素。 
	{
		len--;
		locate=locate->next;
	}
	LNode*p=locate->next;//删除。 
	locate->next=p->next;
	free(p);
	return OK;
}
#endif
