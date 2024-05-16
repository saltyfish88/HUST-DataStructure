#include"../def.h"
#include "图-距离小于k的顶点.h"

status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
{
int i=0,j,one,two;
VertexType e;
//VertexType*ret;
do {
    G.vertices[i].data=V[i];
    G.vertices[i].firstarc=NULL;
} while (V[i++].key!=-1);
G.vexnum=i-1;
i=0;
while (VR[i][0]!=-1) {
    ArcNode *p;
    for(j=0;j<G.vexnum;j++)
        if (VR[i][0]==G.vertices[j].data.key)
        {
            one=j; break;
        }
    for(j=0;j<G.vexnum;j++)
        if (VR[i][1]==G.vertices[j].data.key)
        {
            two=j; break;
        }
    p=(ArcNode*)malloc(sizeof(ArcNode));    
    p->adjvex=two;p->nextarc=G.vertices[one].firstarc;G.vertices[one].firstarc=p;  
    p=(ArcNode*)malloc(sizeof(ArcNode));    
    p->adjvex=one;p->nextarc=G.vertices[two].firstarc;G.vertices[two].firstarc=p;  
    i++;
} 
}
int main()
{
ALGraph G;
VertexType V[21];
KeyType VR[100][2];
int i=0,k=0;
VertexType v;
do {
    scanf("%d%s",&V[i].key,V[i].others);
} while(V[i++].key!=-1);
i=0;
do {
    scanf("%d%d",&VR[i][0],&VR[i][1]);
   } while(VR[i++][0]!=-1);  
CreateCraph(G,V,VR);
scanf("%d%s",&v.key,v.others);
scanf("%d",&k);
VerticesSetLessThanK(G,v,k);
/*ret=(VertexType*)malloc(MAX_VERTEX_NUM*sizeof(VertexType));
ret=VerticesSetLessThanK(G,v,k);
i=0;
while(ret[i].key!=-1){printf("%d %s\n",ret[i]key,ret[i].others);}
free(ret);*/
return 1;
}

