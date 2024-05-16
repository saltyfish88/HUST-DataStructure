status ShortestPathLength(ALGraph G,VertexType v,VertexType w)
{
	int i=0,j=0,locatev=-1,locatew=-1,minid=0,min=-1;
	const int inf=1<<30;//�������޳��� 
	ArcNode*trans=NULL;
	int dist[G.vexnum]={0};//�������顣 
	int book[G.vexnum]={0};//������顣 
	if(G.vertices==NULL){return INFEASIBLE;}
	for(i=0;i<G.vexnum;i++)//���Ҷ����λ�á� 
	{
		if(v.key==G.vertices[i].data.key){locatev=i;}
		if(w.key==G.vertices[i].data.key){locatew=i;}
	}
	if(locatew==-1||locatev==-1){return -1;}//���㲻���ڡ�
	book[locatev]++;
	for(i=0;i<G.vexnum;i++){dist[i]=inf;}//��ʼ���������顣 
	trans=G.vertices[locatev].firstarc;
	dist[locatev]=0;
	while(trans!=NULL)
	{
		dist[trans->adjvex]=1;
		trans=trans->nextarc;
	}
	for(i=0;i<G.vexnum-1;i++)//Dijkstra�㷨��Դ���·���� 
	{
		min=inf;
		for(j=0;j<G.vexnum;j++)//Ѱ��δ��ǵľ���Դ������ĵ㡣 
		{
			if(book[j]==0&&min>dist[j])
			{
				minid=j;
				min=dist[j];
			}
		}
		book[minid]++;
		trans=G.vertices[minid].firstarc;
		while(trans!=NULL)//������������ɳں����ڽ��ĵ㡣 
		{
			if(dist[trans->adjvex]>1+dist[minid])
			{
				dist[trans->adjvex]=1+dist[minid];
			}
			trans=trans->nextarc;
		}
	} 
	if(dist[locatew]==inf){return -1;}//���㲻��ͨ��
	return dist[locatew]; 
}
