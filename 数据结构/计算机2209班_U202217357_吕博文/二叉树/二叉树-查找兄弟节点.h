#ifndef GetSibling_
#define GetSibling_
BiTNode* GetSibling(BiTree T,KeyType e)
//ʵ�ֻ���ֵܽ��
{
    if(T->lchild==NULL&&T->rchild==NULL){return NULL;}//δ�ҵ�˫�ף����ء� 
    if(T->lchild!=NULL&&e==T->lchild->data.key){return T->rchild;}//�ҵ�˫�ף����ض�Ӧ�ֵܽڵ㡣 
    if(T->rchild!=NULL&&e==T->rchild->data.key){return T->lchild;}
    GetSibling(T->lchild,e);//���������м����� 
    GetSibling(T->rchild,e);//���������м����� 
}
#endif

