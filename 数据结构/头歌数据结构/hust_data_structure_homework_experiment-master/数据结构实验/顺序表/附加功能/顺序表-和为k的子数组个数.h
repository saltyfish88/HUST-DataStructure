int book[20000000]={0};//标记出现过的前缀和次数（+1000000）
status SubArrayNum(SqList L,int k)
{
	int i=0,j=0,cnt=0;
	if(L.length==0){return INFEASIBLE;}//空表。 
	int prefix[1+L.length]={0};//前缀和数组。 
	book[10000000]++;//0出现一次。 
	for(i=1;i<=L.length;i++)
	{
		prefix[i]=L.elem[i-1]+prefix[i-1];//推导前缀和。 
		book[10000000+prefix[i]]++;//存储当前前缀和。 
		cnt+=book[10000000+prefix[i]-k];//有无和现在前缀和相差k的前缀和。 
	}
	return cnt;
}
