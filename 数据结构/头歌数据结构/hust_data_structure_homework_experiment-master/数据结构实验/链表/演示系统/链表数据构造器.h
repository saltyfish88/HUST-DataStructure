#ifndef DATACREATER
#define DATACREATER
int getrnum()
{
	srand((unsigned)time(NULL));
	return 1+rand()%10000007;
} 
void createdataforlinkedlist(LinkList &L,int len,const char name[])//��������������ݡ� 
{
	int i=0,n=0;
	LNode *s,*r=L;
	LNode*trans=NULL;
	srand((unsigned)time(NULL));
	if(L->next!=NULL){return;}
    for(i=0;i<len;i++)//���졣 
	{
		n=1+rand()%10000007;
		s=(LNode*)malloc(sizeof(LNode));
		s->data=n;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	trans=L->next;//�洢�� 
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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
