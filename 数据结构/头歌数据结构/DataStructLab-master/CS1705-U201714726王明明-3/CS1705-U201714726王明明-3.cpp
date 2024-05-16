/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stack>
#include <queue>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_NUM 10

typedef int status;
typedef char TElemType;
//����Ԫ�����Ͷ���
/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCRE MENT  10

/*-----page 19 on textbook ---------*/
typedef struct BiTNode{
	int key;//��key��Ϊ��ǣ����ڲ��ҽڵ�
	TElemType data;//char����������
	struct BiTNode *lchild, *rchild;//����������������ָ�����Һ���ָ��
}BiTNode, *BiTree;//BiTNode����ָ��BiTree

typedef struct {
	BiTree T;//�����������õ�ָ��T
	char name[20];//���ڱ�����������
}LElemType;

typedef struct {
	LElemType tree[20];//��������в���
	int length;
	int listsize;
}SqList;

status InitBiTree(BiTree *T);
status DestroyBiTree(BiTree *T);
status CreateBiTree(BiTree *T);
status ClearBiTree(BiTree T);
status BiTreeEmpty(BiTree T);
status BiTreeDepth(BiTree T);
char Root(BiTree T);
char Value(BiTree T, int e);
status Assign(BiTree T, int e, char ch);
BiTNode* Parent(BiTree T, int e);
BiTNode* LeftChild(BiTree T, int e);
BiTNode* RightChild(BiTree T, int e);
BiTNode* RightSibling(BiTree T, int e);
BiTNode* LeftSibling(BiTree T, int e);
BiTree Find(BiTree T, int key);
status InsertChild(BiTree T, BiTree p, int LR, BiTree c);
status DeleteChild(BiTree T, BiTree p, int LR);
status visit(char e);
status PreOrderTraverse(BiTree T, status (* visit)(char e));
status InOrderTraverse(BiTree T, status (* visit)(char e));
status PostOrderTraverse(BiTree T, status (* visit)(char e));
status LevelOrderTraverse(BiTree T, status (* visit)(char e));
status TreeDisplay(BiTree T,int depth,status (* visit)(char e));
status Save(BiTree T,FILE *fp);
status Load(BiTree *T,FILE *fp);

