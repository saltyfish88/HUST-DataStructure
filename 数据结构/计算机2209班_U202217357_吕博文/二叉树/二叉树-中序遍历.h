#ifndef InOrderTraverse_
#define InOrderTraverse_
status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//ÖÐÐò±éÀú¶þ²æÊ÷T
{
    if(T==NULL){return OK;}
    InOrderTraverse(T->lchild,visit);
    visit(T);
    InOrderTraverse(T->rchild,visit);
}
#endif

