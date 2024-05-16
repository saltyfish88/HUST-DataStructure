#ifndef dfs_
#define dfs_
void dfs(ALGraph &G,void (*visit)(VertexType),int nowvex)//������������ݹ顣 
{
    ArcNode*trans=G.vertices[nowvex].firstarc;
    visit(G.vertices[nowvex].data);
    book[nowvex]++;
    while(trans!=NULL)//���������ڽӵ㡣 
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
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    int i=0;
    for(i=0;i<MAX_VERTEX_NUM;i++){book[i]=0;}
    if(G.vexnum==0){return ERROR;}
    for(i=0;i<G.vexnum;i++){if(book[i]==0){dfs(G,visit,i);}}//������������������ͨ��֧�� 
    return OK;
}
#endif
