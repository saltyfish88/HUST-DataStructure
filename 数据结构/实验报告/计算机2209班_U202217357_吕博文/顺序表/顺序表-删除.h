#ifndef ListDelete_
#define ListDelete_
status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem==NULL ){
    return INFEASIBLE;//�ձ� 
}
if(i<1||i>L.length){
		return ERROR;
}//�ж�Խ�� 
e=L.elem[i-1];
for(int j=i;j<L.length;j++){
		L.elem[j-1] = L.elem[j];
}//i���Ԫ����ǰ�ƶ�һλ
L.length--;
return OK;

}
#endif

