#ifndef isrepeat_
#define isrepeat_
status isrepeat(TElemType definition[])//�жϹؼ����Ƿ��ظ��� 
{
	int i=0;
	int key[100000]={0};//������ϣ���¼�ؼ��ֳ��ִ��� 
	while(definition[i].key!=-1)
	{
		if(definition[i].key==0)
		{	
			i++;
			continue;
	    }
		if(key[definition[i].key]>0){return ERROR;}//�ؼ����ظ������ش��� 
		key[definition[i++].key]++;
	}//����Ԫ�� 
	return OK;
}
#endif
#ifndef create_
#define create_
void create(BiTree &T,TElemType definition[],int sign)//�����ĵݹ麯���� 
/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
�������ͬ�Ĺؼ��֣�����ERROR��*/
{
	static int step=0;//������ڵĲ㡣 
	if(sign==0){step=0;}
	if(definition[step].key==-1||definition[step].key==0)//Ҷ�ӽڵ������� 
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
	T->data=definition[step];//�ڵ㸳ֵ�� 
	step++;
	create(T->lchild,definition,1+sign);//�������������� 
	create(T->rchild,definition,2+sign);//�������������� 
}
#endif
#ifndef CreateBiTree_
#define CreateBiTree_
status CreateBiTree(BiTree &T,TElemType definition[])
/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
	int sign=0;
	sign=isrepeat(definition);//���ؼ����Ƿ��ظ��� 
	if(sign==ERROR){return ERROR;}//�ؼ����ظ��� 
	create(T,definition,0);//������
	if(T==NULL){return ERROR;}
	return OK;
}
#endif
//ͷ��Դ���� 
//#ifndef CreateBiTree_
//#define CreateBiTree_
//status CreateBiTree(BiTree &T,TElemType definition[])
///*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
//�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
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

