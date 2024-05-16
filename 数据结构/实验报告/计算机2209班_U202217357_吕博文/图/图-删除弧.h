#ifndef DeleteArc_
#define DeleteArc_
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    int i=0,locatew=-1,locatev=-1,sign=0;
    ArcNode*pr=NULL;
    ArcNode*trans=NULL;
    for(i=0;i<G.vexnum;i++)//查找节点。 
    {
    	if(w==G.vertices[i].data.key){locatew=i;}
    	if(v==G.vertices[i].data.key){locatev=i;}
	}
	if(locatev==-1||locatew==-1){return ERROR;}//节点未找到。 
	trans=G.vertices[locatew].firstarc;
	pr=trans;
	while(trans!=NULL)//查找并删除边。 
	{
		if(locatev==trans->adjvex)
		{
			sign=1;
			if(pr==trans)
			{
				G.vertices[locatew].firstarc=trans->nextarc;
				free(pr);
				pr=NULL;
				break;
			}
			pr->nextarc=trans->nextarc;
			pr=trans;
			free(trans);
			trans=NULL;
			break;
		}
		pr=trans;
		trans=trans->nextarc;
	}
	if(sign==0){return ERROR;}//未找到边。 
	trans=G.vertices[locatev].firstarc;
	pr=trans;
	while(trans!=NULL)//删除边。 
	{
		if(locatew==trans->adjvex)
		{
			if(pr==trans)
			{
				G.vertices[locatev].firstarc=trans->nextarc;
				free(pr);
				pr=NULL;
				break;
			}
			pr->nextarc=trans->nextarc;
			free(trans);
			trans=NULL;
			break;
		}
		pr=trans;
		trans=trans->nextarc;
	}
	G.arcnum--;
	return OK;
}
#endif
