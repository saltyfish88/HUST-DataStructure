#ifndef InitList_
#define InitList_
status InitList(SqList& L)// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L.elem==NULL){
        L.elem=(ElemType *) malloc(sizeof(ElemType));//分配空间 
        L.length=0;
        L.listsize=LIST_INIT_SIZE;
        return OK;
    }else{
        return INFEASIBLE;
    }
}
#endif
