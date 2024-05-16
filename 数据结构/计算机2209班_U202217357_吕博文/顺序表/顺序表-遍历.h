#ifndef ListTraverse_
#define ListTraverse_
status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
	int i=0;
	if(L.length==0){return INFEASIBLE;}//空表 
	for(i=0;i<L.length;i++)//遍历 
	{
		printf("%d",L.elem[i]);
		if(i<L.length-1){
		printf(" ");
		}//打印空格 
	}
	return OK;
}
#endif
