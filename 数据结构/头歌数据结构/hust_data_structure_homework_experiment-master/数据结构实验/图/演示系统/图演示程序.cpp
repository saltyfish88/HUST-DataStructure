#include"../def.h"
#include"../图-插入顶点.h"
#include"../图-插入弧.h"
#include"../图-创建.h"
#include"../图-查找顶点.h"
#include"../图-删除弧.h"
#include"../图-删除节点.h"
#include"../图-顶点赋值.h"
#include"../图-销毁.h"
#include"../图-获得第一邻接点.h"
#include"../图-获得下一邻接点.h"
#include"../图-文件操作.h"
#include"../图-广度优先搜索遍历.h"
#include"../图-深度优先搜索遍历.h"
#include"../附加功能/图-距离小于k的顶点.h"
#include"../附加功能/图-连通分量.h"
#include"../附加功能/图-最短路径.h"
#include"../附加功能/多图管理.h"
#include"../附加功能/图-邻接矩阵遍历.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*  定义常量   
#define TRUE 1   // 定义真值 
#define FALSE 0  // 定制假值 
#define OK 1     // 程序正常运行 
#define ERROR 0  // 程序正常运行 
#define INFEASIBLE -1 // 输入或输出不合法 
#define OVERFLOW -2   // 数值溢出
#define MAX_SIZE 100//最大数量 
#define MAX_VERTEX_NUM 20//最大图节点个数 */
/*  定义变量  
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct 
{
    KeyType  key;
    char others[20];
}VertexType; //顶点类型定义
typedef struct ArcNode //表结点类型定义
{         
   	int adjvex;              //顶点位置编号 
    struct ArcNode  *nextarc;	   //下一个表结点指针
}ArcNode;
typedef struct VNode//头结点及其数组类型定义
{
   	VertexType data;       	//顶点信息
    ArcNode *firstarc;      	 //指向第一条弧
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct //邻接表的类型定义
{
    AdjList vertices;     	 //头结点数组
    int vexnum,arcnum;   	  //顶点数、弧数
    GraphKind  kind;        //图的类型
}ALGraph;
void visit(VertexType v){printf(" %d %s",v.key,v.others);}
void free0(void  *p);
typedef struct//图的管理表的定义。 
{
	ALGraph graphs[MAX_SIZE];
	char*name[MAX_SIZE];
	int len;
	const int listsize=MAX_SIZE;
}ALGraphs;
int book[MAX_VERTEX_NUM]={0};//定义哈希数组以判断关键字 */ 

