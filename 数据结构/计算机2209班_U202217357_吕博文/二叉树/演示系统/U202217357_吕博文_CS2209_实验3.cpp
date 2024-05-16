/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <stdlib.h>

// ����ÿ���ڵ�Ĵ�ӡ���Ϊ 5
#define NODE_WIDTH 5

// ����ÿ���ڵ��ռλ��Ϊ _
#define NODE_PLACEHOLDER '_'

/*---------page 10 on textbook ---------*/
#define TRUE 1//������ֵ 
#define FALSE 0//���Ƽ�ֵ 
#define OK 1//������������ 
#define ERROR 0//�������г��� 
#define INFEASTABLE -1//�����������Ϸ� 
#define OVERFLOW -2//��ֵ��� 
#define MAX_NUM 10//������ 
#define LIST_INIT_SIZE 100//���ߴ� 
#define LISTINCRE MENT  10//��������� 

typedef int status;//��������״̬��ͷ���ֵ������Ϊint
typedef char TElemType;//����Ԫ�����Ͷ���
status definition[1000]={0}; //���岢��ʼ���ؼ��ֹ�ϣ�� 

// ����������Ľڵ�ṹ��
typedef struct BiTNode{
    int key;  // �� key ��Ϊ��ǣ����ڲ��ҽڵ�
    TElemType data;  // char ����������
    struct BiTNode *lchild, *rchild;  // ����������������ָ�����Һ���ָ��
} BiTNode, *BiTree;  // BiTNode ����ָ�� BiTree

// ����һ���ṹ�壬���ڱ������������������
typedef struct {
    BiTree T;  // �����������õ�ָ�� T
    char name[20];  // ���ڱ�����������
} LElemType;

// ����һ���ṹ�壬���ڱ����������в���
typedef struct {
    LElemType tree[20];  // ��������в���
    int length;
    int listsize;
} SqList;
/*---------��������--------*/
status InitBiTree(BiTree *T);  
// ��ʼ��������
status DestroyBiTree(BiTree *T);  
// ���ٶ�����
status CreateBiTree(BiTree *T); 
 // ����������
status ClearBiTree(BiTree T);  
// ��ն�����
status BiTreeEmpty(BiTree T); 
 // �ж϶������Ƿ�Ϊ��
status BiTreeDepth(BiTree T); 
 // ��������������
char Root(BiTree T); 
 // ��ȡ�������ĸ��ڵ�
char Value(BiTree T, int e);  
// ��ȡ��������ָ���ڵ��ֵ
status Assign(BiTree T, int e1,int e2, char ch);  
// ����������ָ���ڵ㸳ֵ
BiTNode* Parent(BiTree T, int e);  
// ��ȡ��������ָ���ڵ�ĸ��ڵ�
BiTNode* LeftChild(BiTree T, int e);  
// ��ȡ��������ָ���ڵ�����ӽڵ�
BiTNode* RightChild(BiTree T, int e);  
// ��ȡ��������ָ���ڵ���Һ��ӽڵ�
BiTNode* RightSibling(BiTree T, int e);  
// ��ȡ��������ָ���ڵ�����ֵܽڵ�
BiTNode* LeftSibling(BiTree T, int e);  
// ��ȡ��������ָ���ڵ�����ֵܽڵ�
BiTree Find(BiTree T, int key);  
// ���Ҷ�������ָ�� key ֵ�Ľڵ�
status InsertChild(BiTree T, BiTree p, int LR, BiTree c);  
// �ڶ�������ָ���ڵ����/�Ҳ��������
status DeleteChild(BiTree T, BiTree p, int LR);  
// ɾ����������ָ���ڵ����/������
status visit(char e);  
// ���ʶ������ڵ�
status PreOrderTraverse(BiTree T, status (* visit)(char e)); 
 // �������������
