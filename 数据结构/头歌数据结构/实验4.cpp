/* Linear Table On Sequence Structure  线性表的顺序结构*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1   // 定义真值
#define FALSE 0  // 定制假值
#define OK 1     // 程序正常运行
#define ERROR 0  // 程序正常运行
#define INFEASIBLE -1 // 输入或输出不合法
#define OVERFLOW -2   // 数值溢出
#define MAX_VERTEX_NUM 20 // 最大端点个数
const int N=100;  // 宏定义常量N的值为100
typedef int status;  //定义所有状态码和返回值的类型为int
typedef int KeyType;  // 数据元素类型定义
typedef enum { DG, DN, UDG, UDN } GraphKind; // 枚举类型 GraphKind 定义为 DG, DN, UDG, UDN
typedef struct 
{
	KeyType  key;   // 数据项项的唯一标识，整型
	char others[20]; // 数据项的其他信息，字符型
} VertexType; // 点的数据结构类型定义

typedef struct ArcNode
{         // 边的表结点类型定义
	int adjvex;              // 相邻顶点的位置编号 
	struct ArcNode* nextarc; // 下一个表结点指针
} ArcNode;

typedef struct VNode 
{				// 头结点及其数组类型定义
	VertexType data;       	// 顶点信息
	ArcNode* firstarc;      	// 指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM]; // 顶点的结构体类型定义，用了邻接表存储方式 
// VNode是定义头节点的结构体，AdjList是头节点的数组类型，每个头结点的指针均指向一个链表，构成一个更大链表 

typedef  struct {  //邻接表的类型定义
	AdjList vertices;       //顶点数组表示邻接表
	int vexnum, arcnum;     // 顶点数，边数
	GraphKind  kind;        //图的类型
} ALGraph;

typedef struct 
{  // 森林的定义
    struct {
        char name[30];      // 每个森林的名称
        ALGraph G;          // 每个森林的邻接表数据结构
    }elem[10];
    int length;             // 森林的长度
    int listsize;           // 森林输出时允许的最大长度
}GRAPHS;

status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]); 
//创建邻接表，G为邻接表，V为点，VR为图的树
status DestroyGraph(ALGraph& G); // 销毁G这个邻接表结构
int LocateVex(ALGraph G, KeyType u); 
// 获取顶点U在邻接表G中的位置，本函数输入参数是一个邻接表和Keytype的整数X
status PutVex(ALGraph& G, KeyType u, VertexType value); 
// 将顶点U的值改为新的value
int FirstAdjVex(ALGraph G, KeyType u); 
// 取顶点U的第一个邻接点，本函数输入参数是一个邻接表和Keytype的整数X
int NextAdjVex(ALGraph G, KeyType v, KeyType w);
 // 取顶点U相对于w的下一个邻接点，输入需要邻接表以及 两个Keytype的整数
status InsertVex(ALGraph& G, VertexType v); 
// 插入一个新节点
status DeleteVex(ALGraph& G, KeyType v); 
// 输入需要删除的节点，从而删除邻接表中相应的节点
status InsertArc(ALGraph& G, KeyType v, KeyType w);
 //输入节点U与节点V之间的边，构成邻接表的G
status DeleteArc(ALGraph& G, KeyType v, KeyType w);  
// 输入节点U与节点V之间的边，将该边从G的邻接表中删除
status DFSTraverse(ALGraph& G, void (*visit)(VertexType));
// 深度优先遍历邻接表
status BFSTraverse(ALGraph& G, void (*visit)(VertexType)); 
// 广度优先遍历邻接表
status SaveGraph(ALGraph G, char FileName[]); 
// 指定文件名把邻接表存为文件
status LoadGraph(ALGraph& G, char FileName[]); 
// 从指定的文件名中读取邻接表
status AddGraph(GRAPHS& Graphs, char ListName[]); 
//向森林中添加新的邻接表
status RemoveGraph(GRAPHS& Graphs, char ListName[]); 
//从森林中删除指定邻接表
int LocateGraph(GRAPHS& Graphs, char ListName[]); 
// 找到指定邻接表在森林中的位置
status GraphsTraverse(GRAPHS& Graphs); 
// 遍历森林，以字符串形式输出每个邻接表
status ChooseGraph(ALGraph& G, GRAPHS& Graphs, int x); 
// 从森林中选择指定的邻接表
status VerticesSetLessThanK(ALGraph G,KeyType v,int k);
// v为某个点，输出邻接表中与该点相连通且边权小于等于k 的点集
status ShortestPathLength(ALGraph G,KeyType v,KeyType w);
// v和w表示起点和终点，输出中间路径的最小长度
status ConnectedComponentsNums(ALGraph G);
// 输出邻接表的连通分量个数

int flag = 0; 
int f[20] = {}; // 定义了数组f和flag
int a[20] = { 0 };
int dist[N][N];
int cnt;  // 定义了变量dist，cnt循环计数器

void visit(VertexType v)  // 传入的参数作为输出打印
{
    printf(" %d %s", v.key, v.others);
}

void firstset(void) // 初始化各数组和变量
{
	for(int i=0;i<100;i++)
	  for(int j=0;j<100;j++)
	  dist[i][j]=200; // 利用双重循环，将dist的二维数组的数组元素的默认值设置为200
	for(int i=0;i<100;i++) dist[i][i]=0;
}

void floyd(void)  // 根据已有的边权距离计算任意两点之间的最短路径
{
	for(int k=0;k<cnt;k++)
       for(int i=0; i<cnt;i++)
         for(int j=i+1;j<cnt;j++)
         {
             if(dist[i][j]>dist[i][k]+dist[k][j]) // 如果两点之间的距离比之前计算出来的小，就更新数组
                dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
         }
}

int main(void)
{
    ALGraph G;
    G.vexnum = 0;
    GRAPHS Graphs;
    Graphs.length = 0;
    VertexType value;
    VertexType V[30] = {};
    KeyType VR[100][2] = {};
    int i = 0, j;
    int v,k,w;
    int op = 1, length, e, pre, next, flag1 = 0;
    char FileName[30] = { '\0' };
    char ListName[30] = { '\0' };
    printf("\n\n");
    printf("      Menu for Linear Table On Sequence Structure \n");
    printf("------------------------------------------------\n");
    printf("     1. CreateGraph              2. DestroyGraph\n");
    printf("     3. LocateVex                4. PutVex\n");
    printf("     5. FirstAdjVex              6. NextAdjVex\n");
    printf("     7. InsertVex                8. DeleteVex\n");
    printf("     9. InsertArc                10.DeleteArc\n");
    printf("     11.DFSTraverse              12.BFSTraverse\n");
    printf("     13.SaveGraph                14.LoadGraph\n");
    printf("     15.AddGraph                 16.RemoveGraph\n");
    printf("     17.LocateGraph              18.GraphsTraverse\n");
    printf("     19.ChooseGraph              20.VerticesSetLessThanK\n");
    printf("     21.ShortestPathLength       22.ConnectedComponentsNums\n");
    printf("     0. Exit\n");
    printf("------------------------------------------------\n");
    printf("\n请选择你的操作[0~22]:\n");
    while (op) {
        scanf("%d", &op);
        switch (op) {
        case 1:
            i = 0;
            printf("请输入顶点序列，以-1 nil结束：");
            do{
                scanf("%d%s", &V[i].key, V[i].others);
            }while (V[i++].key != -1);
            i = 0;
            printf("请输入关系对序列，以-1 -1结束：");
            do{
                scanf("%d%d", &VR[i][0], &VR[i][1]);
            }while (VR[i++][0] != -1);
            if (CreateCraph(G, V, VR) == OK)
                printf("图创建成功！\n");
            else
                printf("图创建失败！\n");
            break;
        case 2:
            if (DestroyGraph(G) == OK)
                printf("成功销毁图并释放数据元素的空间。\n");
            else
                printf("不能对不存在的图进行销毁操作！\n");
            break;
        case 3:
            printf("请输入想要在图中查找的顶点的关键字：");
            scanf("%d", &e);
            i = LocateVex(G, e);
            if (i != -1) printf("图中关键字为%d的顶点的位序为%d\n", e, i);
            else
                printf("图中不存在关键字为%d的顶点！\n", e);
            break;
        case 4:
            printf("请输入想要修改的顶点的关键字：");
            scanf("%d", &e);
            printf("将其顶点值修改为：");
            scanf("%d %s", &value.key, value.others);
            flag1 = PutVex(G, e, value);
            if (flag1 == ERROR)
                printf("赋值操作失败！\n");
            else if (flag1 == OK)
                printf("已将关键字为%d的顶点值修改为%d,%s\n", e, value.key, value.others);
            break;
        case 5:
            printf("请输入想要查找其第一邻接点的顶点：");
            scanf("%d", &e);
            i = FirstAdjVex(G, e);
            if (i != -1)
                printf("顶点%d的第一邻接点的位序为%d\n", e, i);
            else
                printf("顶点%d没有第一邻接点！\n", e);
            break;
        case 6:
            printf("请输入两个顶点的关键字：");
            scanf("%d %d", &e, &j);
            i = NextAdjVex(G, e, j);
            if (i != -1)
                printf("顶点%d相对于顶点%d的下一个邻接顶点为%d %s\n", e, j, G.vertices[i].data.key, G.vertices[i].data.others);
            else printf("无下一邻接顶点！\n");
            break;
        case 7:
            printf("请输入想要插入的顶点值：");
            scanf("%d %s", &value.key, value.others);
            flag1 = InsertVex(G, value);
            if (flag1 == OK)
                printf("顶点 %d %s 已成功插入图中\n", value.key, value.others);
            else if (flag == ERROR)
                printf("插入失败！\n");
            break;
        case 8:
            printf("请输入想要删除的顶点的关键字：");
            scanf("%d", &e);
            flag1 = DeleteVex(G, e);
            if (flag1 == OK)
                printf("关键字为%d的顶点已从图中删除\n", e);
            else if (flag1 == ERROR)
                printf("删除失败！\n");
            break;
        case 9:
            printf("请输入想要插入的弧：");
            scanf("%d %d", &e, &j);
            flag1 = InsertArc(G, e, j);
            if (flag1 == OK)
                printf("插入成功！\n");
            else if (flag1 == ERROR)
                printf("插入失败！\n");
            break;
        case 10:
            printf("请输入想要删除的弧：");
            scanf("%d %d", &e, &j);
            flag1 = DeleteArc(G, e, j);
            if (flag1 == OK)
                printf("删除成功！\n");
            else if (flag1 == ERROR)
                printf("删除失败！\n");
            break;
        case 11:
            for (int m = 0;m < 20;m++)
                f[m] = 0;
            printf("深度优先搜索遍历：\n");
            DFSTraverse(G, visit);
            printf("\n");
            break;
        case 12:
            for (int m = 0;m < 20;m++)
                a[m] = 0;
            printf("广度优先搜索遍历：\n");
            BFSTraverse(G, visit);
            printf("\n");
            break;
        case 13:
            printf("请输入文件名称：");
            scanf("%s", FileName);
            flag1 = SaveGraph(G, FileName);
            if (flag1 == ERROR)
                printf("文件打开失败！\n");
            else if (flag1 == OK)
                printf("图的内容已经复制到名称为 %s 的文件中。\n", FileName);
            break;
        case 14:
            printf("请输入文件名称：");
            scanf("%s", FileName);
            flag1 = LoadGraph(G, FileName);
            if (flag1 == ERROR)
                printf("文件打开失败！\n");
            else if (flag1 == OK)
                printf("名称为 %s 的文件中的内容已复制到图中。\n", FileName);
            else if (flag1 == INFEASIBLE)
                printf("不能对已存在的图进行进行读文件操作。\n");
            else if (flag1 == OVERFLOW)
                printf("溢出！\n");
            break;
        case 15: {char ListName[30] = { '\0' };
               printf("请输入新增图的名称：");
               scanf("%s", ListName);
               flag1 = AddGraph(Graphs, ListName);
               if (flag1 == OK) printf("成功新增名称为 %s 的图。\n", ListName);
               else printf("新增失败！\n");
               break;
        }
        case 16:
            printf("请输入想要删除的图的名称：");
            scanf("%s", ListName);
            flag1 = RemoveGraph(Graphs, ListName);
            if (flag1 == OK)
                printf("成功删除名称为 %s 的图。\n", ListName);
            else if (flag == ERROR)
                printf("删除失败！\n");
            break;
        case 17: 
               printf("请输入想要查找的图的名称：");
               scanf("%s", ListName);
               i = LocateGraph(Graphs, ListName);
               if (i == 0)
                   printf("不存在名称为 %s 的图。\n", ListName);
               else printf("名称为 %s 的图的序号为%d\n", ListName, i);
               break;
        case 18:
            flag1 = GraphsTraverse(Graphs);
            if (flag1 == ERROR) printf("线性表的集合为空。\n");
            break;
        case 19:
            printf("请输入想要进行操作的线性表的序号（从1开始）：");
            scanf("%d", &i);
            flag1 = ChooseGraph(G, Graphs, i);
            if (flag1 == ERROR)
                printf("输入的序号不合法！\n");
            else printf("下面可对线性表集合中序号为%d的线性表进行操作。\n", i);
            break;
        case 20:
        	printf("请输入顶点v和距离k:\n");
        	scanf("%d%d",&v,&k);
        	floyd();
			printf("距离为%d的顶点为:",k);
        	flag=VerticesSetLessThanK(G,v,k);
        	if(flag==0)  printf("失败！\n"); 
        	break;
        case 21:
        	printf("请输入顶点v和w:\n");
        	scanf("%d%d",&v,&w);
        	floyd();
        	flag=ShortestPathLength(G,v,w);
        	printf("最短路径长度为%d",flag);
        	if(flag==0) printf("失败！"); 
        	break;
        case 22:
            if(ConnectedComponentsNums(G)!=0){
            	printf("连通分量个数为%d",ConnectedComponentsNums(G));
			}
            break;
        case 0:
            break;
        }//end of switch
        printf("\n");
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()


/**
函数名称：CreateCraph
初始条件：邻接表G不存在，V为点，VR为图的树
操作结果：创建邻接表G，表示该图，使得邻接表中每个元素分别存储所对应的顶点以及与其相邻的顶点集合
函数变量：ALGraph& G，VertexType V[]，KeyType VR[][2]
*/

