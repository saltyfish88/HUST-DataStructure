#ifndef LocateNode_
#define LocateNode_
void getkeytable(BiTree T,int keytable[])//关键字哈希存储
{
	if(T==NULL){return;}
	keytable[T->data.key]++;
	getkeytable(T->lchild,keytable);
	getkeytable(T->rchild,keytable);
}
BiTNode* LocateNode(BiTree T,KeyType e)//查找结点
{
    if(T==NULL||e==T->data.key){return T;}
    LocateNode(T->lchild,e);
    LocateNode(T->rchild,e);
}
#endif
#ifndef Assign_
#define Assign_
status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。 
{
    int keytable[100000]={0};
    getkeytable(T,keytable);//关键字哈希存储 
    BiTNode*p=LocateNode(T,e);//查找节点
    if(p==NULL){return ERROR;}//未找到节点 
    keytable[e]--;
    if(keytable[value.key]>0){return ERROR;}//关键字重复
    p->data=value;
    keytable[value.key]++;
    return OK;
}
#endif

