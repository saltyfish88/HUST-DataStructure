#include "../def.h"
#include "二叉树-最近公共祖先.h"

typedef struct {
    int pos;
    TElemType data;
} DEF;
status CreateBiTree(BiTree &T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	 p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	   else      p[j/2]->lchild=p[j];
       i++;
    }
    T=p[1];
    return OK;
}

int main()
{
DEF definition[100];
BiTree T;
TElemType c1,c2;
int i=0;
BiTNode*ans=NULL;
do {
	scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
} while (definition[i++].pos);
    CreateBiTree(T,definition);
	scanf("%d%s",&c1.key,c1.others);
	scanf("%d%s",&c2.key,c2.others);
	ans=LowestCommonAncestor(T,c1,c2);
	if (ans!=NULL){printf("%d %s",ans->data.key,ans->data.others);}
	else printf("最近公共祖先操作失败");
	return 1;
}
