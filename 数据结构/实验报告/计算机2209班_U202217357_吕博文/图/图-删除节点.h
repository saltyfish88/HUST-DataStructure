#ifndef DeleteVex_
#define DeleteVex_
status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    int i=0,locate=0;
    ArcNode*pr=NULL;
    ArcNode*trans=NULL; 
	for(i=0;i<G.vexnum;i++){if(v==G.vertices[i].data.key){break;}}//查找节点。 
	if(i==G.vexnum||G.vexnum==1){return ERROR;}//只有一个节点不能删。 
	trans=G.vertices[i].firstarc;
	while(trans!=NULL)//删除所有和节点相连的边。 
	{
		G.arcnum--;
		pr=trans;
		trans=trans->nextarc;
		free(pr);
		pr=NULL;
	}
	locate=i;
	for(;i<G.vexnum-1;i++){G.vertices[i]=G.vertices[1+i];}//移动位置。 
	G.vexnum--;
	for(i=0;i<G.vexnum;i++)//删除所有和节点相连的边。
	{
		trans=G.vertices[i].firstarc;
		pr=trans;
		while(trans!=NULL)
		{
			if(locate==trans->adjvex)
			{
				if(trans==pr)//在第一个节点上。 
				{
					G.vertices[i].firstarc=trans->nextarc;
					trans=trans->nextarc;
					free(pr);
					pr=NULL;
					continue;
				}
				pr->nextarc=trans->nextarc;
				pr=trans;
				trans=trans->nextarc;
				free(pr);
				pr=NULL;
				continue;
			}
			if(trans->adjvex>locate){trans->adjvex--;}//所有大于locate的节点位置减一。 
			pr=trans;
			trans=trans->nextarc;
		}
	}
	return OK;
}
#endif
