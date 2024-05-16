#ifndef DestroyGraph_
#define DestroyGraph_
status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
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
status InitALGraphs(ALGraphs &graphlist)//初始化图的管理表。 
{
	if(graphlist.graphs!=NULL){return INFEASIBLE;}//图的管理表已存在。 
	graphlist.len=0;
	//graphlist.listsize=MAX_SIZE;
	return OK;
}
status DestroyALGraphs(ALGraphs &graphlist)//销毁图的管理表。
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
status AddALGraph(ALGraphs &graphlist,ALGraph G,char name[])//增加新的图。 
{
	int len;
	if(graphlist.graphs==NULL){return INFEASIBLE;}//图的管理表不存在。
	len=strlen(name);
	if(graphlist.listsize==graphlist.len){return OVERFLOW;}//图的管理表已满。 
	//graphlist.graphs[graphlist.len]=(ALGraph*)malloc(sizeof(ALGraph));
	graphlist.graphs[graphlist.len]=G;//复制图。 
	graphlist.name[graphlist.len]=(char*)malloc(len*sizeof(char));
	strcpy(graphlist.name[graphlist.len],name);
	graphlist.len++;
	return OK;
}
status DeleteALGraph(ALGraphs &graphlist,char name[])//删除图。 
{
	int i=0,len=0;
	if(graphlist.graphs==NULL){return INFEASIBLE;}//图的管理表不存在。
	for(i=0;i<graphlist.len;i++){if(strcmp(name,graphlist.name[i])==0){break;}}
	if(graphlist.len==i){return ERROR;}//查找失败。
	//free(graphlist.graphs[i]); 
	DestroyGraph(graphlist.graphs[i]); 
	for(;i<graphlist.len-1;i++)//移动节点。 
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
status SearchALGraph(ALGraphs graphlist,char name[],ALGraph &G)//搜索图。 
{
	int i=0;
	if(graphlist.len==0){return ERROR;}//图的管理表不存在。
	for(i=0;i<graphlist.len;i++)
	{
		if(strcmp(name,graphlist.name[i])==0)//查找成功。 
		{
			G=graphlist.graphs[i];
			return OK;
		}
	}
	return ERROR;
}
