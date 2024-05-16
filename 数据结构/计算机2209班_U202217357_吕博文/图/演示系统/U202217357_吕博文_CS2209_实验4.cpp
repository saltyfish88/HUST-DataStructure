/* Linear Table On Sequence Structure */
#include<cstdio> 
#include<cstring> 
#include<iostream> 
#include<cstdlib> 
#include<algorithm> 
#include<malloc.h> 
#include<numeric> 

/*---------page 10 on textbook ---------*/

#define TRUE 1//定义真值 
#define FALSE 0//定制假值 
#define OK 1//程序正常运行 
#define ERROR 0//程序运行出错 
#define INFEASTABLE -1//输入或输出不合法 
#define OVERFLOW -2//数值溢出 
#define MAX_VERTEX_NUM 20 // 最大顶点数
#define LIST_INIT_SIZE 100 // 邻接表的初始长度
#define LISTINCREMENT  10 // 邻接表的增量

typedef int status; // 定义所有状态码和返回值的类型为int
typedef int KeyType; // 定义类型 KeyType，表示顶点标识
typedef enum { DG, DN, UDG, UDN } GraphKind; // 定义一个枚举类型 GraphKind，表示图的类型，包括有向图、有向网、无向图、无向网
typedef int QElemType; // 定义一个新的类型 QElemType，表示队列中的元素，是一个整型
typedef struct 
{
    KeyType  key;   // 数据项项的唯一标识，整型
    char others[20]; // 数据项的其他信息，字符型
} VertexType; // 定义一个结构体类型 VertexType，表示顶点的数据结构，包括唯一标识和其他信息

typedef struct ArcNode
{         // 定义一个结构体类型 ArcNode，表示边的表结点
    int adjvex;              // 相邻顶点的位置编号 
    struct ArcNode* nextarc; // 下一个表结点指针
} ArcNode;

