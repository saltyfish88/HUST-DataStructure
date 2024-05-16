#ifndef getkeytable_
#define getkeytable_
void getkeytable(BiTree T,int keytable[])//构建哈希表存储关键字 
{
	if(T==NULL){return;}
	keytable[T->data.key]++;
	getkeytable(T->lchild,keytable);
	getkeytable(T->rchild,keytable);
}
#endif
#ifndef LocateNode_
#define LocateNode_
void sol(BiTree T,KeyType e,BiTNode* &p)//查找节点的递归函数
{
    if(T==NULL||e==T->data.key)
	{
		if(T!=NULL){p=T;}//赋值 
		return;
	}
    sol(T->lchild,e,p);//在左子树中继续
    sol(T->rchild,e,p);//在右子树中继续 
}
BiTNode* LocateNode(BiTree T,KeyType e)//查找节点 
{
	BiTNode*p=NULL;
	sol(T,e,p);
	return p;
}
#endif
#ifndef InsertNode_
#define InsertNode_
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)//插入结点。
{
    int keytable[100000]={0};//存储关键字。 
    getkeytable(T,keytable);
    BiTNode*p=LocateNode(T,e);//找到插入位置。 
    if(p==NULL||keytable[c.key]>0){return ERROR;}//未找到。 
    BiTNode*n=(BiTNode*)malloc(sizeof(BiTNode));//新建节点。 
    n->data=c;
    keytable[c.key]++;
    n->lchild=NULL;
    if(LR==1)//按规则插入。 
    {
    	n->rchild=p->rchild;
    	p->rchild=n;
	}
	else if(LR==0)
	{
		n->rchild=p->lchild;
		p->lchild=n;
	}
	else if(LR==-1)
	{
		n->rchild=T;
		T=n;
	}
	return OK;
}
#endif
