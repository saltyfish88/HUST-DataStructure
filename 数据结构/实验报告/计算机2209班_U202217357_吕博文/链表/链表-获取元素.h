#ifndef GetElem_
#define GetElem_
status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	LNode*trans=L;
	if(L==NULL){return INFEASIBLE;}//空表。 
	if(i<=0){return ERROR;}//索引越界。 
	while(1)//寻找元素。 
	{
		trans=trans->next;
		i--;
		if(trans==NULL){return ERROR;}//索引越界。 
		if(i==0)
		{
			e=trans->data;
			return OK;
		}
	}	
}
#endif

