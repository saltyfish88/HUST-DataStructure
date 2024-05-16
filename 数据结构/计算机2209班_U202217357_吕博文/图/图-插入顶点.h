#ifndef InsertVex_
#define InsertVex_
status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    int i=0;
    if(1+G.vexnum>MAX_VERTEX_NUM){return ERROR;}//节点已满。 
    for(i=0;i<G.vexnum;i++){if(v.key==G.vertices[i].data.key){return ERROR;}}//关键字重复。 
    G.vertices[G.vexnum].data=v;//新建顶点。 
    G.vertices[G.vexnum++].firstarc==NULL;
    return OK;
}
#endif

