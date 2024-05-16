#ifndef ListTraverse_
#define ListTraverse_
status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//空表。 
    trans=L->next;
    while(trans!=NULL)//遍历。 
    {
    	printf("%d",trans->data);
    	trans=trans->next;
    	if(trans){printf(" ");}
	}
	return OK;
}
#endif
