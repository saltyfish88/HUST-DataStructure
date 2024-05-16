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
typedef struct{  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;

FILE *fp;

/*-----page 19 on textbook ---------*/
status IntiaList(SqList &L);
status DestroyList(SqList &L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType *e);
status LocateElem(SqList L, ElemType e, status(*compare)(ElemType,ElemType));
status compare(ElemType a, ElemType b);
status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e);
status NextElem(SqList L,ElemType cur_e,ElemType *next_e);
status ListInsert(SqList &L,int i,ElemType e);
status ListDelete(SqList *L,int i,ElemType *e);
status ListTrabverse(SqList L);
status SaveList(SqList L, char *filename);
status LoadList(SqList *L, char *filename);
/*--------------------------------------------*/
int main(void){
    char filename[40];
    int op=1;
    int i;
    int i_num=1;
    SqList L[MAX_NUM];
    for(i=0;i<MAX_NUM;i++)
    {
        L[i].elem = NULL;
        L[i].listsize = 0;
        L[i].length = 0;
    }
    //�����forѭ������������û�д洢�ռ�����Ա�
    ElemType e, cur_e , pre_e, next_e;
  while(op){
        /**
        *������򵥵�printf���������׵Ĳ˵����ɹ�ѡ��
        *������۵Ĳ˵�������ƽ������ʱ������!!!
        */
	system("cls");	//��������
    printf("\n\n");
	printf("      \t\t\tMenu for Linear Table On Sequence Structure \n");
	printf("  ����%d��˳�����ж���������ʼ�����Ȳ�������15,Ĭ���ڵ�һ�����ϲ���\n", MAX_NUM);
	printf("  ------------------------------------------------------------------------------\n");
	printf("**\t\t\t1. IntiaList       7.  LocateElem\t\t\t**\n");
	printf("**\t\t\t2. DestroyList     8.  PriorElem\t\t\t**\n");
	printf("**\t\t\t3. ClearList       9.  NextElem \t\t\t**\n");
	printf("**\t\t\t4. ListEmpty       10. ListInsert\t\t\t**\n");
	printf("**\t\t\t5. ListLength      11. ListDelete\t\t\t**\n");
	printf("**\t\t\t6. GetElem         12. ListTrabverse\t\t\t**\n");
	printf("**\t\t\t13.SaveList	    14. LoadList\t\t\t**\n");
	printf("**\t\t\t0. Exit         				   \n");
	printf("**\t\t\t15.ChooseList(���Ƚ��д�ѡ����ѡ�����ĸ����Ͻ��в���)\n");
	printf("  -------------------------------------lbw-----------------------------------\n");
	printf("��ѡ����Ĳ���[0--15]:\n");
	scanf("%d",&op);//ѡ��op��ֵ,����switch
    switch(op){
	   case 1:
         //��һ������ǳ�ʼ�����Ա�
		 if(IntiaList(L[i_num])==OK)
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
		 if(L[i_num].elem == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 if(DestroyList(L[i_num])==OK)
         {
             printf("�������Ա�ɹ�!\n");
         }
         else printf("�������Ա�ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 3:
		 //�����������Ա�
		 if(L[i_num].elem == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(ClearList(L[i_num])==OK)
         {
            printf("���Ա����óɹ���\n");
         }
         else printf("���Ա�����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 4:
		 //�ж��Ƿ�Ϊ��
		 if(L[i_num].elem == NULL)
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
	       if(L[i_num].elem == NULL)
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
	       if(L[i_num].elem == NULL)
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
	       //ȷ��Ԫ��λ�ã����׳���
	       if(L[i_num].elem == NULL)
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
	       if(L[i_num].elem == NULL)
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
	       if(L[i_num].elem == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         printf("����������Ԫ�أ�\n");
		 scanf("%d",&cur_e);
		 if(NextElem(L[i_num],cur_e,&next_e)==OK)
		 printf("����Ԫ��Ϊ��%d\n",next_e);
		 else if(NextElem(L[i_num],cur_e,&pre_e)==FALSE)
		 printf("�䲻���ں��Ԫ�أ�\n");
		 else
            {printf("˳�����û�и�Ԫ�أ�\n");}
		 getchar();getchar();
		 break;

	   case 10:
	       //����Ԫ��
	       if(L[i_num].elem == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("��������Ҫ���������Ԫ�أ�\n");
		 scanf("%d",&e);
		 printf("��������Ҫ���������Ԫ�ص�λ�ã�\n");
		 scanf("%d",&i);
		 if(ListInsert(L[i_num],i,e)==OK)
		 printf("��������Ԫ�سɹ���\n");
		 else
		 printf("��������Ԫ��ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 11:
	       //ɾ��Ԫ��
	       if(L[i_num].elem == NULL)
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
	       if(L[i_num].elem == NULL)
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
           if(L[i_num].elem == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(SaveList(L[i_num], filename)==OK)
		 	printf("�ļ�����ɹ�\n�ļ���Ϊ%s\n",filename);
         break;

       case 14:
        //�����ļ�����Ҫ������Ҫ���ص�����
         printf("������Ҫ���ص��ļ���:\n ");
		 scanf("%s", filename);
		 if(LoadList(&L[i_num], filename)==OK)
            {
                printf("�ļ����سɹ�\n");
		    }
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
         break;
    	case 16:
         //��Ϊk�����������
		 
		 getchar();getchar();
		 break;
	   case 0:
        //�˳��˵����˳���������
         break;
	}//end of switch
  }//end of while
  printf("��ӭ�´���ʹ�ñ�����ϵͳ!\n");
}//end of main()
/*--------page 23 on textbook --------------------*/
/***************************************************************
*�������ƣ�IntiaList
*�������ܣ�����һ���յ����Ա�
*ע�ͣ���ʼ���������Ա�L�������Ѵ��ڣ���������ǹ���һ���յ����Ա�
*����ֵ���ͣ�status����
****************************************************************/
status IntiaList(SqList &L){
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);//����ռ䲻�㣬����ʧ��
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
	return OK;
}


/***************************************************************
*�������ƣ�DestoryList
*�������ܣ��������Ա�
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ�����������������Ա�L
*����ֵ���ͣ�status����
****************************************************************/
status DestroyList(SqList &L)
{
	if(L.elem)
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}


/***************************************************************
*�������ƣ�ClearList
*�������ܣ�����˳���
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L����Ϊ�ձ�
*����ֵ���ͣ�status����
****************************************************************/
status ClearList(SqList &L)
{
    L.length=0;
    return OK;
}



/***************************************************************
*�������ƣ�ListEmpty
*�������ܣ��ж����Ա��Ƿ�Ϊ��
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ������������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
*����ֵ���ͣ�status����
****************************************************************/
status ListEmpty(SqList L)
{
    if(L.length==0)
    {
        return TRUE;
    }
    return FALSE;

}



/***************************************************************
*�������ƣ�ListLength
*�������ܣ������Ա�ı�
*ע�ͣ���ʼ���������Ա��Ѵ��ڣ���������Ƿ���L������Ԫ�صĸ�����
*����ֵ���ͣ�int����
****************************************************************/
int ListLength(SqList L)
{
    return L.length;
}


/***************************************************************
*�������ƣ�GetElem
*�������ܣ��õ�ĳһ��Ԫ�ص�ֵ
*ע�ͣ���ʼ���������Ա��Ѵ��ڣ�1��i��ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ
*����ֵ���ͣ�status����
****************************************************************/
status GetElem(SqList L,int i,ElemType *e)
{
   if(i<1||i>L.length)
   {
    return ERROR;
   }
   *e = L.elem[i-1];
   return OK;
}




/***************************************************************
*�������ƣ�LocateElem
*�������ܣ�����Ԫ��
*ע�ͣ���ʼ���������Ա��Ѵ��ڣ���������Ƿ���L�е�1����e�����ϵcompare����
       ��ϵ������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
*����ֵ���ͣ�status����
****************************************************************/
status LocateElem(SqList L,ElemType e,status(*compare)(ElemType,ElemType))
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(compare(L.elem[i],e))
            return ++i;
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
	return TRUE;
	else  return FALSE;
}




/***************************************************************
*�������ƣ�PriorElem
*�������ܣ���Ԫ�ص�ǰ��
*ע�ͣ���ʼ���������Ա�L�Ѵ��ڣ������������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ����
       ����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
*����ֵ���ͣ�status����
****************************************************************/
status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
{
  int i;
  for(i=0;i<L.length;i++)
  {
      if(L.elem[i]==cur_e && i==0)
      {
          return ERROR;
      }
      else if(L.elem[i]== cur_e)
      {
          *pre_e = L.elem[i-1];
          return OK;
      }
  }
  return OVERFLOW;
}





/***************************************************************
*�������ƣ�NextElem
*�������ܣ����̽ڵ�
*�����������ʼ���������Ա�L�Ѵ��ڣ������������cur_e��L������Ԫ�أ��Ҳ������һ����
           ����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
*����ֵ���ͣ�status����
****************************************************************/
status NextElem(SqList L,ElemType cur_e,ElemType *next_e)
{
    int i;
    for(i=0;i<(L.length-1);i++)
    {
        if(L.elem[i]==cur_e)
        {
            *next_e = L.elem[i+1];
            return OK;
        }

    }
    if(i==L.length-1 && (L.elem[i]!=cur_e)) return OVERFLOW;
    else return FALSE;
}



/***************************************************************
*�������ƣ�ListInsert
*�������ܣ�����Ԫ��
*ע�ͣ���ʼ���������Ա�L�Ѵ����ҷǿգ�1��i��ListLength(L)+1��
*      �����������L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e
*����ֵ���ͣ�status����
****************************************************************/
status ListInsert(SqList &L,int i,ElemType e)
{
    int *p,*q,*newbase;
    if(i<1||i>L.length+1)
    {
        printf("����λ�ò���ȷ!\n");
        return ERROR;
    }

    if(L.length>=L.listsize){
        newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    q = &(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1) = *p;
    *q=e;
    ++L.length;
	return OK;

}
//���ǿα�����Ĺ��ڲ����㷨��ʵ��





/***************************************************************
*�������ƣ�ListDelete
*�������ܣ�ɾ��Ԫ��
*ע�ͣ���ʼ���������Ա�L�Ѵ����ҷǿգ�1��i��ListLength(L)��
*      ���������ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��
*����ֵ���ͣ�status����
****************************************************************/
status ListDelete(SqList *L,int i,ElemType *e)
{
    if(i<1||i>L->length)
        return ERROR;//ɾ����λ������ȷ
	int j;
	*e=L->elem[i-1];
	for (j = i - 1; j<L->length; j++)
		L->elem[j] = L->elem[j + 1];
	L->length--;
	return OK;
}




/***************************************************************
*�������ƣ�ListTrabverse
*�������ܣ�����˳���
*ע�ͣ����˳����ֵ
*����ֵ���ͣ�status����
****************************************************************/
status ListTrabverse(SqList L){
   int i;
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}






/***************************************************************
*�������ƣ�SaveList
*�������ܣ��������Ա�
*ע�ͣ������Ա��棬�ο���¼B�����й���д��Ԫ�ظ����ͳ��ȵ�������ⲻ�����
*����ֵ���ͣ�
****************************************************************/
status SaveList(SqList L, char* filename)
{
	int i = 0;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("�ļ�����ʧ��\n");
		return ERROR;
	}
	fprintf(fp, "%d ", L.length);//�����ʱ��Ҳ��L�ĳ��ȱ��浽���ļ�
	fprintf(fp, "%d ", L.listsize);//��ÿ��Ԫ�صĴ�СҲ���浽���ļ���
	while (i < L.length)
		fprintf(fp, "%d ", L.elem[i++]);//����ѭ������Ԫ�����δ��ȥ
	fclose(fp);//�ر��ļ�
	return OK;
}







/***************************************************************
*�������ƣ�LoadList
*�������ܣ������ļ�
*ע�ͣ������ļ����Ա㹦�ܵĲ��ԣ��ļ���Ҫ��ȷ
*����ֵ���ͣ�status����
****************************************************************/
status LoadList(SqList *L, char *filename)
{
	int i = 0;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("�ļ�����ʧ��\n");
		return ERROR;
	} 
	fscanf(fp, "%d ", &L->length);
	fscanf(fp, "%d ", &L->listsize);
	L->elem = (ElemType *)malloc(L->listsize * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	while (i < L->length)
		fscanf(fp, "%d ", &L->elem[i++]);//����ѭ�������ζ����ļ��е�����
	fclose(fp);
	return OK;
}

