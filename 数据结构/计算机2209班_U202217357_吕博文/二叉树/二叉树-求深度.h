#ifndef BiTreeDepth_
#define BiTreeDepth_
int BiTreeDepth(BiTree T)
//�������T�����
{
	int left=0,right=0;
    if(T==NULL){return 0;}
    left=1+BiTreeDepth(T->lchild);//������������ȡ� 
    right=1+BiTreeDepth(T->rchild);//������������ȡ� 
    return left<right?right:left;//�������ֵ�� 
}
#endif
