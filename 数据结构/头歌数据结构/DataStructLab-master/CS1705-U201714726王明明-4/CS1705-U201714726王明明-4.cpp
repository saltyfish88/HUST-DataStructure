/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define MAX_NAME 3

typedef int status;
typedef char VertexType[MAX_NAME];//MAX_NAME������ʾͼ��ÿ��������ռ�õ�����ַ��ռ�
typedef int InfoType;//�ڵ���Ϣ����
typedef int QElemType;
int visited[MAX_VERTEX_NUM];

typedef struct ArcNode{
	int adjvex;//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;//ָ����һ������ָ��
	InfoType *info;//�û������Ϣ��ָ��
}ArcNode;

typedef struct{
	VertexType data;//������Ϣ���ڵ������
	int key;//�ؼ���key������Ƕ���,���ڲ�ѯ
	ArcNode *firstarc;//ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;
	int vexnum, arcnum;//������ʾͼ�Ķ�����,����
	int kind;//ͼ������ͱ�־
}ALGraph;

typedef struct QNode{
	QElemType data;//����Ԫ��data��
	struct QNode *next;//ָ����
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front1, rear;//����ǰ������ָ��
}LinkQueue;

status CreateGraph(ALGraph *G);
status DestroyGraph(ALGraph *G);
status LocateVex(ALGraph G, VertexType u);
VertexType* GetVex(ALGraph G,int i);
status PutVex(ALGraph G, VertexType v, VertexType value);
status FirstAdjVex(ALGraph G, VertexType v);
status NextAdjVex(ALGraph G, VertexType v, VertexType w);
status InsertVex(ALGraph *G, VertexType v);
status DeleteVex(ALGraph *G, VertexType v);
status InsertArc(ALGraph *G,VertexType v,VertexType w);
status DeleteArc(ALGraph *G,VertexType v,VertexType w);
status BFSTraverse(ALGraph G,void(*visit)(char*));
status DFSTraverse(ALGraph G,void(*visit)(char*));
status Save(ALGraph G);
status Load(ALGraph *G);
void visit(char *i);

//����Ԫ�����Ͷ���
/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

/*-----page 19 on textbook ---------*/

