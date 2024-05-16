#ifndef PriorElem_
#define PriorElem_
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//空表。 
    if(L->next==NULL){return ERROR;} 
    trans=L->next;
    while(trans->next!=NULL&&trans->next->data!=e){trans=trans->next;}//寻找元素e的前驱。 
    if(trans->next==NULL){return ERROR;}//无前驱。 
    else
    {
    	pre=trans->data;
    	return OK;
	}
}
#endif
