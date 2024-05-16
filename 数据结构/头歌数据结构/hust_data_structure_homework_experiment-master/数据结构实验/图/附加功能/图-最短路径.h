status ShortestPathLength(ALGraph G,VertexType v,VertexType w)
{
	int i=0,j=0,locatev=-1,locatew=-1,minid=0,min=-1;
	const int inf=1<<30;//定义无限长。 
	ArcNode*trans=NULL;
	int dist[G.vexnum]={0};//距离数组。 
	int book[G.vexnum]={0};//标记数组。 
	if(G.vertices==NULL){return INFEASIBLE;}
	for(i=0;i<G.vexnum;i++)//查找顶点的位置。 
	{
		if(v.key==G.vertices[i].data.key){locatev=i;}
		if(w.key==G.vertices[i].data.key){locatew=i;}
	}
	if(locatew==-1||locatev==-1){return -1;}//顶点不存在。
	book[locatev]++;
	for(i=0;i<G.vexnum;i++){dist[i]=inf;}//初始化距离数组。 
	trans=G.vertices[locatev].firstarc;
	dist[locatev]=0;
	while(trans!=NULL)
	{
		dist[trans->adjvex]=1;
		trans=trans->nextarc;
	}
	for(i=0;i<G.vexnum-1;i++)//Dijkstra算法求单源最短路径。 
	{
		min=inf;
		for(j=0;j<G.vexnum;j++)//寻找未标记的距离源点最近的点。 
		{
			if(book[j]==0&&min>dist[j])
			{
				minid=j;
				min=dist[j];
			}
		}
		book[minid]++;
		trans=G.vertices[minid].firstarc;
		while(trans!=NULL)//尝试用这个点松弛和它邻近的点。 
		{
			if(dist[trans->adjvex]>1+dist[minid])
			{
				dist[trans->adjvex]=1+dist[minid];
			}
			trans=trans->nextarc;
		}
	} 
	if(dist[locatew]==inf){return -1;}//两点不连通。
	return dist[locatew]; 
}
