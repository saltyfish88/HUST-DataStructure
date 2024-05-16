#ifndef NextElem_
#define NextElem_
status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//空表。 
    if(L->next==NULL){return ERROR;}//最后一个元素无后继。 
    trans=L->next;
    while(trans->next!=NULL&&e!=trans->data){trans=trans->next;}//寻找元素e。 
    if(trans->next==NULL){return ERROR;}//未找到元素e。 
    else
    {
    	next=trans->next->data;
    	return OK;
	}
}
#endif

