void InOrderTraverseNoRecursion(BiTree T,void (*visit)(BiTree))
{
int top=-1;
BiTNode*stack[MAX_SIZE];//����ڵ��ջ�� 
do
{
	while(T!=NULL)
	{
		if(top==MAX_SIZE){exit(OVERFLOW);}//ջ����,�˳� 
		top++;//�ڵ��ջ�� 
		stack[top]=T;      
		T=T->lchild;//����������     
	}
if (top!=-1)//ջ�ǿա� 
{
	T=stack[top];
	top--;//��ջ�� 
	visit(T);  
	T=T->rchild;//����������
}
}while(!(T==NULL&&top==-1));
}

