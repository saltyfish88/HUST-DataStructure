#ifndef LevelOrderTraverse_
#define LevelOrderTraverse_
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
//BFS
{
	int head=0,tail=0;
    BiTNode*que[100000];//�����ʽڵ�Ķ��С� 
    que[0]=T;//���ڵ���ӡ� 
    while(head<=tail)//�Ӳ�Ϊ�� �� 
    {
    	if(que[head]->lchild!=NULL)//���ӽڵ���ӡ� 
    	{
    		tail++;
    		que[tail]=que[head]->lchild;
		}
		if(que[head]->rchild!=NULL)//���ӽڵ���ӡ� 
    	{
    		tail++;
    		que[tail]=que[head]->rchild;
		}
		visit(que[head]);//���ʡ� 
		head++;//���ӡ� 
	}
}
#endif

