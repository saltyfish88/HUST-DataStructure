#ifndef save_
#define save_
void save(BiTree T,FILE*fp)//递归保存。 
{
    if(T==NULL)//写入结尾。 
    {
    	fprintf(fp,"0 null ");
    	return;
	}
	fprintf(fp,"%d %s ",T->data.key,T->data.others);//写入。 
	save(T->lchild,fp);//存储左子树。 
	save(T->rchild,fp);//存储右子树。 
}
#endif
#ifndef SaveBiTree_
#define SaveBiTree_
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    FILE*fp=fopen(FileName,"w");//打开只写。 
    if(!fp){return ERROR;}//打开失败。 
    if(T==NULL)//写入空树。 
    {
    	fprintf(fp,"0 null ");
    	return OK;
	}
	save(T,fp);
    fclose(fp);
    return OK;
}
#endif
#ifndef load_
#define load_
void load(BiTree &T,FILE*fp)//递归读入。 
{
	TElemType m;
	if(fscanf(fp,"%d %s ",&m.key,&m.others)==EOF){return;}//结尾，返回。 
	if(m.key==0){return;}
	T=(BiTNode*)malloc(sizeof(BiTNode));//新建节点。 
	T->lchild=NULL;
	T->rchild=NULL;
	T->data=m;
	load(T->lchild,fp);//读入左子树。 
	load(T->rchild,fp);//读入右子树。 
}
#endif
#ifndef LoadBiTree_
#define LoadBiTree_
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
	FILE*fp=fopen(FileName,"r");//打开只读。 
	if(!fp){return ERROR;}//打开失败。 
	load(T,fp);
	fclose(fp);
	return OK;
}
#endif
//以下的程序用于过头歌。 
/*status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
	static int sign=0;
    //static FILE*fp=fopen(FileName,"w");
    //if(!fp){printf("ERROR");}
    if(sign==0)
	{
		fp=fopen(FileName,"w");
		sign=1;
	}
    if(T==NULL)
    {
    	fprintf(fp,"0 null ");
    	return OK;
	}
	fprintf(fp,"%d %s ",T->data.key,T->data.others);
	SaveBiTree(T->lchild,FileName);
	SaveBiTree(T->rchild,FileName);
    if(sign==T->data.key){fclose(fp);}
    return OK;
}
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
	static int sign=0;
	TElemType m;
	//static FILE*fp=fopen(FileName,"r");
	if(sign==0)
	{
	    fp=fopen(FileName,"r");
	    sign=1;
	}
	if(fscanf(fp,"%d %s ",&m.key,&m.others)==EOF)
	{
		//fclose(fp);
		return OK;
	}
	if(m.key==0){return OK;}
	T=(BiTNode*)malloc(sizeof(BiTNode));
	T->lchild=NULL;
	T->rchild=NULL;
	T->data=m;
	LoadBiTree(T->lchild,FileName);
	LoadBiTree(T->rchild,FileName);
}*/

