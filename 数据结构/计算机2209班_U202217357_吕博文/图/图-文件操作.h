#ifndef SaveGraph_
#define SaveGraph_
status SaveGraph(ALGraph G, char FileName[])
//��ͼ������д�뵽�ļ�FileName��
{
	int i=0;
	FILE*fp=fopen(FileName,"w");//��ֻд�� 
	if(!fp){return ERROR;}//��ʧ�ܡ� 
	ArcNode*trans=NULL;
	fprintf(fp,"%d %d\n",G.arcnum,G.vexnum);//д��������������� 
	for(i=0;i<G.vexnum;i++)//д���ڽӱ� 
	{
		fprintf(fp,"%d %s\n",G.vertices[i].data.key,G.vertices[i].data.others);
		trans=G.vertices[i].firstarc;
		while(trans!=NULL)
		{
			fprintf(fp,"%d ",trans->adjvex);
			trans=trans->nextarc;
		}
		fprintf(fp,"-1\n");
	}
	fclose(fp);
	return OK;
}
#endif
#ifndef LoadGraph_
#define LoadGraph_
status LoadGraph(ALGraph &G, char FileName[])
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
	int i=0,adjvex=0;
    FILE*fp=fopen(FileName,"r");//��ֻ���� 
    if(!fp){return ERROR;}//��ʧ�ܡ� 
    ArcNode*trans=NULL;
    fscanf(fp,"%d %d\n",&G.arcnum,&G.vexnum);//������������������ 
    for(i=0;i<G.vexnum;i++)//�����ڽӱ�
    {
    	fscanf(fp,"%d %s\n",&G.vertices[i].data.key,G.vertices[i].data.others);
    	trans=G.vertices[i].firstarc=NULL;
    	while(1)
    	{
    		fscanf(fp,"%d",&adjvex);
    		if(adjvex==-1){break;}
    		ArcNode*p=(ArcNode*)malloc(sizeof(ArcNode));
    		p->adjvex=adjvex;
    		p->nextarc=NULL;
    		if(trans==NULL)
			{
				G.vertices[i].firstarc=p;
				trans=p;
			}
    		else
    		{
    			trans->nextarc=p;
    			trans=p;
			}
		}
	}
	fclose(fp);
	return OK;
}
#endif

