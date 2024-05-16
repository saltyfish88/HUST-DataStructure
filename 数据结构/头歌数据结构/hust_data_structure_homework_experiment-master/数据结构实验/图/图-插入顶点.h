#ifndef InsertVex_
#define InsertVex_
status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
int i = 0;
int book[10000];   // 创建数组 book 来存储每个顶点出现的次数
for (i = 0; i < G.vexnum; i++) {
    book[G.vertices[i].data.key]++;   // 遍历顶点，统计每个顶点出现的次数
}
if (book[v.key] == 1) {   // 如果 v 已经存在，返回 ERROR
    return ERROR;
}
if (G.vexnum == MAX_VERTEX_NUM) {   // 判断顶点数是否已满
    return ERROR;
}
VNode node;         // 定义一个结构体变量 node
node.data = v;      // 将 v 的值存储进 node 中
node.firstarc = NULL;
G.vertices[G.vexnum] = node;    // 插入新节点
G.vexnum++;        // 将图 G 的节点数加 1
return OK;        // 返回插入成功
}
#endif

