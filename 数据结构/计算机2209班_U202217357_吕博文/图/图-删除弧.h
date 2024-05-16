#ifndef DeleteArc_
#define DeleteArc_
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
    int i=0,locatew=-1,locatev=-1,sign=0;
    ArcNode*pr=NULL;
    ArcNode*trans=NULL;
    for(i=0;i<G.vexnum;i++)//���ҽڵ㡣 
    {
    	if(w==G.vertices[i].data.key){locatew=i;}
    	if(v==G.vertices[i].data.key){locatev=i;}
	}
	if(locatev==-1||locatew==-1){return ERROR;}//�ڵ�δ�ҵ��� 
	trans=G.vertices[locatew].firstarc;
	pr=trans;
	while(trans!=NULL)//���Ҳ�ɾ���ߡ� 
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
	if(sign==0){return ERROR;}//δ�ҵ��ߡ� 
	trans=G.vertices[locatev].firstarc;
	pr=trans;
	while(trans!=NULL)//ɾ���ߡ� 
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
