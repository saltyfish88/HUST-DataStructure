#ifndef FirstAdjVex_
#define FirstAdjVex_
int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    int i=0;
    for(i=0;i<G.vexnum;i++){if(u==G.vertices[i].data.key){break;}}//查找节点。 
    if(i==G.vexnum||G.vertices[i].firstarc==NULL){return -1;}//未找到或无第一邻接点。 
    return G.vertices[i].firstarc->adjvex; 
}
#endif

