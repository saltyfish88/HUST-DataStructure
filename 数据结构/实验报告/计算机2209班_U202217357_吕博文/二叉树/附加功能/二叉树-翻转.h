#ifndef InvertTree_
#define InvertTree_
status InvertTree(BiTree &T)
{
	BiTNode*t=NULL;
	if(T==NULL){return OK;}
	t=T->rchild;//�����ڵ㡣 
	T->rchild=T->lchild;
	T->lchild=t;
	InvertTree(T->lchild);//��������������ͬ������ 
	InvertTree(T->rchild);//��������������ͬ������
}
#endif
