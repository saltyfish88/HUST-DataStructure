#ifndef LocateNode_
#define LocateNode_
void sol(BiTree T,KeyType e,BiTNode* &p)//���ҽڵ�ĵݹ麯��
//���ҽ��
{
    if(T==NULL||e==T->data.key)
	{
		if(T!=NULL){p=T;}//�ҵ��ˣ����и�ֵ
		return;
	}
    sol(T->lchild,e,p);//����������
    sol(T->rchild,e,p);//���������� 
}
BiTNode* LocateNode(BiTree T,KeyType e)//���ҽڵ�
{
	BiTNode*p=NULL;
	sol(T,e,p);
	return p;
}
#endif
