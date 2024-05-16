#ifndef PutVex_
#define PutVex_
status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    int i=0,locate=-1;
    int book[100000]={0};//标记关键字。 
    for(i=0;i<G.vexnum;i++)
	{
		book[G.vertices[i].data.key]++;
	    if(u==G.vertices[i].data.key)
		{
		    locate=i;
		    book[G.vertices[locate].data.key]--;
		}
	}
	if(locate==-1||book[value.key]>0){return ERROR;}//找失败或关键字不唯一
	G.vertices[locate].data=value;
	return OK;
}
#endif

