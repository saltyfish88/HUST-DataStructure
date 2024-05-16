#ifndef MaxPathSum_
#define MaxPathSum_
status MaxPathSum(BiTree T)
{
	int lret=0,rret=0,ret=0;
	if(T==NULL){return 0;}
	ret=T->data.key;
	lret=MaxPathSum(T->lchild);//求左子树最大路径和。 
	rret=MaxPathSum(T->rchild);//求右子树最大路径和。
	ret+=rret<lret?lret:rret;//返回最大值。 
	return ret;
}
#endif
