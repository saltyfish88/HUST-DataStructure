void InOrderTraverseNoRecursion(BiTree T,void (*visit)(BiTree))
{
int top=-1;
BiTNode*stack[MAX_SIZE];//保存节点的栈。 
do
{
	while(T!=NULL)
	{
		if(top==MAX_SIZE){exit(OVERFLOW);}//栈已满,退出 
		top++;//节点进栈。 
		stack[top]=T;      
		T=T->lchild;//遍历左子树     
	}
if (top!=-1)//栈非空。 
{
	T=stack[top];
	top--;//出栈。 
	visit(T);  
	T=T->rchild;//遍历右子树
}
}while(!(T==NULL&&top==-1));
}

