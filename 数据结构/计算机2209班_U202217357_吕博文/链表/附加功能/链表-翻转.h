#ifndef reverseList_
#define reverseList_
status reverseList(LinkList &L)
{
	LNode*pr=L;
	LNode*trans=NULL;
	LNode*re=NULL;
	if(L==NULL){return INFEASIBLE;}//链表不存在。 
	if(L->next==NULL||L->next->next==NULL){return OK;}//空链表或只含有一个元素的链表。 
	trans=L->next;
	re=L->next->next;
	while(trans!=NULL)
	{
		if(pr!=L){trans->next=pr;}//改变指针方向。
		else{trans->next=NULL;}//第一个元素的next指向NULL。 
		pr=trans;//移动到下一个元素。 
		trans=re;
		if(re!=NULL){re=re->next;}
	}
	L->next=pr;
	return OK;
}
#endif
