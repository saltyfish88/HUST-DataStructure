#ifndef ListDelete_
#define ListDelete_
status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
if(L.elem==NULL ){
    return INFEASIBLE;//空表 
}
if(i<1||i>L.length){
		return ERROR;
}//判定越界 
e=L.elem[i-1];
for(int j=i;j<L.length;j++){
		L.elem[j-1] = L.elem[j];
}//i后的元素向前移动一位
L.length--;
return OK;

}
#endif