int main(){
	int op=1, i, i_num=1, key;
    VertexType e,v,g,va,vb;//����ͼ�еĽڵ�
    ALGraph G[10];//ʮ��ͼ
    for (i = 0; i<=10; i++)
	{
    G[i].kind = 0;//�������ͼ������
	}
    while(op){
	system("cls");	//��������
	printf("\n\n");
	printf("\t\t      Menu for Undirected Graph On Chain Structure \n");
	printf("\t******************************************************************************\n");
	printf("\t\t\t1.  CreateGraph \t 2.  DestroyGraph\n");
	printf("\t\t\t3.  LocateVex   \t 4.  GetVex\n");
	printf("\t\t\t5.  PutVex      \t 6.  FirstAdjVex\n");
	printf("\t\t\t7.  NextAdjVex  \t 8.  InsertVex\n");
	printf("\t\t\t9.  DeleteVex   \t 10. InsertArc\n");
	printf("\t\t\t11. DeleteArc   \t 12. DFSTraverse\n");
	printf("\t\t\t13. BFSTraverse \t 14. Save\n");
	printf("\t\t\t15. Load	      \t 16. Choose\n");
	printf("\t\t\t0.  Exit        \t Powered By @_@||������\n");
	printf("\t******************************************************************************\n");
	printf("\t\t\t��ѡ����Ĳ���[0-16]: ");
	scanf("%d",&op);
    switch(op)
	{

	   case 1:
	    if(CreateGraph(&G[i_num])==OK)
		printf("\t\t\t��������ͼ�ɹ�!\n");
        else
		printf("\t\t\t��������ͼʧ��!\n");
		getchar();getchar();
		break;

	   case 2:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	    if(DestroyGraph(&G[i_num])==OK)
		printf("\t\t\t��������ͼ�ɹ�!\n");
        else
		printf("\t\t\t��������ͼʧ��!\n");
		getchar();getchar();
		break;

	   case 3:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���ҵĶ����ֵ��");
        scanf("%s",e);
        if(LocateVex(G[i_num],e)==INFEASTABLE)
		printf("\t\t\t����ͼ�в����ڸýڵ�!\n");
        else
		printf("\t\t\t�ö����keyΪ%d\n", LocateVex(G[i_num],e)+1);
		getchar();getchar();
		break;

	   case 4:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���ҵĶ����keyֵ��");
        scanf("%d",&key);
        if(key>G[i_num].vexnum || key<1)
        printf("\t\t\t����ͼ�в����ڸ�keyֵ�Ķ���!\n");
        else
        {
            printf("\t\t\t�������keyֵ��Ӧ�Ķ���Ϊ��%s\n",*GetVex(G[i_num],key-1));
        }

		getchar();getchar();
		break;

	   case 5:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t������Ҫ���ҵĶ���: ");
        scanf("%s",e);
        if(LocateVex(G[i_num],e)==INFEASTABLE)
		printf("\t\t\t�ö��㲻����!\n");
        else
        {
        printf("\t\t\t������Ҫ���õ��޸�Ϊ��ֵ: ");
        scanf("%s",g);
        i = LocateVex(G[i_num], e);
		strcpy(G[i_num].vertices[i].data,g);
		printf("\t\t\tkeyΪ%d�Ķ���ֵ���޸�Ϊ��%s\n",i+1,G[i_num].vertices[i].data);
		}
		getchar();getchar();
		break;

	   case 6:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t������Ҫ���ҵĶ����key��");
	    scanf("%d",&key);
        if(key>G[i_num].vexnum || key<1)
        printf("\t\t\t�����ڸ�key�Ķ���!\n");
	    //strcpy(e,*GetVex(G[i_num],key-1));
	    else{

            if(FirstAdjVex(G[i_num],*GetVex(G[i_num],key-1))==INFEASTABLE)
		printf("\t\t\t�ö���û���ڽӶ���!\n");
        else if(FirstAdjVex(G[i_num],*GetVex(G[i_num],key-1))==-2)
		printf("\t\t\t�ö��㲻����!");
        else
        {
		printf("\t\t\t�ö����׸��ڽӶ���Ϊ%s\n",G[i_num].vertices[FirstAdjVex(G[i_num],*GetVex(G[i_num],key-1))].data);
		printf("\t\t\t�ö����׸��ڽӶ����keyΪ%d\n", FirstAdjVex(G[i_num],*GetVex(G[i_num],key-1))+1);
		}
	    }
	    getchar();getchar();
		break;

	   case 7:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
        printf("\t\t\t������Ҫ���ҵĶ��� v ��key��");
	    scanf("%d",&key);

        if(key>G[i_num].vexnum || key<1)
        printf("\t\t\t�����ڸ�key %d�Ķ��㣡",key);

        else{
	           printf("\t\t\t�����������ԵĶ��� w ��key��");
	           scanf("%d",&i);

        if(i>G[i_num].vexnum || i<1)
               printf("\t\t\t�����ڸ�key %d�Ķ��㣡",i);
	        else{
                   if(NextAdjVex(G[i_num],*GetVex(G[i_num],key-1),*GetVex(G[i_num],i-1))==INFEASTABLE)
		              printf("\t\t\tw��v�����һ���ڽӶ���!\n");
                   else if(NextAdjVex(G[i_num],*GetVex(G[i_num],key-1),*GetVex(G[i_num],i-1))==-3)
		              printf("\t\t\tv����w���ڽӶ���!\n");
                   else
                      printf("\t\t\tv�����w����һ���ڽӶ���Ϊ %s\n",G[i_num].vertices[NextAdjVex(G[i_num],*GetVex(G[i_num],key-1),*GetVex(G[i_num],i-1))].data);
	        }

	        }
		getchar();getchar();
		break;

	   case 8:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	   	printf("\t\t\t������Ҫ��ӵĶ���: ");
        scanf("%s",v);
        if(LocateVex(G[i_num],v)!=INFEASTABLE)
        printf("\t\t\t�ö����Ѵ���,���ʧ��!\n");
        else
        {
        	if(InsertVex(&G[i_num],v)==OK)
		    printf("\t\t\t��Ӷ���ɹ�!\n");
            else
		    printf("\t\t\t��Ӷ���ʧ��!\n");
		}
		getchar();getchar();
		break;

	   case 9:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	   	printf("\t\t\t������Ҫɾ���Ķ���: ");
        scanf("%s",v);
        if(DeleteVex(&G[i_num],v)==ERROR)
		printf("\t\t\t��Ҫɾ���Ķ��㲻����!\n");
        else printf("\t\t\tɾ������ɹ�!\n");
		getchar();getchar();
		break;

	   case 10:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t������ߵ�β�ڵ��ͷ�ڵ��ֵ(�ո���Ϊ���,��a1 a2):");
		scanf("%s%s",va,vb);
		if(InsertArc(&G[i_num],va,vb)==ERROR)
		printf("\t\t\t���ʧ��!\n");
        else
		printf("\t\t\t��ӳɹ�!\n");
		getchar();getchar();
		break;

	   case 11:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	   	printf("\t\t\t������ߵ�β�ڵ��ͷ�ڵ��ֵ(�ո���Ϊ���,��a1 a2):");
		scanf("%s%s",va,vb);
		if(DeleteArc(&G[i_num],va,vb)==ERROR)
		printf("\t\t\tɾ��ʧ��!\n");
        else
		printf("\t\t\tɾ���ɹ�!\n");
		getchar();getchar();
		break;

	   case 12:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	   	printf("\t\t\t������ͼ�����������������Ϊ��");
	   	DFSTraverse(G[i_num],visit);
	   	printf("\n");
		getchar();getchar();
		break;

	   case 13:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	   	printf("\t\t\t������ͼ�Ĺ��������������Ϊ��");
	   	BFSTraverse(G[i_num],visit);
	   	printf("\n");
		getchar();getchar();
		break;

	   case 14:
	   	if(G[i_num].kind == 0)
	   	{
	   		printf("\t\t\t����ͼ������!\n");
	   		getchar();getchar();
	   		break;
		}
	    if(Save(G[i_num])==OK)
		printf("\t\t\t�ļ�����ɹ�!\n");
        else
		printf("\t\t\t�ļ�����ʧ��!\n");
		getchar();getchar();
		break;

	   case 15:
	    if(Load(&G[i_num])==OK)
		printf("\t\t\t���سɹ�!\n");
        else
		printf("\t\t\t����ʧ��!\n");
		getchar();getchar();
		break;

	   case 16:
	   	printf("\t\t������Ҫ�ڵڼ��������,ֻ֧����10��˳�����в���: ");
		scanf("%d",&i_num);
		if(i_num<1||i_num>20)
		{
		 	printf("\t\t\t��֧���ڸñ��Ͻ��в���!\n");
		 	i_num=1;
		}
		getchar(); getchar();
		break;


	   case 0:
        break;
	}//end of switch
  }//end of while
    printf("\n");
	printf("\t\t\t��ӭ�´�ʹ�ñ�ϵͳ!\n\n");
	printf("\t\t\tPowered By @_@||������\n");

}//end of main()
/*--------page 23 on textbook --------------------*/

