#ifndef isrepeat_
#define isrepeat_
status isrepeat(TElemType definition[])//判断关键字是否重复。 
{
	int i=0;
	int key[100000]={0};//构建哈希表记录关键字出现次数 
	while(definition[i].key!=-1)
	{
		if(definition[i].key==0)
		{	
			i++;
			continue;
	    }
		if(key[definition[i].key]>0){return ERROR;}//关键字重复。返回错误。 
		key[definition[i++].key]++;
	}//遍历元素 
	return OK;
}
#endif
#ifndef create_
#define create_
void create(BiTree &T,TElemType definition[],int sign)//创建的递归函数。 
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。*/
{
	static int step=0;//标记现在的层。 
	if(sign==0){step=0;}
	if(definition[step].key==-1||definition[step].key==0)//叶子节点或结束。 
	{
		step++;
		return;
	}
	if(T==NULL)
	{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->rchild=NULL;
		T->lchild=NULL;
	}
	T->data=definition[step];//节点赋值。 
	step++;
	create(T->lchild,definition,1+sign);//继续创建左子树 
	create(T->rchild,definition,2+sign);//继续创建右子树 
}
#endif
#ifndef CreateBiTree_
#define CreateBiTree_
status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
	int sign=0;
	sign=isrepeat(definition);//检查关键字是否重复。 
	if(sign==ERROR){return ERROR;}//关键字重复。 
	create(T,definition,0);//创建。
	if(T==NULL){return ERROR;}
	return OK;
}
#endif
//头歌源程序 
//#ifndef CreateBiTree_
//#define CreateBiTree_
//status CreateBiTree(BiTree &T,TElemType definition[])
///*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
//如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
//{
//	static int sign=ERROR;
//	static TElemType*trans=definition;
//	if(sign==ERROR)
//	{
//		sign=isrepeat(trans);
//		if(sign==ERROR){return ERROR;}
//	}
//	if(trans[0].key==-1||trans[0].key==0){return OK;}
//	if(T==NULL)
//	{
//		T=(BiTNode*)malloc(sizeof(BiTNode));
//		T->rchild=NULL;
//		T->lchild=NULL;
//	}
//	T->data=trans[0];
//	CreateBiTree(T->lchild,trans++);
//	CreateBiTree(T->rchild,trans++);
//}
//#endif

