#ifndef InsertVex_
#define InsertVex_
status InsertVex(ALGraph &G,VertexType v)
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
int i = 0;
int book[10000];   // �������� book ���洢ÿ��������ֵĴ���
for (i = 0; i < G.vexnum; i++) {
    book[G.vertices[i].data.key]++;   // �������㣬ͳ��ÿ��������ֵĴ���
}
if (book[v.key] == 1) {   // ��� v �Ѿ����ڣ����� ERROR
    return ERROR;
}
if (G.vexnum == MAX_VERTEX_NUM) {   // �ж϶������Ƿ�����
    return ERROR;
}
VNode node;         // ����һ���ṹ����� node
node.data = v;      // �� v ��ֵ�洢�� node ��
node.firstarc = NULL;
G.vertices[G.vexnum] = node;    // �����½ڵ�
G.vexnum++;        // ��ͼ G �Ľڵ����� 1
return OK;        // ���ز���ɹ�
}
#endif

