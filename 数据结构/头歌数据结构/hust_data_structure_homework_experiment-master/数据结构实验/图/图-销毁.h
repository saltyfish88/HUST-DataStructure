#ifndef ClearGraph_
#define ClearGraph_
void ClearGraph(ALGraph &G)//����G�������ͼ�� 
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
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
{
    int i=0;
    if(G.vexnum==0){return INFEASIBLE;}//ͼ�����ڡ� 
    ArcNode*trans=NULL;
    ArcNode*pr=NULL;
    while(i<G.vexnum)//����ͼ���ͷſռ䡣 
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
