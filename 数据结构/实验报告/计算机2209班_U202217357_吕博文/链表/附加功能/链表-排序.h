#ifndef findmed_
#define findmed_
LNode*findmed(LinkList L)//Ѱ���м�ڵ㡣 
{
	LNode*slow=L;//��ָ�롣 
	LNode*fast=L;//��ָ�롣 
	if(L==NULL){return NULL;}//�ձ� 
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
LinkList mergeList(LinkList a,LinkList b)//�ϲ����� 
{
	LNode*pa=a;
	LNode*pb=b;
	LNode*head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	LNode*trans=head;
	LNode*phead=head;
	while(1)
	{
		if(pa==NULL)//a�������ɡ� 
		{
			trans->next=pb;
			break;
		}
		else if(pb==NULL)//b�������ɡ�
		{
			trans->next=pa;
			break;
		}
		else
		{
			if(pa->data<=pb->data)//�Ƚϴ�С���롣 
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
LinkList sortList(LinkList &L)//���ù鲢��������û��ͷ�ڵ������ 
{
	if(L==NULL||L->next==NULL){return L;}//�ձ��ֻ��һ��Ԫ�ص����Ա� 
	LNode*med=findmed(L);//Ѱ���м�ڵ㡣 
	LNode*right=med->next;
	med->next=NULL;//������Ա� 
	L=sortList(L);
	right=sortList(right);
	return mergeList(L,right);//����ϲ����Ա� 
}
#endif