status InOrderTraverse(BiTree T, status (* visit)(char e));  
// �������������
status PostOrderTraverse(BiTree T, status (* visit)(char e));  
// �������������
status LevelOrderTraverse(BiTree T, status (* visit)(char e));  
// �������������
status TreeDisplay(BiTree T,int depth,status (* visit)(char e));  
// ��ӡ������
status Save(BiTree T,FILE *fp);  
// �����������浽�ļ���
status Load(BiTree *T,FILE *fp);  
// ���ļ��м��ض�����
BiTNode* LowestCommonAncestor(BiTree T, int e1, int e2);  
// ���Ҷ�������ָ���ڵ�������������
BiTNode* LocateNode(BiTree T, int e);  
// ���Ҷ�������ָ�� key ֵ�Ľڵ�
status InvertTree(BiTree &T);  
// ��ת������
status MaxPathSum(BiTree T);  
// ����������и��ڵ㵽Ҷ�ӽڵ�����·����
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
	printf("\t\t\t7.  Assign           \t  8. GetSibling\n");
	printf("\t\t\t9. InsertChild	   \t  10. DeleteChild\n");
	printf("\t\t\t11. PreOrderTraverse      12. InOrderTraverse\n");
	printf("\t\t\t13. PostOrderTraverse     14. LevelOrderTraverse\n");
	printf("\t\t\t15. Choose(��������)      16. Save(�����ļ�)\n");
	printf("\t\t\t17. Load(�����ļ�)        18.  LowestCommonAncestor\n");
	printf("\t\t\t19. TreeDisplay           20. InvertTree\n");
	printf("\t\t\t21. MaxPathSum       \t   22.LocateNode 0.  Exit\n");
	printf("\t****************************Powered By @_@||lbw***********************************\n");
	printf("\t\t\t��ѡ����Ĳ���[0~22]:");
	scanf("%d",&op);
    switch(op)
	{

	   case 1:
	    InitBiTree(&(L.tree[num-1].T));
	    printf("\t\t\t�����������ɹ���\n");
		getchar();getchar();
		break;

	   case 2:
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
        int newkey;
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���ҵ�key:");
		scanf("%d", &key);
		getchar();
		printf("\t\t\t��������Ҫ���¸�ֵ��data��key:���ÿո������");
		scanf("%c %d", &ch,&newkey);
		if (Assign(L.tree[num-1].T, key,newkey, ch) != ERROR){
			printf("\t\t\t��key��Ӧ��data��Ϊ�ˣ�%c\n", ch);
			printf("\t\t\t��key��Ӧ��key��Ϊ�ˣ�%d\n", newkey);
		}
		else
		printf("\t\t\t�����key�����ֲ����ڣ�\n");
		getchar();getchar();
		break;

	   case 8:
	   	if (L.tree[num-1].T == NULL)
	   	{
	   		printf("\t\t\t�����������ڣ�\n");
	   		getchar();getchar();
	   		break;
		}
	    printf("\t\t\t��������Ҫ���������ֵܵ�key: ");
		scanf("%d", &key);
		if (LeftSibling(L.tree[num-1].T, key) != NULL)
        {
            printf("\t\t\t���ֵܶ�Ӧ��dataΪ��%c\n", LeftSibling(L.tree[num-1].T, key)->data);
            printf("\t\t\t���ֵܶ�Ӧ��keyΪ��%d\n", LeftSibling(L.tree[num-1].T, key)->key);
        }
		else{printf("\t\t\t���ֵܲ����ڣ�\n");}
		
		if (RightSibling(L.tree[num-1].T, key) != NULL)
        {
            printf("\t\t\t���ֵܶ�Ӧ��dataΪ��%c\n", RightSibling(L.tree[num-1].T, key)->data);
            printf("\t\t\t���ֵܶ�Ӧ��keyΪ��%d\n", RightSibling(L.tree[num-1].T, key)->key);
        }
		else{printf("\t\t\t���ֵܲ����ڣ�\n");}
		getchar();getchar();
		break;

	   case 9:
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

	   case 10:
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

	   case 11:
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

	   case 12:
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

	   case 13:
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

	   case 14:
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

	   case 15:
	   	printf("\t\t\t�ڵڼ���������?ֻ֧��20�������в���: ");
		scanf("%d",&num);
		if(num<1||num>20)
		{
			printf("\t\t\t��ѡ����ȷ��Χ��\n");
			num=1;
		}
		printf("\t\t\t���ڵ�%d�����ϲ���",num);
		getchar(); getchar();
		break;

	   case 16: 
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

	   case 17:
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
		
		case 18:
			int e1,e2;
		    printf("\t\t\t��������Ҫ���ҹ������ȵ�����Ԫ�صĹؼ��֣�\n");
		    scanf("%d %d",&e1,&e2); 
		    if(LowestCommonAncestor(L.tree[num-1].T, e1,e2)==NULL ){
		    	printf("\t\t\t��������治���ڣ�\n");
		    	getchar();getchar();
        		break;
			}
			printf("\t\t\t�������������%d %c!\n",LowestCommonAncestor(L.tree[num-1].T, e1,e2)->key,LowestCommonAncestor(L.tree[num-1].T, e1,e2)->data);
            getchar();getchar();
        	break;

		case 19:
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
       		 
       		 
       	case 20:
		    if(InvertTree(L.tree[num-1].T)==ERROR){
		    	printf("\t\t\t������Ϊ������\n");
		    	getchar();getchar();
       		    break;
			}
			
			printf("\t\t\t�������ѷ�ת!\n");
			printf("\t\t\t��ת�������Ϊ:\n");
            TreeDisplay((L.tree[num-1].T),1, visit);
            getchar();getchar();
       		 break;
       	case 21:
		    if(MaxPathSum(L.tree[num-1].T)==INFEASTABLE){
		    	printf("\t\t\t������Ϊ������\n");
		    	getchar();getchar();
       		    break;
			}
			printf("\t\t\t���·����Ϊ%d��\n",MaxPathSum(L.tree[num-1].T));
            getchar();getchar();
       		break;
       	case 22:
    		printf("������Ҫ���ҽڵ�Ĺؼ���\n");
    		int e;
    		scanf("%d",&e);
    		if (LocateNode(L.tree[num-1].T,e)== NULL) {
       		 printf("δ�ҵ��ڵ㣡\n");
      	 	 getchar();getchar();
       		 break;
   			 }
    		printf("�ڵ��������%c��\n",LocateNode(L.tree[num-1].T,e)->data);
    		getchar();getchar();
   			 break;
	    case 0:
        break;
	}//end of switch
  }//end of while
    printf("\n");
	printf("\t\t\t��ӭ�´���ʹ�ñ�ϵͳ��\n\n");
	printf("\t\t\tPowered By@_@||lbw\n\n");
	//system("pause");
}//end of main()
/*--------page 23 on textbook --------------------*/
/**
 * ��������: InitBiTree
 * ��ʼ������������T������
 * �������: �������������T
 * ���������� BiTree *T
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
 *���������� BiTree *T
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
 *���������� BiTree *T
 */
