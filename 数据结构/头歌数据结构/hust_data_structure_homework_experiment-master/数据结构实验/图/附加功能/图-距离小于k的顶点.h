//VertexType*VerticesSetLessThanK(ALGraph G,VertexType v,int k)
status VerticesSetLessThanK(ALGraph G,VertexType v,int k)
{
	int i=0,j=0,locate=-1,min=0,minid=0,sign=0;
	const int inf=1<<30;//�������޳��� 
	ArcNode*trans=NULL;
	int dist[G.vexnum]={0};//�������顣 
	int book[G.vexnum]={0};//������顣 
	VertexType ret[MAX_VERTEX_NUM];
	if(G.vertices==NULL){return ERROR;}//ͼ�����ڡ� 
	for(i=0;i<G.vexnum;i++){if(v.key==G.vertices[i].data.key){locate=i;}}//���Ҷ����λ�á�
	if(locate==-1){return ERROR;}//���㲻���ڡ�
	book[locate]++;
	for(i=0;i<G.vexnum;i++){dist[i]=inf;}//��ʼ���������顣 
	trans=G.vertices[locate].firstarc;
	dist[locate]=0;
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
	for(i=0;i<G.vexnum;i++)//��ӡ����� 
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
