ElemType stackmin[10000000]={0};//单调栈
ElemType prefix[10000000]={0};//前缀和数组
ElemType prefixmin[10000000]={0};//前缀最小值数组
status MaxSubArray(SqList L)
{
	int i=0,topmin=0,topmax=0;
	ElemType max=-(1<<30);//初始化 
	if(L.length==0){return INFEASIBLE;} //空表
	for(i=1;i<=L.length;i++){prefix[i]=L.elem[i-1]+prefix[i-1];}//推导前缀和 
	for(i=1;i<L.length;i++)
	{
		if(stackmin[topmin]<prefix[i])//求前缀和数组的前缀最小值
		{
			topmin++;
			stackmin[topmin]=prefix[i];
		}
		else
		{
			while(topmin>-1&&prefix[topmin]>=prefix[i]){topmin--;}
			topmin++;
			stackmin[topmin]=prefix[i];
		}
		prefixmin[i]=stackmin[0];
	}
	for(i=1;i<=L.length;i++){
	if(prefix[i]-prefixmin[i-1]>max){
	max=prefix[i]-prefixmin[i-1];
	}
	}//枚举前缀和数组，求元素和前缀最小值的差的最大值。 
	return max;
}
