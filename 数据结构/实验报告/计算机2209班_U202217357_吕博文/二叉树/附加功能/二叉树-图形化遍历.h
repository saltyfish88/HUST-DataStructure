//#include"../������-�����.h"
/***********
          �����Ű����⣬ͼ�λ�����ֻ����ʾ�ڵ����Ƶĵ�һ���ַ���
		  ***********/ 
char map[MAX_SIZE][MAX_SIZE];
#ifndef isleaf_
#define isleaf_
int isleaf(BiTNode*T)//�ж��Ƿ�Ϊ�ջ�Ҷ�ӽڵ㡣 
{
	if(T==NULL||(T->rchild==NULL&&T->lchild==NULL)){return 1;}
	return 0;
}
#endif
#ifndef drawtree_
#define drawtree_
void drawtree(BiTree T,int n,int x,int y)
{
	int i=0,j=0,len=0;
	if(T==NULL){return;}
	map[y][x]=T->data.others[0];
	if(isleaf(T->rchild)&&isleaf(T->lchild))//���Ϊ2�������� 
	{
		if(T->lchild!=NULL)//������ڵ㡣 
		{
			map[1+y][x-1]='/';
			map[2+y][x-2]=T->lchild->data.others[0];
		}
		if(T->rchild!=NULL)//�����ҽڵ㡣 
		{
			map[1+y][1+x]='\\';
			map[2+y][2+x]=T->rchild->data.others[0];
		}
		return;
	}
	len=(1<<(n-2))+(1<<(n-3));
	if(T->rchild!=NULL){for(i=1+y,j=1+x;i<y+len;i++,j++){map[i][j]='\\';}}//�����Ҳ�ߡ� 
	if(T->lchild!=NULL){for(i=1+y,j=x-1;i<y+len;i++,j--){map[i][j]='/';}}//�������ߡ� 
	drawtree(T->lchild,n-1,x-len,len+y);//�������� 
	drawtree(T->rchild,n-1,x+len,len+y);//�������� 
}
#endif
#ifndef print_
#define print_
void print(int n,int x,int y)//��ӡ���� 
{
	int i=0,j=0;
	for(i=0;i<3*(1<<(n-2));i++)
	{
		for(j=0;j<3*(1<<(n-1))-1;j++)
		{
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
status UITraverse(BiTree T)
{
	int i=0,j=0,n=0;
	for(i=0;i<MAX_SIZE;i++){for(j=0;j<MAX_SIZE;j++){map[i][j]=' ';}}//��ʼ���� 
	if(isleaf(T)==1)
	{
		printf("���и��ڵ������������ƣ�\n"); 
		return INFEASIBLE;
	}//���и��ڵ������������ơ�
	n=BiTreeDepth(T);
	drawtree(T,n,3*(1<<(n-2))-1,0);
	print(n,3*(1<<(n-2))-1,0);
	return OK;
}
#endif