int check(VertexType V[], KeyType VR[][2])
{
    if (V[0].key == -1) return 1;
    for (int i = 0;V[i].key != -1;i++)
    {
        if (i >= 20) return 1;
        for (int j = i + 1;V[j].key != -1;j++)
            if (V[i].key == V[j].key)
                return 1;
    }
    for (int i = 0;VR[i][0] != -1;i++)
        for (int j = i + 1;VR[j][0] != -1;j++)
            if (VR[i][0] == VR[j][0] && VR[i][1] == VR[j][1])
                return 1;
    return 0;
}
status insert(ALGraph& G, int x, int y)
{
    ArcNode* p = NULL;ArcNode* p1 = NULL;
    int i = 21, j = 21;
    for (int k = 0;k < G.vexnum;k++)
    {
        if (x == G.vertices[k].data.key) i = k;
        if (y == G.vertices[k].data.key) j = k;
    }
    if (i == 21 || j == 21) return ERROR;
    dist[i][j]=dist[j][i]=1;
    if (G.vertices[i].firstarc == NULL)
    {
        G.vertices[i].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
        if (G.vertices[i].firstarc != NULL) {
            G.vertices[i].firstarc->adjvex = j;
            G.vertices[i].firstarc->nextarc = NULL;
        }
    }
    else
    {
        if (!(p = (ArcNode*)malloc(sizeof(ArcNode))))
            return OVERFLOW;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
        p->adjvex = j;
    }
    if (G.vertices[j].firstarc == NULL)
    {
        G.vertices[j].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
        if (G.vertices[j].firstarc != NULL) {
            G.vertices[j].firstarc->adjvex = i;
            G.vertices[j].firstarc->nextarc = NULL;
        }
    }
    else
    {
        if (!(p = (ArcNode*)malloc(sizeof(ArcNode))))
            return OVERFLOW;
        p->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p;
        p->adjvex = i;
    }
    G.arcnum++;
    return OK;
}
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2])
{
	firstset();
    flag = check(V, VR);
    if (flag == 1) return ERROR;
    else
    {
        int i = 0;
        for (i = 0;V[i].key != -1;i++)
        {
            G.vertices[i].data.key = V[i].key;
            strcpy(G.vertices[i].data.others, V[i].others);
            G.vertices[i].firstarc = NULL;
        }
        G.vexnum = i;
        cnt=i;
        G.arcnum = 0;
        for (i = 0;VR[i][0] != -1;i++)
            insert(G, VR[i][0], VR[i][1]);
        return OK;
    }
}

