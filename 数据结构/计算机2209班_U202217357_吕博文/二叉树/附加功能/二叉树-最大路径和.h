#ifndef MaxPathSum_
#define MaxPathSum_
status MaxPathSum(BiTree T)
{
	int lret=0,rret=0,ret=0;
	if(T==NULL){return 0;}
	ret=T->data.key;
	lret=MaxPathSum(T->lchild);//�����������·���͡� 
	rret=MaxPathSum(T->rchild);//�����������·���͡�
	ret+=rret<lret?lret:rret;//�������ֵ�� 
	return ret;
}
#endif
