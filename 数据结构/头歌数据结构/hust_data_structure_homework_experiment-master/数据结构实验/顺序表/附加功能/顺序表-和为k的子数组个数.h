int book[20000000]={0};//��ǳ��ֹ���ǰ׺�ʹ�����+1000000��
status SubArrayNum(SqList L,int k)
{
	int i=0,j=0,cnt=0;
	if(L.length==0){return INFEASIBLE;}//�ձ� 
	int prefix[1+L.length]={0};//ǰ׺�����顣 
	book[10000000]++;//0����һ�Ρ� 
	for(i=1;i<=L.length;i++)
	{
		prefix[i]=L.elem[i-1]+prefix[i-1];//�Ƶ�ǰ׺�͡� 
		book[10000000+prefix[i]]++;//�洢��ǰǰ׺�͡� 
		cnt+=book[10000000+prefix[i]-k];//���޺�����ǰ׺�����k��ǰ׺�͡� 
	}
	return cnt;
}
