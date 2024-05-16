//VertexType*VerticesSetLessThanK(ALGraph G,VertexType v,int k)
status VerticesSetLessThanK(ALGraph G,VertexType v,int k)
{
	int i=0,j=0,locate=-1,min=0,minid=0,sign=0;
	const int inf=1<<30;//定义无限长。 
	ArcNode*trans=NULL;
	int dist[G.vexnum]={0};//距离数组。 
	int book[G.vexnum]={0};//标记数组。 
	VertexType ret[MAX_VERTEX_NUM];
	if(G.vertices==NULL){return ERROR;}//图不存在。 
	for(i=0;i<G.vexnum;i++){if(v.key==G.vertices[i].data.key){locate=i;}}//查找顶点的位置。
	if(locate==-1){return ERROR;}//顶点不存在。
	book[locate]++;
	for(i=0;i<G.vexnum;i++){dist[i]=inf;}//初始化距离数组。 
	trans=G.vertices[locate].firstarc;
	dist[locate]=0;
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
	for(i=0;i<G.vexnum;i++)//打印结果。 
	{
		if(i!=locate&&dist[i]<k)
		{
			sign=1;
			printf("%d %s\n",G.vertices[i].data.key,G.vertices[i].data.others);
		}
	}
	if(sign==0){return ERROR;}
	else{return OK;}
	/*for(i=0,j=0;i<G.vexnum;i++,j++)
	{
		if(i!=locate&&dist[i]<k)
		{
			ret[j]=G.vertices[i].data;
		}
	}
	ret[j].key=-1;
	return ret;*/
}
