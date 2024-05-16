#ifndef BiTreeDepth_
#define BiTreeDepth_
int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
	int left=0,right=0;
    if(T==NULL){return 0;}
    left=1+BiTreeDepth(T->lchild);//计算左子树深度。 
    right=1+BiTreeDepth(T->rchild);//计算右子树深度。 
    return left<right?right:left;//返回最大值。 
}
#endif
