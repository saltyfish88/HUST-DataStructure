#ifndef ClearGraph_
#define ClearGraph_
void ClearGraph(ALGraph &G)//����G�������ͼ�� 
{
	int i=0;
	while(i<G.vexnum)
    {
    	G.vertices[i].firstarc=NULL;
		i++;
	}
	G.vexnum=0;
	G.arcnum=0;
}
#endif
#ifndef DestroyGraph_
#define DestroyGraph_
status DestroyGraph(ALGraph &G)
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
{
int i=0;
if(G.vexnum==0){
    return INFEASIBLE;
}//ͼ������ 
ArcNode *temp=NULL;
ArcNode *pr=NULL;
while(i<G.vexnum){ 
    temp=G.vertices[i].firstarc;
    while(temp!=NULL){
        pr=temp;
        temp=temp->nextarc;
        free(pr);
        pr=NULL;
    }
i++;
} //����ͼ���ͷŽڵ�ռ� 
G.vexnum=0;
G.arcnum=0;
return OK; //����ڵ�������� 
}
#endif
