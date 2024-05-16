#ifndef SaveGraph_
#define SaveGraph_
status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
	int i=0;
	FILE*fp=fopen(FileName,"w");//打开只写。 
	if(!fp){return ERROR;}//打开失败。 
	ArcNode*trans=NULL;
	fprintf(fp,"%d %d\n",G.arcnum,G.vexnum);//写入边数、顶点数。 
	for(i=0;i<G.vexnum;i++)//写入邻接表。 
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
//读入文件FileName的图数据，创建图的邻接表
{
	int i=0,adjvex=0;
    FILE*fp=fopen(FileName,"r");//打开只读。 
    if(!fp){return ERROR;}//打开失败。 
    ArcNode*trans=NULL;
    fscanf(fp,"%d %d\n",&G.arcnum,&G.vexnum);//读出边数、顶点数。 
    for(i=0;i<G.vexnum;i++)//读出邻接表。
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

