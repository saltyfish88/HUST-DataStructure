#ifndef ListInsert_
#define  ListInsert_
status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	LNode*trans=L;
    if(L==NULL){return INFEASIBLE;}//空表。 
    if(i<=0){return ERROR;}//索引越界。 
    while(trans!=NULL&&i>1)//寻找第i个元素。 
    {
    	i--;
    	trans=trans->next;
	}
	if(trans==NULL){return ERROR;}//索引越界。 
	LNode*p=(LNode*)malloc(sizeof(LNode));//分配空间。 
	p->next=trans->next;//插入。 
	p->data=e;
	trans->next=p;
	return OK;
}
#endif

