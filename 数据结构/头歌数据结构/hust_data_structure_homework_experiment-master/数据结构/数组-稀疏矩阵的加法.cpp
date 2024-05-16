#include<stdio.h>
#define  MAXSIZE 10000
typedef int ElemType;
typedef struct  {
   int       i,j;//����Ԫ�С����±�
   ElemType    e;
 } Triple;        //��Ԫ�鶨��

typedef struct  {
   Triple  data[MAXSIZE+1];   //��Ԫ����±�1��ʼ���
   int  mu,nu,tu;         //���ھ���������������ͷ���Ԫ��ֵ
 } TSMatrix;              //��Ԫ��˳���Ķ���
TSMatrix ADD(TSMatrix A,TSMatrix B);
int main()
{
	TSMatrix A[3],B,C;
   int i,j;
   for(i=0;i<2;i++)
   {
   		scanf("%d%d%d",&A[i].mu,&A[i].nu,&A[i].tu);
   		for(j=1;j<=A[i].tu;j++)
   		 	scanf("%d%d%d",&A[i].data[j].i,&A[i].data[j].j,&A[i].data[j].e);
   }
   A[2]=ADD(A[0],A[1]);
   printf("%d %d %d\n",A[2].mu,A[2].nu,A[2].tu);
   for(i=1;i<=A[2].tu;i++)
   		printf("%d %d %d     ",A[2].data[i].i,A[2].data[i].j,A[2].data[i].e);
	return 1;
}
TSMatrix ADD(TSMatrix A,TSMatrix B)
//���ؾ���A��B��ӵĽ��
{
int i=0,j=0;
TSMatrix C;
C.tu=1;
C.mu=A.mu;
C.nu=A.nu;
int book[1+A.mu][1+A.nu];
for(i=0;i<=A.mu;i++){for(j=0;j<=A.nu;j++){book[i][j]=0;}}
for(i=1;i<=A.tu;i++){book[A.data[i].i][A.data[i].j]+=A.data[i].e;}
for(i=1;i<=B.tu;i++){book[B.data[i].i][B.data[i].j]+=B.data[i].e;}
for(i=1;i<=A.mu;i++)
{
	for(j=1;j<=A.nu;j++)
	{
		if(book[i][j]!=0)
		{
			C.data[C.tu].e=book[i][j];
			C.data[C.tu].i=i;
			C.data[C.tu].j=j;
			C.tu++;
		}
	}
}
C.tu--;
return C; 
}
