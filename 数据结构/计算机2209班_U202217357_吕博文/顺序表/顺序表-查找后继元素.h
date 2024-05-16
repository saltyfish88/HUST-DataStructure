#ifndef NextElem_
#define NextElem_
status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
if(L.elem==NULL){
    return INFEASIBLE;//空表 
}else{
    for(int i = 0;i < L.length;i++){
		if(L.elem[i] == e&&i+1<L.length){//越界判定 
			next=L.elem[i+1];
            return OK;
		}//遍历寻找e 
	}
    return ERROR;
}
}
#endif

