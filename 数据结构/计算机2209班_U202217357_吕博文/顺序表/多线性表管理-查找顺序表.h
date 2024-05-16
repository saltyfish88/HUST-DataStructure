#ifndef LocateList_
#define LocateList_
int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
       for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name,ListName)==0){//匹配名字 
        return i+1;
        }
    }
    return 0;
}
#endif

