#ifndef PostOrderTraverse_
#define PostOrderTraverse_
status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//ºóÐò±éÀú¶þ²æÊ÷T
{
    if(T==NULL){return OK;}
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    visit(T);
}
#endif