/*************************
 * ��������: CreateGraph
 * ��ʼ������ͼG������
 * �������: ����ͼG
 *************************/
status CreateGraph(ALGraph *G)
{
	int i, j, k, m;
	VertexType va, vb;//ͼ�еĽڵ�
	ArcNode *p;//����ͼ�� �� ���͵�ָ��
	printf("\t\t\tͼ������Ϊ������ͼ\n");
	(*G).kind = 1;
	printf("\t\t\t������ͼ�Ķ�������");
	scanf("%d", &(*G).vexnum);//���û���Ҫ����ͼ�Ľڵ�����洢����
	printf("\t\t\t������ͼ�ı�����");
	scanf("%d", &(*G).arcnum);//���û���Ҫ���ɵ�ͼ�ı����洢����
	printf("\t\t\t������%d�������ֵ(<%d���ַ�,��v1): \n", (*G).vexnum, MAX_NAME);//MAX_NAME��������ÿ���ڵ��������ռ�ַ���С
	for(i=0; i<(*G).vexnum; i++)
	{
	    m = i;
	    m++;
		(*G).vertices[i].key = m;//����Ϊͼ�Ľڵ㸳��ؼ���
		printf("\t\t\t�ؼ���key:%d    ����ֵdata:", (*G).vertices[i].key);
		scanf("%s", (*G).vertices[i].data);//���û�����Ľڵ�洢���ڵ����͵�data��
	    (*G).vertices[i].firstarc = NULL;//��һ�������ö���ıߵ�ָ��ָ���
	}
	printf("\t\t\t������ÿ���ߵ�β��ͷ��ֵ\n\t\t\t(�ո���Ϊ���, ��v1 v2):\n");
	for(k=0; k<(*G).arcnum; k++)
	{
		printf("\t\t\t��%d:", k+1);
		scanf("%s%s",va,vb);//�ߵ������ڵ�
	    i = LocateVex(*G,va);
		j = LocateVex(*G,vb);//������������ڵ��λ�ã����ڼ����ڵ�
		p = (ArcNode*)malloc(sizeof(ArcNode));//����һ����
		p->adjvex = j;
		p->info = NULL;
		p->nextarc = (*G).vertices[i].firstarc;
		(*G).vertices[i].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = NULL;
		p->nextarc = (*G).vertices[j].firstarc;
		(*G).vertices[j].firstarc = p;
    }
	return OK;
}

