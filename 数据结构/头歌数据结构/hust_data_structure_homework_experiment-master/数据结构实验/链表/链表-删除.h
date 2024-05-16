#ifndef ListDelete_
#define ListDelete_
status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    LNode*trans=L;
    LNode*pr=NULL;
    if(L==NULL){return INFEASIBLE;}//空表。 
    if(i<=0){return ERROR;}
    while(trans!=NULL&&i>0)//寻找前驱。 
    {
    	pr=trans;
    	trans=trans->next;
    	i--;
	}
	if(trans==NULL){return ERROR;}//未找到。 
	pr->next=trans->next;//删除。 
	e=trans->data;
	free(trans);
	return OK;
}
#endif