status CreateBiTree(BiTree *T)
{	
	char ch;
	int key;
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
 *���������� BiTree *T
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
 *���������� BiTree *T
 */
status BiTreeEmpty(BiTree T)
{
	if(T->data=='#')//�жϸ��ڵ��data��ֵ�Ƿ�Ϊ��
	{
		return OK;
	}
	else
	{
		return ERROR;//�������� 
	}
}

/**
 * ��������: BiTreeDepth
 * ��ʼ������������T�Ѵ���
 * �������: ����T�����
 *���������� BiTree *T�����depth 
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
 *���������� BiTree *T
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
 *���������� BiTree *T���ؼ���e 
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
 *���������� BiTree *T���ؼ���e ������ch 
 */
status Assign(BiTree T, int e1, int e2,char ch)
{
	if (!T) return ERROR;
    BiTNode *st[10], *p;
	int top = 0;
	st[top++] = T;
	while (top)
	{
		p = st[--top];
		if (p->key == e1)
		{
			p->data =ch;
			p->key == e2;//�ҵ�����и���,��Value��������
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
 *���������� BiTree *T���ؼ���e 
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
 *���������� BiTree *T���ؼ���e 
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
 *���������� BiTree *T���ؼ���e 
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
 *���������� BiTree *T���ؼ���e 
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
 *���������� BiTree *T���ؼ���e 
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
 *���������� ָ��BiTree T, ָ��BiTree p, ���� LR, ָ��BiTree c
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
 *ָ��BiTree T, ָ��BiTree p, ����int LR
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
 *BiTree T, ����ָ��* visit)(char e)
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
 *BiTree T, ����ָ��* visit)(char e)
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
 *BiTree T, ����ָ��* visit)(char e)
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
 *BiTree T, ����ָ��* visit)(char e)
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
 *BiTree T,�ļ�ָ��FILE *fp
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
 *BiTree T,�ļ�ָ��FILE *fp
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

