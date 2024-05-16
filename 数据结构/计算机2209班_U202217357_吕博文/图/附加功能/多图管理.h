#ifndef DestroyGraph_
#define DestroyGraph_
status DestroyGraph(ALGraph &G)
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
{
    int i=0;
    ArcNode*trans=NULL;
    ArcNode*pr=NULL;
    while(i<G.vexnum)
    {
    	trans=G.vertices[i].firstarc;
    	while(trans!=NULL)
    	{
    		pr=trans;
    		trans=trans->nextarc;
    		free(pr);
    		pr=NULL;
		}
		i++;
	}
	G.vexnum=0;
	G.arcnum=0;
}
#endif
status InitALGraphs(ALGraphs &graphlist)//��ʼ��ͼ�Ĺ���� 
{
	if(graphlist.graphs!=NULL){return INFEASIBLE;}//ͼ�Ĺ�����Ѵ��ڡ� 
	graphlist.len=0;
	//graphlist.listsize=MAX_SIZE;
	return OK;
}
status DestroyALGraphs(ALGraphs &graphlist)//����ͼ�Ĺ����
{
	int i=0;
	if(graphlist.graphs==NULL){return INFEASIBLE;}
	for(i=0;i<graphlist.len;i++)
	{
		free(graphlist.name[i]);
		DestroyGraph(graphlist.graphs[i]); 
	}
	graphlist.len=0;
	//graphlist.listsize=0;
	return OK;
}
status AddALGraph(ALGraphs &graphlist,ALGraph G,char name[])//�����µ�ͼ�� 
{
	int len;
	if(graphlist.graphs==NULL){return INFEASIBLE;}//ͼ�Ĺ�������ڡ�
	len=strlen(name);
	if(graphlist.listsize==graphlist.len){return OVERFLOW;}//ͼ�Ĺ���������� 
	//graphlist.graphs[graphlist.len]=(ALGraph*)malloc(sizeof(ALGraph));
	graphlist.graphs[graphlist.len]=G;//����ͼ�� 
	graphlist.name[graphlist.len]=(char*)malloc(len*sizeof(char));
	strcpy(graphlist.name[graphlist.len],name);
	graphlist.len++;
	return OK;
}
status DeleteALGraph(ALGraphs &graphlist,char name[])//ɾ��ͼ�� 
{
	int i=0,len=0;
	if(graphlist.graphs==NULL){return INFEASIBLE;}//ͼ�Ĺ�������ڡ�
	for(i=0;i<graphlist.len;i++){if(strcmp(name,graphlist.name[i])==0){break;}}
	if(graphlist.len==i){return ERROR;}//����ʧ�ܡ�
	//free(graphlist.graphs[i]); 
	DestroyGraph(graphlist.graphs[i]); 
	for(;i<graphlist.len-1;i++)//�ƶ��ڵ㡣 
	{
		graphlist.graphs[i]=graphlist.graphs[1+i];
		free(graphlist.name[i]);
		graphlist.name[i]=(char*)malloc(strlen(graphlist.name[1+i])*sizeof(char));
		strcpy(graphlist.name[i],graphlist.name[1+i]); 
	}
	free(graphlist.name[graphlist.len-1]);
	//graphlist.graphs[graphlist.len-1]=NULL;
	graphlist.len--;
	return OK;
}
status SearchALGraph(ALGraphs graphlist,char name[],ALGraph &G)//����ͼ�� 
{
	int i=0;
	if(graphlist.len==0){return ERROR;}//ͼ�Ĺ�������ڡ�
	for(i=0;i<graphlist.len;i++)
	{
		if(strcmp(name,graphlist.name[i])==0)//���ҳɹ��� 
		{
			G=graphlist.graphs[i];
			return OK;
		}
	}
	return ERROR;
}
