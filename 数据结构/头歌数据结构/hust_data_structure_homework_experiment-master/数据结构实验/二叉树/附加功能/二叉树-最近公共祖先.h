#ifndef LCA_
#define LCA_
BiTNode*LCA(BiTNode*T,TElemType e1,TElemType e2,int sign)//递归求解最近公共祖先。 
{
	static int visit1=0,visit2=0,pos=-1,ret=1<<30;
	static BiTNode*ans=T;
	if(sign==0)//初始化。 
	{
		visit1=0;
		visit2=0;
		pos=-1;
		ret=1<<30;
		ans=T;
	}
	pos++;//记录层。 
	if(T==NULL||visit1+visit2==2){return ans;}//都访问了，返回。 
	if(e1.key==T->data.key){visit1=1;}//访问了节点1。 
	if(e2.key==T->data.key){visit2=1;}//访问了节点2。
	LCA(T->lchild,e1,e2,1+sign);//计算左子树。 
	pos--;
	if(visit1+visit2==1)
	{
		if(ret>pos)
		{
			ret=pos;
			ans=T;
		}
	}
	LCA(T->rchild,e1,e2,2+sign);//计算右子树。
	pos--;
	return ans;
}
#endif
#ifndef LocateNode_
#define LocateNode_
BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    if(T==NULL||e==T->data.key){return T;}
    LocateNode(T->lchild,e);
    LocateNode(T->rchild,e);
}
#endif
#ifndef LowestCommonAncestor_
#define LowestCommonAncestor_
BiTNode*LowestCommonAncestor(BiTNode*T,TElemType e1,TElemType e2)
{
	if(LocateNode(T,e2.key)==NULL||LocateNode(T,e1.key)==NULL){return NULL;}
	return LCA(T,e1,e2,0);
}
#endif
/*BiTNode*LowestCommonAncestor(BiTNode*T,TElemType e1,TElemType e2)
{
	static int visit1=0,visit2=0,pos=-1,ret=1<<30;
	static BiTNode*ans=T;
	pos++;
	if(T==NULL||visit1+visit2==2){return ans;}
	if(e1.key==T->data.key){visit1=1;}
	if(e2.key==T->data.key){visit2=1;}
	LowestCommonAncestor(T->lchild,e1,e2);
	pos--;
	if(visit1+visit2==1)
	{
		if(ret>pos)
		{
			ret=pos;
			ans=T;
		}
	}
	LowestCommonAncestor(T->rchild,e1,e2);
	pos--;
	return ans;
}*/