/**************************
 * ��������: DestroyGraph
 * ��ʼ������ͼG�Ѵ���
 * �������: ����ͼG
 *
 *************************/
status DestroyGraph(ALGraph *G)
{
	int i;
	ArcNode *p, *q;//�����͵�ָ��p,q
	for(i = 0; i < (*G).vexnum; i++)
	{
        p=(*G).vertices[i].firstarc;//pָ���i���ڵ�� ��һ�������ڸýڵ��ָ��
	    while(p)//p��Ϊ��,�����ν�qָ����һ����,�ͷ�p,����ٽ�pָ��q����ʼ��һ��ѭ��
	    {
	    q = p->nextarc;
	    free(p);
	    p = q;
	    }
	}
	(*G).vexnum = 0;//֮��ͼ����Ϣ,������Ŀ,����Ŀ,kind��Ϊ0
	(*G).arcnum = 0;
	(*G).kind = 0;
	return OK;
}

/******************************************************************
 * ��������: LocateVex
 * ��ʼ������ͼG���ڣ�u��G�еĶ��������ͬ����
 * ��������: ��u��ͼG�д��ڣ����ض���u����Ϣ�����򷵻�������Ϣ
 *
 ******************************************************************/
status LocateVex(ALGraph G, VertexType u)
{
	int i;
	for(i=0; i<G.vexnum; i++)
	{
		if(!strcmp(u, G.vertices[i].data))//�жϽڵ������Ƿ���ͬ
		return i;//������ҳɹ�������i��ֵ
	}
	return -1;
}

/**************************************************************
 * ��������: GetVex
 * ��ʼ������ͼG���ڣ�v��G�е�ĳ������
 * ��������: ����v��ֵ
 *
 **************************************************************/
VertexType * GetVex(ALGraph G,int i)
{
   	if(i>=G.vexnum || i<0)
    printf("��Ӧkeyֵ������\n");//��Ϊ��������洢�ڵ㣬��˿����������
   	return &G.vertices[i].data;
}

/***************************************
 * ��������: PutVex
 * ��ʼ������ͼG���ڣ�v��G�е�ĳ������
 * ��������: ��v��ֵvalue
 **************************************/
status PutVex(ALGraph G, VertexType v, VertexType value)
{
	int i;
	i = LocateVex(G, v);
	strcpy(G.vertices[i].data, value);//������ڵ�����Ƹ�Ϊ��Ӧ������
	return 1;
}

/********************************************************************
 * ��������: FirstAdjVex
 * ��ʼ������ͼG���ڣ�v��G�е�ĳ������
 * ��������: ����v�ĵ�һ���ڽӶ��㣬���vû���ڽӶ��㣬����"��"
 ********************************************************************/
status FirstAdjVex(ALGraph G, VertexType v)
{
	ArcNode *p;
	status v1 = LocateVex(G, v);
	if(v1 == -1)  return -2;
	p = G.vertices[v1].firstarc;//����LocateVex����,���ݷ���ֵ����pָ���
	if(p)  return p->adjvex;
	else   return -1;

}

/***********************************************************************************
 * ��������: NextAdjVex
 * ��ʼ������ͼG���ڣ�v��G��һ������,w��v���ڽӶ���
 * ��������: ����v�ģ������w����һ���ڽӶ��㣬���w�����һ���ڽӶ��㣬����"��"
 ***********************************************************************************/
status NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
	ArcNode *p;
	int v1 = LocateVex(G, v);
	int w1 = LocateVex(G, w);
	if(v1 == -1 || w1 == -1)
	return -2;
	p = G.vertices[v1].firstarc;
	while (p && p->adjvex != w1)
	{
		p = p->nextarc;
	}
	if(!p) return -3;//���ݷ���ֵ���ж��Ƿ����ڽӵ�,�Ƿ������һ���ڽӵ�
	if(!p->nextarc) return -1;
	else return p->nextarc->adjvex;
}

/*************************************************
 * ��������: InsertVex
 * ��ʼ������ͼG���ڣ�v��G�еĶ��������ͬ����
 * ��������: ��ͼG�������¶���v
 *************************************************/
status InsertVex(ALGraph *G, VertexType v)
{
	if((*G).vexnum == MAX_VERTEX_NUM)
	return ERROR;
	strcpy(/***************************************************************************************************
 * ��������: DFSTraverse
 * ��ʼ������ͼG����
 * ��������: ������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
 ***************************************************************************************************/(*G).vertices[(*G).vexnum].data, v);
	(*G).vertices[(*G).vexnum].key = (*G).vexnum+1;
	(*G).vertices[(*G).vexnum].firstarc = NULL;
	(*G).vexnum++;
	return OK;
}

/***************************************************
 * ��������: DeleteVex
 * ��ʼ������ͼG���ڣ�v��G��һ������
 * ��������: ��ͼG��ɾ������v����v��صĻ�
 ***************************************************/