int main(){
	FILE *fp;
	char filename[30];
	SqList L;//�൱�������鹹�����������Ŀ��
	BiTree T1, T2;//������BiTree������BiTNodeָ��
	int op=1, key;//op����case,�����û�����;key��������ǽڵ�
    int i, num=1, LR;//numĬ��Ϊ1����Ĭ���ڵ�һ�������в�����LR������ʾ����
    char ch;//��������data���ֵ
    for(i=0;i<20;i++)
    {
        L.tree[i].T = NULL;//�൱�ڴ���20�����������͵�����ָ�룬ͬʱָ�գ���20������
    }

    while(op){
	system("cls");//ϵͳ��������������
	system("color F");
    printf("\n\n");
	printf("\t\t      Menu for Binary Tree On Binary Linked List \n");
	printf("\t*****************************************************************************\n");
	printf("\t\t\t1.  InitBiTree       \t  2.  DestroyBiTree\n");
	printf("\t\t\t3.  CreateBiTree     \t  4.  ClearBiTree\n");
	printf("\t\t\t5.  BiTreeEmpty      \t  6.  BiTreeDepth\n");
	printf("\t\t\t7.  Root             \t  8.  Value\n");
	printf("\t\t\t9.  Assign           \t  10. Parent\n");
	printf("\t\t\t11. LeftChild        \t  12. RightChild\n");
	printf("\t\t\t13. LeftSibling	   \t  14. RightSibling\n");
	printf("\t\t\t15. InsertChild	   \t  16. DeleteChild\n");
	printf("\t\t\t17. PreOrderTraverse      18. InOrderTraverse\n");
	printf("\t\t\t19. PostOrderTraverse     20. LevelOrderTraverse\n");
	printf("\t\t\t21. Choose(��������)      22. Save(�����ļ�)\n");
	printf("\t\t\t23. Load(�����ļ�)        0.  Exit\n");
	printf("\t\t\t24. TreeDisplay           Powered By @_@||������\n");
	printf("\t****************************************************************************\n");
	printf("\t\t\t��ѡ����Ĳ���[0~24]:");
	scanf("%d",&op);
    switch(op)
	{

	   case 1:
        system("color 3");
	    InitBiTree(&(L.tree[num-1].T));
	    printf("\t\t\t�����������ɹ���\n");
		getchar();getchar();
		break;

	   case 2:
        system("color 2");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    DestroyBiTree(&(L.tree[num-1].T));
	    printf("\t\t\t���������ٳɹ���\n");
		getchar();getchar();
		break;

	   case 3:
        system("color F");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	   	getchar();
	   	printf("\t\t\t����ǰ��ʽ������������#��ʾ�ս�㣡\n");
	    CreateBiTree(&L.tree[num-1].T);
	    printf("\t\t\t����������ɹ���\n");
		getchar();getchar();
		break;

	   case 4:
        system("color D");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    if(ClearBiTree(L.tree[num-1].T) == 1)
	    printf("\t\t\t������ճɹ���\n");
	    else
	    printf("\t\t\t���������ʧ�ܣ�\n");
		getchar();getchar();
		break;

	   case 5:
        system("color 8");
	   	if (L.tree[num-1].T==NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    if(BiTreeEmpty(L.tree[num-1].T) == OK)
	    printf("\t\t\t������Ϊ������\n");
	    else
	    printf("\t\t\t��������Ϊ������\n");
		getchar();getchar();
		break;

	   case 6:
        system("color A");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		if(BiTreeEmpty(L.tree[num-1].T) == OK)
	    printf("\t\t\t������Ϊ������\n");
	    else
	    printf("\t\t\t�����������Ϊ:%d\n", BiTreeDepth(L.tree[num-1].T));
		getchar();getchar();
		break;

	   case 7:
        system("color C");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t�������ĸ�Ϊ:%c\n", Root(L.tree[num-1].T));
		getchar();getchar();
		break;

	   case 8:
        system("color D");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���ҵ�key:");
		scanf("%d", &key);
		if (Value(L.tree[num-1].T, key) != ERROR)
        {
            printf("\t\t\t��key��dataΪ��%c\n", Value(L.tree[num-1].T, key));
            if (Parent(L.tree[num-1].T, key) != NULL)
            {
            printf("\t\t\t��key˫�׵�dataΪ��%c\n", Parent(L.tree[num-1].T, key)->data);
		    printf("\t\t\t��key˫�׵�keyΪ��%d\n", Parent(L.tree[num-1].T, key)->key);
            }
		   else{
                  printf("\t\t\t��key˫�ײ����ڣ�\n");
		       }

            if (LeftChild(L.tree[num-1].T, key) != NULL)
            {
            printf("\t\t\t��key���Ӷ�Ӧ��dataΪ��%c\n", LeftChild(L.tree[num-1].T, key)->data);
		    printf("\t\t\t��key���Ӷ�Ӧ��keyΪ��%d\n", LeftChild(L.tree[num-1].T, key)->key);
            }
		   else{
                  printf("\t\t\t��key���Ӳ����ڣ�\n");
               }

            if (RightChild(L.tree[num-1].T, key) != NULL)
               {
                 printf("\t\t\t��key�Һ��Ӷ�Ӧ��dataΪ��%c\n", RightChild(L.tree[num-1].T, key)->data);
                 printf("\t\t\t��key�Һ��Ӷ�Ӧ��keyΪ��%d\n",  RightChild(L.tree[num-1].T, key)->key);
               }
           else{
                 printf("\t\t\t��key�Һ��Ӳ����ڣ�\n");
           }

             if (LeftSibling(L.tree[num-1].T, key) != NULL)
              {
            printf("\t\t\t��key���ֵܶ�Ӧ��dataΪ��%c\n", LeftSibling(L.tree[num-1].T, key)->data);
            printf("\t\t\t��key���ֵܶ�Ӧ��keyΪ��%d\n", LeftSibling(L.tree[num-1].T, key)->key);
              }

		   else{
            printf("\t\t\t��key���ֵܲ����ڣ�\n");
		   }
		   if (RightSibling(L.tree[num-1].T, key) != NULL)
            {
            printf("\t\t\t��key���ֵܶ�Ӧ��dataΪ��%c\n", RightSibling(L.tree[num-1].T, key)->data);
            printf("\t\t\t��key���ֵܶ�Ӧ��keyΪ��%d\n", RightSibling(L.tree[num-1].T, key)->key);
            }

		else{
            printf("\t\t\t��key���ֵܲ����ڣ�\n");
		    }
        }

		else
		printf("\t\t\t�����key�����в����ڣ�\n");
		getchar();getchar();
		break;

	   case 9:
        system("color A");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���ҵ�key:");
		scanf("%d", &key);
		getchar();
		printf("\t\t\t��������Ҫ���¸�ֵ��data:");
		scanf("%c", &ch);
		if (Assign(L.tree[num-1].T, key, ch) != ERROR)
		printf("\t\t\t��key��Ӧ��data��Ϊ�ˣ�%c\n", ch);
		else
		printf("\t\t\t�����key�����ֲ����ڣ�\n");
		getchar();getchar();
		break;

	   case 10:
        system("color B");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���Ҹ�ĸ��key:");
		scanf("%d", &key);
		if (Parent(L.tree[num-1].T, key) != NULL)
           {
            printf("\t\t\t˫�׶�Ӧ��dataΪ��%c\n", Parent(L.tree[num-1].T, key)->data);
		    printf("\t\t\t˫�׶�Ӧ��keyΪ��%d\n", Parent(L.tree[num-1].T, key)->key);
           }

		else
		printf("\t\t\t˫�ײ����ڣ�\n");
		getchar();getchar();
		break;

	   case 11:
        system("color C");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ�������ӵ�key: ");
		scanf("%d", &key);
		if (LeftChild(L.tree[num-1].T, key) != NULL)
          {
            printf("\t\t\t���Ӷ�Ӧ��dataΪ��%c\n", LeftChild(L.tree[num-1].T, key)->data);
		    printf("\t\t\t���Ӷ�Ӧ��keyΪ��%d\n", LeftChild(L.tree[num-1].T, key)->key);
          }

		else
		printf("\t\t\t���Ӳ����ڣ�\n");
		getchar();getchar();
		break;

	   case 12:
        system("color D");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ�����Һ��ӵ�key: ");
		scanf("%d", &key);
		if (RightChild(L.tree[num-1].T, key) != NULL)
        {
            printf("\t\t\t�Һ��Ӷ�Ӧ��dataΪ��%c\n", RightChild(L.tree[num-1].T, key)->data);
            printf("\t\t\t�Һ��Ӷ�Ӧ��keyΪ��%d\n",  RightChild(L.tree[num-1].T, key)->key);
        }

		else
		printf("\t\t\t�Һ��Ӳ����ڣ�\n");
		getchar();getchar();
		break;

	   case 13:
        system("color E");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ�������ֵܵ�key: ");
		scanf("%d", &key);
		if (LeftSibling(L.tree[num-1].T, key) != NULL)
        {
            printf("\t\t\t���ֵܶ�Ӧ��dataΪ��%c\n", LeftSibling(L.tree[num-1].T, key)->data);
            printf("\t\t\t���ֵܶ�Ӧ��keyΪ��%d\n", LeftSibling(L.tree[num-1].T, key)->key);
        }

		else
		printf("\t\t\t���ֵܲ����ڣ�\n");
		getchar();getchar();
		break;

	   case 14:
        system("color F");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ�������ֵܵ�key: ");
		scanf("%d", &key);
		if (RightSibling(L.tree[num-1].T, key) != NULL)
        {
            printf("\t\t\t���ֵܶ�Ӧ��dataΪ��%c\n", RightSibling(L.tree[num-1].T, key)->data);
            printf("\t\t\t���ֵܶ�Ӧ��keyΪ��%d\n", RightSibling(L.tree[num-1].T, key)->key);
        }

		else
		printf("\t\t\t���ֵܲ����ڣ�\n");
		getchar();getchar();
		break;

	   case 15:
        system("color D");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t��������Ҫ����λ�õ�key: ");
		scanf("%d", &key);
		getchar();
		T1 = Find(L.tree[num-1].T, key);
		printf("\t\t\t����������Ҫ����ķ���,0��ʾ���,1��ʾ�ұ�: ");
		scanf("%d", &LR);
		getchar();
		CreateBiTree(&T2);
		if (InsertChild(L.tree[num-1].T, T1, LR, T2) == OK)
		{
		    printf("\t\t\t����ɹ�!\n");
			getchar(); getchar();
		}
		else
		{
		    printf("\t\t\t����ʧ��!\n");
			getchar(); getchar();
		}
		break;

	   case 16:
        system("color A");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t��������Ҫɾ��λ�õ�key: ");
		scanf("%d", &key);
		getchar();
		T1 = Find(L.tree[num-1].T, key);
		printf("\t\t\t����������Ҫɾ���ķ���,0��ʾ���,1��ʾ�ұ�: ");
		scanf("%d", &LR);
		getchar();
		if (DeleteChild(L.tree[num-1].T, T1, LR) == OK)
		{
		    printf("\t\t\tɾ���ɹ�!\n");
			getchar(); getchar();
		}
		else
		{
		    printf("\t\t\tɾ��ʧ��!\n");
			getchar(); getchar();
		}
		break;

	   case 17:
        system("color C");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t�ö�������ǰ�����Ϊ��\n");
	   	PreOrderTraverse(L.tree[num-1].T, visit);
		getchar();getchar();
		break;

	   case 18:
        system("color E");
	   	if (!L.tree[num-1].T)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t�ö��������������Ϊ��\n");
	   	InOrderTraverse(L.tree[num-1].T, visit);
		getchar();getchar();
		break;

	   case 19:
        system("color F");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t�ö������ĺ������Ϊ��\n");
	   	PostOrderTraverse(L.tree[num-1].T, visit);
		getchar();getchar();
		break;

	   case 20:
        system("color D");
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
		printf("\t\t\t�ö������Ĳ������Ϊ��\n");
	   	LevelOrderTraverse(L.tree[num-1].T, visit);
		getchar();getchar();
		break;

	   case 21:
        system("color 2");
	   	printf("\t\t\t�ڵڼ���������?ֻ֧��20�������в���: \n");
		scanf("%d",&num);
		if(num<1||num>20)
		{
			printf("\t\t\t��ѡ����ȷ��Χ��\n");
			num=1;
		}
		getchar(); getchar();
		break;

	   case 22:
        system("color D");
	   	printf("\t\t\t������Ҫ������ļ���: ");
		scanf("%s", filename);
	    if((fp=fopen(filename,"w"))==NULL) printf("\t\t\t���ļ�ʧ�ܣ�\n");
       	else
		{
       		if(Save(L.tree[num-1].T,fp)==OK)
			   printf("\t\t\t�����ļ��ɹ���\n");
       		else printf("\t\t\t�����ļ�ʧ�ܣ�\n");
		}
		fclose(fp);
		getchar();getchar();
		break;

	   case 23:
        system("color B");
	   printf("\t\t\t������Ҫ���ص��ļ���: ");
       	scanf("%s",filename);
       	if((fp=fopen(filename,"r"))==NULL)
		   printf("\t\t\t����ʧ�ܣ�\n");
       	else
		{
       		if(Load(&L.tree[num-1].T,fp)==OK)
			printf("\t\t\t���سɹ���\n");
       		else printf("\t\t\t����ʧ�ܣ�\n");
		}
		fclose(fp);
		getchar();getchar();
		break;

		case 24:
		    system("color A");
            if (!L.tree[num-1].T)
	    	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		    }
            if(BiTreeEmpty(L.tree[num-1].T) == OK)
	           printf("\t\t\t������Ϊ������\n");
            else{
               printf("\t\t\t�ö�����Ϊ:\n");
               TreeDisplay((L.tree[num-1].T),1, visit);
                }
               getchar();getchar();
        break;

	   case 0:
        break;
	}//end of switch
  }//end of while
    printf("\n");
	printf("\t\t\t��ӭ�´���ʹ�ñ�ϵͳ��\n\n");
	system("color 9");
	printf("\t\t\tPowered By@_@||������\n\n");
	//system("pause");
}//end of main()

