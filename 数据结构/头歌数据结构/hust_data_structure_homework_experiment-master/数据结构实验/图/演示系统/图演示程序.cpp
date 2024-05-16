#include"../def.h"
#include"../ͼ-���붥��.h"
#include"../ͼ-���뻡.h"
#include"../ͼ-����.h"
#include"../ͼ-���Ҷ���.h"
#include"../ͼ-ɾ����.h"
#include"../ͼ-ɾ���ڵ�.h"
#include"../ͼ-���㸳ֵ.h"
#include"../ͼ-����.h"
#include"../ͼ-��õ�һ�ڽӵ�.h"
#include"../ͼ-�����һ�ڽӵ�.h"
#include"../ͼ-�ļ�����.h"
#include"../ͼ-���������������.h"
#include"../ͼ-���������������.h"
#include"../���ӹ���/ͼ-����С��k�Ķ���.h"
#include"../���ӹ���/ͼ-��ͨ����.h"
#include"../���ӹ���/ͼ-���·��.h"
#include"../���ӹ���/��ͼ����.h"
#include"../���ӹ���/ͼ-�ڽӾ������.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*  ���峣��   
#define TRUE 1   // ������ֵ 
#define FALSE 0  // ���Ƽ�ֵ 
#define OK 1     // ������������ 
#define ERROR 0  // ������������ 
#define INFEASIBLE -1 // �����������Ϸ� 
#define OVERFLOW -2   // ��ֵ���
#define MAX_SIZE 100//������� 
#define MAX_VERTEX_NUM 20//���ͼ�ڵ���� */
/*  �������  
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct 
{
    KeyType  key;
    char others[20];
}VertexType; //�������Ͷ���
typedef struct ArcNode //�������Ͷ���
{         
   	int adjvex;              //����λ�ñ�� 
    struct ArcNode  *nextarc;	   //��һ������ָ��
}ArcNode;
typedef struct VNode//ͷ��㼰���������Ͷ���
{
   	VertexType data;       	//������Ϣ
    ArcNode *firstarc;      	 //ָ���һ����
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct //�ڽӱ�����Ͷ���
{
    AdjList vertices;     	 //ͷ�������
    int vexnum,arcnum;   	  //������������
    GraphKind  kind;        //ͼ������
}ALGraph;
void visit(VertexType v){printf(" %d %s",v.key,v.others);}
void free0(void  *p);
typedef struct//ͼ�Ĺ����Ķ��塣 
{
	ALGraph graphs[MAX_SIZE];
	char*name[MAX_SIZE];
	int len;
	const int listsize=MAX_SIZE;
}ALGraphs;
int book[MAX_VERTEX_NUM]={0};//�����ϣ�������жϹؼ��� */ 