status DeleteVex(ALGraph *G, VertexType v)
{
	int i, j;
	ArcNode *p, *q;
	j = LocateVex(*G, v);
	if(j == -1)
	return ERROR;
	p = (*G).vertices[j].firstarc;
	while(p)
	{
	    q = p;
	    p = p->nextarc;
	    free(q);
	    (*G).arcnum--;
	}
	(*G).vexnum--;
	for(i=j; i<(*G).vexnum; i++)
	(*G).vertices[i] = (*G).vertices[i+1];
	for(i=0; i<(*G).vexnum; i++)
	{
		p = (*G).vertices[i].firstarc;
		while(p)
		{
			if(p->adjvex == j)
			{
				if(p == (*G).vertices[i].firstarc)
				{
					(*G).vertices[i].firstarc = p->nextarc;
					free(p);
					p = (*G).vertices[i].firstarc;
				}
				else
				{
					q->nextarc = p->nextarc;
					free(p);
					p = q->nextarc;
				}
			}
			else
			{
				if(p->adjvex > j)
				p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	return OK;
}

/********************************************************************
 * ��������: InsertArc
 * ��ʼ����:ͼG���ڣ�v��w��G�Ķ���
 * ��������: ��ͼG�����ӻ�<v,w>�����ͼG������ͼ������Ҫ����<w,v>
 ********************************************************************/
status InsertArc(ALGraph *G,VertexType v,VertexType w)
{
	ArcNode *p;
	int  i, j;
	i = LocateVex(*G, v);
	j = LocateVex(*G, w);
	if(i == -1 || j == -1)
	return ERROR;
	(*G).arcnum++;
	p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->info=NULL;
	p->nextarc = (*G).vertices[i].firstarc;
	(*G).vertices[i].firstarc = p;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = i;
	p->info = NULL;
	p->nextarc = (*G).vertices[j].firstarc;
	(*G).vertices[j].firstarc = p;
	return OK;
}

/*********************************************************************
 * ��������: DeleteArc
 * ��ʼ����:ͼG���ڣ�v��w��G�Ķ���
 * ��������: ��ͼG��ɾ����<v,w>�����ͼG������ͼ������Ҫɾ��<w,v>
 *********************************************************************/
status DeleteArc(ALGraph * G,VertexType v,VertexType w)
{
	ArcNode *p, *q;
	int i, j;
	i = LocateVex(*G, v);
	j = LocateVex(*G, w);
	if(i < 0 || j < 0)
	return ERROR;
	p = (*G).vertices[i].firstarc;
	while(p && p->adjvex != j)
	{
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == j)
	{
		if(p == (*G).vertices[i].firstarc)
		(*G).vertices[i].firstarc = p->nextarc;
		else
		q->nextarc = p->nextarc;
		free(p);
		(*G).arcnum--;
	}
	p = (*G).vertices[j].firstarc;
	while(p && p->adjvex != i)
	{
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == i)
	{
		if(p == (*G).vertices[j].firstarc)
		(*G).vertices[j].firstarc=p->nextarc;
		else
		q->nextarc=p->nextarc;
		free(p);
	}
	return OK;
 }

/*****************************
 * ��������: InitQueue
 * ��������: ����һ���ն���
 *****************************/
status InitQueue(LinkQueue *Q)
{
	(*Q).front1 = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front1)
	exit(OVERFLOW);
	(*Q).front1->next = NULL;
	return OK;
}

/***************************
 * ��������: DestroyQueue
 * ��������: �����ٶ���
 ***************************/
status DestroyQueue(LinkQueue *Q)
{
	while ((*Q).front1)
	{
	(*Q).rear = (*Q).front1->next;
	free((*Q).front1);
	(*Q).front1 = (*Q).rear;
	}
	return OK;
}

/********************************
 * ��������: ClearQueue
 * ��������: ��ն���
 * �� �� ֵ: status����.
 ********************************/
status ClearQueue(LinkQueue *Q)
{
	QueuePtr p, q;
	(*Q).rear = (*Q).front1;
	p = (*Q).front1->next;
	(*Q).front1->next = NULL;

	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

/******************************************************
 * ��������: QueueEmpty
 * ��������: ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE
 ******************************************************/
status QueueEmpty(LinkQueue Q)
{
	if (Q.front1 == Q.rear)//���ǰָ�����βָ��,���ʱ�Ѿ�Ϊ��
		return TRUE;
	else
		return FALSE;
}

/*****************************
 * ��������: QueueLength
 * ��������: ����еĳ���
 *****************************/
int QueueLength(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front1;
	int i = 0;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*****************************
 * ��������: EnQueue
 * ��������: ����Ԫ�ص�����
 *****************************/
status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;//�½ڵ��data��
	p->next = NULL;//�½ڵ��nextָ���
	(*Q).rear->next = p;//βָ�����һ���ڵ�����Ϊp��ָ���½ڵ�
	(*Q).rear = p;//��βָ��
	return OK;
}

/****************************************************************************
 * ��������: DeQueue
 * ��������: �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR
 ****************************************************************************/
status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if ((*Q).front1 == (*Q).rear)
		return ERROR;
	p = (*Q).front1->next;
	*e = p->data;
	(*Q).front1->next = p->next;//ɾ������Ԫ��
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front1;
	free(p);
	return OK;
}

/***************************************************
 * ��������: QueueTraverse
 * ��������: �Ӷ�ͷ����β���α�������Q��ÿ��Ԫ��
 ***************************************************/
status QueueTraverse(LinkQueue Q, void(*vi)(QElemType))
{
	QueuePtr p;
	p = Q.front1->next;
	while (p)
	{
		printf("&d ",p->data);//�������������Ԫ�ص�data
		p = p->next;
	}
	printf("\n");
	return OK;
}

/***********************************************************************************************
 * ��������: BFSTraverse
 * ��ʼ������ͼG����
 * ��������: ���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
 ***********************************************************************************************/
status BFSTraverse(ALGraph G,void(*visit)(char*))
{
	int i, j, w;
  	VertexType va, vb;
   	LinkQueue Q;
	for(i=0; i<G.vexnum; i++)
    visited[i]=FALSE;
   	InitQueue(&Q);
   	for(i=0; i<G.vexnum; i++)
    if(!visited[i])
	{
       	visited[i]=TRUE;//��ʾ�Ѿ����ʹ��ýڵ�
       	visit(G.vertices[i].data);//���ʸýڵ��data��
       	EnQueue(&Q,i);//���ö������͵����ʣ����й�����ȱ���
       	while(!QueueEmpty(Q))
		{
         	DeQueue(&Q,&j);
         	strcpy(va,*GetVex(G,j));
         	for(w=FirstAdjVex(G,va);w>=0;w=NextAdjVex(G,va,strcpy(vb,*GetVex(G,w))))
           	if(!visited[w])
			{
             	visited[w]=TRUE;
             	visit(G.vertices[w].data);
             	EnQueue(&Q,w);
           	}
       	}
    }
   	printf("\n");
   	return OK;
}

/*************************************************
 * ��������: DFS
 * ��ʼ������ͼG����
 * ��������: ��Ϊ���ʵĽڵ�������������������
 *************************************************/
void DFS(ALGraph G,int v)
{
	int i;
	VertexType va, vb;
	strcpy(va,*GetVex(G,v));
	visited[v]=TRUE;
	printf("%s ",G.vertices[v].data);
	for(i=FirstAdjVex(G,va); i>=0; i=NextAdjVex(G,va,strcpy(vb,*GetVex(G,i))))
    if(!visited[i])
    DFS(G,i);
}

/***************************************************************************************************
 * ��������: DFSTraverse
 * ��ʼ������ͼG����
 * ��������: ������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
 ***************************************************************************************************/
status DFSTraverse(ALGraph G,void(*visit)(char*))
{
	int i;
	for(i=0; i<G.vexnum; i++)
    visited[i] = FALSE;
   	for(i=0; i<G.vexnum; i++)
    if(!visited[i])
    DFS(G,i);/* ����δ���ʵĶ������DFS */
   	printf("\n");
   	return OK;
}

/****************************
 * ��������: visit
 * ��ʼ������ͼG����
 * ��������: ���ʽڵ�һ��
 ****************************/
void visit(char *i)
{
   	printf("%s ",i);
}

int OutDegree(VNode i)
{
	int num = 0;
	ArcNode * p;
	p = i.firstarc;
	while (p != NULL)
	{
		num++;
		p = p->nextarc;
	}
	return num;
}

/*****************************
 * ��������: Save
 * ��ʼ������ͼG����
 * ��������: ����ͼΪ�ļ�
 *****************************/
status Save(ALGraph G)
{
	int i, num;
	FILE  *fp;
	char filename[30];
	ArcNode *p;
	printf("\t\t\t������Ҫ������ļ���: ");
    scanf("%s",&filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t\t\t�����ļ�ʧ�ܣ�\n");
		return ERROR;
	}
	fwrite(&G.kind, sizeof(int), 1, fp);
	fwrite(&G.vexnum, sizeof(int), 1, fp);
	fwrite(&G.arcnum, sizeof(int), 1, fp);
	for (i = 0; i < G.vexnum; i++)
	{
		fwrite(G.vertices[i].data, sizeof(char), MAX_VERTEX_NUM, fp);
		num = OutDegree(G.vertices[i]);
		fwrite(&num, sizeof(int), 1, fp);
		if ((p = G.vertices[i].firstarc) != NULL)
		{
			fwrite(&p->adjvex, sizeof(int), 1, fp);
			while ((p = p->nextarc) != NULL)
			{
				fwrite(&(p->adjvex), sizeof(int), 1, fp);
			}
		}
	}
	fclose(fp);
	return OK;
}

/*****************************
 * ��������: Load
 * ��ʼ����:�ļ�����
 * ��������: ���ļ��м���ͼ
 *****************************/
status Load(ALGraph *G)
{
	int i, k = 0, num;
	FILE *fp;
	ArcNode *p;
	char filename[30];
	printf("\t\t\t������Ҫ���ص��ļ���: ");
	scanf("%s", &filename);
	if ((fp = fopen(filename,"r")) == NULL)
	{
		printf("\t\t\t�ļ�����ʧ�ܣ�\n");
		return ERROR;
	}
	fread(&G->kind, sizeof(int), 1, fp);
	fread(&G->vexnum, sizeof(int), 1, fp);
	fread(&G->arcnum, sizeof(int), 1, fp);
	while(fread(G->vertices[k].data, sizeof(char), MAX_VERTEX_NUM, fp))
	{
		fread(&num, sizeof(int), 1, fp);
		if (num == 0)
		G->vertices[k].firstarc = NULL;
		else
		{
			G->vertices[k].firstarc = NULL;
			for (i = 0; i < num; i++)
			{
				p = (ArcNode *)malloc(sizeof(ArcNode));
				fread(&(p->adjvex), sizeof(int), 1, fp);
				p->info = NULL;
				p->nextarc = (*G).vertices[k].firstarc;
				(*G).vertices[k].firstarc = p;
			}
		}
		k++;
	}
	fclose(fp);
	return OK;
}
