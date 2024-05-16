#ifndef LocateVex_
#define LocateVex_
int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    int i=0;
	for(i=0;i<G.vexnum;i++){if(u==G.vertices[i].data.key){return i;}}//查找顶点
	return -1;
}
#endif

