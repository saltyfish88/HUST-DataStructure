#ifndef LocateVex_
#define LocateVex_
int LocateVex(ALGraph G,KeyType u)
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
{
    int i=0;
	for(i=0;i<G.vexnum;i++){if(u==G.vertices[i].data.key){return i;}}//���Ҷ���
	return -1;
}
#endif

