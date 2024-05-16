/* Linear Table On Sequence Structure  ���Ա��˳��ṹ*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1   // ������ֵ
#define FALSE 0  // ���Ƽ�ֵ
#define OK 1     // ������������
#define ERROR 0  // ������������
#define INFEASIBLE -1 // �����������Ϸ�
#define OVERFLOW -2   // ��ֵ���
#define MAX_VERTEX_NUM 20 // ���˵����
const int N=100;  // �궨�峣��N��ֵΪ100
typedef int status;  //��������״̬��ͷ���ֵ������Ϊint
typedef int KeyType;  // ����Ԫ�����Ͷ���
typedef enum { DG, DN, UDG, UDN } GraphKind; // ö������ GraphKind ����Ϊ DG, DN, UDG, UDN
typedef struct 
{
	KeyType  key;   // ���������Ψһ��ʶ������
	char others[20]; // �������������Ϣ���ַ���
} VertexType; // ������ݽṹ���Ͷ���

typedef struct ArcNode
{         // �ߵı������Ͷ���
	int adjvex;              // ���ڶ����λ�ñ�� 
	struct ArcNode* nextarc; // ��һ������ָ��
} ArcNode;

typedef struct VNode 
{				// ͷ��㼰���������Ͷ���
	VertexType data;       	// ������Ϣ
	ArcNode* firstarc;      	// ָ���һ����
} VNode, AdjList[MAX_VERTEX_NUM]; // ����Ľṹ�����Ͷ��壬�����ڽӱ�洢��ʽ 
// VNode�Ƕ���ͷ�ڵ�Ľṹ�壬AdjList��ͷ�ڵ���������ͣ�ÿ��ͷ����ָ���ָ��һ����������һ���������� 

typedef  struct {  //�ڽӱ�����Ͷ���
	AdjList vertices;       //���������ʾ�ڽӱ�
	int vexnum, arcnum;     // ������������
	GraphKind  kind;        //ͼ������
} ALGraph;

typedef struct 
{  // ɭ�ֵĶ���
    struct {
        char name[30];      // ÿ��ɭ�ֵ�����
        ALGraph G;          // ÿ��ɭ�ֵ��ڽӱ����ݽṹ
    }elem[10];
    int length;             // ɭ�ֵĳ���
    int listsize;           // ɭ�����ʱ�������󳤶�
}GRAPHS;

status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]); 
//�����ڽӱ�GΪ�ڽӱ�VΪ�㣬VRΪͼ����
status DestroyGraph(ALGraph& G); // ����G����ڽӱ�ṹ
int LocateVex(ALGraph G, KeyType u); 
// ��ȡ����U���ڽӱ�G�е�λ�ã����������������һ���ڽӱ��Keytype������X
status PutVex(ALGraph& G, KeyType u, VertexType value); 
// ������U��ֵ��Ϊ�µ�value
int FirstAdjVex(ALGraph G, KeyType u); 
// ȡ����U�ĵ�һ���ڽӵ㣬���������������һ���ڽӱ��Keytype������X
int NextAdjVex(ALGraph G, KeyType v, KeyType w);
 // ȡ����U�����w����һ���ڽӵ㣬������Ҫ�ڽӱ��Լ� ����Keytype������
status InsertVex(ALGraph& G, VertexType v); 
// ����һ���½ڵ�
status DeleteVex(ALGraph& G, KeyType v); 
// ������Ҫɾ���Ľڵ㣬�Ӷ�ɾ���ڽӱ�����Ӧ�Ľڵ�
status InsertArc(ALGraph& G, KeyType v, KeyType w);
 //����ڵ�U��ڵ�V֮��ıߣ������ڽӱ��G
status DeleteArc(ALGraph& G, KeyType v, KeyType w);  
// ����ڵ�U��ڵ�V֮��ıߣ����ñߴ�G���ڽӱ���ɾ��
status DFSTraverse(ALGraph& G, void (*visit)(VertexType));
// ������ȱ����ڽӱ�
status BFSTraverse(ALGraph& G, void (*visit)(VertexType)); 
// ������ȱ����ڽӱ�
status SaveGraph(ALGraph G, char FileName[]); 
// ָ���ļ������ڽӱ��Ϊ�ļ�
status LoadGraph(ALGraph& G, char FileName[]); 
// ��ָ�����ļ����ж�ȡ�ڽӱ�
status AddGraph(GRAPHS& Graphs, char ListName[]); 
//��ɭ��������µ��ڽӱ�
status RemoveGraph(GRAPHS& Graphs, char ListName[]); 
//��ɭ����ɾ��ָ���ڽӱ�
int LocateGraph(GRAPHS& Graphs, char ListName[]); 
// �ҵ�ָ���ڽӱ���ɭ���е�λ��
status GraphsTraverse(GRAPHS& Graphs); 
// ����ɭ�֣����ַ�����ʽ���ÿ���ڽӱ�
status ChooseGraph(ALGraph& G, GRAPHS& Graphs, int x); 
// ��ɭ����ѡ��ָ�����ڽӱ�
status VerticesSetLessThanK(ALGraph G,KeyType v,int k);
// vΪĳ���㣬����ڽӱ�����õ�����ͨ�ұ�ȨС�ڵ���k �ĵ㼯
status ShortestPathLength(ALGraph G,KeyType v,KeyType w);
// v��w��ʾ�����յ㣬����м�·������С����
status ConnectedComponentsNums(ALGraph G);
// ����ڽӱ����ͨ��������

int flag = 0; 
int f[20] = {}; // ����������f��flag
int a[20] = { 0 };
int dist[N][N];
int cnt;  // �����˱���dist��cntѭ��������

void visit(VertexType v)  // ����Ĳ�����Ϊ�����ӡ
{
    printf(" %d %s", v.key, v.others);
}

void firstset(void) // ��ʼ��������ͱ���
{
	for(int i=0;i<100;i++)
	  for(int j=0;j<100;j++)
	  dist[i][j]=200; // ����˫��ѭ������dist�Ķ�ά���������Ԫ�ص�Ĭ��ֵ����Ϊ200
	for(int i=0;i<100;i++) dist[i][i]=0;
}

void floyd(void)  // �������еı�Ȩ���������������֮������·��
{
	for(int k=0;k<cnt;k++)
       for(int i=0; i<cnt;i++)
         for(int j=i+1;j<cnt;j++)
         {
             if(dist[i][j]>dist[i][k]+dist[k][j]) // �������֮��ľ����֮ǰ���������С���͸�������
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
    printf("\n��ѡ����Ĳ���[0~22]:\n");
    while (op) {
        scanf("%d", &op);
        switch (op) {
        case 1:
            i = 0;
            printf("�����붥�����У���-1 nil������");
            do{
                scanf("%d%s", &V[i].key, V[i].others);
            }while (V[i++].key != -1);
            i = 0;
            printf("�������ϵ�����У���-1 -1������");
            do{
                scanf("%d%d", &VR[i][0], &VR[i][1]);
            }while (VR[i++][0] != -1);
            if (CreateCraph(G, V, VR) == OK)
                printf("ͼ�����ɹ���\n");
            else
                printf("ͼ����ʧ�ܣ�\n");
            break;
        case 2:
            if (DestroyGraph(G) == OK)
                printf("�ɹ�����ͼ���ͷ�����Ԫ�صĿռ䡣\n");
            else
                printf("���ܶԲ����ڵ�ͼ�������ٲ�����\n");
            break;
        case 3:
            printf("��������Ҫ��ͼ�в��ҵĶ���Ĺؼ��֣�");
            scanf("%d", &e);
            i = LocateVex(G, e);
            if (i != -1) printf("ͼ�йؼ���Ϊ%d�Ķ����λ��Ϊ%d\n", e, i);
            else
                printf("ͼ�в����ڹؼ���Ϊ%d�Ķ��㣡\n", e);
            break;
        case 4:
            printf("��������Ҫ�޸ĵĶ���Ĺؼ��֣�");
            scanf("%d", &e);
            printf("���䶥��ֵ�޸�Ϊ��");
            scanf("%d %s", &value.key, value.others);
            flag1 = PutVex(G, e, value);
            if (flag1 == ERROR)
                printf("��ֵ����ʧ�ܣ�\n");
            else if (flag1 == OK)
                printf("�ѽ��ؼ���Ϊ%d�Ķ���ֵ�޸�Ϊ%d,%s\n", e, value.key, value.others);
            break;
        case 5:
            printf("��������Ҫ�������һ�ڽӵ�Ķ��㣺");
            scanf("%d", &e);
            i = FirstAdjVex(G, e);
            if (i != -1)
                printf("����%d�ĵ�һ�ڽӵ��λ��Ϊ%d\n", e, i);
            else
                printf("����%dû�е�һ�ڽӵ㣡\n", e);
            break;
        case 6:
            printf("��������������Ĺؼ��֣�");
            scanf("%d %d", &e, &j);
            i = NextAdjVex(G, e, j);
            if (i != -1)
                printf("����%d����ڶ���%d����һ���ڽӶ���Ϊ%d %s\n", e, j, G.vertices[i].data.key, G.vertices[i].data.others);
            else printf("����һ�ڽӶ��㣡\n");
            break;
        case 7:
            printf("��������Ҫ����Ķ���ֵ��");
            scanf("%d %s", &value.key, value.others);
            flag1 = InsertVex(G, value);
            if (flag1 == OK)
                printf("���� %d %s �ѳɹ�����ͼ��\n", value.key, value.others);
            else if (flag == ERROR)
                printf("����ʧ�ܣ�\n");
            break;
        case 8:
            printf("��������Ҫɾ���Ķ���Ĺؼ��֣�");
            scanf("%d", &e);
            flag1 = DeleteVex(G, e);
            if (flag1 == OK)
                printf("�ؼ���Ϊ%d�Ķ����Ѵ�ͼ��ɾ��\n", e);
            else if (flag1 == ERROR)
                printf("ɾ��ʧ�ܣ�\n");
            break;
        case 9:
            printf("��������Ҫ����Ļ���");
            scanf("%d %d", &e, &j);
            flag1 = InsertArc(G, e, j);
            if (flag1 == OK)
                printf("����ɹ���\n");
            else if (flag1 == ERROR)
                printf("����ʧ�ܣ�\n");
            break;
        case 10:
            printf("��������Ҫɾ���Ļ���");
            scanf("%d %d", &e, &j);
            flag1 = DeleteArc(G, e, j);
            if (flag1 == OK)
                printf("ɾ���ɹ���\n");
            else if (flag1 == ERROR)
                printf("ɾ��ʧ�ܣ�\n");
            break;
        case 11:
            for (int m = 0;m < 20;m++)
                f[m] = 0;
            printf("�����������������\n");
            DFSTraverse(G, visit);
            printf("\n");
            break;
        case 12:
            for (int m = 0;m < 20;m++)
                a[m] = 0;
            printf("�����������������\n");
            BFSTraverse(G, visit);
            printf("\n");
            break;
        case 13:
            printf("�������ļ����ƣ�");
            scanf("%s", FileName);
            flag1 = SaveGraph(G, FileName);
            if (flag1 == ERROR)
                printf("�ļ���ʧ�ܣ�\n");
            else if (flag1 == OK)
                printf("ͼ�������Ѿ����Ƶ�����Ϊ %s ���ļ��С�\n", FileName);
            break;
        case 14:
            printf("�������ļ����ƣ�");
            scanf("%s", FileName);
            flag1 = LoadGraph(G, FileName);
            if (flag1 == ERROR)
                printf("�ļ���ʧ�ܣ�\n");
            else if (flag1 == OK)
                printf("����Ϊ %s ���ļ��е������Ѹ��Ƶ�ͼ�С�\n", FileName);
            else if (flag1 == INFEASIBLE)
                printf("���ܶ��Ѵ��ڵ�ͼ���н��ж��ļ�������\n");
            else if (flag1 == OVERFLOW)
                printf("�����\n");
            break;
        case 15: {char ListName[30] = { '\0' };
               printf("����������ͼ�����ƣ�");
               scanf("%s", ListName);
               flag1 = AddGraph(Graphs, ListName);
               if (flag1 == OK) printf("�ɹ���������Ϊ %s ��ͼ��\n", ListName);
               else printf("����ʧ�ܣ�\n");
               break;
        }
        case 16:
            printf("��������Ҫɾ����ͼ�����ƣ�");
            scanf("%s", ListName);
            flag1 = RemoveGraph(Graphs, ListName);
            if (flag1 == OK)
                printf("�ɹ�ɾ������Ϊ %s ��ͼ��\n", ListName);
            else if (flag == ERROR)
                printf("ɾ��ʧ�ܣ�\n");
            break;
        case 17: 
               printf("��������Ҫ���ҵ�ͼ�����ƣ�");
               scanf("%s", ListName);
               i = LocateGraph(Graphs, ListName);
               if (i == 0)
                   printf("����������Ϊ %s ��ͼ��\n", ListName);
               else printf("����Ϊ %s ��ͼ�����Ϊ%d\n", ListName, i);
               break;
        case 18:
            flag1 = GraphsTraverse(Graphs);
            if (flag1 == ERROR) printf("���Ա�ļ���Ϊ�ա�\n");
            break;
        case 19:
            printf("��������Ҫ���в��������Ա����ţ���1��ʼ����");
            scanf("%d", &i);
            flag1 = ChooseGraph(G, Graphs, i);
            if (flag1 == ERROR)
                printf("�������Ų��Ϸ���\n");
            else printf("����ɶ����Ա��������Ϊ%d�����Ա���в�����\n", i);
            break;
        case 20:
        	printf("�����붥��v�;���k:\n");
        	scanf("%d%d",&v,&k);
        	floyd();
			printf("����Ϊ%d�Ķ���Ϊ:",k);
        	flag=VerticesSetLessThanK(G,v,k);
        	if(flag==0)  printf("ʧ�ܣ�\n"); 
        	break;
        case 21:
        	printf("�����붥��v��w:\n");
        	scanf("%d%d",&v,&w);
        	floyd();
        	flag=ShortestPathLength(G,v,w);
        	printf("���·������Ϊ%d",flag);
        	if(flag==0) printf("ʧ�ܣ�"); 
        	break;
        case 22:
            if(ConnectedComponentsNums(G)!=0){
            	printf("��ͨ��������Ϊ%d",ConnectedComponentsNums(G));
			}
            break;
        case 0:
            break;
        }//end of switch
        printf("\n");
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()


/**
�������ƣ�CreateCraph
��ʼ�������ڽӱ�G�����ڣ�VΪ�㣬VRΪͼ����
��������������ڽӱ�G����ʾ��ͼ��ʹ���ڽӱ���ÿ��Ԫ�طֱ�洢����Ӧ�Ķ����Լ��������ڵĶ��㼯��
����������ALGraph& G��VertexType V[]��KeyType VR[][2]
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
�������ƣ�DestroyGraph
��ʼ�������ڽӱ�G����
�������������G����ڽӱ�ṹ���ͷ���Ӧ�Ŀռ�
����������ALGraph& G
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
�������ƣ�LocateVex
��ʼ�������ڽӱ�G���ڣ�Keytype������u
�����������ȡ����U���ڽӱ�G�е�λ�ã����ظõ����ڽӱ�G�е��±꣬����õ㲻���ڷ���-1
����������ALGraph G��KeyType u
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
�������ƣ�PutVex
��ʼ�������ڽӱ�G���ڣ��ڵ��ֵvalue����
����������ҵ��ڽӱ�G�еĶ���U���������ֵ��Ϊ������value
����������ALGraph& G��KeyType u��VertexType value
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
�������ƣ�FirstAdjVex
��ʼ�������ڽӱ�G���ڣ�Keytype������u
����������ҵ�����U�ĵ�һ���ڽӵ㲢���ظ��ڽӵ���±꣬���U�����ڻ���Uû���ڽӵ��򷵻�-1
����������ALGraph G��KeyType u
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
�������ƣ�NextAdjVex
��ʼ�������ڽӱ�G���ڣ��ڵ�v��ڵ�w����
����������ҵ���ڵ�U���ڵĽڵ�V����W���ڽӱ��е���һ���ڽӽڵ㲢���ظ��ڽӵ���±�,û����һ���򷵻�-1
����������ALGraph G��KeyType v��KeyType w
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
�������ƣ�InsertVex
��ʼ�������ڽӱ�G���ڣ��¶���v����
������������ڽӱ�G�в���һ���½ڵ�V
����������ALGraph& G��VertexType v
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
�������ƣ�DeleteVex
��ʼ�������ڽӱ�G���ڣ���Ҫɾ���Ľڵ�u����
���������ɾ���ڽӱ�G�нڵ�U�Լ��������U������ı�
����������ALGraph& G��KeyType u
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
�������ƣ�InsertArc
��ʼ�������ڽӱ�G���ڣ��ڵ�U��ڵ�V֮��ıߴ���
������������ڽӱ�G�����һ���ӽڵ�Uָ��ڵ�V�ı�
����������ALGraph& G��KeyType u��KeyType v
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
�������ƣ�DeleteArc
��ʼ�������ڽӱ�G���ڣ��ڵ�U��ڵ�V֮��ıߴ���
���������ɾ���������ڽӱ�G�д�Uָ��V�ı�
����������ALGraph& G��KeyType u��KeyType v
*/
status DeleteArc(ALGraph& G, KeyType v, KeyType w)
{
    int i=0,locatew=-1,locatev=-1,sign=0;
    ArcNode*pr=NULL;
    ArcNode*trans=NULL;
    for(i=0;i<G.vexnum;i++)//���ҽڵ㡣 
    {
    	if(w==G.vertices[i].data.key){locatew=i;}
    	if(v==G.vertices[i].data.key){locatev=i;}
	}
	if(locatev==-1||locatew==-1){return ERROR;}//�ڵ�δ�ҵ��� 
	trans=G.vertices[locatew].firstarc;
	pr=trans;
	while(trans!=NULL)//���Ҳ�ɾ���ߡ� 
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
			}//ɾ���Ļ��ڶ���
			pr->nextarc=trans->nextarc;
			pr=trans;
			free(trans);
			trans=NULL;
			break;//ɾ�������м�
		}
		pr=trans;
		trans=trans->nextarc;
	}
	if(sign==0){return ERROR;}//δ�ҵ��ߡ� 
	trans=G.vertices[locatev].firstarc;
	pr=trans;
	while(trans!=NULL)//ɾ���ߡ� 
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
�������ƣ�DFSTraverse
��ʼ�������ڽӱ�G���ڣ�visit�����Ѿ�ʵ��
������������ڽӱ�G����������ȱ���������ӡ��������� visit�������ڶԽڵ���в���
����������ALGraph& G��void (*visit)(VertexType)
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
�������ƣ�BFSTraverse
��ʼ�������ڽӱ�G���ڣ�visit�����Ѿ�ʵ��
������������ڽӱ�G���й�����ȱ���������ӡ��������� visit�������ڶԽڵ���в���
����������ALGraph& G��void (*visit)(VertexType)
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
�������ƣ�SaveGraph
��ʼ�������ڽӱ�G���ڣ��Լ�һ�����洢Ϊ�ļ����ļ���FileName[]
���������ָ���ļ������ڽӱ�G��Ϊ�ļ�
����������ALGraph G��char FileName[]
*/
status SaveGraph(ALGraph G, char FileName[])
{
    FILE* fp;
    if ((fp = fopen(FileName, "w")) == NULL) return ERROR;
    fprintf(fp, "%d ", G.vexnum);
    fprintf(fp, "%d ", G.arcnum);//���涥�����뻡��
    for (int i = 0; i < G.vexnum; i++) {//������
        fprintf(fp, "%d ", G.vertices[i].data.key);
        fprintf(fp, "%s ", G.vertices[i].data.others);
    }
    int keyflag = -1;
    char othersflag[10] = "nil";
    fprintf(fp, "%d ", keyflag);//�������
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
    fprintf(fp, "%d ", keyflag);//������
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
�������ƣ�LoadGraph
��ʼ������һ������ȡ�����ļ����ļ���FileName[]
�����������ָ�����ļ����ж�ȡͼ����Ϣ��������һ���ڽӱ�G����ʾ��ͼ
����������ALGraph& G��char FileName[]
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
�������ƣ�AddGraph
��ʼ����������һ��ɭ��Graphs���Լ�һ������ӵ��ڽӱ�����ListName[]
�����������Graphs�����һ���µ��ڽӱ�
����������GRAPHS& Graphs��char ListName[]
*/
status AddGraph(GRAPHS& Graphs, char ListName[])
{
    for (int i = 0;i < Graphs.length;i++)
        if (strcmp(Graphs.elem[i].name, ListName) == 0)
        {
            printf("�������Ѵ�������Ϊ %s ��ͼ��\n", ListName);
            return ERROR;
        }
    printf("��ͼ %s ����Ӷ��㣬�����붥�����к͹�ϵ�����У�\n", ListName);
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
        printf("�ؼ��ֲ�Ψһ��");return ERROR;
    }
}

