#ifndef SaveList_
#define SaveList_
status SaveList(LinkList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
	LNode*trans=NULL;
    if(L==NULL){return INFEASIBLE;}//�ձ� 
    FILE*fp=fopen(FileName,"w");//��ֻд�� 
    if(!fp){return ERROR;}//��ʧ�ܡ� 
    trans=L->next;
    while(trans!=NULL)//д�����ݡ� 
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
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
	int m=0;
    if(L!=NULL){return INFEASIBLE;}//�ձ� 
    FILE*fp=fopen(FileName,"r");//��ֻ���� 
    if(!fp){return ERROR;}//��ʧ�ܡ� 
    L=(LNode*)malloc(sizeof(LNode));//����ռ䡣 
    LNode*last=L;
    while(fscanf(fp,"%d",&m)!=EOF)//�������ݡ� 
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
