#ifndef PutVex_
#define PutVex_
status PutVex(ALGraph &G,KeyType u,VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
    int i=0,locate=-1;
    int book[100000]={0};//��ǹؼ��֡� 
    for(i=0;i<G.vexnum;i++)
	{
		book[G.vertices[i].data.key]++;
	    if(u==G.vertices[i].data.key)
		{
		    locate=i;
		    book[G.vertices[locate].data.key]--;
		}
	}
	if(locate==-1||book[value.key]>0){return ERROR;}//��ʧ�ܻ�ؼ��ֲ�Ψһ
	G.vertices[locate].data=value;
	return OK;
}
#endif

