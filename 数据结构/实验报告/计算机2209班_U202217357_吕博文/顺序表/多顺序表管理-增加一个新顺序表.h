#ifndef AddList1_
#define AddList1_
status AddList1(LISTS &Lists,char ListName[])//���ڹ�ͷ�衣 
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
    strcpy(Lists.elem[Lists.length].name,ListName);
    Lists.elem[Lists.length].L.elem = NULL;
    InitList(Lists.elem[Lists.length].L);
    Lists.length++;
}
#endif
#ifndef AddList_
#define AddList_
status AddList(LISTS &Lists,SqList L,char ListName[])//������ʾϵͳ�� 
{
	int i=0;
	if(Lists.length==Lists.listsize){return INFEASIBLE;}//���Ա����� 
	for(i=0;i<Lists.length;i++){if(strcmp(ListName,Lists.elem[i].name)==0){return ERROR;}}//�����ظ��� 
    strcpy(Lists.elem[Lists.length].name,ListName);//���������Ա� 
    Lists.elem[Lists.length].L.elem=NULL;
    Lists.elem[Lists.length].L.length=0;
    InitList(Lists.elem[Lists.length].L);
    Lists.elem[Lists.length].L.length=L.length;//���� 
    Lists.elem[Lists.length].L.listsize=L.listsize;
    for(i=0;i<L.length;i++){Lists.elem[Lists.length].L.elem[i]=L.elem[i];}
    Lists.length++;
    return OK;
}
#endif