/*--------page 23 on textbook --------------------*/
/**
 * ��������: InitBiTree
 * ��ʼ������������T������
 * �������: �������������T
 *
 */
status InitBiTree(BiTree *T) {
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	(*T)->data='#';//��ʼ��������,������ָ��ָ���,data����Ϊ#
	return OK;
}

/**
 * ��������: DestroyBiTree
 * ��ʼ������������T�Ѵ���
 * �������: ���ٶ�����T
 *
 */
status DestroyBiTree(BiTree *T)
{
	if (*T) {
		if ((*T)->lchild)
			DestroyBiTree(&((*T)->lchild));
		if ((*T)->rchild)
			DestroyBiTree(&((*T)->rchild));
		free(*T);
		(*T) = NULL;//ʹ�õݹ������ͷ��������������������ڵ�ָ��
	}
	return OK;
}

/**
 * ��������: CreateBiTree
 * ��ʼ������������T�Ѵ���
 * �������: ����������
 *
 */
status CreateBiTree(BiTree *T)
{
	char ch;
	printf("\t\t\t������data: ");
	scanf("%c", &ch);
	getchar();
	if(ch == '#')
	{
		*T = NULL;
		return 0;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		printf("\t\t\t������key:");
		scanf("%d", &(*T)->key);
		getchar();
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));
	}
	return OK;
}
//ȡ���ڿα�,��������ڵ�ֵ������key��ǽڵ�

