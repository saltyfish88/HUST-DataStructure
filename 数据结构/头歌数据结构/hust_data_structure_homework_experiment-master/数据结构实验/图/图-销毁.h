#ifndef ClearGraph_
#define ClearGraph_
void ClearGraph(ALGraph &G)//更换G所代表的图。 
{
	int i=0;
	while(i<G.vexnum)
    {
    	G.vertices[i].firstarc=NULL;
		i++;
	}
	G.vexnum=0;
	G.arcnum=0;
}
#endif
#ifndef DestroyGraph_
#define DestroyGraph_
status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    int i=0;
    if(G.vexnum==0){return INFEASIBLE;}//图不存在。 
    ArcNode*trans=NULL;
    ArcNode*pr=NULL;
    while(i<G.vexnum)//遍历图，释放空间。 
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
	return OK;
}
#endif
