#ifndef findmed_
#define findmed_
LNode*findmed(LinkList L)//寻找中间节点。 
{
	LNode*slow=L;//慢指针。 
	LNode*fast=L;//快指针。 
	if(L==NULL){return NULL;}//空表。 
	while(fast->next!=NULL&&fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		fast=fast->next;
	}
	return slow;
}
#endif
#ifndef mergeList_
#define mergeList_
LinkList mergeList(LinkList a,LinkList b)//合并链表。 
{
	LNode*pa=a;
	LNode*pb=b;
	LNode*head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	LNode*trans=head;
	LNode*phead=head;
	while(1)
	{
		if(pa==NULL)//a表遍历完成。 
		{
			trans->next=pb;
			break;
		}
		else if(pb==NULL)//b表遍历完成。
		{
			trans->next=pa;
			break;
		}
		else
		{
			if(pa->data<=pb->data)//比较大小插入。 
			{
				LNode*p=pa;
				pa=pa->next;
				p->next=NULL;
				trans->next=p;
				trans=p;
			}
			else
			{
				LNode*p=pb;
				pb=pb->next;
				p->next=NULL;
				trans->next=p;
				trans=p;
			}
		}
	}
	head=head->next;
	free(phead);
	return head;
}
#endif
#ifndef sortList_
#define sortList_
LinkList sortList(LinkList &L)//采用归并排序排序没有头节点的链表。 
{
	if(L==NULL||L->next==NULL){return L;}//空表或只有一个元素的线性表。 
	LNode*med=findmed(L);//寻找中间节点。 
	LNode*right=med->next;
	med->next=NULL;//拆分线性表。 
	L=sortList(L);
	right=sortList(right);
	return mergeList(L,right);//有序合并线性表。 
}
#endif
