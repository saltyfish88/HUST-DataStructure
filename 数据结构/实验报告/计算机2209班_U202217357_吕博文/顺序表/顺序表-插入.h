#ifndef ListInsert_
#define ListInsert_
status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	int j=0;
	if(i>1+L.length||i<=0){
	return ERROR;
	}//越界判定 
	if(L.length==0){
	return INFEASIBLE;
	}//空表
	if(L.length>=L.listsize)//线性表已满
	{
	    L.elem=(ElemType*)realloc(L.elem,(1+L.length)*sizeof(ElemType));
	    if(L.elem==NULL){
		return OVERFLOW;
		}
	    L.listsize=1+L.length;
	}
	i--;
	L.length++;
	for(j=L.length-1;j>=i;j--){
	L.elem[1+j]=L.elem[j];
	}//插入和移位 
	L.elem[i]=e;
	return OK;
}
#endif

