#ifndef GetSibling_
#define GetSibling_
BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    if(T->lchild==NULL&&T->rchild==NULL){return NULL;}//未找到双亲，返回。 
    if(T->lchild!=NULL&&e==T->lchild->data.key){return T->rchild;}//找到双亲，返回对应兄弟节点。 
    if(T->rchild!=NULL&&e==T->rchild->data.key){return T->lchild;}
    GetSibling(T->lchild,e);//在左子树中继续。 
    GetSibling(T->rchild,e);//在右子树中继续。 
}
#endif

