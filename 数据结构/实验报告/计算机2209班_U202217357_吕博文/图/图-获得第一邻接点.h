#ifndef FirstAdjVex_
#define FirstAdjVex_
int FirstAdjVex(ALGraph G,KeyType u)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
    int i=0;
    for(i=0;i<G.vexnum;i++){if(u==G.vertices[i].data.key){break;}}//���ҽڵ㡣 
    if(i==G.vexnum||G.vertices[i].firstarc==NULL){return -1;}//δ�ҵ����޵�һ�ڽӵ㡣 
    return G.vertices[i].firstarc->adjvex; 
}
#endif