/**
函数名称：DestroyGraph
初始条件：邻接表G存在
操作结果：销毁G这个邻接表结构并释放相应的空间
函数变量：ALGraph& G
*/
status DestroyGraph(ALGraph& G)
{
    if (G.vexnum == 0) return ERROR;
    G.arcnum = 0;
    ArcNode* p1, * p2;
    int i = 0, j;
    for (i = 0;i < G.vexnum;i++)
    {
        if (G.vertices[i].firstarc != NULL) p1 = G.vertices[i].firstarc;
        else p1 = NULL;
        do
        {
            p2 = p1;
            if(p1!=NULL){
                if (p1->nextarc == NULL) p1 = NULL;
                else p1 = p1->nextarc;
                free(p2);
            }
        } while (p1);
        G.vertices[i].firstarc = NULL;
    }
    G.vexnum = 0;
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
    int i = 0;
    while (i < G.vexnum)
    {
        if (u == G.vertices[i].data.key) return i;
        i++;
    }
    return -1;
}

/**
函数名称：PutVex
初始条件：邻接表G存在，节点的值value存在
操作结果：找到邻接表G中的顶点U，并将其点值改为给定的value
函数变量：ALGraph& G，KeyType u，VertexType value
*/
status PutVex(ALGraph& G, KeyType u, VertexType value)
{
    int i = 0, num = -1;
    while (i < G.vexnum)
    {
        if (u == G.vertices[i].data.key) num = i;
        if (value.key == G.vertices[i].data.key && value.key != u) return ERROR;
        i++;
    }
    if (num == -1) return ERROR;
    G.vertices[num].data = value;
    return OK;
}

