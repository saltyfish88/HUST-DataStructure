#ifndef isrepeat_
#define isrepeat_
status isrepeat(VertexType V[])//�����ظ��ڵ㡣 
{
	int i=0;
	int book[100000]={0};
	while(V[i].key!=-1)
	{
		if(book[V[i].key]>0){return 1;}//�����ظ��ڵ㡣 
		book[V[i].key]++;
		i++;
	}
	return 0;//�������ظ��ڵ㡣 
}
#endif
#ifndef CreateGraph_
#define CreateGraph_
status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*����V��VR����ͼT������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
	int i=0;
	int book[100000];//��ǹؼ��֡� 
	int bookvr[500][500]={0};//��Ǳߡ� 
	memset(book,-1,100000);
	if(isrepeat(V)==1||V[0].key==-1||(V[1].key==-1&&VR[0][0]!=-1)){return ERROR;}//��ͼ���Ի����رߡ� 
	while(V[i].key!=-1)//�������㡣 
	{
		if(i>=MAX_VERTEX_NUM){return ERROR;}//�ڵ������� 
		G.vertices[i].data=V[i];
		G.vertices[i].firstarc=NULL;
		book[V[i].key]=i;
		i++;
	}
	G.vexnum=i;
	i=0;
	while(VR[i][1]!=-1)//�����ߡ� 
	{
		bookvr[VR[i][0]][VR[i][1]]++;
		if(VR[i][0]==VR[i][1]||bookvr[VR[i][0]][VR[i][1]]+bookvr[VR[i][1]][VR[i][0]]>1){return ERROR;}//���бߡ� 
		if(book[VR[i][1]]==-1){return ERROR;}//������ 
		ArcNode*last=G.vertices[book[VR[i][1]]].firstarc;//ͷ�巨�����ڵ㡣 
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
	while(VR[i][0]!=-1)//�����ߡ� 
	{
		if(book[VR[i][0]]==-1){return ERROR;}//������
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

