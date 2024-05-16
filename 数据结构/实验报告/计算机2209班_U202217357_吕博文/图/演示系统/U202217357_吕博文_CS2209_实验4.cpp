/* Linear Table On Sequence Structure */
#include<cstdio> 
#include<cstring> 
#include<iostream> 
#include<cstdlib> 
#include<algorithm> 
#include<malloc.h> 
#include<numeric> 

/*---------page 10 on textbook ---------*/

#define TRUE 1//������ֵ 
#define FALSE 0//���Ƽ�ֵ 
#define OK 1//������������ 
#define ERROR 0//�������г��� 
#define INFEASTABLE -1//�����������Ϸ� 
#define OVERFLOW -2//��ֵ��� 
#define MAX_VERTEX_NUM 20 // ��󶥵���
#define LIST_INIT_SIZE 100 // �ڽӱ�ĳ�ʼ����
#define LISTINCREMENT  10 // �ڽӱ������

typedef int status; // ��������״̬��ͷ���ֵ������Ϊint
typedef int KeyType; // �������� KeyType����ʾ�����ʶ
typedef enum { DG, DN, UDG, UDN } GraphKind; // ����һ��ö������ GraphKind����ʾͼ�����ͣ���������ͼ��������������ͼ��������
typedef int QElemType; // ����һ���µ����� QElemType����ʾ�����е�Ԫ�أ���һ������
typedef struct 
{
    KeyType  key;   // ���������Ψһ��ʶ������
    char others[20]; // �������������Ϣ���ַ���
} VertexType; // ����һ���ṹ������ VertexType����ʾ��������ݽṹ������Ψһ��ʶ��������Ϣ

typedef struct ArcNode
{         // ����һ���ṹ������ ArcNode����ʾ�ߵı���
    int adjvex;              // ���ڶ����λ�ñ�� 
    struct ArcNode* nextarc; // ��һ������ָ��
} ArcNode;

typedef struct VNode 
{               // ����һ���ṹ������ VNode����ʾͷ��㼰������
    VertexType data;        // ������Ϣ
    ArcNode* firstarc;       // ָ���һ����
} VNode, AdjList[MAX_VERTEX_NUM]; // ����һ���ṹ������ VNode����ʾ����Ľṹ�����ͣ�����������Ϣ��ָ���һ������ָ�룻����һ���������� AdjList����ʾͷ�����������ͣ�ÿ��ͷ����ָ���ָ��һ����������һ���������� 

typedef  struct {  // ����һ���ṹ������ ALGraph����ʾ�ڽӱ������
    AdjList vertices;       // ���������ʾ�ڽӱ�
    int vexnum, arcnum;     // ������������
    GraphKind  kind;        // ͼ������
} ALGraph;

typedef struct QNode { // ����һ���ṹ������ QNode����ʾ���н��
    QElemType data; // �����е�Ԫ��
    struct QNode* next; // ��һ�����н��ָ��
}QNode, * QueuePtr;

typedef struct {
    QueuePtr front1, rear; // ����һ���ṹ������ LinkQueue����ʾ��ʽ���У�������ͷ�Ͷ�βָ��
}LinkQueue;
int book[MAX_VERTEX_NUM];// �����ϣ�����ж϶����Ƿ񱻷��ʹ�
int visited[MAX_VERTEX_NUM]; // ��������visited�ж϶����Ƿ񱻷��ʹ�

/*---------��������--------*/
status CreateGraph(ALGraph& G, VertexType V[], KeyType VR[][2]);
 // ����һ������ CreateGraph�����ڴ���ͼ