typedef struct VNode 
{               // 定义一个结构体类型 VNode，表示头结点及其数组
    VertexType data;        // 顶点信息
    ArcNode* firstarc;       // 指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM]; // 定义一个结构体类型 VNode，表示顶点的结构体类型，包括顶点信息和指向第一条弧的指针；定义一个数组类型 AdjList，表示头结点的数组类型，每个头结点的指针均指向一个链表，构成一个更大链表 

typedef  struct {  // 定义一个结构体类型 ALGraph，表示邻接表的类型
    AdjList vertices;       // 顶点数组表示邻接表
    int vexnum, arcnum;     // 顶点数，边数
    GraphKind  kind;        // 图的类型
} ALGraph;

typedef struct QNode { // 定义一个结构体类型 QNode，表示队列结点
    QElemType data; // 队列中的元素
    struct QNode* next; // 下一个队列结点指针
}QNode, * QueuePtr;

typedef struct {
    QueuePtr front1, rear; // 定义一个结构体类型 LinkQueue，表示链式队列，包括队头和队尾指针
}LinkQueue;
int book[MAX_VERTEX_NUM];// 定义哈希表来判断顶点是否被访问过
int visited[MAX_VERTEX_NUM]; // 定义数组visited判断顶点是否被访问过

/*---------函数声明--------*/
status CreateGraph(ALGraph& G, VertexType V[], KeyType VR[][2]);
 // 声明一个函数 CreateGraph，用于创建图
status DestroyGraph(ALGraph& G); 
// 声明一个函数 DestroyGraph，用于销毁图
int LocateVex(ALGraph G, KeyType u); 
// 声明一个函数 LocateVex，用于查找顶点在图中的位置
status PutVex(ALGraph& G, KeyType u, VertexType value); 
// 声明一个函数 PutVex，用于修改顶点的值
int FirstAdjVex(ALGraph G, KeyType u); 
// 声明一个函数 FirstAdjVex，用于查找顶点的第一个邻接点
int NextAdjVex(ALGraph G, KeyType v, KeyType w); 
// 声明一个函数 NextAdjVex，用于查找顶点的下一个邻接点
status InsertVex(ALGraph& G, VertexType v); 
// 声明一个函数 InsertVex，用于插入顶点
status DeleteVex(ALGraph& G, KeyType v); 
// 声明一个函数 DeleteVex，用于删除顶点
status InsertArc(ALGraph& G, KeyType v, KeyType w); 
// 声明一个函数 InsertArc，用于插入边
status DeleteArc(ALGraph& G, KeyType v, KeyType w); 
// 声明一个函数 DeleteArc，用于删除边
void DFS(ALGraph G, int v, void (*visit)(VertexType)) ; 
// 声明一个函数 DFS，用于深度优先遍历图
void visit(VertexType v); 
// 声明一个函数 visit，用于访问顶点
status DFSTraverse(ALGraph& G, void (*visit)(VertexType)); 
// 声明一个函数 DFSTraverse，用于深度优先遍历图
status InitQueue(LinkQueue& Q); 
// 声明一个函数 InitQueue，用于初始化队列
status DestroyQueue(LinkQueue& Q) ; 
// 声明一个函数 DestroyQueue，用于销毁队列
status ClearQueue(LinkQueue& Q) ; 
// 声明一个函数 ClearQueue，用于清空队列
status QueueEmpty(LinkQueue Q) ; 
// 声明一个函数 QueueEmpty，用于判断队列是否为空
int QueueLength(LinkQueue Q); 
// 声明一个函数 QueueLength，用于获取队列长度
status EnQueue(LinkQueue& Q, QElemType e) ; 
// 声明一个函数 EnQueue，用于入队
status DeQueue(LinkQueue& Q, QElemType& e); 
// 声明一个函数 DeQueue，用于出队
status BFSTraverse(ALGraph& G, void(*visit)(VertexType)) ; 
// 声明一个函数 BFSTraverse，用于广度优先遍历图
status SaveGraph(ALGraph G, char FileName[]); 
// 声明一个函数 SaveGraph，用于将图保存到文件中
status Load(ALGraph& G, char FileName[]); 
// 声明一个函数 Load，用于从文件中加载图
status LoadGraph(ALGraph& G, char FileName[]) ; 
// 声明一个函数 LoadGraph，用于从文件中加载图
status VerticesSetLessThanK(ALGraph G, KeyType key, int k) ; 
// 声明一个函数 VerticesSetLessThanK，用于查找度数小于 k 的顶点集合
status ShortestPathLength(ALGraph G, VertexType v, VertexType w); 
// 声明一个函数 ShortestPathLength，用于查找两个顶点之间的最短路径长度
void bfs(ALGraph G, int startnode); 
// 声明一个函数 bfs，用于广度优先遍历图
status ConnectedComponentsNums(ALGraph G); 
// 声明一个函数 ConnectedComponentsNums，用于查找图的连通分量个数
int main() {
	int op = 1, i = 0, i_num = 0;
	KeyType key;
	VertexType e;
	ALGraph G[11];
	for (i = 0; i < 10; i++){
		G[i].kind = DG;
		G[i].vexnum = 0;
	}
	while (op) {
		system("cls");
		printf("\n\n");
		printf("\t\t      Menu for Undirected Graph On Chain Structure \n");
		printf("\t******************************************************************************\n");
		printf("\t\t\t1.  CreateGraph \t 2.  DestroyGraph\n");
		printf("\t\t\t3.  LocateVex   \t 4.  PutVex\n");
		printf("\t\t\t5.  FirstAdjVex \t 6.  NextAdjVex\n");
		printf("\t\t\t7.  InsertVex   \t 8.  DeleteVex\n");
		printf("\t\t\t9.  InsertArc   \t 10. DeleteArc\n");
		printf("\t\t\t11. DFSTraverse \t 12. BFSTraverse\n");
		printf("\t\t\t13. Save        \t 14. Load\n");
		printf("\t\t\t15. Choose      \t 0.  Exit\n");
		printf("\t\t\t-----------------------------------------------------------\n");
		printf("\t\t\t16. VerticesSetLessThanK 17.  ShortestPathLength\n");
		printf("\t\t\t18. ConnectedComponentsNums\n");
		printf("\t******************************************************************************\n");
		printf("\t\t\t请选择你的操作[0-18]: ");
		scanf("%d", &op);
		switch (op) {
		case 1: {
			VertexType V[30];
			KeyType VR[100][2];
			printf("请输入顶点序列和关系对序列:\n");
			i = 0;
			do {
				scanf("%d%s", &V[i].key, V[i].others);
			} while (V[i++].key != -1);
			i = 0;
			do {
				scanf("%d%d", &VR[i][0], &VR[i][1]);
			} while (VR[i++][0] != -1);
			if (CreateGraph(G[i_num], V, VR) == OK)
				printf("\t\t\t创建无向图成功!\n");
			else
				printf("\t\t\t创建无向图失败!\n");
			getchar(); getchar();
			break;
		}
		case 2: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			if (DestroyGraph(G[i_num]) == OK) {
				printf("\t\t\t销毁无向图成功!\n");
				for (i = i_num; i < 10; i++)
				{
					G[i] = G[i + 1];
				}
				i_num = 0;
			}
			else
				printf("\t\t\t销毁无向图失败!\n");
			getchar(); getchar();
			break;
		}
		case 3: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入所要查找的顶点的key:");
			scanf("%d", &key);
			if (LocateVex(G[i_num], key) == -1)
				printf("\t\t\t无向图中不存在该节点!\n");
			else {
				printf("\t\t\t该顶点的编号为%d ", LocateVex(G[i_num], key) + 1);
				visit(G[i_num].vertices[LocateVex(G[i_num], key)].data);
			}
			getchar(); getchar();
			break;
		}
		case 4: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入要修改的key: ");
			scanf("%d", &key);
			if (LocateVex(G[i_num], key) == -1)
				printf("\t\t\t该顶点不存在!\n");
			else
			{
				printf("\t\t\t请输入要将该点修改为的key和值: ");
				scanf("%d%s", &e.key, e.others);
				if (PutVex(G[i_num], key, e) == OK) printf("\t\t\t修改成功\n");
				else printf("\t\t\t修改失败\n");
			}
			getchar(); getchar();
			break;
		}
		
		case 5: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入要查找的顶点的key：");
			scanf("%d", &key);
			if (FirstAdjVex(G[i_num], key) == -1)
				printf("\t\t\t查找失败!\n");
			else {
				printf("\t\t\t该顶点首个邻接顶点的序号为%d\n", FirstAdjVex(G[i_num], key) + 1);
				printf("\t\t\t该顶点首个邻接顶点的值为%d,%s\n", G[i_num].vertices[FirstAdjVex(G[i_num], key)].data.key, G[i_num].vertices[FirstAdjVex(G[i_num], key)].data.others);
			}
			getchar(); getchar();
			break;
		}
		case 6: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入要查找的顶点的key:");
			scanf("%d", &key);
			printf("\t\t\t请输入和其相对的顶点的key：");
			scanf("%d", &i);
			if (NextAdjVex(G[i_num], key, i) == -1)
				printf("\t\t\t查找失败!\n");
			else
				printf("\t\t\tv相对于w的下一个邻接顶点为%d,%s\n", G[i_num].vertices[NextAdjVex(G[i_num], key, i)].data.key, G[i_num].vertices[NextAdjVex(G[i_num], key, i)].data.others);
			getchar(); getchar();
			break;
		}
		case 7: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入要添加的顶点的key和值: ");
			scanf("%d%s", &e.key, e.others);
			if (LocateVex(G[i_num], e.key) != -1)
				printf("\t\t\t该顶点已存在,添加失败!\n");
			else
			{
				if (InsertVex(G[i_num], e) == OK)
					printf("\t\t\t添加顶点成功!\n");
				else
					printf("\t\t\t添加顶点失败!\n");
			}
			getchar(); getchar();
			break;
		}
		case 8: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入要删除的顶点: ");
			scanf("%d", &key);
			if (DeleteVex(G[i_num], key) == ERROR)
				printf("\t\t\t所要删除的顶点不存在!\n");
			else printf("\t\t\t删除顶点成功!\n");
			getchar(); getchar();
			break;
		}
		case 9: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入边的头节点和尾节点的key:");
			scanf("%d%d", &key, &i);
			if (InsertArc(G[i_num], key, i) == ERROR)
				printf("\t\t\t添加失败!\n");
			else
				printf("\t\t\t添加成功!\n");
			getchar(); getchar();
			break;
		}
		case 10: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入边的尾节点和头节点的key:");
			scanf("%d%d", &key, &i);
			if (DeleteArc(G[i_num], key, i) == ERROR)
				printf("\t\t\t删除失败!\n");
			else
				printf("\t\t\t删除成功!\n");
			getchar(); getchar();
			break;
		}
		case 11: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t该无向图的深度优先搜索遍历为：");
			DFSTraverse(G[i_num], visit);
			getchar(); getchar();
			break;
		}
		case 12: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t该无向图的广度优先搜索遍历为：");
			BFSTraverse(G[i_num], visit);
			getchar(); getchar();
			break;
		}
		case 13: {
			char filename[100];
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入文件名:");
			scanf("%s", filename);
			if (SaveGraph(G[i_num], filename) == OK)
				printf("\t\t\t文件保存成功!\n");
			else
				printf("\t\t\t文件保存失败!\n");
			getchar(); getchar();
			break;
		}
		case 14: {
			char filename[100];
			printf("\t\t\t请输入文件名:");
			scanf("%s", filename);
			if (Load(G[i_num], filename) == OK)
				printf("\t\t\t加载成功!\n");
			else
				printf("\t\t\t加载失败!\n");
			getchar(); getchar();
			break;
		}
		case 15: {
			printf("\t\t请输入要在第几个表操作,只支持在10个顺序表进行操作: ");
			scanf("%d", &i_num);
			if (i_num < 0 || i_num > 9)
			{
				printf("\t\t\t不支持在该表上进行操作!\n");
				i_num = 0;
			}
			printf("\t\t在第%d个表操作", i_num);
			getchar(); getchar();
			break;
		}
		case 16: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入顶点的key和k:");
			scanf("%d%d", &key, &i);
			VerticesSetLessThanK(G[i_num], key, i);
			getchar(); getchar();
			break;
		}
		case 17: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t请输入两个顶点的key:");
			VertexType i;
			scanf("%d%d", &e.key, &i.key);
			printf("\t\t\t距离为%d", ShortestPathLength(G[i_num], e, i));
			getchar(); getchar();
			break;
		}
		case 18: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t无向图不存在!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t连通分量个数为:%d", ConnectedComponentsNums(G[i_num]));
			getchar(); getchar();
			break;
		}
		case 0:
			break;
		}
	}
	printf("\t\t\t欢迎下次使用本系统!\n\n");
}
/**
函数名称：CreateCraph
初始条件：邻接表G不存在，V为点，VR为图的树
操作结果：创建邻接表G，表示该图，使得邻接表中每个元素分别存储所对应的顶点以及与其相邻的顶点集合
函数变量：ALGraph& G，VertexType V[]，KeyType VR[][2]
*/
status CreateGraph(ALGraph& G, VertexType V[], KeyType VR[][2]){
	int i = 0;
	memset(&G, 0, sizeof(G));
	if (V[0].key == -1) return ERROR;
	while (V[i].key != -1) {
		G.vertices[i].data = V[i];
		G.vertices[i].firstarc = NULL;
		G.vexnum++;
		i++;
		if (G.vexnum > MAX_VERTEX_NUM) return ERROR;
	}
	i = 0;
	while (VR[i][0] != -1) {
		ArcNode* p; int first = 0, next = 0;
		int flag1 = 0, flag2 = 0;
		for (int j = 0; j < G.vexnum; j++)
			if (VR[i][0] == G.vertices[j].data.key) {
				flag1 = 1;
				first = j;
				break;
			}
		for (int j = 0; j < G.vexnum; j++)
			if (VR[i][1] == G.vertices[j].data.key) {
				flag2 = 1;
				next = j;
				break;
			}
		if (!flag1 || !flag2) return ERROR;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = next; p->nextarc = G.vertices[first].firstarc; G.vertices[first].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = first; p->nextarc = G.vertices[next].firstarc; G.vertices[next].firstarc = p;
		G.arcnum++;
		i++;
	}
	return OK;
}
/**
函数名称：DestroyGraph
初始条件：邻接表G存在
操作结果：销毁G这个邻接表结构并释放相应的空间
函数变量：ALGraph& G
*/
status DestroyGraph(ALGraph& G)
{
	ArcNode* p, * q;
	for (int i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while (p) {
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	G.vexnum = 0;
	G.arcnum = 0;
	return OK;
}
/**
函数名称：LocateVex
初始条件：邻接表G存在，Keytype的整数u
操作结果：获取顶点U在邻接表G中的位置，返回该点在邻接表G中的下标，如果该点不存在返回-1
函数变量：ALGraph G，KeyType u
*/
int LocateVex(ALGraph G, KeyType u)
{
	for (int i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data.key) return i;
	}
	return -1;
}
/**
函数名称：PutVex
初始条件：邻接表G存在，节点的值value存在
操作结果：找到邻接表G中的顶点U，并将其点值改为给定的value
函数变量：ALGraph& G，KeyType u，VertexType value
*/
status PutVex(ALGraph& G, KeyType u, VertexType value){

	for (int i = 0; i < G.vexnum; i++) {
		if (value.key == G.vertices[i].data.key) {
			return ERROR;
		}
	}
	for (int i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data.key) {
			G.vertices[i].data = value;
			return OK;
		}
	}
	return ERROR;
}
/**
函数名称：FirstAdjVex
初始条件：邻接表G存在，Keytype的整数u
操作结果：找到顶点U的第一个邻接点并返回该邻接点的下标，如果U不存在或者U没有邻接点则返回-1
函数变量：ALGraph G，KeyType u
*/
int FirstAdjVex(ALGraph G, KeyType u){
	for (int i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data.key) {
			if (G.vertices[i].firstarc) return G.vertices[i].firstarc->adjvex;
		}
	}
	return -1;
}
/**
函数名称：NextAdjVex
初始条件：邻接表G存在，节点v与节点w存在
操作结果：找到与节点U相邻的节点V在与W的邻接表中的下一个邻接节点并返回该邻接点的下标,没有下一个则返回-1
函数变量：ALGraph G，KeyType v，KeyType w
*/
int NextAdjVex(ALGraph G, KeyType v, KeyType w){
	for (int i = 0; i < G.vexnum; i++) {
		if (v == G.vertices[i].data.key) {
			ArcNode* p = G.vertices[i].firstarc;
			while (p) {
				if (G.vertices[p->adjvex].data.key == w) {
					if (p->nextarc != NULL) return p->nextarc->adjvex;
					else return -1;
				}
				p = p->nextarc;
			}
		}
	}
	return -1;
}
/**
函数名称：InsertVex
初始条件：邻接表G存在，新顶点v存在
操作结果：在邻接表G中插入一个新节点V
函数变量：ALGraph& G，VertexType v
*/
status InsertVex(ALGraph& G, VertexType v){
	if (G.vexnum == MAX_VERTEX_NUM) return ERROR;
	if (LocateVex(G, v.key) != -1) return ERROR;
	G.vertices[G.vexnum].data = v;
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
	return OK;
}
/**
函数名称：DeleteVex
初始条件：邻接表G存在，需要删除的节点u存在
操作结果：删除邻接表G中节点U以及所有与点U相关联的边
函数变量：ALGraph& G，KeyType u
*/
status DeleteVex(ALGraph& G, KeyType v){
	if (G.vexnum <= 1) return ERROR;
	int i, j;
	ArcNode* p, *q = NULL;
	j = LocateVex(G, v);
	if (j == -1) return ERROR;
	p = G.vertices[j].firstarc;
	while (p) {
		q = p;
		p = p->nextarc;
		free(q);
		G.arcnum--;
	}
	for (i = j; i < G.vexnum; i++) G.vertices[i] = G.vertices[i + 1];
	G.vexnum--;
	for (i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while (p) {
			if (p->adjvex == j) {
				if (p == G.vertices[i].firstarc) {
					G.vertices[i].firstarc = p->nextarc;
					free(p);
					p = G.vertices[i].firstarc;
				}
				else {
					q->nextarc = p->nextarc;
					free(p);
					p = q->nextarc;
				}
			}
			else {
				if (p->adjvex > j) p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	return OK;
}
/**
函数名称：InsertArc
初始条件：邻接表G存在，节点U与节点V之间的边存在
操作结果：在邻接表G中添加一条从节点U指向节点V的边
函数变量：ALGraph& G，KeyType u，KeyType v
*/
status InsertArc(ALGraph& G, KeyType v, KeyType w){
	ArcNode* p;
	int i = 0, j = 0;
	i = LocateVex(G, v);
	j = LocateVex(G, w);
	if (i == -1 || j == -1) return ERROR;
	p = G.vertices[i].firstarc;
	while (p) {
		if (p->adjvex == j) return ERROR;
		p = p->nextarc;
	}
	G.arcnum++;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = G.vertices[i].firstarc;
	G.vertices[i].firstarc = p;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = i;
	p->nextarc = G.vertices[j].firstarc;
	G.vertices[j].firstarc = p;
	return OK;
}
/**
函数名称：DeleteArc
初始条件：邻接表G存在，节点U与节点V之间的边存在
操作结果：删除所有在邻接表G中从U指向V的边
函数变量：ALGraph& G，KeyType u，KeyType v
*/
status DeleteArc(ALGraph& G, KeyType v, KeyType w){
	ArcNode* p, *q = NULL;
	int i = 0, j = 0;
	i = LocateVex(G, v);
	j = LocateVex(G, w);
	if (i == -1 || j == -1) return ERROR;
	p = G.vertices[i].firstarc;
	while (p && p->adjvex != j) {
		q = p;
		p = p->nextarc;
	}
	if (p && p->adjvex == j) {
		if (p == G.vertices[i].firstarc) G.vertices[i].firstarc = p->nextarc;
		else q->nextarc = p->nextarc;
		free(p);
		G.arcnum--;
	}
	p = G.vertices[j].firstarc;
	while (p && p->adjvex != i)
	{
		q = p;
		p = p->nextarc;
	}
	if (p && p->adjvex == i) {
		if (p == G.vertices[j].firstarc) G.vertices[j].firstarc = p->nextarc;
		else q->nextarc = p->nextarc;
		free(p);
	}
	return OK;
}
/**
函数名称：DFSTraverse
初始条件：邻接表G存在，visit函数已经实现
操作结果：对邻接表G进行深度优先遍历，并打印遍历结果， visit函数用于对节点进行操作
函数变量：ALGraph& G，void (*visit)(VertexType)
*/
void DFS(ALGraph G, int v, void (*visit)(VertexType)) {
	visited[v] = 1;
	visit(G.vertices[v].data);
	for (int i = FirstAdjVex(G, G.vertices[v].data.key); i != -1; i = NextAdjVex(G, G.vertices[v].data.key, G.vertices[i].data.key))
		if (!visited[i]) DFS(G, i, visit);
}
void visit(VertexType v){
	printf(" %d,%s", v.key, v.others);
}
status DFSTraverse(ALGraph& G, void (*visit)(VertexType))
{
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < G.vexnum; i++) if (!visited[i]) DFS(G, i, visit);
	return OK;
}
status InitQueue(LinkQueue& Q) {
	Q.front1 = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front1) exit(OVERFLOW);
	Q.front1->next = NULL;
	return OK;
}
status DestroyQueue(LinkQueue& Q) {
	while (Q.front1) {
		Q.rear = Q.front1->next;
		free(Q.front1);
		Q.front1 = Q.rear;
	}
	return OK;
}
status ClearQueue(LinkQueue& Q) {
	QueuePtr p, q;
	Q.rear = Q.front1;
	p = Q.front1->next;
	Q.front1->next = NULL;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}
status QueueEmpty(LinkQueue Q) {
	if (Q.front1 == Q.rear)
		return TRUE;
	else
		return FALSE;
}
int QueueLength(LinkQueue Q) {
	QueuePtr p;
	p = Q.front1;
	int i = 0;
	while (Q.rear != p) {
		i++;
		p = p->next;
	}
	return i;
}
status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
status DeQueue(LinkQueue& Q, QElemType& e) {
	QueuePtr p;
	if (Q.front1 == Q.rear) return ERROR;
	p = Q.front1->next;
	e = p->data;
	Q.front1->next = p->next;
	if (Q.rear == p) Q.rear = Q.front1;
	free(p);
	return OK;
}
/**
函数名称：BFSTraverse
初始条件：邻接表G存在，visit函数已经实现
操作结果：对邻接表G进行广度优先遍历，并打印遍历结果， visit函数用于对节点进行操作
函数变量：ALGraph& G，void (*visit)(VertexType)
*/
status BFSTraverse(ALGraph& G, void(*visit)(VertexType)) {
	int i, j, w;
	LinkQueue Q;
	memset(visited, 0, sizeof(visited));
	InitQueue(Q);
	for (i = 0; i < G.vexnum; i++)
		if (!visited[i]) {
			visited[i] = 1;
			visit(G.vertices[i].data);
			EnQueue(Q, i);
			while (!QueueEmpty(Q)) {
				DeQueue(Q, j);
				for (w = FirstAdjVex(G, G.vertices[j].data.key); w != -1; w = NextAdjVex(G, G.vertices[j].data.key, G.vertices[w].data.key))
					if (!visited[w]) {
						visited[w] = 1;
						visit(G.vertices[w].data);
						EnQueue(Q, w);
					}
			}
		}
	return OK;
}
/**
函数名称：SaveGraph
初始条件：邻接表G存在，以及一个待存储为文件的文件名FileName[]
操作结果：指定文件名把邻接表G存为文件
函数变量：ALGraph G，char FileName[]
*/
status SaveGraph(ALGraph G, char FileName[]){
	int i = 0;
	FILE* fp = fopen(FileName, "w");
	ArcNode* p;
	fprintf(fp, "%d %d %d\n", G.vexnum, G.arcnum, G.kind);
	for (i = 0; i < G.vexnum; i++) {
		fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
		if ((p = G.vertices[i].firstarc) != NULL) {
			fprintf(fp, "%d ", p->adjvex);
			while ((p = p->nextarc) != NULL) {
				fprintf(fp, "%d ", p->adjvex);
			}
		}
		fprintf(fp, "%d\n", -1);
	}
	fclose(fp);
	return OK;
}
status Load(ALGraph& G, char FileName[]){
	int i, num = 0;
	FILE* fp = fopen(FileName, "r");
	ArcNode* p;
	fscanf(fp, "%d %d %d", &G.vexnum, &G.arcnum, &G.kind);
	for (i = 0; i < G.vexnum; i++) {
		fscanf(fp, "%d %s", &G.vertices[i].data.key, &G.vertices[i].data.others);
		fscanf(fp, "%d", &num);
		G.vertices[i].firstarc = NULL;
		while (num != -1) {
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = num;
			p->nextarc = G.vertices[i].firstarc;
			G.vertices[i].firstarc = p;
			fscanf(fp, "%d", &num);
		}
	}
	fclose(fp);
	return OK;
}
/**
函数名称：LoadGraph
初始条件：一个待读取数据文件的文件名FileName[]
操作结果：从指定的文件名中读取图的信息，并生成一个邻接表G来表示该图
函数变量：ALGraph& G，char FileName[]
*/
status LoadGraph(ALGraph& G, char FileName[]) {
	Load(G, FileName);
	SaveGraph(G, FileName);
	Load(G, FileName);
	return OK;
}
/**
函数名称：VerticesSetLessThanK
初始条件：邻接表G存在，节点v以及整数k存在
操作结果：找到邻接表G中与节点v相连通且边权小于等于k的点集（不包括v）
函数变量：ALGraph G，KeyType v，int k
*/
status VerticesSetLessThanK(ALGraph G, KeyType key, int k) {
	LinkQueue q, nextlevel;
	InitQueue(q);
	InitQueue(nextlevel);
	int count = 0;
	memset(visited, 0, sizeof(visited));
	EnQueue(q, LocateVex(G, key));
	visit(G.vertices[LocateVex(G, key)].data);
	visited[LocateVex(G, key)] = 1;
	while (count < k - 1) {
		while (!QueueEmpty(q)) {
			int j = 0;
			DeQueue(q, j);
			for (int w = FirstAdjVex(G, G.vertices[j].data.key); w != -1; w = NextAdjVex(G, G.vertices[j].data.key, G.vertices[w].data.key))
				if (!visited[w]) {
					visited[w] = 1;
					visit(G.vertices[w].data);
					EnQueue(nextlevel, w);
				}
		}
		while (!QueueEmpty(nextlevel)) {
			int n = 0;
			DeQueue(nextlevel, n);
			EnQueue(q, n);
		}
		ClearQueue(nextlevel);
		count++;
	}
	return OK;
}
/**
函数名称：ShortestPathLength
初始条件：邻接表G存在，节点v以及节点w存在
操作结果：找到从节点v到节点w的路径的最短长度，并返回该最短路径长度
函数变量：ALGraph G，KeyType v，KeyType w
*/
status ShortestPathLength(ALGraph G, VertexType v, VertexType w)
{
	int i = 0, j = 0, locatev = -1, locatew = -1, minid = 0, min = -1;
	const int inf = 1 << 30; 
	ArcNode* trans = NULL;
	int dist[MAX_VERTEX_NUM] = { 0 };
	int book[MAX_VERTEX_NUM] = { 0 };
	if (G.vertices == NULL) { return -1; }
	for (i = 0; i < G.vexnum; i++) 
	{
		if (v.key == G.vertices[i].data.key) { locatev = i; }
		if (w.key == G.vertices[i].data.key) { locatew = i; }
	}
	if (locatew == -1 || locatev == -1) { return -1; }
	book[locatev]++;
	for (i = 0; i < G.vexnum; i++) { dist[i] = inf; } 
	trans = G.vertices[locatev].firstarc;
	dist[locatev] = 0;
	while (trans != NULL)
	{
		dist[trans->adjvex] = 1;
		trans = trans->nextarc;
	}
	for (i = 0; i < G.vexnum - 1; i++) 
	{
		min = inf;
		for (j = 0; j < G.vexnum; j++)
		{
			if (book[j] == 0 && min > dist[j])
			{
				minid = j;
				min = dist[j];
			}
		}
		book[minid]++;
		trans = G.vertices[minid].firstarc;
		while (trans != NULL)//尝试用这个点松弛和它邻近的点。 
		{
			if (dist[trans->adjvex] > 1 + dist[minid])
			{
				dist[trans->adjvex] = 1 + dist[minid];
			}
			trans = trans->nextarc;
		}
	}
	if (dist[locatew] == inf) { return -1; }//两点不连通。
	return dist[locatew];
}
void bfs(ALGraph G, int startnode)
{
	int head = 0, tail = 0;
	int queue[MAX_VERTEX_NUM] = { startnode };
	while (head <= tail)
	{
		ArcNode* trans = G.vertices[queue[head]].firstarc;
		while (trans != NULL)
		{
			if (book[trans->adjvex] == 0)
			{
				tail++;
				queue[tail] = trans->adjvex;
				book[trans->adjvex]++;
			}
			trans = trans->nextarc;
		}
		head++;
	}
}
/**
函数名称：ConnectedComponentsNums
初始条件：邻接表G存在
操作结果：输出邻接表G的连通分量个数
函数变量：ALGraph G
*/
status ConnectedComponentsNums(ALGraph G)
{
	int i = 0, cnt = 0;
	for (i = 0; i < MAX_VERTEX_NUM; i++) { book[i] = 0; }
	if (G.vertices == NULL) { return 0; }
	for (i = 0; i < G.vexnum; i++)
	{
		if (book[i] == 0)
		{
			book[i]++;
			cnt++;
			bfs(G, i);
		}
	}
	return cnt;
}
