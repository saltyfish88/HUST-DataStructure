#ifndef InsertArc_
#define InsertArc_
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    int i=0,locatew=-1,locatev=-1;
    ArcNode*trans=NULL;
    if(v==w){return ERROR;}//���߻������� 
    for(i=0;i<G.vexnum;i++)//���Ҷ��㡣 
    {
    	if(w==G.vertices[i].data.key){locatew=i;}
    	if(v==G.vertices[i].data.key){locatev=i;}
	}
	if(locatev==-1||locatew==-1){return ERROR;}//δ�ҵ����㡣 
	trans=G.vertices[locatew].firstarc;
	while(trans!=NULL)
	{
		if(locatev==trans->adjvex){return ERROR;}//���бߡ� 
		trans=trans->nextarc;
	}
	ArcNode*p=(ArcNode*)malloc(sizeof(ArcNode));//�½���ڵ㡣 
	p->adjvex=locatew;
	p->nextarc=NULL;
	if(G.vertices[locatev].firstarc!=NULL){p->nextarc=G.vertices[locatev].firstarc;}
	G.vertices[locatev].firstarc=p;
	ArcNode*q=(ArcNode*)malloc(sizeof(ArcNode));//�½���ڵ㡣
	q->adjvex=locatev;
	q->nextarc=NULL;
	if(G.vertices[locatew].firstarc!=NULL){q->nextarc=G.vertices[locatew].firstarc;}
	G.vertices[locatew].firstarc=q;
	G.arcnum++;
	return OK;
}
#endif
