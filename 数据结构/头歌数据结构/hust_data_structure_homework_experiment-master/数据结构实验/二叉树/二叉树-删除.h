#ifndef Locatefather_
#define Locatefather_
BiTNode*Locatefather(BiTree T,KeyType e)//查找父结点
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
//删除结点。
{
	int sign=0;
    BiTNode*father=Locatefather(T,e);//查找父节点
    BiTNode*p=NULL;
    if(father==NULL)//父节点未找到 
	{
		if(e==T->data.key)//判断该节点是否为根节点
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
		else{return ERROR;}//未找到节点
	}
    if(e==father->rchild->data.key)//右子节点
	{
		sign=1;
		p=father->rchild;
	}
    else{p=father->lchild;}//左子节点 
    if(p->lchild==NULL&&p->rchild==NULL)//叶子节点 
	{
		free(p);
		if(sign==0){father->lchild=NULL;}
		else{father->rchild=NULL;}
	}
	else if(p->lchild==NULL)//情况一：左子节点为空
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
	else if(p->rchild==NULL)//情况二：右子节点为空
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
	else//情况三：都不为空
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