/**
函数名称：FirstAdjVex
初始条件：邻接表G存在，Keytype的整数u
操作结果：找到顶点U的第一个邻接点并返回该邻接点的下标，如果U不存在或者U没有邻接点则返回-1
函数变量：ALGraph G，KeyType u
*/
int FirstAdjVex(ALGraph G, KeyType u)
{
    int i = 0, num = -1;
    while (i < G.vexnum)
    {
        if (u == G.vertices[i].data.key) 
        {
            num = i;break;
        }
        i++;
    }
    if (num == -1 || G.vertices[num].firstarc == NULL) return -1;
    else return G.vertices[num].firstarc->adjvex;
}

/**
函数名称：NextAdjVex
初始条件：邻接表G存在，节点v与节点w存在
操作结果：找到与节点U相邻的节点V在与W的邻接表中的下一个邻接节点并返回该邻接点的下标,没有下一个则返回-1
函数变量：ALGraph G，KeyType v，KeyType w
*/
int NextAdjVex(ALGraph G, KeyType v, KeyType w)
{
    int i = 0, num1 = -1, num2 = -1;
    while (i < G.vexnum)
    {
        if (v == G.vertices[i].data.key) num1 = i;
        if (w == G.vertices[i].data.key) num2 = i;
        i++;
    }
    if (num1 == -1 || num2 == -1) return -1;
    if (num1 == num2 || G.vertices[num1].firstarc == NULL) return -1;
    ArcNode* p1;
    p1 = G.vertices[num1].firstarc;
    while (p1->adjvex != num2) {
        p1 = p1->nextarc;
        if (p1 == NULL) return -1;
    }
    if (p1->nextarc == NULL) return -1;
    else return p1->nextarc->adjvex;
}

