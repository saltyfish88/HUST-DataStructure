#ifndef ListLength_ 
#define ListLength_
status ListLength(SqList L)// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
if(L.elem==NULL){return 
	INFEASIBLE;
}//空表。 
else{
	return L.length;
}
}
#endif

