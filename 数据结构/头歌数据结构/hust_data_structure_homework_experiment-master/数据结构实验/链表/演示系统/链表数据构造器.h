#ifndef DATACREATER
#define DATACREATER
int getrnum()
{
	srand((unsigned)time(NULL));
	return 1+rand()%10000007;
} 
void createdataforlinkedlist(LinkList &L,int len,const char name[])//随机生成链表数据。 
{
	int i=0,n=0;
	LNode *s,*r=L;
	LNode*trans=NULL;
	srand((unsigned)time(NULL));
	if(L->next!=NULL){return;}
    for(i=0;i<len;i++)//构造。 
	{
		n=1+rand()%10000007;
		s=(LNode*)malloc(sizeof(LNode));
		s->data=n;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	trans=L->next;//存储。 
	FILE*fp=fopen(name,"w");
	while(trans!=NULL)
    {
    	fprintf(fp,"%d",trans->data);
    	trans=trans->next;
    	if(trans!=NULL){fprintf(fp," ");}
	}
	fclose(fp);
}
void savelistforlinklist(LinkList L,const char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
	LNode*trans=NULL;
    if(L==NULL){return;}
    FILE*fp=fopen(FileName,"w");
    trans=L->next;
    while(trans!=NULL)
    {
    	fprintf(fp,"%d",trans->data);
    	trans=trans->next;
    	if(trans!=NULL){fprintf(fp," ");}
	}
	fclose(fp);
}
#endif
