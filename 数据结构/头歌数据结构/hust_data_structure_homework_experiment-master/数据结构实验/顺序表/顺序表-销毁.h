#ifndef DestroyList_
#define DestroyList_
status DestroyList(SqList& L)// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
if(L.elem==NULL){
        return INFEASIBLE;//空表
}else{
    free(L.elem);//回收空间。 
	L.elem = NULL;
    return OK;
}
}
#endif
