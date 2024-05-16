#ifndef Locatefather_
#define Locatefather_
BiTNode*Locatefather(BiTree T,KeyType e)//���Ҹ����
{
	if((T->lchild==NULL&&T->rchild==NULL)){return NULL;}
    if((T->lchild!=NULL&&e==T->lchild->data.key)||(T->rchild!=NULL&&e==T->rchild->data.key)){return T;}
    if(T->lchild!=NULL){Locatefather(T->lchild,e);}
    if(T->rchild!=NULL){Locatefather(T->rchild,e);}
}
#endif
#ifndef DeleteNode_
#define DeleteNode_
status DeleteNode(BiTree &T,KeyType e)
//ɾ����㡣
{
	int sign=0;
    BiTNode*father=Locatefather(T,e);//���Ҹ��ڵ�
    BiTNode*p=NULL;
    if(father==NULL)//���ڵ�δ�ҵ� 
	{
		if(e==T->data.key)//�жϸýڵ��Ƿ�Ϊ���ڵ�
		{
			p=T;
			if(T->lchild==NULL&&T->rchild==NULL)
			{
				free(T);
				T=NULL;
				return OK;
			}
			else if(T->lchild==NULL)
			{
				T=T->rchild;
				free(p);
				return OK;
			}
			else if(T->rchild==NULL)
			{
				T=T->lchild;
				free(p);
				return OK;
			}
			else
			{
				T=T->lchild;
				BiTNode*last=T;
				while(last->rchild!=NULL){last=last->rchild;}
				last->rchild=p->rchild;
				free(p);
				return OK;
			}
		}
		else{return ERROR;}//δ�ҵ��ڵ�
	}
    if(e==father->rchild->data.key)//���ӽڵ�
	{
		sign=1;
		p=father->rchild;
	}
    else{p=father->lchild;}//���ӽڵ� 
    if(p->lchild==NULL&&p->rchild==NULL)//Ҷ�ӽڵ� 
	{
		free(p);
		if(sign==0){father->lchild=NULL;}
		else{father->rchild=NULL;}
	}
	else if(p->lchild==NULL)//���һ�����ӽڵ�Ϊ��
	{
		if(sign==0)
		{
			father->lchild=p->rchild;
			free(p);
			p=NULL;
		}
		else
		{
			father->rchild=p->rchild;
			free(p);
			p=NULL;
		}
	}
	else if(p->rchild==NULL)//����������ӽڵ�Ϊ��
	{
		if(sign==0)
		{
			father->lchild=p->lchild;
			free(p);
			p=NULL;
		}
		else
		{
			father->rchild=p->lchild;
			free(p);
			p=NULL;
		}
	}
	else//�����������Ϊ��
	{
		if(sign==0)
		{
			father->lchild=p->lchild;
			BiTNode*last=p->lchild;
			while(last->rchild!=NULL){last=last->rchild;}
			last->rchild=p->rchild;
			free(p);
			p=NULL;
		}
		else
		{
			father->rchild=p->lchild;
			BiTNode*last=p->lchild;
			while(last->rchild!=NULL){last=last->rchild;}
			last->rchild=p->rchild;
			free(p);
			p=NULL;
		}
	}
	return OK;
}
#endif
