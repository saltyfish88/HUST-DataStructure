#ifndef LevelOrderTraverse_
#define LevelOrderTraverse_
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
//BFS
{
	int head=0,tail=0;
    BiTNode*que[100000];//待访问节点的队列。 
    que[0]=T;//根节点入队。 
    while(head<=tail)//队不为空 。 
    {
    	if(que[head]->lchild!=NULL)//左子节点入队。 
    	{
    		tail++;
    		que[tail]=que[head]->lchild;
		}
		if(que[head]->rchild!=NULL)//右子节点入队。 
    	{
    		tail++;
    		que[tail]=que[head]->rchild;
		}
		visit(que[head]);//访问。 
		head++;//出队。 
	}
}
#endif

