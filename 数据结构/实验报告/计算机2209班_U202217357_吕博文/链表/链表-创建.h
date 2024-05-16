#ifndef InitList_
#define InitList_
status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
	if(L!=NULL){return INFEASIBLE;}//线性表不为空。 
	L=(LNode*)malloc(sizeof(LNode));//创建头节点。 
	L->next=NULL;
	return OK;
}
#endif
