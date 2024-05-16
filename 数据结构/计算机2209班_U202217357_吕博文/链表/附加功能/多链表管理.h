#ifndef InitLists_
#define InitLists_
status InitLists(LinkLists*&list_table)//��ʼ������� 
{
	if(list_table!=NULL){return INFEASIBLE;}//������Ѵ��ڡ� 
	list_table=(LinkLists*)malloc(sizeof(LinkLists));//����ռ䡣 
	list_table->next=NULL;
	return OK;
}
#endif
#ifndef DestroyLists_
#define DestroyLists_
status DestroyLists(LinkLists*&list_table)//���ٹ���� 
{
	LinkLists*trans=list_table;
	if(list_table==NULL){return INFEASIBLE;}//�ձ� 
	while(trans!=NULL)//���տռ䡣 
	{
		LinkLists*p=trans;
		trans=trans->next;
		free(p);
	}
	list_table=NULL;
	return OK;
}
#endif
#ifndef AddList_
#define AddList_
status AddList(LinkLists*&list_table,LinkList a,char name[])//����Ԫ�ء� 
{
	LinkLists*trans=list_table;
	if(list_table==NULL){return INFEASIBLE;}//�ձ� 
	while(trans->next!=NULL)//Ѱ��β�ڵ㡣 
	{
		trans=trans->next;
		if(strcmp(trans->name,name)==0){return INFEASIBLE;}
	}
	LinkLists*p=(LinkLists*)malloc(sizeof(LinkLists));//����ռ䡣 
	p->heads=a;//���ơ� 
	strcpy(p->name,name);
	p->next=NULL;
	trans->next=p;
	return OK;
}
#endif
#ifndef DelList_
#define DelList_
status DelList(LinkLists*&list_table,char name[])//ɾ��Ԫ�ء� 
{
	LinkLists*trans=list_table;
	if(list_table==NULL){return INFEASIBLE;}//�ձ� 
	while(trans->next!=NULL&&strcmp(name,trans->next->name)!=0){trans=trans->next;}//��������Ѱ�����Ա��ǰ���� 
	if(trans->next==NULL){return ERROR;}//δ�ҵ����Ա� 
	LinkLists*p=trans->next;//ɾ���� 
	trans->next=trans->next->next;
	free(p);
	return OK;
}
#endif
#ifndef FindList_
#define FindList_
LinkList FindList(LinkLists*list_table,char name[])//����Ԫ�ء� 
{
	LinkLists*trans=NULL;
	if(list_table==NULL){return NULL;}
	trans=list_table->next;
	while(trans!=NULL&&strcmp(trans->name,name)!=0){trans=trans->next;}//��������Ѱ�����Ա� 
	if(trans==NULL){return NULL;}
	else{return trans->heads;}
}
#endif
