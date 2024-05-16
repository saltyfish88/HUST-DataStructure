#ifndef save_
#define save_
void save(BiTree T,FILE*fp)//�ݹ鱣�档 
{
    if(T==NULL)//д���β�� 
    {
    	fprintf(fp,"0 null ");
    	return;
	}
	fprintf(fp,"%d %s ",T->data.key,T->data.others);//д�롣 
	save(T->lchild,fp);//�洢�������� 
	save(T->rchild,fp);//�洢�������� 
}
#endif
#ifndef SaveBiTree_
#define SaveBiTree_
status SaveBiTree(BiTree T, char FileName[])
//���������Ľ������д�뵽�ļ�FileName��
{
    FILE*fp=fopen(FileName,"w");//��ֻд�� 
    if(!fp){return ERROR;}//��ʧ�ܡ� 
    if(T==NULL)//д������� 
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
void load(BiTree &T,FILE*fp)//�ݹ���롣 
{
	TElemType m;
	if(fscanf(fp,"%d %s ",&m.key,&m.others)==EOF){return;}//��β�����ء� 
	if(m.key==0){return;}
	T=(BiTNode*)malloc(sizeof(BiTNode));//�½��ڵ㡣 
	T->lchild=NULL;
	T->rchild=NULL;
	T->data=m;
	load(T->lchild,fp);//������������ 
	load(T->rchild,fp);//������������ 
}
#endif
#ifndef LoadBiTree_
#define LoadBiTree_
status LoadBiTree(BiTree &T,  char FileName[])
//�����ļ�FileName�Ľ�����ݣ�����������
{
	FILE*fp=fopen(FileName,"r");//��ֻ���� 
	if(!fp){return ERROR;}//��ʧ�ܡ� 
	load(T,fp);
	fclose(fp);
	return OK;
}
#endif
//���µĳ������ڹ�ͷ�衣 
/*status SaveBiTree(BiTree T, char FileName[])
//���������Ľ������д�뵽�ļ�FileName��
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
//�����ļ�FileName�Ľ�����ݣ�����������
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