status DestroyGraph(ALGraph& G); 
// ����һ������ DestroyGraph����������ͼ
int LocateVex(ALGraph G, KeyType u); 
// ����һ������ LocateVex�����ڲ��Ҷ�����ͼ�е�λ��
status PutVex(ALGraph& G, KeyType u, VertexType value); 
// ����һ������ PutVex�������޸Ķ����ֵ
int FirstAdjVex(ALGraph G, KeyType u); 
// ����һ������ FirstAdjVex�����ڲ��Ҷ���ĵ�һ���ڽӵ�
int NextAdjVex(ALGraph G, KeyType v, KeyType w); 
// ����һ������ NextAdjVex�����ڲ��Ҷ������һ���ڽӵ�
status InsertVex(ALGraph& G, VertexType v); 
// ����һ������ InsertVex�����ڲ��붥��
status DeleteVex(ALGraph& G, KeyType v); 
// ����һ������ DeleteVex������ɾ������
status InsertArc(ALGraph& G, KeyType v, KeyType w); 
// ����һ������ InsertArc�����ڲ����
status DeleteArc(ALGraph& G, KeyType v, KeyType w); 
// ����һ������ DeleteArc������ɾ����
void DFS(ALGraph G, int v, void (*visit)(VertexType)) ; 
// ����һ������ DFS������������ȱ���ͼ
void visit(VertexType v); 
// ����һ������ visit�����ڷ��ʶ���
status DFSTraverse(ALGraph& G, void (*visit)(VertexType)); 
// ����һ������ DFSTraverse������������ȱ���ͼ
status InitQueue(LinkQueue& Q); 
// ����һ������ InitQueue�����ڳ�ʼ������
status DestroyQueue(LinkQueue& Q) ; 
// ����һ������ DestroyQueue���������ٶ���
status ClearQueue(LinkQueue& Q) ; 
// ����һ������ ClearQueue��������ն���
status QueueEmpty(LinkQueue Q) ; 
// ����һ������ QueueEmpty�������ж϶����Ƿ�Ϊ��
int QueueLength(LinkQueue Q); 
// ����һ������ QueueLength�����ڻ�ȡ���г���
status EnQueue(LinkQueue& Q, QElemType e) ; 
// ����һ������ EnQueue���������
status DeQueue(LinkQueue& Q, QElemType& e); 
// ����һ������ DeQueue�����ڳ���
status BFSTraverse(ALGraph& G, void(*visit)(VertexType)) ; 
// ����һ������ BFSTraverse�����ڹ�����ȱ���ͼ
status SaveGraph(ALGraph G, char FileName[]); 
// ����һ������ SaveGraph�����ڽ�ͼ���浽�ļ���
status Load(ALGraph& G, char FileName[]); 
// ����һ������ Load�����ڴ��ļ��м���ͼ
status LoadGraph(ALGraph& G, char FileName[]) ; 
// ����һ������ LoadGraph�����ڴ��ļ��м���ͼ
status VerticesSetLessThanK(ALGraph G, KeyType key, int k) ; 
// ����һ������ VerticesSetLessThanK�����ڲ��Ҷ���С�� k �Ķ��㼯��
status ShortestPathLength(ALGraph G, VertexType v, VertexType w); 
// ����һ������ ShortestPathLength�����ڲ�����������֮������·������
void bfs(ALGraph G, int startnode); 
// ����һ������ bfs�����ڹ�����ȱ���ͼ
status ConnectedComponentsNums(ALGraph G); 
// ����һ������ ConnectedComponentsNums�����ڲ���ͼ����ͨ��������
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
		printf("\t\t\t��ѡ����Ĳ���[0-18]: ");
		scanf("%d", &op);
		switch (op) {
		case 1: {
			VertexType V[30];
			KeyType VR[100][2];
			printf("�����붥�����к͹�ϵ������:\n");
			i = 0;
			do {
				scanf("%d%s", &V[i].key, V[i].others);
			} while (V[i++].key != -1);
			i = 0;
			do {
				scanf("%d%d", &VR[i][0], &VR[i][1]);
			} while (VR[i++][0] != -1);
			if (CreateGraph(G[i_num], V, VR) == OK)
				printf("\t\t\t��������ͼ�ɹ�!\n");
			else
				printf("\t\t\t��������ͼʧ��!\n");
			getchar(); getchar();
			break;
		}
		case 2: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			if (DestroyGraph(G[i_num]) == OK) {
				printf("\t\t\t��������ͼ�ɹ�!\n");
				for (i = i_num; i < 10; i++)
				{
					G[i] = G[i + 1];
				}
				i_num = 0;
			}
			else
				printf("\t\t\t��������ͼʧ��!\n");
			getchar(); getchar();
			break;
		}
		case 3: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t��������Ҫ���ҵĶ����key:");
			scanf("%d", &key);
			if (LocateVex(G[i_num], key) == -1)
				printf("\t\t\t����ͼ�в����ڸýڵ�!\n");
			else {
				printf("\t\t\t�ö���ı��Ϊ%d ", LocateVex(G[i_num], key) + 1);
				visit(G[i_num].vertices[LocateVex(G[i_num], key)].data);
			}
			getchar(); getchar();
			break;
		}
		case 4: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������Ҫ�޸ĵ�key: ");
			scanf("%d", &key);
			if (LocateVex(G[i_num], key) == -1)
				printf("\t\t\t�ö��㲻����!\n");
			else
			{
				printf("\t\t\t������Ҫ���õ��޸�Ϊ��key��ֵ: ");
				scanf("%d%s", &e.key, e.others);
				if (PutVex(G[i_num], key, e) == OK) printf("\t\t\t�޸ĳɹ�\n");
				else printf("\t\t\t�޸�ʧ��\n");
			}
			getchar(); getchar();
			break;
		}
		
		case 5: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������Ҫ���ҵĶ����key��");
			scanf("%d", &key);
			if (FirstAdjVex(G[i_num], key) == -1)
				printf("\t\t\t����ʧ��!\n");
			else {
				printf("\t\t\t�ö����׸��ڽӶ�������Ϊ%d\n", FirstAdjVex(G[i_num], key) + 1);
				printf("\t\t\t�ö����׸��ڽӶ����ֵΪ%d,%s\n", G[i_num].vertices[FirstAdjVex(G[i_num], key)].data.key, G[i_num].vertices[FirstAdjVex(G[i_num], key)].data.others);
			}
			getchar(); getchar();
			break;
		}
		case 6: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������Ҫ���ҵĶ����key:");
			scanf("%d", &key);
			printf("\t\t\t�����������ԵĶ����key��");
			scanf("%d", &i);
			if (NextAdjVex(G[i_num], key, i) == -1)
				printf("\t\t\t����ʧ��!\n");
			else
				printf("\t\t\tv�����w����һ���ڽӶ���Ϊ%d,%s\n", G[i_num].vertices[NextAdjVex(G[i_num], key, i)].data.key, G[i_num].vertices[NextAdjVex(G[i_num], key, i)].data.others);
			getchar(); getchar();
			break;
		}
		case 7: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������Ҫ��ӵĶ����key��ֵ: ");
			scanf("%d%s", &e.key, e.others);
			if (LocateVex(G[i_num], e.key) != -1)
				printf("\t\t\t�ö����Ѵ���,���ʧ��!\n");
			else
			{
				if (InsertVex(G[i_num], e) == OK)
					printf("\t\t\t��Ӷ���ɹ�!\n");
				else
					printf("\t\t\t��Ӷ���ʧ��!\n");
			}
			getchar(); getchar();
			break;
		}
		case 8: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������Ҫɾ���Ķ���: ");
			scanf("%d", &key);
			if (DeleteVex(G[i_num], key) == ERROR)
				printf("\t\t\t��Ҫɾ���Ķ��㲻����!\n");
			else printf("\t\t\tɾ������ɹ�!\n");
			getchar(); getchar();
			break;
		}
		case 9: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������ߵ�ͷ�ڵ��β�ڵ��key:");
			scanf("%d%d", &key, &i);
			if (InsertArc(G[i_num], key, i) == ERROR)
				printf("\t\t\t���ʧ��!\n");
			else
				printf("\t\t\t��ӳɹ�!\n");
			getchar(); getchar();
			break;
		}
		case 10: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������ߵ�β�ڵ��ͷ�ڵ��key:");
			scanf("%d%d", &key, &i);
			if (DeleteArc(G[i_num], key, i) == ERROR)
				printf("\t\t\tɾ��ʧ��!\n");
			else
				printf("\t\t\tɾ���ɹ�!\n");
			getchar(); getchar();
			break;
		}
		case 11: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������ͼ�����������������Ϊ��");
			DFSTraverse(G[i_num], visit);
			getchar(); getchar();
			break;
		}
		case 12: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t������ͼ�Ĺ��������������Ϊ��");
			BFSTraverse(G[i_num], visit);
			getchar(); getchar();
			break;
		}
		case 13: {
			char filename[100];
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t�������ļ���:");
			scanf("%s", filename);
			if (SaveGraph(G[i_num], filename) == OK)
				printf("\t\t\t�ļ�����ɹ�!\n");
			else
				printf("\t\t\t�ļ�����ʧ��!\n");
			getchar(); getchar();
			break;
		}
		case 14: {
			char filename[100];
			printf("\t\t\t�������ļ���:");
			scanf("%s", filename);
			if (Load(G[i_num], filename) == OK)
				printf("\t\t\t���سɹ�!\n");
			else
				printf("\t\t\t����ʧ��!\n");
			getchar(); getchar();
			break;
		}
		case 15: {
			printf("\t\t������Ҫ�ڵڼ��������,ֻ֧����10��˳�����в���: ");
			scanf("%d", &i_num);
			if (i_num < 0 || i_num > 9)
			{
				printf("\t\t\t��֧���ڸñ��Ͻ��в���!\n");
				i_num = 0;
			}
			printf("\t\t�ڵ�%d�������", i_num);
			getchar(); getchar();
			break;
		}
		case 16: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t�����붥���key��k:");
			scanf("%d%d", &key, &i);
			VerticesSetLessThanK(G[i_num], key, i);
			getchar(); getchar();
			break;
		}
		case 17: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t���������������key:");
			VertexType i;
			scanf("%d%d", &e.key, &i.key);
			printf("\t\t\t����Ϊ%d", ShortestPathLength(G[i_num], e, i));
			getchar(); getchar();
			break;
		}
		case 18: {
			if (G[i_num].vexnum == 0)
			{
				printf("\t\t\t����ͼ������!\n");
				getchar(); getchar();
				break;
			}
			printf("\t\t\t��ͨ��������Ϊ:%d", ConnectedComponentsNums(G[i_num]));
			getchar(); getchar();
			break;
		}
		case 0:
			break;
		}
	}
	printf("\t\t\t��ӭ�´�ʹ�ñ�ϵͳ!\n\n");
}
/**
�������ƣ�CreateCraph
��ʼ�������ڽӱ�G�����ڣ�VΪ�㣬VRΪͼ����
��������������ڽӱ�G����ʾ��ͼ��ʹ���ڽӱ���ÿ��Ԫ�طֱ�洢����Ӧ�Ķ����Լ��������ڵĶ��㼯��
����������ALGraph& G��VertexType V[]��KeyType VR[][2]
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
�������ƣ�DestroyGraph
��ʼ�������ڽӱ�G����
�������������G����ڽӱ�ṹ���ͷ���Ӧ�Ŀռ�
����������ALGraph& G
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
�������ƣ�LocateVex
��ʼ�������ڽӱ�G���ڣ�Keytype������u
�����������ȡ����U���ڽӱ�G�е�λ�ã����ظõ����ڽӱ�G�е��±꣬����õ㲻���ڷ���-1
����������ALGraph G��KeyType u
*/
int LocateVex(ALGraph G, KeyType u)
{
	for (int i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data.key) return i;
	}
	return -1;
}
/**
�������ƣ�PutVex
��ʼ�������ڽӱ�G���ڣ��ڵ��ֵvalue����
����������ҵ��ڽӱ�G�еĶ���U���������ֵ��Ϊ������value
����������ALGraph& G��KeyType u��VertexType value
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
�������ƣ�FirstAdjVex
��ʼ�������ڽӱ�G���ڣ�Keytype������u
����������ҵ�����U�ĵ�һ���ڽӵ㲢���ظ��ڽӵ���±꣬���U�����ڻ���Uû���ڽӵ��򷵻�-1
����������ALGraph G��KeyType u
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
�������ƣ�NextAdjVex
��ʼ�������ڽӱ�G���ڣ��ڵ�v��ڵ�w����
����������ҵ���ڵ�U���ڵĽڵ�V����W���ڽӱ��е���һ���ڽӽڵ㲢���ظ��ڽӵ���±�,û����һ���򷵻�-1
����������ALGraph G��KeyType v��KeyType w
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
�������ƣ�InsertVex
��ʼ�������ڽӱ�G���ڣ��¶���v����
������������ڽӱ�G�в���һ���½ڵ�V
����������ALGraph& G��VertexType v
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
�������ƣ�DeleteVex
��ʼ�������ڽӱ�G���ڣ���Ҫɾ���Ľڵ�u����
���������ɾ���ڽӱ�G�нڵ�U�Լ��������U������ı�
����������ALGraph& G��KeyType u
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
�������ƣ�InsertArc
��ʼ�������ڽӱ�G���ڣ��ڵ�U��ڵ�V֮��ıߴ���
������������ڽӱ�G�����һ���ӽڵ�Uָ��ڵ�V�ı�
����������ALGraph& G��KeyType u��KeyType v
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
�������ƣ�DeleteArc
��ʼ�������ڽӱ�G���ڣ��ڵ�U��ڵ�V֮��ıߴ���
���������ɾ���������ڽӱ�G�д�Uָ��V�ı�
����������ALGraph& G��KeyType u��KeyType v
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
�������ƣ�DFSTraverse
��ʼ�������ڽӱ�G���ڣ�visit�����Ѿ�ʵ��
������������ڽӱ�G����������ȱ���������ӡ��������� visit�������ڶԽڵ���в���
����������ALGraph& G��void (*visit)(VertexType)
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
�������ƣ�BFSTraverse
��ʼ�������ڽӱ�G���ڣ�visit�����Ѿ�ʵ��
������������ڽӱ�G���й�����ȱ���������ӡ��������� visit�������ڶԽڵ���в���
����������ALGraph& G��void (*visit)(VertexType)
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
�������ƣ�SaveGraph
��ʼ�������ڽӱ�G���ڣ��Լ�һ�����洢Ϊ�ļ����ļ���FileName[]
���������ָ���ļ������ڽӱ�G��Ϊ�ļ�
����������ALGraph G��char FileName[]
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
�������ƣ�LoadGraph
��ʼ������һ������ȡ�����ļ����ļ���FileName[]
�����������ָ�����ļ����ж�ȡͼ����Ϣ��������һ���ڽӱ�G����ʾ��ͼ
����������ALGraph& G��char FileName[]
*/
status LoadGraph(ALGraph& G, char FileName[]) {
	Load(G, FileName);
	SaveGraph(G, FileName);
	Load(G, FileName);
	return OK;
}
/**
�������ƣ�VerticesSetLessThanK
��ʼ�������ڽӱ�G���ڣ��ڵ�v�Լ�����k����
����������ҵ��ڽӱ�G����ڵ�v����ͨ�ұ�ȨС�ڵ���k�ĵ㼯��������v��
����������ALGraph G��KeyType v��int k
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
�������ƣ�ShortestPathLength
��ʼ�������ڽӱ�G���ڣ��ڵ�v�Լ��ڵ�w����
����������ҵ��ӽڵ�v���ڵ�w��·������̳��ȣ������ظ����·������
����������ALGraph G��KeyType v��KeyType w
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
		while (trans != NULL)//������������ɳں����ڽ��ĵ㡣 
		{
			if (dist[trans->adjvex] > 1 + dist[minid])
			{
				dist[trans->adjvex] = 1 + dist[minid];
			}
			trans = trans->nextarc;
		}
	}
	if (dist[locatew] == inf) { return -1; }//���㲻��ͨ��
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
�������ƣ�ConnectedComponentsNums
��ʼ�������ڽӱ�G����
�������������ڽӱ�G����ͨ��������
����������ALGraph G
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
