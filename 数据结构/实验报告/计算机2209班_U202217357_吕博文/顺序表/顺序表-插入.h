#ifndef ListInsert_
#define ListInsert_
status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	int j=0;
	if(i>1+L.length||i<=0){
	return ERROR;
	}//Խ���ж� 
	if(L.length==0){
	return INFEASIBLE;
	}//�ձ�
	if(L.length>=L.listsize)//���Ա�����
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
	}//�������λ 
	L.elem[i]=e;
	return OK;
}
#endif

