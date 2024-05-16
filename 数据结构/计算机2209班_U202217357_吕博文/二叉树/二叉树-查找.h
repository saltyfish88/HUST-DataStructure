#ifndef LocateNode_
#define LocateNode_
void sol(BiTree T,KeyType e,BiTNode* &p)//查找节点的递归函数
//查找结点
{
    if(T==NULL||e==T->data.key)
	{
		if(T!=NULL){p=T;}//找到了，进行赋值
		return;
	}
    sol(T->lchild,e,p);//在左子树中
    sol(T->rchild,e,p);//在右子树中 
}
BiTNode* LocateNode(BiTree T,KeyType e)//查找节点
{
	BiTNode*p=NULL;
	sol(T,e,p);
	return p;
}
#endif
