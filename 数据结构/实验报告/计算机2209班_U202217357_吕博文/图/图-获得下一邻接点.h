#ifndef NextAdjVex_
#define NextAdjVex_
int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
{
    int i=0,locate=-1;
    ArcNode*trans=NULL;
    int book[100000]={0};//�洢�����λ�� 
    for(i=0;i<G.vexnum;i++)
	{
		book[G.vertices[i].data.key]=i;
	    if(v==G.vertices[i].data.key){locate=i;}
	}
	if(locate==-1){return -1;}//δ�ҵ��ڵ㡣 
    trans=G.vertices[locate].firstarc;
    while(trans!=NULL)//�����ڽӵ㡣 
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

