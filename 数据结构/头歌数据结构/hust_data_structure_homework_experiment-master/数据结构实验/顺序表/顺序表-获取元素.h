#ifndef GetElem_
#define GetElem_
status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(L.length==0){return INFEASIBLE;}//�ձ�
	if(i<=0||i>L.length){
	return ERROR;
	}//�ж�Խ�� 
	else
	{
		e=L.elem[i-1];
		return OK;
	}
}
#endif
