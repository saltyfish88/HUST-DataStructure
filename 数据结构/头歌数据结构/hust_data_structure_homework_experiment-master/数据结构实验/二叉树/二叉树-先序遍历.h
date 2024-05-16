#ifndef PreOrderTraverse_
#define PreOrderTraverse_
status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//ÏÈÐò±éÀú¶þ²æÊ÷T
{
	if(T==NULL){return OK;}
    visit(T);
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
}
#endif