/**
函数名称：InsertVex
初始条件：邻接表G存在，新顶点v存在
操作结果：在邻接表G中插入一个新节点V
函数变量：ALGraph& G，VertexType v
*/
status InsertVex(ALGraph& G, VertexType v)
{
    int i = 0;
    while (i < G.vexnum) {
        if (v.key == G.vertices[i].data.key) return ERROR;
        i++;
        if (i >= 20) return ERROR;
    }
    G.vertices[i].data = v;
    G.vertices[i].firstarc = NULL;
    G.vexnum++;
    return OK;
}

/**
函数名称：DeleteVex
初始条件：邻接表G存在，需要删除的节点u存在
操作结果：删除邻接表G中节点U以及所有与点U相关联的边
函数变量：ALGraph& G，KeyType u
*/
status DeleteVex(ALGraph& G, KeyType v)
{
    int i = 0, num = -1;
    while (i < G.vexnum) {
        if (v == G.vertices[i].data.key) num = i;
        i++;
    }
    if (num == -1) return ERROR;
    if (num != -1 && G.vexnum == 1) return ERROR;
    ArcNode* p1, * p2;
    for (i = 0;i < G.vexnum;i++)
    {
        p1 = G.vertices[i].firstarc;
        p2 = p1;
        if (p1 == NULL) continue;
        if (i == num)
        {
            do{
                p2 = p1;
                p1 = p1->nextarc;
                free(p2);
            } while (p1);
            G.vertices[i].firstarc = NULL;
            continue;
        }
        else
        {
            if (p1->adjvex == num)
            {
                G.vertices[i].firstarc = p1->nextarc;free(p1);G.arcnum--;
            }
            else
            {
                p1 = p1->nextarc;
                while (p1)
                {
                    if (p1->adjvex == num) { p2->nextarc = p1->nextarc;free(p1);G.arcnum--;break; }
                    else { p1 = p1->nextarc;p2 = p2->nextarc; }
                }
            }
        }
    }
    for (i = num;i < G.vexnum;i++)
        G.vertices[i] = G.vertices[i + 1];
    G.vexnum--;
    for (i = 0;i < G.vexnum;i++)
    {
        p1 = G.vertices[i].firstarc;
        while (p1)
        {
            if (p1->adjvex > num) p1->adjvex--;
            p1 = p1->nextarc;
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
status InsertArc(ALGraph& G, KeyType v, KeyType w)
{
    int i = 0, num1 = -1, num2 = -1;
    while (i < G.vexnum)
    {
        if (v == G.vertices[i].data.key) num1 = i;
        if (w == G.vertices[i].data.key) num2 = i;
        i++;
    }
    if (num1 == -1 || num2 == -1 || num1 == num2) return ERROR;
    dist[num1][num2]=1;
    dist[num2][num1]=1;
     
    ArcNode* p1, * p2;

    p1 = G.vertices[num1].firstarc;
    while (p1)
    {
        if (p1->adjvex == num2) return ERROR;
        p1 = p1->nextarc;
    }

    p1 = G.vertices[num1].firstarc;
    p2 = (ArcNode*)malloc(sizeof(ArcNode));
    G.vertices[num1].firstarc = p2;
    p2->nextarc = p1;p2->adjvex = num2;

    p1 = G.vertices[num2].firstarc;
    p2 = (ArcNode*)malloc(sizeof(ArcNode));
    G.vertices[num2].firstarc = p2;
    p2->nextarc = p1;p2->adjvex = num1;

    G.arcnum++;
    return OK;
}

/**
函数名称：DeleteArc
初始条件：邻接表G存在，节点U与节点V之间的边存在
操作结果：删除所有在邻接表G中从U指向V的边
函数变量：ALGraph& G，KeyType u，KeyType v
*/
status DeleteArc(ALGraph& G, KeyType v, KeyType w)
{
    int i=0,locatew=-1,locatev=-1,sign=0;
    ArcNode*pr=NULL;
    ArcNode*trans=NULL;
    for(i=0;i<G.vexnum;i++)//查找节点。 
    {
    	if(w==G.vertices[i].data.key){locatew=i;}
    	if(v==G.vertices[i].data.key){locatev=i;}
	}
	if(locatev==-1||locatew==-1){return ERROR;}//节点未找到。 
	trans=G.vertices[locatew].firstarc;
	pr=trans;
	while(trans!=NULL)//查找并删除边。 
	{
		if(locatev==trans->adjvex)
		{
			sign=1;
			if(pr==trans)
			{
				G.vertices[locatew].firstarc=trans->nextarc;
				free(pr);
				pr=NULL;
				break;
			}//删除的弧在顶点
			pr->nextarc=trans->nextarc;
			pr=trans;
			free(trans);
			trans=NULL;
			break;//删除弧在中间
		}
		pr=trans;
		trans=trans->nextarc;
	}
	if(sign==0){return ERROR;}//未找到边。 
	trans=G.vertices[locatev].firstarc;
	pr=trans;
	while(trans!=NULL)//删除边。 
	{
		if(locatew==trans->adjvex)
		{
			if(pr==trans)
			{
				G.vertices[locatev].firstarc=trans->nextarc;
				free(pr);
				pr=NULL;
				break;
			}
			pr->nextarc=trans->nextarc;
			free(trans);
			trans=NULL;
			break;
		}
		pr=trans;
		trans=trans->nextarc;
	}
	G.arcnum--;
	return OK;
}

/**
函数名称：DFSTraverse
初始条件：邻接表G存在，visit函数已经实现
操作结果：对邻接表G进行深度优先遍历，并打印遍历结果， visit函数用于对节点进行操作
函数变量：ALGraph& G，void (*visit)(VertexType)
*/
void  DFS(ALGraph& G, int num, void (*visit)(VertexType))
{
    if (f[num]) return ;
    ArcNode* p = NULL;
    f[num] = 1;
    visit(G.vertices[num].data);
    p = G.vertices[num].firstarc;
    while (p) {
        num = p->adjvex;
        DFS(G, num, visit);
        p = p->nextarc;
    }
    return ;
}
status DFSTraverse(ALGraph& G, void (*visit)(VertexType))
{
    int i;
    int res=0;
    int flag=-1; 
    for (i = 0;i < G.vexnum;i++) 
        DFS(G, i, visit);
    return OK;
}

/**
函数名称：BFSTraverse
初始条件：邻接表G存在，visit函数已经实现
操作结果：对邻接表G进行广度优先遍历，并打印遍历结果， visit函数用于对节点进行操作
函数变量：ALGraph& G，void (*visit)(VertexType)
*/
status BFSTraverse(ALGraph& G, void (*visit)(VertexType))
{
    int i = 0;
    ArcNode* p1;
    while (i < G.vexnum)
    {
        if (a[i] == 0) { visit(G.vertices[i].data);a[i] = 1; }
        p1 = G.vertices[i].firstarc;
        while (p1)
        {
            if (a[p1->adjvex] == 0) { visit(G.vertices[p1->adjvex].data);a[p1->adjvex] = 1; }
            p1 = p1->nextarc;
        }
        i++;
    }
    return OK;
}

/**
函数名称：SaveGraph
初始条件：邻接表G存在，以及一个待存储为文件的文件名FileName[]
操作结果：指定文件名把邻接表G存为文件
函数变量：ALGraph G，char FileName[]
*/
status SaveGraph(ALGraph G, char FileName[])
{
    FILE* fp;
    if ((fp = fopen(FileName, "w")) == NULL) return ERROR;
    fprintf(fp, "%d ", G.vexnum);
    fprintf(fp, "%d ", G.arcnum);//保存顶点数与弧数
    for (int i = 0; i < G.vexnum; i++) {//保存结点
        fprintf(fp, "%d ", G.vertices[i].data.key);
        fprintf(fp, "%s ", G.vertices[i].data.others);
    }
    int keyflag = -1;
    char othersflag[10] = "nil";
    fprintf(fp, "%d ", keyflag);//顶点结束
    fprintf(fp, "%s ", othersflag);
    int stack[50][2];
    int top = 0;
    int key1 = 0, key2 = 0;
    ArcNode* p = NULL;
    for (int i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        while (p) {
            stack[top][0] = G.vertices[i].data.key;
            stack[top][1] = G.vertices[p->adjvex].data.key;
            top++;
            p = p->nextarc;
        }
        while (top != 0) {
            key1 = stack[top - 1][0];
            key2 = stack[top - 1][1];
            top--;
            fprintf(fp, "%d ", key1);
            fprintf(fp, "%d ", key2);
        }
    }
    fprintf(fp, "%d ", keyflag);//弧结束
    fprintf(fp, "%d ", keyflag);
    fclose(fp);
    return OK;
}


status createCraph(ALGraph& G, VertexType V[], KeyType VR[][2])
{
    int i = 0, j = 0;
    ArcNode* p;
    VertexType v;
    G.vexnum = 0;
    G.arcnum = 0;
    int arrkey[50] = { 0 };
    v.key = V[0].key;
    strcpy(v.others, V[0].others);
    while (v.key != -1) {
        for (int m = 0; m < G.vexnum; m++) {
            if (v.key == arrkey[m]) return ERROR;
        }
        G.vertices[G.vexnum].data = v;
        G.vertices[G.vexnum].firstarc = NULL;
        arrkey[G.vexnum] = v.key;
        G.vexnum++;
        i++;
        v.key = V[i].key;
        strcpy(v.others, V[i].others);
    }
    if (G.vexnum > 20 || G.vexnum < 1)  return ERROR;
    int a, b;
    int k = 0;
    a = VR[0][0];
    b = VR[0][1];
    while (a != -1 && b != -1) {
        G.arcnum++;
        int loca = LocateVex(G, a);
        int locb = LocateVex(G, b);
        if (loca == -1 || locb == -1) return ERROR;

        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->nextarc = G.vertices[loca].firstarc;
        p->adjvex = locb;
        G.vertices[loca].firstarc = p;

        k++;
        a = VR[k][0];
        b = VR[k][1];
    }
    return OK;
}
/**
函数名称：LoadGraph
初始条件：一个待读取数据文件的文件名FileName[]
操作结果：从指定的文件名中读取图的信息，并生成一个邻接表G来表示该图
函数变量：ALGraph& G，char FileName[]
*/
status LoadGraph(ALGraph& G, char FileName[])
{
    if (G.vexnum != 0) return INFEASIBLE;
    FILE* fp;
    fp = fopen(FileName, "r");
    int vexnum = -1, arcnum = -1, k = 0;
    VertexType V[25];
    KeyType VR[200][2];
    int vis[25][25] = { 0 };
    int key1 = -1, key2 = -1;
    fscanf(fp, "%d ", &vexnum);
    fscanf(fp, "%d ", &arcnum);
    for (int i = 0; i <= vexnum; i++) {
        fscanf(fp, "%d ", &V[i].key);
        fscanf(fp, "%s ", V[i].others);
    }
    fscanf(fp, "%d ", &key1);
    fscanf(fp, "%d ", &key2);
    while (key1 != -1 && key2 != -1) {
        VR[k][0] = key1;
        VR[k][1] = key2;
        k++;
        fscanf(fp, "%d ", &key1);
        fscanf(fp, "%d ", &key2);
    }
    createCraph(G, V, VR);
    return OK;
}

/**
函数名称：AddGraph
初始条件：存在一个森林Graphs，以及一个待添加的邻接表名称ListName[]
操作结果：向Graphs中添加一个新的邻接表
函数变量：GRAPHS& Graphs，char ListName[]
*/
status AddGraph(GRAPHS& Graphs, char ListName[])
{
    for (int i = 0;i < Graphs.length;i++)
        if (strcmp(Graphs.elem[i].name, ListName) == 0)
        {
            printf("集合中已存在名称为 %s 的图！\n", ListName);
            return ERROR;
        }
    printf("在图 %s 中添加顶点，请输入顶点序列和关系对序列：\n", ListName);
    int i;
    VertexType V[30] = {};
    KeyType VR[100][2] = {};
    i = 0;
    do {
        scanf("%d%s", &V[i].key, V[i].others);
    } while (V[i++].key != -1);
    i = 0;
    do {
        scanf("%d%d", &VR[i][0], &VR[i][1]);
    } while (VR[i++][0] != -1);
    flag = 0;
    Graphs.elem[Graphs.length].G.vexnum = 0;
    int a = CreateCraph(Graphs.elem[Graphs.length].G, V, VR);
    if (a == OK) {
        strcpy(Graphs.elem[Graphs.length].name, ListName);
        Graphs.length++;
        return OK;
    }
    else if (a == ERROR) {
        printf("关键字不唯一！");return ERROR;
    }
}

/**
函数名称：RemoveGraph
初始条件：存在一个森林Graphs，以及一个待删除的邻接表名称ListName[]
操作结果：在Graphs中删除名为ListName的邻接表
函数变量：GRAPHS& Graphs，char ListName[]
*/
status RemoveGraph(GRAPHS& Graphs, char ListName[])
{
    for (int i = 0;i < Graphs.length;i++)
    {
        if (strcmp(Graphs.elem[i].name, ListName) == 0)
        {
            DestroyGraph(Graphs.elem[i].G);
            for (int k = i;k < Graphs.length - 1;k++)
                Graphs.elem[k] = Graphs.elem[k + 1];
            Graphs.length--;
            return OK;
        }
    }
    return ERROR;
}
/**
函数名称：LocateGraph
初始条件：存在一个森林Graphs，以及一个待查找的邻接表名称ListName[]
操作结果：返回ListName在Graphs所占据的下标
函数变量：GRAPHS& Graphs，char ListName[]
*/
int LocateGraph(GRAPHS& Graphs, char ListName[]) {
    for (int i = 0;i < Graphs.length;i++)
    {
        if (strcmp(Graphs.elem[i].name, ListName) == 0) return i + 1;
    }
    return 0;
}
/**
函数名称：GraphsTraverse
初始条件：存在一个森林Graphs
操作结果：遍历森林Graphs，并以字符串形式输出每个邻接表的信息
函数变量：GRAPHS& Graphs
*/
status GraphsTraverse(GRAPHS& Graphs) {
    if (Graphs.length == 0) return ERROR;
    for (int n = 0;n < Graphs.length;n++)
    {
        printf("%s ", Graphs.elem[n].name);
        for (int m = 0;m < 20;m++)
            f[m] = 0;
        DFSTraverse(Graphs.elem[n].G, visit);
        putchar('\n');
    }
    return OK;
}

/**
函数名称：ChooseGraph
初始条件：存在一个森林Graphs，以及一个待选择邻接表的下标x
操作结果：从Graphs中选择x指向的邻接表，并赋值给G
函数变量：ALGraph& G，GRAPHS& Graphs，int x
*/
status ChooseGraph(ALGraph& G, GRAPHS& Graphs, int x) {
    if (x > Graphs.length || x < 1) return ERROR;
    else
    {
        char s[10] = { "aaa" };
        SaveGraph(Graphs.elem[x - 1].G, s);
        DestroyGraph(G);
        LoadGraph(G, s);
    }
    return OK;
}

/**
函数名称：VerticesSetLessThanK
初始条件：邻接表G存在，节点v以及整数k存在
操作结果：找到邻接表G中与节点v相连通且边权小于等于k的点集（不包括v）
函数变量：ALGraph G，KeyType v，int k
*/
status VerticesSetLessThanK(ALGraph G,KeyType v,int k){
	int i = 0, num1 = -1;
    while (i<cnt)
    {
        if (v == G.vertices[i].data.key) num1 = i;
        i++;
    }
    if (num1 == -1 ) return ERROR;
    i=num1;
	for(int j=0;j<cnt;j++)
	   if(dist[j][i]<k&&i!=j)
	     visit(G.vertices[j].data);
	return OK;
}

/**
函数名称：ShortestPathLength
初始条件：邻接表G存在，节点v以及节点w存在
操作结果：找到从节点v到节点w的路径的最短长度，并返回该最短路径长度
函数变量：ALGraph G，KeyType v，KeyType w
*/
status ShortestPathLength(ALGraph G,KeyType v,KeyType w){
	int i = 0, num1 = -1, num2 = -1, flag = 0;
    while (i < G.vexnum)
    {
        if (v == G.vertices[i].data.key) num1 = i;
        if (w == G.vertices[i].data.key) num2 = i;
        i++;
    }
    if (num1 == -1 || num2 == -1 || num1 == num2) return ERROR;
    return dist[num1][num2];
}

/**
函数名称：ConnectedComponentsNums
初始条件：邻接表G存在
操作结果：输出邻接表G的连通分量个数
函数变量：ALGraph G
*/
int  DFS1(ALGraph& G, int num)
{
    if (f[num]) return 0;
    ArcNode* p = NULL;
    f[num] = 1;
    p = G.vertices[num].firstarc;
    while (p) {
        num = p->adjvex;
        DFS1(G, num);
        p = p->nextarc;
    }
    return 1;
}
status ConnectedComponentsNums(ALGraph G){
	int i;
    int res=0;
    int flag=-1; 
    for(int i=0;i<cnt;i++) f[i]=0;
    for (i = 0;i < G.vexnum;i++) {
        flag=DFS1(G, i);
        if(flag) res++;
    }
    return res;
}
