#ifndef PostOrderTraverse_
#define PostOrderTraverse_
status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    if(T==NULL){return OK;}
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    visit(T);
}
#endif

