#ifndef DeleteVex_
#define DeleteVex_
status DeleteVex(ALGraph &G,KeyType v)
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
    int i=0,locate=0;
    ArcNode*pr=NULL;
    ArcNode*trans=NULL; 
	for(i=0;i<G.vexnum;i++){if(v==G.vertices[i].data.key){break;}}//���ҽڵ㡣 
	if(i==G.vexnum||G.vexnum==1){return ERROR;}//ֻ��һ���ڵ㲻��ɾ�� 
	trans=G.vertices[i].firstarc;
	while(trans!=NULL)//ɾ�����кͽڵ������ıߡ� 
	{
		G.arcnum--;
		pr=trans;
		trans=trans->nextarc;
		free(pr);
		pr=NULL;
	}
	locate=i;
	for(;i<G.vexnum-1;i++){G.vertices[i]=G.vertices[1+i];}//�ƶ�λ�á� 
	G.vexnum--;
	for(i=0;i<G.vexnum;i++)//ɾ�����кͽڵ������ıߡ�
	{
		trans=G.vertices[i].firstarc;
		pr=trans;
		while(trans!=NULL)
		{
			if(locate==trans->adjvex)
			{
				if(trans==pr)//�ڵ�һ���ڵ��ϡ� 
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
			if(trans->adjvex>locate){trans->adjvex--;}//���д���locate�Ľڵ�λ�ü�һ�� 
			pr=trans;
			trans=trans->nextarc;
		}
	}
	return OK;
}
#endif
