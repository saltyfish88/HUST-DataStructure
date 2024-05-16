#ifndef ListEmpty_
#define ListEmpty_
status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
	if(L==NULL){return INFEASIBLE;}//空表。 
	if(L->next==NULL){return TRUE;}
	else{return FALSE;}
}
#endif

