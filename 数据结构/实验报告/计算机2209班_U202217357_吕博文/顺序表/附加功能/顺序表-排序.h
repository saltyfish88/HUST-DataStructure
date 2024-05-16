void quicksort(SqList &L,int left,int right)
{
	int i=0,j=0;
	ElemType t,med;
	if(right<left){return;}//���� 
	med=L.elem[left];
	i=left;
	j=right;
	while(i<j)//����Ԫ�� 
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
	quicksort(L,1+j,right);//�������� 
	quicksort(L,left,j-1);//��������
}
status sortList(SqList &L)
{
	if(L.length==0){return INFEASIBLE;}//�ձ� 
	quicksort(L,0,L.length-1);//��������
	return OK;
}
