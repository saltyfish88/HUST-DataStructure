#ifndef ListLength_ 
#define ListLength_
status ListLength(SqList L)// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
if(L.elem==NULL){return 
	INFEASIBLE;
}//�ձ� 
else{
	return L.length;
}
}
#endif

