#ifndef PriorElem_
#define PriorElem_
status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
if(L.elem==NULL){
    return INFEASIBLE;//空表 
}else{
    for(int i = 0;i < L.length;i++){
		if(L.elem[i] == e&&i>0){
			pre=L.elem[i-1];
            return OK;
		}//遍历寻找元素e 
	}
    return ERROR;//未找到 
}
}
#endif