/**
�������ƣ�RemoveGraph
��ʼ����������һ��ɭ��Graphs���Լ�һ����ɾ�����ڽӱ�����ListName[]
�����������Graphs��ɾ����ΪListName���ڽӱ�
����������GRAPHS& Graphs��char ListName[]
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
�������ƣ�LocateGraph
��ʼ����������һ��ɭ��Graphs���Լ�һ�������ҵ��ڽӱ�����ListName[]
�������������ListName��Graphs��ռ�ݵ��±�
����������GRAPHS& Graphs��char ListName[]
*/
int LocateGraph(GRAPHS& Graphs, char ListName[]) {
    for (int i = 0;i < Graphs.length;i++)
    {
        if (strcmp(Graphs.elem[i].name, ListName) == 0) return i + 1;
    }
    return 0;
}
/**
�������ƣ�GraphsTraverse
��ʼ����������һ��ɭ��Graphs
�������������ɭ��Graphs�������ַ�����ʽ���ÿ���ڽӱ����Ϣ
����������GRAPHS& Graphs
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
�������ƣ�ChooseGraph
��ʼ����������һ��ɭ��Graphs���Լ�һ����ѡ���ڽӱ���±�x
�����������Graphs��ѡ��xָ����ڽӱ�����ֵ��G
����������ALGraph& G��GRAPHS& Graphs��int x
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
�������ƣ�VerticesSetLessThanK
��ʼ�������ڽӱ�G���ڣ��ڵ�v�Լ�����k����
����������ҵ��ڽӱ�G����ڵ�v����ͨ�ұ�ȨС�ڵ���k�ĵ㼯��������v��
����������ALGraph G��KeyType v��int k
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
�������ƣ�ShortestPathLength
��ʼ�������ڽӱ�G���ڣ��ڵ�v�Լ��ڵ�w����
����������ҵ��ӽڵ�v���ڵ�w��·������̳��ȣ������ظ����·������
����������ALGraph G��KeyType v��KeyType w
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
�������ƣ�ConnectedComponentsNums
��ʼ�������ڽӱ�G����
�������������ڽӱ�G����ͨ��������
����������ALGraph G
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
