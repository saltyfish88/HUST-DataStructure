void bfs(ALGraph G,int startnode)
{
	int head=0,tail=0;
	int queue[MAX_VERTEX_NUM]={startnode};
	while(head<=tail)
	{
		ArcNode*trans=G.vertices[queue[head]].firstarc;
		while(trans!=NULL)
		{
			if(book[trans->adjvex]==0)
			{
				tail++;
				queue[tail]=trans->adjvex;
				book[trans->adjvex]++;
			}
			trans=trans->nextarc;
		}
		head++;
	}
}
status ConnectedComponentsNums(ALGraph G)
{
	int i=0,cnt=0;
	for(i=0;i<MAX_VERTEX_NUM;i++){book[i]=0;}
	if(G.vertices==NULL){return 0;}
	for(i=0;i<G.vexnum;i++)
	{
		if(book[i]==0)
		{
			book[i]++;
			cnt++;
			bfs(G,i);
		}
	}
	return cnt;
}