/**
 * ��������: ClearBiTree
 * ��ʼ������������T�ѳ�ʼ��
 * �������: ���������
 *
 */
status ClearBiTree(BiTree T)
{
	if(T)
	{
		T->lchild = NULL;
		T->rchild = NULL;
		T->data = '#';//��ն�����,��������ָ��ָ���,data������Ϊ#
	}
	return OK;
}

/**
 * ��������: BiTreeEmpty
 * ��ʼ������������T�Ѵ���
 * �������: ��TΪ�ն������򷵻�TRUE�����򷵻�FALSE
 *
 */
status BiTreeEmpty(BiTree T)
{
	if(T->data=='#')//�жϸ��ڵ��data��ֵ�Ƿ�Ϊ��
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/**
 * ��������: BiTreeDepth
 * ��ʼ������������T�Ѵ���
 * �������: ����T�����
 *
 */
status BiTreeDepth(BiTree T)
{
	int depth = 0;
	if(T)
	{
		int lchilddepth = BiTreeDepth(T->lchild);
		int rchilddepth = BiTreeDepth(T->rchild);
		depth = (lchilddepth>=rchilddepth?(lchilddepth+1):(rchilddepth+1));
	}//ʹ�õݹ�,�õ��������������,���Ƚϴ�С,֮�󷵻��������
	return depth;
}

/**
 * ��������: Root
 * ��ʼ������������T�Ѵ���
 * �������: ����T�ĸ�
 *
 */
char Root(BiTree T)
{
	return T->data;//T��data���ֵ�����ڵ�
}

/**
 * ��������: visit
 * �������: ��ӡ�ַ�e
 */
status visit(char e)
{
	printf("%c",e);//���ε��øú�����������ӡ
}

/**
 * ��������: Value
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ����e��ֵ
 *
 */
char Value(BiTree T, int e)
{
	if (!T) return ERROR;   //��������Ϊ��,����ERROR
	BiTNode *st[10], *p;
	int top = 0;  //�ÿ�ջ
	st[top++] = T;
	while (top)
	{
		p = st[--top]; //�������,����ջ��Ԫ��,�ж��Ƿ���key��ֵ��e���
		if (p->key == e)
        {
            return p->data;
        }

		else {
			if(p->rchild!=NULL)
				st[top++] = p->rchild;
			if(p->lchild!=NULL)
				st[top++] = p->lchild;
		}
	}
	return ERROR;
}

/**
 * ��������: Assign
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ���e��ֵΪvalue
 *
 */
status Assign(BiTree T, int e, char ch)
{
	if (!T) return ERROR;
    BiTNode *st[10], *p;
	int top = 0;
	st[top++] = T;
	while (top)
	{
		p = st[--top];
		if (p->key == e)
		{
			p->data =ch;//�ҵ�����и���,��Value��������
			return OK;
		}
		else
		{
			if (p->rchild != NULL)
				st[top++] = p->rchild;
			if (p->lchild != NULL)
				st[top++] = p->lchild;
		}
	}
	return ERROR;
}

/**
 * ��������: Parent
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ��e��T�ķǸ���㣬�򷵻�����˫�׽��ָ�룬���򷵻�NULL
 *
 */
BiTNode* Parent(BiTree T, int e)
{
	BiTree T1;//���ñ����͵ݹ�����Ѱ�������Һ��Ӷ�Ӧ��eֵ,���������㷵��ָ��
	if (T)
	{
		if ((T->lchild!=NULL&&T->lchild->key == e) ||(T->rchild!=NULL&& T->rchild->key == e)) return T;
		T1 = Parent(T->lchild, e);
		if (T1 != NULL) return T1;
		T1 = Parent(T->rchild, e);
		if (T1 != NULL) return T1;
	}
	return NULL;
}

/**
 * ��������: LeftChild
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ����e�����ӽ��ָ�롣��e�����ӣ��򷵻�NULL
 *
 */
BiTNode* LeftChild(BiTree T, int e)
{
	BiTree p;//���õݹ�������,˼·��
	if (T)
	{
		if (T->key == e) return T->lchild;
		p = LeftChild(T->lchild, e);
		if (p != NULL) return p;
		p = LeftChild(T->rchild, e);
		if (p != NULL) return p;
	}
	return NULL;
}

/**
 * ��������: RightChild
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ����e���Һ��ӽ��ָ�롣��e���Һ��ӣ��򷵻�NULL
 *
 */
BiTNode* RightChild(BiTree T, int e)
{
	BiTree p;//����һ��ͬ��
	if (T)
	{
		if (T->key == e) return T->rchild;
		p = RightChild(T->lchild, e);
		if (p != NULL) return p;
		p = RightChild(T->rchild, e);
		if (p != NULL) return p;
	}
	return NULL;
}

/**
 * ��������: LeftSibling
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ����e�����ֵܽ��ָ�롣��e��T�����ӻ��������ֵܣ��򷵻�NULL
 *
 */
BiTNode* LeftSibling(BiTree T, int e)
{
	BiTree p=NULL;
	if (T)
	{
		if (T->rchild!=NULL&&T->rchild->key == e)//����Һ��Ӳ�Ϊ�ղ��ҽڵ��ֵ����,��ô�㷵�����ӵ�ָ��
		return T->lchild;
		p = LeftSibling(T->lchild, e);
		if (p != NULL) return p;
		p = LeftSibling(T->rchild, e);
		if (p != NULL) return p;
	}
	return NULL;
}

/**
 * ��������: RightSibling
 * ��ʼ������������T�Ѵ���, e��T�е�ĳ�����
 * �������: ����e�����ֵܽ��ָ�롣��e��T�����ӻ��������ֵܣ��򷵻�NULL��e�����ֵܽ��ָ�롣��e��T���Һ��ӻ��������ֵܣ��򷵻�NULL
 *
 */
BiTNode* RightSibling(BiTree T, int e)
{
	BiTree p=NULL;
	if (T)
	{
		if (T->lchild!=NULL&&T->lchild->key == e)//����һ����������,������εݹ����������������
		return T->rchild;
		p = RightSibling(T->lchild, e);
		if (p != NULL) return p;
		p = RightSibling(T->rchild, e);
		if (p != NULL) return p;
	}
	return NULL;
}

BiTree Find(BiTree T, int key)
{
	BiTree T1;
	if (T == NULL) return NULL;
	if (T->key == key) return T;
	else
	{
		T1 = Find(T->lchild, key);
		if (T1 != NULL) return T1;
		T1 = Find(T->rchild, key);
		if (T1 != NULL) return T1;
	}
	return NULL;
}

/**
 * ��������: InsertChild
 * ��ʼ������������T���ڣ�pָ��T�е�ĳ����㣬LRΪ0��1
 * �������: ����LRΪ0����1������cΪT��p��ָ���������������p	��ָ����ԭ������������������Ϊc��������
 *
 */
status InsertChild(BiTree T, BiTree p, int LR, BiTree c)
{
	if (!T)
	{
		printf("\t\t\t�����������ڣ�");
		return ERROR;
	}
	if (c->rchild != NULL)
	{
		printf("\t\t\t���������������������Ϊ�գ�");
		return ERROR;
	}
	if (LR == 0)
	{
		c->rchild = p->lchild;//���뷽��Ϊ������
		p->lchild = c;
	}
	else
	{
		c->rchild = p->rchild;//���뷽��Ϊ�ҵ����
		p->rchild = c;
    }
		return OK;
}

/**
 * ��������: DeleteChild
 * ��ʼ������������T���ڣ�pָ��T�е�ĳ����㣬LRΪ0��1
 * �������: ����LRΪ0����1��ɾ��cΪT��p��ָ�������������
 *
 */
status DeleteChild(BiTree T, BiTree p, int LR)
{
	BiTree T1;
	if (T == NULL)
	{
		printf("\t\t\t�����������ڣ�\n");
		return ERROR;
	}
	if (LR == 0)//ɾ��������
	{
		T1 = p->lchild;
		p->lchild = NULL;
		if(!DestroyBiTree(&T1)) return ERROR;
	}
	else//ɾ��������
	{
		T1 = p->rchild;
		p->rchild = NULL;
		if (!DestroyBiTree(&T1)) return ERROR;
	}
	return OK;
}

/**
 * ��������: PreOrderTraverse
 * ��ʼ������������T�Ѵ���
 * �������: �������t����ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ��
 *
 */
status PreOrderTraverse(BiTree T, status (* visit)(char e))
{
	if(T)
	{
		if(visit(T->data))//������������õݹ鷽ʽ
		if(PreOrderTraverse(T->lchild, visit))
		if(PreOrderTraverse(T->rchild, visit))
		return 1;
		return 0;
	}
	else return 1;
}

/**
 * ��������: InOrderTraverse
 * ��ʼ������������T�Ѵ���
 * �������: �������t����ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ��
 *
 */
status InOrderTraverse(BiTree T, status (* visit)(char e))
{
	if(T)
	{
		if(InOrderTraverse(T->lchild, visit))
		if(visit(T->data))//������������õݹ鷽ʽ
		if(InOrderTraverse(T->rchild, visit))
		return 1;
		return 0;
	}
	else return 1;
}

/**
 * ��������: PostOrderTraverse
 * ��ʼ������������T�Ѵ���
 * �������: �������t����ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ��
 *
 */
status PostOrderTraverse(BiTree T, status (* visit)(char e))
{
	if(T)
	{
		if(PostOrderTraverse(T->lchild, visit))
		if(PostOrderTraverse(T->rchild, visit))
		if(visit(T->data))//������������õݹ鷽ʽ
		return 1;
		return 0;
	}
	else return 1;
}

void level(BiTree T, int i)
{
	if(T)
	{
		if(i == 1)
		visit(T->data);//�ú������������������
		else
		{
			level(T->lchild, i-1);
			level(T->rchild, i-1);
		}
	}
}

/**
 * ��������: LevelOrderTraverse
 * ��ʼ������������T�Ѵ���
 * �������: �������t����ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ��
 *
 */
status LevelOrderTraverse(BiTree T, status (* visit)(char e))
{
	if(T)
	{
		int h = BiTreeDepth(T);//���ú���,�õ����
		int i;
		for(i=1; i<=h; i++)
		{
			level(T, i);//��ÿһ����з���
		}
		return OK;
	}
	else
	return OK;
}

/**
 * ��������: Save
 * ��ʼ������������T�Ѵ���
 * �������: ���������Ϊ�ļ�
 *
 */
status Save(BiTree T,FILE *fp)
{
	int i = 0;
	char ch = '#';
	if(T)
	{
        fprintf(fp,"%d%c",T->key,T->data);//��key��data����д���ļ�
        if(Save(T->lchild,fp))
        if(Save(T->rchild,fp)) return OK;
        else return ERROR;
	}
	else
	{
	fprintf(fp,"%d%c",i,ch);//i��ch��ʼ����,��ζ�ſսڵ��keyΪ0,#����սڵ�.
	return OK;
	}
}

/**
 * ��������: Load
 * �������: ���ļ��ж�ȡ������
 *
 */
status Load(BiTree *T,FILE *fp)
{
	int i;//��i����ʾkey
	char ch;//��ch����ȡdata��
	if(feof(fp))
	{
		(*T)=NULL;
		return OK;
	}
	fscanf(fp,"%d",&i);
	fscanf(fp,"%c",&ch);
	if(ch=='#')
	{
		(*T)=NULL;
	}
	else
	{
		(*T)=(BiTree)malloc(sizeof(BiTNode));
		(*T)->key=i;
		(*T)->data=ch;
		Load(&((*T)->lchild),fp);
		Load(&((*T)->rchild),fp);
	}//�൱�����ζ�ȡ֮�󴴽�Ϊ������
	return OK;
}

status TreeDisplay(BiTree T,int depth,status (* visit)(char e))
{
    if(!T)
    {
        printf("\n");
        return OK;
    }
    int i=0;
    for(; i<depth; i++)
        printf(" ");
    visit(T->data);
    printf("\n");
    if(T->lchild||T->rchild)
    {
	TreeDisplay(T->lchild,depth+1,visit);
    TreeDisplay(T->rchild,depth+1,visit);
    }
    return OK;
}

