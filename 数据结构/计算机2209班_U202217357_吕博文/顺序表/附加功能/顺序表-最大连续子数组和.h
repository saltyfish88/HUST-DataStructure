ElemType stackmin[10000000]={0};//����ջ
ElemType prefix[10000000]={0};//ǰ׺������
ElemType prefixmin[10000000]={0};//ǰ׺��Сֵ����
status MaxSubArray(SqList L)
{
	int i=0,topmin=0,topmax=0;
	ElemType max=-(1<<30);//��ʼ�� 
	if(L.length==0){return INFEASIBLE;} //�ձ�
	for(i=1;i<=L.length;i++){prefix[i]=L.elem[i-1]+prefix[i-1];}//�Ƶ�ǰ׺�� 
	for(i=1;i<L.length;i++)
	{
		if(stackmin[topmin]<prefix[i])//��ǰ׺�������ǰ׺��Сֵ
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
	}//ö��ǰ׺�����飬��Ԫ�غ�ǰ׺��Сֵ�Ĳ�����ֵ�� 
	return max;
}
