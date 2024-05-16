#ifndef isrepeat_
#define isrepeat_
status isrepeat(VertexType V[])//查找重复节点。 
{
	int i=0;
	int book[100000]={0};
	while(V[i].key!=-1)
	{
		if(book[V[i].key]>0){return 1;}//存在重复节点。 
		book[V[i].key]++;
		i++;
	}
	return 0;//不存在重复节点。 
}
#endif
#ifndef CreateGraph_
#define CreateGraph_
status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
	int i=0;
	int book[100000];//标记关键字。 
	int bookvr[500][500]={0};//标记边。 
	memset(book,-1,100000);
	if(isrepeat(V)==1||V[0].key==-1||(V[1].key==-1&&VR[0][0]!=-1)){return ERROR;}//空图，自环，重边。 
	while(V[i].key!=-1)//创建顶点。 
	{
		if(i>=MAX_VERTEX_NUM){return ERROR;}//节点已满。 
		G.vertices[i].data=V[i];
		G.vertices[i].firstarc=NULL;
		book[V[i].key]=i;
		i++;
	}
	G.vexnum=i;
	i=0;
	while(VR[i][1]!=-1)//创建边。 
	{
		bookvr[VR[i][0]][VR[i][1]]++;
		if(VR[i][0]==VR[i][1]||bookvr[VR[i][0]][VR[i][1]]+bookvr[VR[i][1]][VR[i][0]]>1){return ERROR;}//已有边。 
		if(book[VR[i][1]]==-1){return ERROR;}//结束。 
		ArcNode*last=G.vertices[book[VR[i][1]]].firstarc;//头插法插入表节点。 
		ArcNode*p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=book[VR[i][0]];
		p->nextarc=NULL;
		if(last==NULL)
		{
			G.vertices[book[VR[i][1]]].firstarc=p;
			i++;
			continue;
		}
		p->nextarc=last;
		G.vertices[book[VR[i][1]]].firstarc=p;
		i++;
	}
	i=0;
	while(VR[i][0]!=-1)//创建边。 
	{
		if(book[VR[i][0]]==-1){return ERROR;}//结束。
		ArcNode*last=G.vertices[book[VR[i][0]]].firstarc; 
		ArcNode*p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=book[VR[i][1]];
		p->nextarc=NULL;
		if(last==NULL)
		{
			G.vertices[book[VR[i][0]]].firstarc=p;
			i++;
			continue;
		}
		p->nextarc=last;
		G.vertices[book[VR[i][0]]].firstarc=p;
		i++;
	}
	G.arcnum=i;
	return OK;
}
#endif

