#ifndef InsertVex_
#define InsertVex_
status InsertVex(ALGraph &G,VertexType v)
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
    int i=0;
    if(1+G.vexnum>MAX_VERTEX_NUM){return ERROR;}//�ڵ������� 
    for(i=0;i<G.vexnum;i++){if(v.key==G.vertices[i].data.key){return ERROR;}}//�ؼ����ظ��� 
    G.vertices[G.vexnum].data=v;//�½����㡣 
    G.vertices[G.vexnum++].firstarc==NULL;
    return OK;
}
#endif

