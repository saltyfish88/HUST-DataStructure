#ifndef InitLists_
#define InitLists_
status InitLists(LinkLists*&list_table)//初始化管理表。 
{
	if(list_table!=NULL){return INFEASIBLE;}//管理表已存在。 
	list_table=(LinkLists*)malloc(sizeof(LinkLists));//分配空间。 
	list_table->next=NULL;
	return OK;
}
#endif
#ifndef DestroyLists_
#define DestroyLists_
status DestroyLists(LinkLists*&list_table)//销毁管理表。 
{
	LinkLists*trans=list_table;
	if(list_table==NULL){return INFEASIBLE;}//空表。 
	while(trans!=NULL)//回收空间。 
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
status AddList(LinkLists*&list_table,LinkList a,char name[])//增加元素。 
{
	LinkLists*trans=list_table;
	if(list_table==NULL){return INFEASIBLE;}//空表。 
	while(trans->next!=NULL)//寻找尾节点。 
	{
		trans=trans->next;
		if(strcmp(trans->name,name)==0){return INFEASIBLE;}
	}
	LinkLists*p=(LinkLists*)malloc(sizeof(LinkLists));//分配空间。 
	p->heads=a;//复制。 
	strcpy(p->name,name);
	p->next=NULL;
	trans->next=p;
	return OK;
}
#endif
#ifndef DelList_
#define DelList_
status DelList(LinkLists*&list_table,char name[])//删除元素。 
{
	LinkLists*trans=list_table;
	if(list_table==NULL){return INFEASIBLE;}//空表。 
	while(trans->next!=NULL&&strcmp(name,trans->next->name)!=0){trans=trans->next;}//根据名字寻找线性表的前驱。 
	if(trans->next==NULL){return ERROR;}//未找到线性表。 
	LinkLists*p=trans->next;//删除。 
	trans->next=trans->next->next;
	free(p);
	return OK;
}
#endif
#ifndef FindList_
#define FindList_
LinkList FindList(LinkLists*list_table,char name[])//查找元素。 
{
	LinkLists*trans=NULL;
	if(list_table==NULL){return NULL;}
	trans=list_table->next;
	while(trans!=NULL&&strcmp(trans->name,name)!=0){trans=trans->next;}//根据名字寻找线性表。 
	if(trans==NULL){return NULL;}
	else{return trans->heads;}
}
#endif
