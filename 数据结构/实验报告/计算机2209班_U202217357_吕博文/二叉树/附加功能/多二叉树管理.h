status InitBiTrees(BiTrees &treelist)  // ��ʼ���������Ĺ���� 
{
    if (treelist.trees != NULL) {  // ���������Ѵ��ڣ��򷵻ش���
        return INFEASIBLE;
    }
    treelist.len = 0;  // �����㡣 
    return OK;
}

status DestroyBiTrees(BiTrees &treelist)  // ���ٶ������Ĺ����
{
    int i = 0;
    if (treelist.trees == NULL) {  // �����������ڣ��򷵻ش���
        return INFEASIBLE;
    }
    for (i = 0; i < treelist.len; i++) {  // �ͷ�ÿ���ڵ㣬��ָ�븳Ϊ NULL��
        free(treelist.name[i]);
        treelist.trees[i] = NULL;
    }
    treelist.len = 0;  // �����㡣 
    return OK;
}

status AddBiTree(BiTrees &treelist, BiTNode* T, char name[])  // �����µĶ�������
{
    int len;
    if (treelist.trees == NULL) {  // �����������ڣ��򷵻ش���
        return INFEASIBLE;
    }
    len = strlen(name);  // �������ֵĳ��ȡ� 
    if (treelist.listsize == treelist.len) {  // ���������������򷵻ش���
        return OVERFLOW;
    }
    treelist.trees[treelist.len] = T;  // �������������β�� 
    treelist.name[treelist.len] = (char*)malloc(len * sizeof(char));  // Ϊ�ڵ�������ռ䡣 
    strcpy(treelist.name[treelist.len], name);  // ���ڵ������Ƶ�������С� 
    treelist.len++;  // ����һ�� 
    return OK;
}
status DeleteBiTree(BiTrees &treelist,char name[])//ɾ���������� 
{
	int i=0,len=0;
	if(treelist.trees==NULL){return INFEASIBLE;}//�������Ĺ�������ڡ�
	for(i=0;i<treelist.len;i++){if(strcmp(name,treelist.name[i])==0){break;}}
	if(treelist.len==i){return ERROR;}//����ʧ�ܡ� 
	treelist.trees[i]=NULL;
	for(;i<treelist.len-1;i++)//�ƶ��ڵ㡣 
	{
		treelist.trees[i]=treelist.trees[1+i];
		free(treelist.name[i]);
		treelist.name[i]=(char*)malloc(strlen(treelist.name[1+i])*sizeof(char));
		strcpy(treelist.name[i],treelist.name[1+i]); 
	}
	free(treelist.name[treelist.len-1]);//ɾ���ڵ㡣 
	treelist.trees[treelist.len-1]=NULL;
	treelist.len--;
	return OK;
}
BiTNode*SearchBiTree(BiTrees treelist,char name[])//������������ 
{
	int i=0;
	BiTNode*ret=NULL;
	if(treelist.trees==NULL){return NULL;}//�������Ĺ�������ڡ�
	for(i=0;i<treelist.len;i++)
	{
		if(strcmp(name,treelist.name[i])==0)//���ҳɹ��� 
		{
			ret=treelist.trees[i];
			return ret;
		}
	}
	return NULL;
}
