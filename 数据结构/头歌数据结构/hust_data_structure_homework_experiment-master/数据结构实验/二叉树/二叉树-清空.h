#ifndef ClearBiTree_
#define ClearBiTree_
status ClearBiTree(BiTree &T)
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
{
	if(T==NULL){return OK;}//������
    ClearBiTree(T->lchild);//������������� 
    ClearBiTree(T->rchild);//������������� 
    free(T);//�ͷſռ�
    T=NULL;
}
#endif

