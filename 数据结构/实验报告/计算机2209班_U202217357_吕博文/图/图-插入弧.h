#ifndef InsertArc_
#define InsertArc_
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    int i=0,locatew=-1,locatev=-1;
    ArcNode*trans=NULL;
    if(v==w){return ERROR;}//单边弧，错误。 
    for(i=0;i<G.vexnum;i++)//查找顶点。 
    {
    	if(w==G.vertices[i].data.key){locatew=i;}
    	if(v==G.vertices[i].data.key){locatev=i;}
	}
	if(locatev==-1||locatew==-1){return ERROR;}//未找到顶点。 
	trans=G.vertices[locatew].firstarc;
	while(trans!=NULL)
	{
		if(locatev==trans->adjvex){return ERROR;}//已有边。 
		trans=trans->nextarc;
	}
	ArcNode*p=(ArcNode*)malloc(sizeof(ArcNode));//新建表节点。 
	p->adjvex=locatew;
	p->nextarc=NULL;
	if(G.vertices[locatev].firstarc!=NULL){p->nextarc=G.vertices[locatev].firstarc;}
	G.vertices[locatev].firstarc=p;
	ArcNode*q=(ArcNode*)malloc(sizeof(ArcNode));//新建表节点。
	q->adjvex=locatev;
	q->nextarc=NULL;
	if(G.vertices[locatew].firstarc!=NULL){q->nextarc=G.vertices[locatew].firstarc;}
	G.vertices[locatew].firstarc=q;
	G.arcnum++;
	return OK;
}
#endif