/**
�������ƣ�TreeDisplay
��ʼ������������T����
����������������νṹ��ӡ������
����������BiTree T,�ļ�ָ��FILE *fp�����depth 
*/
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
/**
�������ƣ�LowestCommonAncestor
��ʼ������������T���ڣ�e1��e2�Ƕ������е������ڵ�
������������Ҷ�������ָ���ڵ�������������
����������BiTree T,�ؼ���e1���ؼ���e2 
*/
BiTNode* LowestCommonAncestor(BiTree T, int e1, int e2) {
	if (T == NULL) {
        return NULL;
    }
    if (T->key == e1 || T->key == e2) {
        return T;
    }
    // ���������в���
    BiTNode* left = LowestCommonAncestor(T->lchild, e1, e2);
    // ���������в���
    BiTNode* right = LowestCommonAncestor(T->rchild, e1, e2);
    // ��� e1 �� e2 �ֱ������������У��� T �������������
    if (left != NULL && right != NULL) {
        return T;
    }
    // ���򷵻ز�Ϊ�յ�����
    return (left != NULL) ? left : right;
}

/**
�������ƣ�LocateNode
��ʼ������������T���ڣ�e�Ƕ������е�һ���ڵ��keyֵ
������������Ҷ�������ָ��keyֵ�Ľڵ�
����������BiTree T,�ؼ���e1
*/
BiTNode* LocateNode(BiTree T, int e) {
   if (T == NULL) {
        return NULL;
    }
    std::queue<BiTree> q;
    q.push(T);
    while (!q.empty()) {
        BiTree node = q.front();
        q.pop();
        if (node->key == e) {
            return node;
        }
        // �������������
        if (node->lchild != NULL) {
            q.push(node->lchild);
        }
        if (node->rchild != NULL) {
            q.push(node->rchild);
        }
    }
    // δ�ҵ�
    return NULL;
}
/**

�������ƣ�InvertTree
��ʼ������������T����
�����������ת������
����������&BiTree T
*/
status InvertTree(BiTree &T)
{
	if (T == NULL) {
        return OK;
    }
    // �ݹ齻����������
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    InvertTree(T->lchild);
    InvertTree(T->rchild);
    return OK;
}

/**
�������ƣ�MaxPathSum
��ʼ������������T����
�������������������и��ڵ㵽Ҷ�ӽڵ�����·����
����������BiTree T
*/
status MaxPathSum(BiTree T) {
    if (T == NULL) {
        return INFEASTABLE;
    }
    int left = MaxPathSum(T->lchild);
    int right = MaxPathSum(T->rchild);
    // ���������ǰ�ڵ�����·����
    int sum = T->key + ((left > 0) ? left : 0) + ((right > 0) ? right : 0);
    // ���ز�������ǰ�ڵ�����·����
    return (left > right) ? ((left > 0) ? left : 0) + T->key : ((right > 0) ? right : 0) + T->key;
}
