#ifndef LocateNode_
#define LocateNode_
void getkeytable(BiTree T,int keytable[])//�ؼ��ֹ�ϣ�洢
{
	if(T==NULL){return;}
	keytable[T->data.key]++;
	getkeytable(T->lchild,keytable);
	getkeytable(T->rchild,keytable);
}
BiTNode* LocateNode(BiTree T,KeyType e)//���ҽ��
{
    if(T==NULL||e==T->data.key){return T;}
    LocateNode(T->lchild,e);
    LocateNode(T->rchild,e);
}
#endif
#ifndef Assign_
#define Assign_
status Assign(BiTree &T,KeyType e,TElemType value)
//ʵ�ֽ�㸳ֵ�� 
{
    int keytable[100000]={0};
    getkeytable(T,keytable);//�ؼ��ֹ�ϣ�洢 
    BiTNode*p=LocateNode(T,e);//���ҽڵ�
    if(p==NULL){return ERROR;}//δ�ҵ��ڵ� 
    keytable[e]--;
    if(keytable[value.key]>0){return ERROR;}//�ؼ����ظ�
    p->data=value;
    keytable[value.key]++;
    return OK;
}
#endif