/* 相关函数定义 
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]); //创建邻接表，G为邻接表，V为点，VR为图的树

status DestroyGraph(ALGraph& G); // 销毁G这个邻接表结构

int LocateVex(ALGraph G, KeyType u); // 获取顶点U在邻接表G中的位置，本函数输入参数是一个邻接表和Keytype的整数X

status PutVex(ALGraph& G, KeyType u, VertexType value); // 将顶点U的值改为新的value

int FirstAdjVex(ALGraph G, KeyType u); // 取顶点U的第一个邻接点，本函数输入参数是一个邻接表和Keytype的整数X

int NextAdjVex(ALGraph G, KeyType v, KeyType w); // 取顶点U相对于w的下一个邻接点，输入需要邻接表以及 两个Keytype的整数

status InsertVex(ALGraph& G, VertexType v); // 插入一个新节点

status DeleteVex(ALGraph& G, KeyType v); // 输入需要删除的节点，从而删除邻接表中相应的节点

status InsertArc(ALGraph& G, KeyType v, KeyType w); //输入节点U与节点V之间的边，构成邻接表的G

status DeleteArc(ALGraph& G, KeyType v, KeyType w);  // 输入节点U与节点V之间的边，将该边从G的邻接表中删除

status DFSTraverse(ALGraph& G, void (*visit)(VertexType)); // 深度优先遍历邻接表

status BFSTraverse(ALGraph& G, void (*visit)(VertexType)); // 广度优先遍历邻接表

status SaveGraph(ALGraph G, char FileName[]); // 指定文件名把邻接表存为文件

status LoadGraph(ALGraph& G, char FileName[]); // 从指定的文件名中读取邻接表

status AddGraph(GRAPHS& Graphs, char ListName[]); //向森林中添加新的邻接表

status RemoveGraph(GRAPHS& Graphs, char ListName[]); //从森林中删除指定邻接表

int LocateGraph(GRAPHS& Graphs, char ListName[]); // 找到指定邻接表在森林中的位置

status GraphsTraverse(GRAPHS& Graphs); // 遍历森林，以字符串形式输出每个邻接表

status ChooseGraph(ALGraph& G, GRAPHS& Graphs, int x); // 从森林中选择指定的邻接表

status VerticesSetLessThanK(ALGraph G,KeyType v,int k);// v为某个点，输出邻接表中与该点相连通且边权小于等于k 的点集

status ShortestPathLength(ALGraph G,KeyType v,KeyType w);// v和w表示起点和终点，输出中间路径的最小长度

status ConnectedComponentsNums(ALGraph G);// 输出邻接表的连通分量个数
*/ 
int main()
{
int i=0,j=0,op1=1,op2=0,op3=0,sign=0,n=0,ret=0;
VertexType V[21],w,v;
KeyType VR[100][2];
ALGraph G; 
ALGraphs graph_table;
graph_table.len=0;
//graph_table.graphs=NULL;
char name[20];
while(op1)
{
	system("cls");	printf("\n\n");
	printf("      以邻接表实现的图菜单 \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. 创建图          9. 插入弧\n");
	printf("    	  2. 销毁图          10. 删除弧\n");
	printf("    	  3. 查找顶点        11. 深度优先搜索遍历 \n");
	printf("    	  4. 顶点赋值        12. 广度优先搜索遍历\n");
	printf("    	  5. 获得第一邻接点  13. 距离小于k的顶点\n");
	printf("    	  6. 获得下一邻接点  14. 连通分量\n");
	printf("    	  7. 插入顶点        15. 最短路径\n");
	printf("    	  8. 删除顶点        16. 图的保存\n");
	printf("    	  17. 图的读取\n");
	printf("    	  0. 退出\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~16]:");
	scanf("%d",&op1);
	if(op1<0||op1>17)
	{
		printf("Invalid Input!\n");
		system("pause");
		exit(-1);
	}
	printf("请问您是否需要先创建若干个图？(本操作会测评多图管理的插入)(本操作会覆盖掉已有的图)是：1，否：0\n");
	scanf("%d",&op2);
	if(op2!=1&&op2!=0)
	{
		printf("Invalid Input!\n");
		system("pause");
		exit(-1);
	}
	if(op2==1)//创建图的管理表。 
	{
		//DestroyALGraphs(graph_table); 
		//tree_table.trees=NULL;
		//InitALGraphs(graph_table);
		graph_table.len=0;
		printf("请输入您需要创建的图的个数。\n"); 
		scanf("%d",&n); 
		for(j=0;j<n;j++)
		{
			printf("请输入您给这个图起的名字。\n");
			scanf("%s",&name);
			printf("您输入的名字是%s。\n",name); 
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("正在保存这个图...\n");
				sign=AddALGraph(graph_table,G,name);
				if(sign==OK){printf("图保存成功！\n");}
				else{printf("图保存失败！\n");}
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			ClearGraph(G);
		}
	}
    switch(op1)
	{
	   case 1://创建图。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3!=1)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			printf("正在创建图...\n"); 
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		DestroyGraph(G);
		getchar();getchar();
		break;
	   case 2://销毁图。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("正在销毁图...\n");
				sign=DestroyGraph(G);
				if(sign==OK){printf("销毁成功！\n");}
				else{printf("销毁失败！\n");}
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("正在销毁图...\n");
			sign=DestroyGraph(G);
			if(sign==OK){printf("销毁成功！\n");}
			else{printf("销毁失败！\n");}
			printf("正在从管理表中删除...\n");
			sign=DeleteALGraph(graph_table,name); 
			if(sign==OK){printf("删除成功！\n");}
			else{printf("删除失败！\n");}
			printf("本次测评结束。\n");
		}
		getchar();getchar();
		break;
	   case 3://查找顶点。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要查找的顶点的关键字。\n");
				scanf("%d",&j); 
				printf("正在查找顶点...\n");
				ret=LocateVex(G,j);
				if(ret!=-1){printf("查找成功，位序%d。\n",ret);}
				else{printf("未找到顶点！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要查找的顶点的关键字。\n");
			scanf("%d",&j); 
			printf("正在查找顶点...\n");
			ret=LocateVex(G,j);
			if(ret!=-1){printf("查找成功，位序%d。\n",ret);}
			else{printf("未找到顶点！\n");} 
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 4://顶点赋值。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要赋值的顶点的关键字。\n");
				scanf("%d",&j); 
				printf("请输入新的顶点的关键字和名称。\n");
				scanf("%d %s",&v.key,&v.others);
				printf("正在进行顶点的赋值...\n");
				sign=PutVex(G,j,v);
				if(sign==OK)
				{
					printf("赋值成功！\n");
					printf("赋值后的图如下：\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("顶点关键字重复或未找到顶点！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要赋值的顶点的关键字。\n");
			scanf("%d",&j); 
			printf("请输入新的顶点的关键字和名称。\n");
			scanf("%d %s",&v.key,&v.others);
			printf("正在进行顶点的赋值...\n");
			sign=PutVex(G,j,v);
			if(sign==OK)
			{
				printf("赋值成功！\n");
				printf("赋值后的图如下：\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("顶点关键字重复或未找到顶点！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 5://获得第一邻接点。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要查找第一邻接点的顶点的关键字。\n");
				scanf("%d",&j); 
				printf("正在查找第一邻接点...\n");
				ret=FirstAdjVex(G,j);
				if(ret!=-1){printf("查找第一邻接点成功，顶点位序是%d。\n",ret);}
				else{printf("顶点无邻接点或未找到顶点！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要查找第一邻接点的顶点的关键字。\n");
			scanf("%d",&j); 
			printf("正在查找第一邻接点...\n");
			ret=FirstAdjVex(G,j);
			if(ret!=-1){printf("查找第一邻接点成功，顶点位序是%d。\n",ret);}
			else{printf("顶点无邻接点或未找到顶点！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 6://获得下一邻接点。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要查找下一邻接点的顶点的关键字。\n");
				scanf("%d",&j);
				printf("请输入要查找下一邻接点的顶点的一个邻接点的关键字。\n");
				scanf("%d",&sign);
				printf("正在查找下一邻接点...\n");
				ret=NextAdjVex(G,j,sign); 
				if(ret!=-1){printf("查找下一邻接点成功，顶点位序是%d。\n",ret);}
				else{printf("查找下一邻接点失败！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要查找下一邻接点的顶点的关键字。\n");
			scanf("%d",&j);
			printf("请输入要查找下一邻接点的顶点的一个邻接点的关键字。\n");
			scanf("%d",&sign);
			printf("正在查找下一邻接点...\n");
			ret=NextAdjVex(G,j,sign); 
			if(ret!=-1){printf("查找下一邻接点成功，顶点位序是%d。\n",ret);}
			else{printf("查找下一邻接点失败！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 7://插入顶点。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要插入的顶点的关键字和名称。\n");
				scanf("%d %s",&v.key,&v.others);
				printf("正在插入顶点...\n");
				sign=InsertVex(G,v);
				if(sign==OK)
				{
					printf("插入顶点成功！\n");
					printf("插入顶点后的图如下：\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("顶点关键字重复或未找到顶点！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要插入的顶点的关键字和名称。\n");
			scanf("%d %s",&v.key,&v.others);
			printf("正在插入顶点...\n");
			sign=InsertVex(G,v);
			if(sign==OK)
			{
				printf("插入顶点成功！\n");
				printf("插入顶点后的图如下：\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("顶点关键字重复或未找到顶点！\n");}	
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 8://删除顶点。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要删除的顶点的关键字。\n");
				scanf("%d",&j);
				printf("正在删除顶点...\n");
				sign=DeleteVex(G,j); 
				if(sign==OK)
				{
					printf("删除顶点成功！\n");
					printf("删除顶点后的图如下：\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("未找到顶点！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要删除的顶点的关键字。\n");
			scanf("%d",&j);
			printf("正在删除顶点...\n");
			sign=DeleteVex(G,j); 
			if(sign==OK)
			{
				printf("删除顶点成功！\n");
				printf("删除顶点后的图如下：\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("未找到顶点！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 9://插入弧。 
	    printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要插入的弧的两个顶点的关键字。\n");
				scanf("%d %d",&i,&j);
				printf("正在插入弧...\n");
				sign=InsertArc(G,i,j); 
				if(sign==OK) 
				{
					printf("插入弧成功！\n");
					printf("插入弧后的图如下：\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("未找到顶点或弧已存在！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要插入的弧的两个顶点的关键字。\n");
			scanf("%d %d",&i,&j);
			printf("正在插入弧...\n");
			sign=InsertArc(G,i,j);
			if(sign==OK)
			{
				printf("插入弧成功！\n");
				printf("插入弧后的图如下：\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("未找到顶点或边已存在！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 10://删除弧。
	    printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要删除的弧的两个顶点的关键字。\n");
				scanf("%d %d",&i,&j);
				printf("正在删除弧...\n");
				sign=DeleteArc(G,i,j); 
				if(sign==OK)
				{
					printf("删除弧成功！\n");
					printf("删除弧后的图如下：\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("未找到顶点或边不存在！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要删除的弧的两个顶点的关键字。\n");
			scanf("%d %d",&i,&j);
			printf("正在删除弧...\n");
			sign=DeleteArc(G,i,j); 
			if(sign==OK)
			{
				printf("删除弧成功！\n");
				printf("删除弧后的图如下：\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("未找到顶点或边不存在！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 11://深度优先搜索遍历。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("正在进行深度优先搜索遍历...\n");
				DFSTraverse(G,visit);
				printf("深度优先搜索遍历成功！\n");
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("正在进行深度优先搜索遍历...\n");
			DFSTraverse(G,visit);
			printf("深度优先搜索遍历成功！\n");
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 12://广度优先搜索遍历。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("正在进行广度优先搜索遍历...\n");
				BFSTraverse(G,visit);
				printf("广度优先搜索遍历成功！\n");
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("正在进行广度优先搜索遍历...\n");
			BFSTraverse(G,visit);
			printf("广度优先搜索遍历成功！\n");
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 13://距离小于k的顶点。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要计算的顶点的关键字和名称。\n");
				scanf("%d %s",&v.key,&v.others); 
				printf("请输入距离。\n");
				scanf("%d",&j);
				printf("正在计算距离小于%d的顶点...\n",j);
				sign=VerticesSetLessThanK(G,v,j);
				if(sign==OK){printf("\n");}
				else{printf("未找到距离小于%d的顶点！\n",j);}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要计算的顶点的关键字和名称。\n");
			scanf("%d %s",&v.key,&v.others); 
			printf("请输入距离。\n");
			scanf("%d",&j);
			printf("正在计算距离小于%d的顶点...\n",j);
			sign=VerticesSetLessThanK(G,v,j);
			if(sign==OK){printf("\n");}
			else{printf("未找到距离小于%d的顶点！\n",j);}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 14://连通分量。
	    printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("正在计算连通分量...\n");
				ret=ConnectedComponentsNums(G);
				printf("图的连通分量是%d。\n",ret);
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("正在计算连通分量...\n");
			ret=ConnectedComponentsNums(G);
			printf("图的连通分量是%d。\n",ret);
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 15://最短路径。
	    printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入要计算的顶点的关键字和名称。\n");
				scanf("%d %s %d %s",&v.key,&v.others,&w.key,&w.others); 
				printf("正在计算最短路径...\n",j);
				ret=ShortestPathLength(G,v,w);
				if(ret>=0){printf("最短路径是%d。\n",ret);}
				else{printf("未找到顶点或不连通！\n");}
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入要计算的顶点的关键字和名称。\n");
			scanf("%d %s %d %s",&v.key,&v.others,&w.key,&w.others); 
			printf("正在计算最短路径...\n",j);
			ret=ShortestPathLength(G,v,w);
			if(ret>=0){printf("最短路径是%d。\n",ret);}
			else{printf("未找到顶点或不连通！\n");}
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 16://图的文保存操作。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入文件名。\n");
				scanf("%s",&name);
				printf("正在保存图...\n",j);
				SaveGraph(G,name);
				printf("保存成功！\n");
				printf("\n");
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入文件名。\n");
			scanf("%s",&name);
			printf("正在保存图...\n",j);
			SaveGraph(G,name);
			printf("保存成功！\n");
			printf("\n");
			printf("本次测评结束。\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
		
		case 17://图的读取操作。 
		printf("请问您要如何测试这个函数？\n");
		printf("1.手动输入数据。\n2.从已有图中选择。(本操作会测评多图管理的查找和删除，以下同理。)\n"); 
		printf("请选择。\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//手动输入数据。 
		{
			printf("请您输入顶点集。格式：顶点关键字 顶点名称。输入结束符：-1 任意字符串。\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//读入点集和边集。 
			printf("请输入边集。格式：起点关键字 终点关键字。输入结束符：-1 任意数字。\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("您输入的图如下：\n");
				Traverse(G);
				printf("\n");
				printf("请输入文件名。\n");
				scanf("%s",&name);
				printf("正在读入图...\n");
				LoadGraph(G,name);
				printf("读入成功！\n");
				printf("读入的图如下：\n");
				Traverse(G);
				printf("\n");
				DestroyGraph(G); 
			}
			else{printf("顶点关键字重复或图不存在！\n");}
			printf("本次测评结束。\n"); 
		}
		else//从已有图中选择。 
		{
			if(graph_table.len==0)
			{
				printf("没有已有图！\n");
				break;
			}
			printf("请输入图的名字。\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("未找到图！\n");
				break;
			}
			printf("您选择的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("请输入文件名。\n");
			scanf("%s",&name);
			printf("正在读入图...\n");
			printf("读入成功！\n");
			LoadGraph(G,name);
			printf("读入的图如下：\n");
			Traverse(G);
			printf("\n");
			printf("本次测评结束。\n");
			ClearGraph(G);
		} 
		getchar();getchar();
		break;
	   case 0:
	   	system("pause");
         break;
	}//end of switch
}//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()
