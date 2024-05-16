#ifndef bfs_
#define bfs_
void bfs(ALGraph &G,void (*visit)(VertexType),int startnode)//广度优先搜索。 
{
	int head=0,tail=0;
	int queue[MAX_VERTEX_NUM]={startnode};//待访问队列。 
	while(head<=tail)//队列不为空。 
	{
		visit(G.vertices[queue[head]].data);
		ArcNode*trans=G.vertices[queue[head]].firstarc;
		while(trans!=NULL)//把邻接点入队。 
		{
			if(book[trans->adjvex]==0)
			{
				tail++;
				queue[tail]=trans->adjvex;
				book[trans->adjvex]++;
			}
			trans=trans->nextarc;
		}
		head++;//出队。 
	}
}
#endif
#ifndef BFSTraverse_
#define BFSTraverse_
status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    int i=0;
    for(i=0;i<MAX_VERTEX_NUM;i++){book[i]=0;}
    if(G.vexnum==0){return ERROR;}//空图。 
    for(i=0;i<G.vexnum;i++)//遍历搜索所有连通分支。 
	{
		if(book[i]==0)
		{
			book[i]++;
			bfs(G,visit,i);
		}
	}
	return OK;
}
#endif
