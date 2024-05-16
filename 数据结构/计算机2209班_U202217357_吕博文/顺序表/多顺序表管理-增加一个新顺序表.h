#ifndef AddList1_
#define AddList1_
status AddList1(LISTS &Lists,char ListName[])//用于过头歌。 
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    strcpy(Lists.elem[Lists.length].name,ListName);
    Lists.elem[Lists.length].L.elem = NULL;
    InitList(Lists.elem[Lists.length].L);
    Lists.length++;
}
#endif
#ifndef AddList_
#define AddList_
status AddList(LISTS &Lists,SqList L,char ListName[])//用于演示系统。 
{
	int i=0;
	if(Lists.length==Lists.listsize){return INFEASIBLE;}//线性表已满 
	for(i=0;i<Lists.length;i++){if(strcmp(ListName,Lists.elem[i].name)==0){return ERROR;}}//名字重复。 
    strcpy(Lists.elem[Lists.length].name,ListName);//创建新线性表 
    Lists.elem[Lists.length].L.elem=NULL;
    Lists.elem[Lists.length].L.length=0;
    InitList(Lists.elem[Lists.length].L);
    Lists.elem[Lists.length].L.length=L.length;//复制 
    Lists.elem[Lists.length].L.listsize=L.listsize;
    for(i=0;i<L.length;i++){Lists.elem[Lists.length].L.elem[i]=L.elem[i];}
    Lists.length++;
    return OK;
}
#endif

