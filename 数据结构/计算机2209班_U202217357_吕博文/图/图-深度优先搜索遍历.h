#ifndef dfs_
#define dfs_
void dfs(ALGraph &G,void (*visit)(VertexType),int nowvex)//深度优先搜索递归。 
{
    ArcNode*trans=G.vertices[nowvex].firstarc;
    visit(G.vertices[nowvex].data);
    book[nowvex]++;
    while(trans!=NULL)//搜索所有邻接点。 
    {
    	nowvex=trans->adjvex;
    	trans=trans->nextarc;
    	if(book[nowvex]!=1){dfs(G,visit,nowvex);}
	}
}
#endif
#ifndef DFSTraverse_
#define DFSTraverse_
status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    int i=0;
    for(i=0;i<MAX_VERTEX_NUM;i++){book[i]=0;}
    if(G.vexnum==0){return ERROR;}
    for(i=0;i<G.vexnum;i++){if(book[i]==0){dfs(G,visit,i);}}//遍历顶点搜索所有连通分支。 
    return OK;
}
#endif
