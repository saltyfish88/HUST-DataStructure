#ifndef GetElem_
#define GetElem_
status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	if(L.length==0){return INFEASIBLE;}//空表
	if(i<=0||i>L.length){
	return ERROR;
	}//判定越界 
	else
	{
		e=L.elem[i-1];
		return OK;
	}
}
#endif
