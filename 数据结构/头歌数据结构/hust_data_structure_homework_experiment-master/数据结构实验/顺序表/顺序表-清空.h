#ifndef ClearList_
#define ClearList_
status ClearList(SqList& L)// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
if(L.elem==NULL){
    return INFEASIBLE;//空表 
}else{
    for (int j = 0; j < L.length; j++){
		L.elem[j] = 0;
	}//元素清零 
	L.length = 0;//长度置0 
    return OK;
}
}
#endif
