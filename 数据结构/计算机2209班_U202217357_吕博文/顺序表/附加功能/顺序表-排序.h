void quicksort(SqList &L,int left,int right)
{
	int i=0,j=0;
	ElemType t,med;
	if(right<left){return;}//结束 
	med=L.elem[left];
	i=left;
	j=right;
	while(i<j)//交换元素 
	{
		if(L.elem[j]<med)
		{
			if(L.elem[i]>med)
			{
				t=L.elem[j];
				L.elem[j]=L.elem[i];
				L.elem[i]=t;
			}
			else{i++;}
		}
		else{j--;}
	}
	if(j==i)
	{
		t=L.elem[left];
		L.elem[left]=L.elem[j];
		L.elem[j]=t;
	}
	quicksort(L,1+j,right);//继续排左 
	quicksort(L,left,j-1);//继续排右
}
status sortList(SqList &L)
{
	if(L.length==0){return INFEASIBLE;}//空表 
	quicksort(L,0,L.length-1);//快速排序
	return OK;
}
