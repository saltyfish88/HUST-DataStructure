#ifndef InvertTree_
#define InvertTree_
status InvertTree(BiTree &T)
{
	BiTNode*t=NULL;
	if(T==NULL){return OK;}
	t=T->rchild;//交换节点。 
	T->rchild=T->lchild;
	T->lchild=t;
	InvertTree(T->lchild);//对左子树进行相同操作。 
	InvertTree(T->rchild);//对右子树进行相同操作。
}
#endif
