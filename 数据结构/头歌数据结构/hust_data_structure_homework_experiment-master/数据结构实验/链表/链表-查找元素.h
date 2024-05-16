#ifndef LocateElem_
#define LocateElem_
status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
	int ret=1;
	LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//空表。 
    trans=L->next;
    while(trans!=NULL)//寻找元素e。 
    {
    	if(e==trans->data){return ret;}
    	ret++;
    	trans=trans->next;
	}
	return ERROR;
}
#endif

