void Traverse(ALGraph G)
{
	int i=0,j=0;
	int map[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	ArcNode*trans=NULL;
	for(i=0;i<MAX_VERTEX_NUM;i++){for(j=0;j<MAX_VERTEX_NUM;j++){map[i][j]=0;}}//初始化。 
	for(i=0;i<G.vexnum;i++)//生成邻接矩阵。 
	{
		trans=G.vertices[i].firstarc;
		while(trans!=0)
		{
			//map[i][trans->adjvex]++;
			map[trans->adjvex][i]++;
			trans=trans->nextarc;
		}
	}
	printf("    ");//打印邻接矩阵。 
	for(i=0;i<G.vexnum;i++){printf("%-4d",G.vertices[i].data.key);}
	printf("\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(j==0)printf("%-4d",G.vertices[i].data.key);
			if(map[i][j]==0){printf("    ");}
			else{printf("%-4d",map[i][j]);}
		}
		printf("\n");
	}
}
