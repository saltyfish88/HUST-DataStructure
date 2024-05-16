#ifndef ClearList_
#define ClearList_
status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
	LNode*trans=NULL;
	if(L==NULL){return INFEASIBLE;}//空表。 
	trans=L->next;
	while(trans!=NULL)//遍历回收。 
	{
		LNode*p=trans;
		trans=trans->next;
		free(p);
	}
	L->next=NULL;
	return OK;
}
#endif

