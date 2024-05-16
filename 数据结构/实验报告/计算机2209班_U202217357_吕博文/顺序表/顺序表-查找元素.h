#ifndef LocateElem_
#define LocateElem_
int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
if(L.elem==NULL){
    return INFEASIBLE;//空表 
}else{
    for(int i = 0;i < L.length;i++){
		if(L.elem[i] == e){
			return i+1;
		}
	}//遍历匹配元素e 
    return ERROR;
}
}
#endif

