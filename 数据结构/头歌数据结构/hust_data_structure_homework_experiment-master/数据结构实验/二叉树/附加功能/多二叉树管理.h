status InitBiTrees(BiTrees &treelist)//初始化二叉树的管理表。 
{
	if(treelist.trees!=NULL){return INFEASIBLE;}//二叉树的管理表已存在。 
	treelist.len=0;//表长归零。 
	//treelist.listsize=MAX_SIZE;
	return OK;
}
status DestroyBiTrees(BiTrees &treelist)//销毁二叉树的管理表。
{
	int i=0;
	if(treelist.trees==NULL){return INFEASIBLE;}
	for(i=0;i<treelist.len;i++)
	{
		free(treelist.name[i]);//释放节点。 
		treelist.trees[i]=NULL;
	}
	treelist.len=0;//表长归零。 
	//treelist.listsize=0;
	return OK;
}
status AddBiTree(BiTrees &treelist,BiTNode*T,char name[])//增加新的二叉树 
{
	int len;
	if(treelist.trees==NULL){return INFEASIBLE;}//二叉树的管理表不存在。
	len=strlen(name);//名字的长度。 
	if(treelist.listsize==treelist.len){return OVERFLOW;}//二叉树的管理表已满。 
	treelist.trees[treelist.len]=T;//表尾插入。 
	treelist.name[treelist.len]=(char*)malloc(len*sizeof(char));
	strcpy(treelist.name[treelist.len],name);
	treelist.len++;
	return OK;
}
status DeleteBiTree(BiTrees &treelist,char name[])//删除二叉树。 
{
	int i=0,len=0;
	if(treelist.trees==NULL){return INFEASIBLE;}//二叉树的管理表不存在。
	for(i=0;i<treelist.len;i++){if(strcmp(name,treelist.name[i])==0){break;}}
	if(treelist.len==i){return ERROR;}//查找失败。 
	treelist.trees[i]=NULL;
	for(;i<treelist.len-1;i++)//移动节点。 
	{
		treelist.trees[i]=treelist.trees[1+i];
		free(treelist.name[i]);
		treelist.name[i]=(char*)malloc(strlen(treelist.name[1+i])*sizeof(char));
		strcpy(treelist.name[i],treelist.name[1+i]); 
	}
	free(treelist.name[treelist.len-1]);//删除节点。 
	treelist.trees[treelist.len-1]=NULL;
	treelist.len--;
	return OK;
}
BiTNode*SearchBiTree(BiTrees treelist,char name[])//搜索二叉树。 
{
	int i=0;
	BiTNode*ret=NULL;
	if(treelist.trees==NULL){return NULL;}//二叉树的管理表不存在。
	for(i=0;i<treelist.len;i++)
	{
		if(strcmp(name,treelist.name[i])==0)//查找成功。 
		{
			ret=treelist.trees[i];
			return ret;
		}
	}
	return NULL;
}
