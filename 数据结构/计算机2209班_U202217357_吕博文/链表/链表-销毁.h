#ifndef DestroyList_
#define DestroyList_
status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
	LNode*trans=L;
	if(L==NULL){return INFEASIBLE;}//线性表为空。 
	while(trans!=NULL)//遍历线性表。 
	{
		LNode*p=trans;
		trans=trans->next;
		free(p);//释放节点的空间。 
	}
	L=NULL;//头节点指向空。 
	return OK;
}
#endif
