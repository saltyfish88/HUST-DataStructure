#ifndef ClearBiTree_
#define ClearBiTree_
status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
	if(T==NULL){return OK;}//清除完成
    ClearBiTree(T->lchild);//继续清除左子树 
    ClearBiTree(T->rchild);//继续清除右子树 
    free(T);//释放空间
    T=NULL;
}
#endif

