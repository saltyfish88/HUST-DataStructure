/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_NUM 10

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

FILE *fp;

status InitList(LinkList *L);
status DestroyList(LinkList *L);
status ClearList(LinkList *L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType *e);
int LocateElem(LinkList L, ElemType e, status(*compare)(ElemType a, ElemType b));
status compare(ElemType a, ElemType b);
status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);
status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);
status ListInsert(LinkList *L, int i, ElemType e);
status ListDelete(LinkList *L, int i,ElemType *e);
status ListTrabverse(LinkList L);
status SaveList(LinkList L, char* filename);
status LoadList(LinkList *L, char *filename);

int main(){
	char filename[40];
	int op=1;
    int i,i_num=1;
    LinkList L[MAX_NUM];
    for (i = 0; i<MAX_NUM; i++)
	{
    L[i]=NULL;
	}
	ElemType e, cur_e, pre_e, next_e;
    while(op){
	system("cls");
    printf("\n\n");
    printf("      \t\t\tMenu for Linear Table On Sequence Structure \n");
	printf("  ����%d��˳�����ж���������ʼ�����Ȳ�������15,Ĭ���ڵ�һ�����ϲ���\n", MAX_NUM);
	printf("  ------------------------------------------------------------------------------\n");
	printf("**\t\t\t1. InitList       7.  LocateElem\t\t\t**\n");
	printf("**\t\t\t2. DestroyList     8.  PriorElem\t\t\t**\n");
	printf("**\t\t\t3. ClearList       9.  NextElem \t\t\t**\n");
	printf("**\t\t\t4. ListEmpty       10. ListInsert\t\t\t**\n");
	printf("**\t\t\t5. ListLength      11. ListDelete\t\t\t**\n");
	printf("**\t\t\t6. GetElem         12. ListTrabverse\t\t\t**\n");
	printf("**\t\t\t13.SaveList	    14. LoadList\t\t\t**\n");
	printf("**\t\t\t0. Exit            ����ʱ�䣺2018.11.13\t\t\t**\n");
	printf("**\t\t\t15.ChooseList(���Ƚ��д�ѡ����ѡ�����ĸ����Ͻ��в���)\n");
	printf("**\t\t\t��ʵ�������ļ�sss����ͨ������14���м���\n");
	printf("  -------------------------------------������-----------------------------------\n");
	printf("��ѡ����Ĳ���[0--15]:\n");
	scanf("%d",&op);
    switch(op)
	{
	   case 1:
         //��һ������ǳ�ʼ�����Ա�
		 if(InitList(&L[i_num])==OK)
         {

             printf("������Ҫ��������Ա�����\n");
             scanf("%s", filename);
             printf("���Ա����ɹ�\n");
         }
		     else printf("���Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 2:
		 //�ڶ�������������������Ա�
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 if(DestroyList(&L[i_num])==OK)
         {
             printf("�������Ա�ɹ�!\n");
         }
         else printf("�������Ա�ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 3:
		 //�����������Ա�
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(ClearList(&L[i_num])==OK)
         {
            printf("���Ա����óɹ���\n");
         }
         else printf("���Ա�����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 4:
		 //�ж��Ƿ�Ϊ��
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(ListEmpty(L[i_num])==TRUE)
         {
             printf("�ļ�Ϊ�գ�\n");
         }
         else printf("���Ա��ǿձ�\n");
		 getchar();getchar();
		 break;

	   case 5:
	       //�õ����Ա���
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         printf("���Ա��Ϊ%d\n",ListLength(L[i_num]));
		 getchar();getchar();
		 break;

	   case 6:
		 //�õ�ĳ��Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("������Ҫȡ����λ�ã�\n");
		 scanf("%d",&i);
		 if(GetElem(L[i_num],i,&e)==OK)
		 printf("��%d������Ԫ���ǣ�%d\n",i,e);
		 else  printf("����λ�ô���\n");
		 getchar();getchar();
		 break;

	   case 7:
		 //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("����������Ԫ��ֵ��\n");
		 scanf("%d",&e);
		 if(i=LocateElem(L[i_num],e,compare))
		 printf("%dԪ��λ�ڵ�%d��λ�ã�\n",e,i);
		 else  printf("��Ԫ�ز�����!\n");
		 getchar();getchar();
		 break;

	   case 8:
	       //���ǰ�����
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("����������Ԫ�أ�\n");
		 scanf("%d",&cur_e);
		 PriorElem(L[i_num],cur_e,&pre_e);
		 if(PriorElem(L[i_num],cur_e,&pre_e)==OK)
		 printf("��ǰ��Ԫ��Ϊ��%d\n",pre_e);
		 else if(PriorElem(L[i_num],cur_e,&pre_e)==OVERFLOW)
		 printf("˳�����û�и�Ԫ�أ�\n");
		 else  printf("�䲻����ǰ��Ԫ�أ�\n");
		 getchar();getchar();
		 break;


	   case 9:
	       //������ýڵ�
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         printf("����������Ԫ�أ�\n");
		 scanf("%d",&cur_e);
		 if(NextElem(L[i_num],cur_e,&next_e)==OK)
		 printf("����Ԫ��Ϊ��%d\n",next_e);
		 else if(NextElem(L[i_num],cur_e,&pre_e)==ERROR)
		 printf("˳�����û�и�Ԫ�أ�\n");
		 else
            {printf("�䲻���ں��Ԫ�أ�\n");}
		 getchar();getchar();
		 break;

	   case 10:
	       //����Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("��������Ҫ���������Ԫ�أ�\n");
		 scanf("%d",&e);
		 printf("��������Ҫ���������Ԫ�ص�λ�ã�\n");
		 scanf("%d",&i);
		 if(ListInsert(&L[i_num],i,e)==OK)
		 printf("��������Ԫ�سɹ���\n");
		 else
		 printf("��������Ԫ��ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 11:
	       //ɾ��Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("��������Ҫɾ��������Ԫ�ص�λ�ã�\n");
		 scanf("%d",&i);
		 if(ListDelete(&L[i_num],i,&e)==OK)
		 printf("ɾ������Ԫ�سɹ���\n");
		 else
		 printf("ɾ������Ԫ��ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 12:
	       //�������Ա��е�Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(!ListTrabverse(L[i_num])) printf("���Ա��ǿձ�\n");
		 getchar();getchar();
		 break;

	   case 13:
           //�����ļ�
           if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(SaveList(L[i_num], filename)==OK)
		 	printf("�ļ�����ɹ�!�ļ���Ϊ%s\n",filename);
		 	getchar();getchar();
         break;

	   case 14:
        //�����ļ�����Ҫ������Ҫ���ص�����
         InitList(&L[i_num]);
         printf("������Ҫ���ص��ļ���:\n ");
		 scanf("%s", filename);
		 if(LoadList(&L[i_num], filename)==OK)
            {
                printf("�ļ����سɹ�\n");
		    }
		    getchar();getchar();
         break;

	   case 15:
           //ѡ�����ĸ�����в���
           printf("������Ҫ�ڵڼ��������:\n ");
           printf("*ֻ֧����%d��˳����ϲ���*\n",MAX_NUM);
		   scanf("%d",&i_num);
		   printf("���ڶԵ�%d������в���\n",i_num);
		 if((i_num<1)||(i_num>10))
		 {
		 	printf("��ѡ����ȷ��Χ��\n");
		 	i_num=1;
		 }
		 getchar(); getchar();
         break;

	   case 0:
         break;
	}//end of switch
  }//end of while
	printf("\t\t��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
/*--------page 23 on textbook --------------------*/


/***************************************************************
*�������ƣ�IntiaList
*�������ܣ�����һ���յ����Ա�
*ע�ͣ���ʼ���������Ա�L�������Ѵ��ڣ���������ǹ���һ���յ����Ա�
*����ֵ���ͣ�status����
****************************************************************/
status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));//��̬����
	if(*L == NULL)
	{
		exit(OVERFLOW);//���û���㹻�Ŀռ䣬����ʧ��
	}
	(*L)->data = 0;
	(*L)->next = NULL;//�������б�ͷ�ڵ��������ͷ�ڵ��������ֵΪ0
	return OK;
}

/***************************************************************
*�������ƣ�DestoryList
*�������ܣ��������Ա�
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ�����������������Ա�L
*����ֵ���ͣ�status����
****************************************************************/
status DestroyList(LinkList *L)
{
	LinkList p, q;//ָ��p,q
	p = *L;//��ָ��pָ���ͷ�ڵ�
	while(p)
	{
		q = p->next;//���p��ָ��գ���qָ��p����һ���ڵ�
		free(p);//Ȼ���ͷ�p
		p = q;//�ٽ�q��ָ��Ľڵ㸳��p
	}
	*L = NULL;//���ָ��Lָ���
	return OK;
}

/***************************************************************
*�������ƣ�ClearList
*�������ܣ�����˳���
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L����Ϊ�ձ�
*����ֵ���ͣ�status����
****************************************************************/
status ClearList(LinkList *L)
{
	LinkList p, q;//��������ָ��p,q
	p = (*L)->next;//��pָ���һ���ڵ�
	while(p)
	{
		q = p->next;//��p��ָ���ʱ��qָ��p����һ���ڵ�
		free(p);//�ͷ�p
		p = q;//��qָ��Ľڵ㸳��p
	}
	(*L)->next = NULL;//��󣬽���ͷ�ڵ��ָ����ָ���
	return OK;
}

/***************************************************************
*�������ƣ�ListEmpty
*�������ܣ��ж����Ա��Ƿ�Ϊ��
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ������������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
*����ֵ���ͣ�status����
****************************************************************/
status ListEmpty(LinkList L)
{
	if(L->next)
	{
		return FALSE;
	}
	return TRUE;//�����ͷ�ڵ��ָ����ָ��գ���ô����TRUE
}

/***************************************************************
*�������ƣ�ListLength
*�������ܣ������Ա�ı�
*ע�ͣ���ʼ���������Ա��Ѵ��ڣ���������Ƿ���L������Ԫ�صĸ�����
*����ֵ���ͣ�int����
****************************************************************/
int ListLength(LinkList L)
{
	int i = 0;//i����ͳ�ƴ���������
	LinkList p = L->next;//�Ƚ�pָ���ͷ�ڵ�ĺ�һ���ڵ㣬����һ���ڵ�
	while(p)
	{
		i++;
		p = p->next;//���pָ��Ϊ�գ�i�Ĵ�����һ��pָ����һ���ڵ�
	}
	return i;//���ش���i������
}


/***************************************************************
*�������ƣ�GetElem
*�������ܣ��õ�ĳһ��Ԫ�ص�ֵ
*ע�ͣ���ʼ���������Ա��Ѵ��ڣ�1��i��ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ
*����ֵ���ͣ�status����
****************************************************************/
status GetElem(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList p;
	p = L->next;//pָ���ͷ�ڵ��ĵ�һ���ڵ�
	while(p && j < i)
	{
		p = p->next;//ѭ�������ҵ�iλ�ýڵ�
		++j;
	}
	if(!p || j>i)
	{
		return ERROR;//�����ж�����λ���Ƿ���ȷ���ձ��
	}
	*e = p->data;//��eȡ�ڵ��Ԫ��
	return OK;
}

/***************************************************************
*�������ƣ�LocateElem
*�������ܣ�����Ԫ��
*ע�ͣ���ʼ���������Ա��Ѵ��ڣ���������Ƿ���L�е�1����e�����ϵcompare����
       ��ϵ������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
*����ֵ���ͣ�status����
****************************************************************/
int LocateElem(LinkList L, ElemType e, status(*compare)(ElemType a, ElemType b))
{
	int i = 0;
	LinkList p = L->next;//pָ���һ���ڵ�
	while(p)
	{
		i++;
		if((*compare)(p->data, e))//ͨ���������Ƚϵõ���Ҫ�ҵ�Ԫ��
		return i;//��ʱ���ҵ���Ԫ������λ��
		p = p->next;//û���ҵ�ʱ��pָ����һ���ڵ㣬ѭ��
	}
	return 0;
}

/***************************************************************
*�������ƣ�compare
*�������ܣ��Ƚϴ�С��������LocateList����
*ע�ͣ���������ElemType���͵�ֵ
*����ֵ���ͣ�status����
****************************************************************/
status compare(ElemType a, ElemType b)
{
	if(a == b)
	return TRUE;//�Ƚ����������Ԫ�صĴ�С��һ������ΪTRUE
	else
	return FALSE;
}

/***************************************************************
*�������ƣ�PriorElem
*�������ܣ���Ԫ�ص�ǰ��
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ������������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ����
       ����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
*����ֵ���ͣ�status����
****************************************************************/
status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LinkList p = L->next;//pָ���һ���ڵ�
	if(p->data==cur_e) return ERROR;//�����һ���ڵ����Ҫ�ҵ�Ԫ�أ���û��ǰ��
	while(p->next != NULL && p->next->data != cur_e)
	{
		p = p->next;//ͨ��ѭ������pָ��ָ����Ҫ�ҵ�Ԫ�ص�ǰһ���ڵ�
	}
	if(p->next == NULL)//�����ʱpָ��ָ��գ�����ζ�ű���û�и�Ԫ��
	return OVERFLOW;

	*pre_e = p->data;//��pre_eȡ��pָ��Ľڵ��Ԫ�أ�������Ԫ�ص�ǰ��
	return OK;
}
/*status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LinkList p,q;
	p = L;
	q = L->next;
	if(q->data==cur_e) return ERROR;
	while(q!= NULL && q->data != cur_e)
	{
	    p = q;
		q = q->next;
	}
	if(q== NULL && p->data !=cur_e)
	return OVERFLOW;
	else if(q== NULL && p->data ==cur_e){
        return ERROR;
	}
	else {
        *pre_e = p->data;
        return OK;
	}
}*/
/***************************************************************
*�������ƣ�NextElem
*�������ܣ����̽ڵ�
*�����������ʼ���������Ա�L�Ѵ��ڣ������������cur_e��L������Ԫ�أ��Ҳ������һ����
           ����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
*����ֵ���ͣ�status����
****************************************************************/
status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	LinkList p = L->next;//pָ���һ���ڵ�
	while(p->next != NULL && p->data != cur_e)
	{
		p = p->next;//ѭ���ķ�ʽ�ҵ���Ҫ�ҵ�Ԫ�ص�ǰһ���ڵ�
	}
	if(p->next == NULL && p->data != cur_e)//��ʱpָ��ָ��գ�pָ��ڵ��ֵ���������Ԫ�أ���ôû�������Ԫ��
	return ERROR;
	if(p->next == NULL && p->data == cur_e)//��ʱpָ��ָ��գ�pָ��ڵ��ֵ�������Ԫ�أ���ôû�к�̽ڵ�
	return OVERFLOW;
	*next_e = p->next->data;//ʣ�������������next_eȡ��p��ָ��ڵ����һ���ڵ��ֵ
	return OK;
}

/***************************************************************
*�������ƣ�ListInsert
*�������ܣ�����Ԫ��
*ע�ͣ���ʼ���������Ա�L�Ѵ����ҷǿգ�1��i��ListLength(L)+1��
*      �����������L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e
*����ֵ���ͣ�status����
****************************************************************/
status ListInsert(LinkList *L, int i, ElemType e)
{
	int j = 1;
	LinkList p, q;//������ָ��ȷ������λ�õ�ǰ��ڵ�
	p = *L;//pָ���ͷ�ڵ㣨���ǵ���ͷ���룩
	while(p && j < i)
	{
		p = p->next;//��������λ��
		++j;
	}
	if(!p || j > i)
	{
		return ERROR;
	}
	q = (LinkList)malloc(sizeof(LNode));//������Ԫ�ط���ռ�
	if(q == NULL)
	{
		exit(OVERFLOW);//û����ɹ�
	}
	q->data = e;
	q->next = p->next;//�����д�����������Ԫ�ش��ȥ��ͬʱ��ָ��ָ��������
	p->next = q;
	return OK;
}

/***************************************************************
*�������ƣ�ListDelete
*�������ܣ�ɾ��Ԫ��
*ע�ͣ���ʼ���������Ա�L�Ѵ����ҷǿգ�1��i��ListLength(L)��
*      ���������ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��
*����ֵ���ͣ�status����
****************************************************************/
status ListDelete(LinkList *L, int i,ElemType *e)
{
	int j = 1;
	LinkList p ,q;
	p = *L;//pָ���ͷ�ڵ�
	while(p->next && j < i)
	{
		p = p->next;//�ҵ�ɾ��λ�ã�ͬʱp����һ���ڵ㲻Ϊ��
		++j;
	}
	if(!(p->next) || j>i)//��ʱ������pָ������ ���� j ��ֵ�ж�
	return ERROR;//��Ҫô�ǿձ�Ҫô��ɾ��λ�ò��ԡ����߾�����Ϊ��ɾ��λ�ò���

	q = p->next;
	p->next = q->next;//�����д�����ɾ���ڵ㣬����eȡ��ɾ���ڵ��ֵ
	*e = q->data;
	free(q);

	return OK;
}

/***************************************************************
*�������ƣ�ListTrabverse
*�������ܣ�����˳���
*ע�ͣ����˳����ֵ
*����ֵ���ͣ�status����
****************************************************************/
status ListTrabverse(LinkList L)
{
   LinkList p = L->next;
   if(!p)//��ʱΪ�ձ�
   return ERROR;
   printf("\n---------------------------- all elements -------------------------------------\n");
   while(p)
   {
   	printf("%d ",p->data);//ѭ�������ֵ
   	p = p->next;
   }
   printf("\n--------------------------------- end -----------------------------------------\n");
   return OK;
}

/***************************************************************
*�������ƣ�SaveList
*�������ܣ��������Ա�
*ע�ͣ������Ա��棬�ο���¼B�����й���д��Ԫ�ظ����ͳ��ȵ�������ⲻ�����
*����ֵ���ͣ�
****************************************************************/
status SaveList(LinkList L, char* filename)
{
	LinkList p = L->next;//ָ��ָ���һ���ڵ�
	int listsize=LIST_INIT_SIZE;//����
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t\t\t�ļ�����ʧ�ܣ�");//�ļ�����ʧ��
		return ERROR;
	}
	fprintf(fp, "%d ", ListLength(L));//��Ԫ�ظ���д��
	fprintf(fp, "%d ", listsize);//����󳤶�д��
	while(p)
    {
	fprintf(fp, "%d ", p->data);//ָ��op��ָ��գ�����д���ļ�
	p = p->next;
    }
	fclose(fp);
	return OK;
}

/***************************************************************
*�������ƣ�LoadList
*�������ܣ������ļ�
*ע�ͣ������ļ����Ա㹦�ܵĲ��ԣ��ļ���Ҫ��ȷ
*����ֵ���ͣ�status����
****************************************************************/
status LoadList(LinkList *L, char *filename)
{
	int i = 1,length = 0,listsize;
	ElemType e;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("�ļ�����ʧ��!");
		return ERROR;
	}
	fscanf(fp, "%d ", &length);
	fscanf(fp, "%d ", &listsize);
	fscanf(fp, "%d ", &e);
	while(i<=length)
    {
	ListInsert(L,i,e);
	fscanf(fp, "%d ", &e);
	i++;
    }
	fclose(fp);
	return OK;
}