/* ��غ������� 
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]); //�����ڽӱ�GΪ�ڽӱ�VΪ�㣬VRΪͼ����

status DestroyGraph(ALGraph& G); // ����G����ڽӱ�ṹ

int LocateVex(ALGraph G, KeyType u); // ��ȡ����U���ڽӱ�G�е�λ�ã����������������һ���ڽӱ��Keytype������X

status PutVex(ALGraph& G, KeyType u, VertexType value); // ������U��ֵ��Ϊ�µ�value

int FirstAdjVex(ALGraph G, KeyType u); // ȡ����U�ĵ�һ���ڽӵ㣬���������������һ���ڽӱ��Keytype������X

int NextAdjVex(ALGraph G, KeyType v, KeyType w); // ȡ����U�����w����һ���ڽӵ㣬������Ҫ�ڽӱ��Լ� ����Keytype������

status InsertVex(ALGraph& G, VertexType v); // ����һ���½ڵ�

status DeleteVex(ALGraph& G, KeyType v); // ������Ҫɾ���Ľڵ㣬�Ӷ�ɾ���ڽӱ�����Ӧ�Ľڵ�

status InsertArc(ALGraph& G, KeyType v, KeyType w); //����ڵ�U��ڵ�V֮��ıߣ������ڽӱ��G

status DeleteArc(ALGraph& G, KeyType v, KeyType w);  // ����ڵ�U��ڵ�V֮��ıߣ����ñߴ�G���ڽӱ���ɾ��

status DFSTraverse(ALGraph& G, void (*visit)(VertexType)); // ������ȱ����ڽӱ�

status BFSTraverse(ALGraph& G, void (*visit)(VertexType)); // ������ȱ����ڽӱ�

status SaveGraph(ALGraph G, char FileName[]); // ָ���ļ������ڽӱ��Ϊ�ļ�

status LoadGraph(ALGraph& G, char FileName[]); // ��ָ�����ļ����ж�ȡ�ڽӱ�

status AddGraph(GRAPHS& Graphs, char ListName[]); //��ɭ��������µ��ڽӱ�

status RemoveGraph(GRAPHS& Graphs, char ListName[]); //��ɭ����ɾ��ָ���ڽӱ�

int LocateGraph(GRAPHS& Graphs, char ListName[]); // �ҵ�ָ���ڽӱ���ɭ���е�λ��

status GraphsTraverse(GRAPHS& Graphs); // ����ɭ�֣����ַ�����ʽ���ÿ���ڽӱ�

status ChooseGraph(ALGraph& G, GRAPHS& Graphs, int x); // ��ɭ����ѡ��ָ�����ڽӱ�

status VerticesSetLessThanK(ALGraph G,KeyType v,int k);// vΪĳ���㣬����ڽӱ�����õ�����ͨ�ұ�ȨС�ڵ���k �ĵ㼯

status ShortestPathLength(ALGraph G,KeyType v,KeyType w);// v��w��ʾ�����յ㣬����м�·������С����

status ConnectedComponentsNums(ALGraph G);// ����ڽӱ����ͨ��������
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
	printf("      ���ڽӱ�ʵ�ֵ�ͼ�˵� \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. ����ͼ          9. ���뻡\n");
	printf("    	  2. ����ͼ          10. ɾ����\n");
	printf("    	  3. ���Ҷ���        11. ��������������� \n");
	printf("    	  4. ���㸳ֵ        12. ���������������\n");
	printf("    	  5. ��õ�һ�ڽӵ�  13. ����С��k�Ķ���\n");
	printf("    	  6. �����һ�ڽӵ�  14. ��ͨ����\n");
	printf("    	  7. ���붥��        15. ���·��\n");
	printf("    	  8. ɾ������        16. ͼ�ı���\n");
	printf("    	  17. ͼ�Ķ�ȡ\n");
	printf("    	  0. �˳�\n");
	printf("-------------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~16]:");
	scanf("%d",&op1);
	if(op1<0||op1>17)
	{
		printf("Invalid Input!\n");
		system("pause");
		exit(-1);
	}
	printf("�������Ƿ���Ҫ�ȴ������ɸ�ͼ��(�������������ͼ����Ĳ���)(�������Ḳ�ǵ����е�ͼ)�ǣ�1����0\n");
	scanf("%d",&op2);
	if(op2!=1&&op2!=0)
	{
		printf("Invalid Input!\n");
		system("pause");
		exit(-1);
	}
	if(op2==1)//����ͼ�Ĺ���� 
	{
		//DestroyALGraphs(graph_table); 
		//tree_table.trees=NULL;
		//InitALGraphs(graph_table);
		graph_table.len=0;
		printf("����������Ҫ������ͼ�ĸ�����\n"); 
		scanf("%d",&n); 
		for(j=0;j<n;j++)
		{
			printf("�������������ͼ������֡�\n");
			scanf("%s",&name);
			printf("�������������%s��\n",name); 
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("���ڱ������ͼ...\n");
				sign=AddALGraph(graph_table,G,name);
				if(sign==OK){printf("ͼ����ɹ���\n");}
				else{printf("ͼ����ʧ�ܣ�\n");}
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			ClearGraph(G);
		}
	}
    switch(op1)
	{
	   case 1://����ͼ�� 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3!=1)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			printf("���ڴ���ͼ...\n"); 
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		DestroyGraph(G);
		getchar();getchar();
		break;
	   case 2://����ͼ�� 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("��������ͼ...\n");
				sign=DestroyGraph(G);
				if(sign==OK){printf("���ٳɹ���\n");}
				else{printf("����ʧ�ܣ�\n");}
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("��������ͼ...\n");
			sign=DestroyGraph(G);
			if(sign==OK){printf("���ٳɹ���\n");}
			else{printf("����ʧ�ܣ�\n");}
			printf("���ڴӹ������ɾ��...\n");
			sign=DeleteALGraph(graph_table,name); 
			if(sign==OK){printf("ɾ���ɹ���\n");}
			else{printf("ɾ��ʧ�ܣ�\n");}
			printf("���β���������\n");
		}
		getchar();getchar();
		break;
	   case 3://���Ҷ��㡣 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ���ҵĶ���Ĺؼ��֡�\n");
				scanf("%d",&j); 
				printf("���ڲ��Ҷ���...\n");
				ret=LocateVex(G,j);
				if(ret!=-1){printf("���ҳɹ���λ��%d��\n",ret);}
				else{printf("δ�ҵ����㣡\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ���ҵĶ���Ĺؼ��֡�\n");
			scanf("%d",&j); 
			printf("���ڲ��Ҷ���...\n");
			ret=LocateVex(G,j);
			if(ret!=-1){printf("���ҳɹ���λ��%d��\n",ret);}
			else{printf("δ�ҵ����㣡\n");} 
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 4://���㸳ֵ�� 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ��ֵ�Ķ���Ĺؼ��֡�\n");
				scanf("%d",&j); 
				printf("�������µĶ���Ĺؼ��ֺ����ơ�\n");
				scanf("%d %s",&v.key,&v.others);
				printf("���ڽ��ж���ĸ�ֵ...\n");
				sign=PutVex(G,j,v);
				if(sign==OK)
				{
					printf("��ֵ�ɹ���\n");
					printf("��ֵ���ͼ���£�\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("����ؼ����ظ���δ�ҵ����㣡\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ��ֵ�Ķ���Ĺؼ��֡�\n");
			scanf("%d",&j); 
			printf("�������µĶ���Ĺؼ��ֺ����ơ�\n");
			scanf("%d %s",&v.key,&v.others);
			printf("���ڽ��ж���ĸ�ֵ...\n");
			sign=PutVex(G,j,v);
			if(sign==OK)
			{
				printf("��ֵ�ɹ���\n");
				printf("��ֵ���ͼ���£�\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("����ؼ����ظ���δ�ҵ����㣡\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 5://��õ�һ�ڽӵ㡣 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ���ҵ�һ�ڽӵ�Ķ���Ĺؼ��֡�\n");
				scanf("%d",&j); 
				printf("���ڲ��ҵ�һ�ڽӵ�...\n");
				ret=FirstAdjVex(G,j);
				if(ret!=-1){printf("���ҵ�һ�ڽӵ�ɹ�������λ����%d��\n",ret);}
				else{printf("�������ڽӵ��δ�ҵ����㣡\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ���ҵ�һ�ڽӵ�Ķ���Ĺؼ��֡�\n");
			scanf("%d",&j); 
			printf("���ڲ��ҵ�һ�ڽӵ�...\n");
			ret=FirstAdjVex(G,j);
			if(ret!=-1){printf("���ҵ�һ�ڽӵ�ɹ�������λ����%d��\n",ret);}
			else{printf("�������ڽӵ��δ�ҵ����㣡\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 6://�����һ�ڽӵ㡣 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ������һ�ڽӵ�Ķ���Ĺؼ��֡�\n");
				scanf("%d",&j);
				printf("������Ҫ������һ�ڽӵ�Ķ����һ���ڽӵ�Ĺؼ��֡�\n");
				scanf("%d",&sign);
				printf("���ڲ�����һ�ڽӵ�...\n");
				ret=NextAdjVex(G,j,sign); 
				if(ret!=-1){printf("������һ�ڽӵ�ɹ�������λ����%d��\n",ret);}
				else{printf("������һ�ڽӵ�ʧ�ܣ�\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ������һ�ڽӵ�Ķ���Ĺؼ��֡�\n");
			scanf("%d",&j);
			printf("������Ҫ������һ�ڽӵ�Ķ����һ���ڽӵ�Ĺؼ��֡�\n");
			scanf("%d",&sign);
			printf("���ڲ�����һ�ڽӵ�...\n");
			ret=NextAdjVex(G,j,sign); 
			if(ret!=-1){printf("������һ�ڽӵ�ɹ�������λ����%d��\n",ret);}
			else{printf("������һ�ڽӵ�ʧ�ܣ�\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 7://���붥�㡣 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ����Ķ���Ĺؼ��ֺ����ơ�\n");
				scanf("%d %s",&v.key,&v.others);
				printf("���ڲ��붥��...\n");
				sign=InsertVex(G,v);
				if(sign==OK)
				{
					printf("���붥��ɹ���\n");
					printf("���붥����ͼ���£�\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("����ؼ����ظ���δ�ҵ����㣡\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ����Ķ���Ĺؼ��ֺ����ơ�\n");
			scanf("%d %s",&v.key,&v.others);
			printf("���ڲ��붥��...\n");
			sign=InsertVex(G,v);
			if(sign==OK)
			{
				printf("���붥��ɹ���\n");
				printf("���붥����ͼ���£�\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("����ؼ����ظ���δ�ҵ����㣡\n");}	
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 8://ɾ�����㡣 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫɾ���Ķ���Ĺؼ��֡�\n");
				scanf("%d",&j);
				printf("����ɾ������...\n");
				sign=DeleteVex(G,j); 
				if(sign==OK)
				{
					printf("ɾ������ɹ���\n");
					printf("ɾ��������ͼ���£�\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("δ�ҵ����㣡\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫɾ���Ķ���Ĺؼ��֡�\n");
			scanf("%d",&j);
			printf("����ɾ������...\n");
			sign=DeleteVex(G,j); 
			if(sign==OK)
			{
				printf("ɾ������ɹ���\n");
				printf("ɾ��������ͼ���£�\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("δ�ҵ����㣡\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 9://���뻡�� 
	    printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ����Ļ�����������Ĺؼ��֡�\n");
				scanf("%d %d",&i,&j);
				printf("���ڲ��뻡...\n");
				sign=InsertArc(G,i,j); 
				if(sign==OK) 
				{
					printf("���뻡�ɹ���\n");
					printf("���뻡���ͼ���£�\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("δ�ҵ�������Ѵ��ڣ�\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ����Ļ�����������Ĺؼ��֡�\n");
			scanf("%d %d",&i,&j);
			printf("���ڲ��뻡...\n");
			sign=InsertArc(G,i,j);
			if(sign==OK)
			{
				printf("���뻡�ɹ���\n");
				printf("���뻡���ͼ���£�\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("δ�ҵ��������Ѵ��ڣ�\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 10://ɾ������
	    printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫɾ���Ļ�����������Ĺؼ��֡�\n");
				scanf("%d %d",&i,&j);
				printf("����ɾ����...\n");
				sign=DeleteArc(G,i,j); 
				if(sign==OK)
				{
					printf("ɾ�����ɹ���\n");
					printf("ɾ�������ͼ���£�\n");
					Traverse(G);
					printf("\n");
				}
				else{printf("δ�ҵ������߲����ڣ�\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫɾ���Ļ�����������Ĺؼ��֡�\n");
			scanf("%d %d",&i,&j);
			printf("����ɾ����...\n");
			sign=DeleteArc(G,i,j); 
			if(sign==OK)
			{
				printf("ɾ�����ɹ���\n");
				printf("ɾ�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
			}
			else{printf("δ�ҵ������߲����ڣ�\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 11://����������������� 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("���ڽ������������������...\n");
				DFSTraverse(G,visit);
				printf("����������������ɹ���\n");
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("���ڽ������������������...\n");
			DFSTraverse(G,visit);
			printf("����������������ɹ���\n");
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 12://����������������� 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("���ڽ��й��������������...\n");
				BFSTraverse(G,visit);
				printf("����������������ɹ���\n");
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("���ڽ��й��������������...\n");
			BFSTraverse(G,visit);
			printf("����������������ɹ���\n");
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 13://����С��k�Ķ��㡣 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ����Ķ���Ĺؼ��ֺ����ơ�\n");
				scanf("%d %s",&v.key,&v.others); 
				printf("��������롣\n");
				scanf("%d",&j);
				printf("���ڼ������С��%d�Ķ���...\n",j);
				sign=VerticesSetLessThanK(G,v,j);
				if(sign==OK){printf("\n");}
				else{printf("δ�ҵ�����С��%d�Ķ��㣡\n",j);}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ����Ķ���Ĺؼ��ֺ����ơ�\n");
			scanf("%d %s",&v.key,&v.others); 
			printf("��������롣\n");
			scanf("%d",&j);
			printf("���ڼ������С��%d�Ķ���...\n",j);
			sign=VerticesSetLessThanK(G,v,j);
			if(sign==OK){printf("\n");}
			else{printf("δ�ҵ�����С��%d�Ķ��㣡\n",j);}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 14://��ͨ������
	    printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("���ڼ�����ͨ����...\n");
				ret=ConnectedComponentsNums(G);
				printf("ͼ����ͨ������%d��\n",ret);
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("���ڼ�����ͨ����...\n");
			ret=ConnectedComponentsNums(G);
			printf("ͼ����ͨ������%d��\n",ret);
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 15://���·����
	    printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("������Ҫ����Ķ���Ĺؼ��ֺ����ơ�\n");
				scanf("%d %s %d %s",&v.key,&v.others,&w.key,&w.others); 
				printf("���ڼ������·��...\n",j);
				ret=ShortestPathLength(G,v,w);
				if(ret>=0){printf("���·����%d��\n",ret);}
				else{printf("δ�ҵ��������ͨ��\n");}
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("������Ҫ����Ķ���Ĺؼ��ֺ����ơ�\n");
			scanf("%d %s %d %s",&v.key,&v.others,&w.key,&w.others); 
			printf("���ڼ������·��...\n",j);
			ret=ShortestPathLength(G,v,w);
			if(ret>=0){printf("���·����%d��\n",ret);}
			else{printf("δ�ҵ��������ͨ��\n");}
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
	   case 16://ͼ���ı�������� 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("�������ļ�����\n");
				scanf("%s",&name);
				printf("���ڱ���ͼ...\n",j);
				SaveGraph(G,name);
				printf("����ɹ���\n");
				printf("\n");
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("�������ļ�����\n");
			scanf("%s",&name);
			printf("���ڱ���ͼ...\n",j);
			SaveGraph(G,name);
			printf("����ɹ���\n");
			printf("\n");
			printf("���β���������\n");
			ClearGraph(G);
		}
		getchar();getchar();
		break;
		
		case 17://ͼ�Ķ�ȡ������ 
		printf("������Ҫ��β������������\n");
		printf("1.�ֶ��������ݡ�\n2.������ͼ��ѡ��(�������������ͼ����Ĳ��Һ�ɾ��������ͬ��)\n"); 
		printf("��ѡ��\n");
		scanf("%d",&op3);
		if(op3<=0||op3>2)
		{
			printf("Invalid Input!");
			break;
		}
		if(op3==1)//�ֶ��������ݡ� 
		{
			printf("�������붥�㼯����ʽ������ؼ��� �������ơ������������-1 �����ַ�����\n");
			i=0;
			do{scanf("%d%s",&V[i].key,V[i].others);}while(V[i++].key!=-1);//����㼯�ͱ߼��� 
			printf("������߼�����ʽ�����ؼ��� �յ�ؼ��֡������������-1 �������֡�\n");
			i=0;
			do{scanf("%d%d",&VR[i][0],&VR[i][1]);}while(VR[i++][0]!=-1);
			sign=CreateGraph(G,V,VR);
			if(sign==OK)
			{
				printf("�������ͼ���£�\n");
				Traverse(G);
				printf("\n");
				printf("�������ļ�����\n");
				scanf("%s",&name);
				printf("���ڶ���ͼ...\n");
				LoadGraph(G,name);
				printf("����ɹ���\n");
				printf("�����ͼ���£�\n");
				Traverse(G);
				printf("\n");
				DestroyGraph(G); 
			}
			else{printf("����ؼ����ظ���ͼ�����ڣ�\n");}
			printf("���β���������\n"); 
		}
		else//������ͼ��ѡ�� 
		{
			if(graph_table.len==0)
			{
				printf("û������ͼ��\n");
				break;
			}
			printf("������ͼ�����֡�\n");
			scanf("%s",&name);
			sign=SearchALGraph(graph_table,name,G);
			if(sign==ERROR)
			{
				printf("δ�ҵ�ͼ��\n");
				break;
			}
			printf("��ѡ���ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("�������ļ�����\n");
			scanf("%s",&name);
			printf("���ڶ���ͼ...\n");
			printf("����ɹ���\n");
			LoadGraph(G,name);
			printf("�����ͼ���£�\n");
			Traverse(G);
			printf("\n");
			printf("���β���������\n");
			ClearGraph(G);
		} 
		getchar();getchar();
		break;
	   case 0:
	   	system("pause");
         break;
	}//end of switch
}//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
