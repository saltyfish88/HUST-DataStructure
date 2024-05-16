#ifndef NextAdjVex_
#define NextAdjVex_
int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    int i=0,locate=-1;
    ArcNode*trans=NULL;
    int book[100000]={0};//存储顶点的位序。 
    for(i=0;i<G.vexnum;i++)
	{
		book[G.vertices[i].data.key]=i;
	    if(v==G.vertices[i].data.key){locate=i;}
	}
	if(locate==-1){return -1;}//未找到节点。 
    trans=G.vertices[locate].firstarc;
    while(trans!=NULL)//遍历邻接点。 
    {
    	if(book[w]==trans->adjvex&&trans->nextarc!=NULL)
    	{
    		return trans->nextarc->adjvex;
		}
		trans=trans->nextarc;
	}
	return -1;
}
#endif

