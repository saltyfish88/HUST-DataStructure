#ifndef bfs_
#define bfs_
void bfs(ALGraph &G,void (*visit)(VertexType),int startnode)//������������� 
{
	int head=0,tail=0;
	int queue[MAX_VERTEX_NUM]={startnode};//�����ʶ��С� 
	while(head<=tail)//���в�Ϊ�ա� 
	{
		visit(G.vertices[queue[head]].data);
		ArcNode*trans=G.vertices[queue[head]].firstarc;
		while(trans!=NULL)//���ڽӵ���ӡ� 
		{
			if(book[trans->adjvex]==0)
			{
				tail++;
				queue[tail]=trans->adjvex;
				book[trans->adjvex]++;
			}
			trans=trans->nextarc;
		}
		head++;//���ӡ� 
	}
}
#endif
#ifndef BFSTraverse_
#define BFSTraverse_
status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    int i=0;
    for(i=0;i<MAX_VERTEX_NUM;i++){book[i]=0;}
    if(G.vexnum==0){return ERROR;}//��ͼ�� 
    for(i=0;i<G.vexnum;i++)//��������������ͨ��֧�� 
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
