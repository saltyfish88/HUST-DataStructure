#ifndef SaveList_
#define SaveList_
status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
	LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//空表。 
    FILE*fp=fopen(FileName,"w");//打开只写。 
    if(!fp){return ERROR;}//打开失败。 
    trans=L->next;
    while(trans!=NULL)//写入数据。 
    {
    	fprintf(fp,"%d",trans->data);
    	trans=trans->next;
    	if(trans!=NULL){fprintf(fp," ");}
	}
	fclose(fp);
	return OK;
}
#endif
#ifndef LoadList_
#define LoadList_
status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
	int m=0;
    if(L!=NULL){return INFEASIBLE;}//空表。 
    FILE*fp=fopen(FileName,"r");//打开只读。 
    if(!fp){return ERROR;}//打开失败。 
    L=(LNode*)malloc(sizeof(LNode));//分配空间。 
    LNode*last=L;
    while(fscanf(fp,"%d",&m)!=EOF)//读入数据。 
    {
    	LNode*p=(LNode*)malloc(sizeof(LNode));
    	p->next=NULL;
    	p->data=m;
    	last->next=p;
    	last=p;
	}
	fclose(fp);
	return OK;
}
#endif
