#ifndef getkeytable_
#define getkeytable_
void getkeytable(BiTree T,int keytable[])//������ϣ��洢�ؼ��� 
{
	if(T==NULL){return;}
	keytable[T->data.key]++;
	getkeytable(T->lchild,keytable);
	getkeytable(T->rchild,keytable);
}
#endif
#ifndef LocateNode_
#define LocateNode_
void sol(BiTree T,KeyType e,BiTNode* &p)//���ҽڵ�ĵݹ麯��
{
    if(T==NULL||e==T->data.key)
	{
		if(T!=NULL){p=T;}//��ֵ 
		return;
	}
    sol(T->lchild,e,p);//���������м���
    sol(T->rchild,e,p);//���������м��� 
}
BiTNode* LocateNode(BiTree T,KeyType e)//���ҽڵ� 
{
	BiTNode*p=NULL;
	sol(T,e,p);
	return p;
}
#endif
#ifndef InsertNode_
#define InsertNode_
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)//�����㡣
{
    int keytable[100000]={0};//�洢�ؼ��֡� 
    getkeytable(T,keytable);
    BiTNode*p=LocateNode(T,e);//�ҵ�����λ�á� 
    if(p==NULL||keytable[c.key]>0){return ERROR;}//δ�ҵ��� 
    BiTNode*n=(BiTNode*)malloc(sizeof(BiTNode));//�½��ڵ㡣 
    n->data=c;
    keytable[c.key]++;
    n->lchild=NULL;
    if(LR==1)//��������롣 
    {
    	n->rchild=p->rchild;
    	p->rchild=n;
	}
	else if(LR==0)
	{
		n->rchild=p->lchild;
		p->lchild=n;
	}
	else if(LR==-1)
	{
		n->rchild=T;
		T=n;
	}
	return OK;
}
#endif
