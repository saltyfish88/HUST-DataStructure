#ifndef RemoveList_
#define RemoveList_
status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
for(int i=0;i<Lists.length;i++){
    if(strcmp(Lists.elem[i].name,ListName)==0){//匹配名字 
        Lists.elem[i].L.length++;
        for(int j=i;j<Lists.length-1;j++){
            strcpy(Lists.elem[i].name,Lists.elem[i+1].name);
            for(int p=0;p<=Lists.elem[i+1].L.length;p++){
                    Lists.elem[i].L.elem[p]=Lists.elem[i+1].L.elem[p];
            }//删除后移动元素 
             
        }
        Lists.length--;//修改长度 
        return OK;
    }
}
return ERROR;
}
#endif
