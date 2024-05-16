#ifndef SaveList_
#define SaveList_
status SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
if(L.elem==NULL){
    return INFEASIBLE;//空表
}
if(L.elem!=NULL){
    int i=0;
    FILE* fp=fopen(FileName,"w");//打开只写
    if(fp==NULL){
        return ERROR;//打开失败
    }
    else for(i=0;i<L.length;i++){
        fprintf(fp,"%d ",L.elem[i]);//遍历写入
    }
    fclose(fp);//关闭文件 
    return OK;
}
}
#endif
#ifndef LoadList_
#define LoadList_
status LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
if(L.elem!=NULL){
    return INFEASIBLE;//线性表已存在
}
if(L.elem==NULL){
    int i=0,j,s[100];
    FILE*fp=fopen(FileName,"r");//打开只读
    if(fp==NULL){
        return ERROR;//打开失败
    }
    else L.length=0;
    while(fscanf(fp,"%d",&j)!=EOF){
        s[L.length++]=j;
    }//读入长度
    L.elem=(ElemType*)malloc(L.listsize*sizeof(ElemType));//分配空间
    for(i=0;i<L.length;i++){
        L.elem[i]=s[i];
    }//读入数据
    fclose(fp);//关闭文件 
    return OK;
}

}
#endif
