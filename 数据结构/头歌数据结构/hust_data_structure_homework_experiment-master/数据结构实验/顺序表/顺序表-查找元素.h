#ifndef LocateElem_
#define LocateElem_
int LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
{
if(L.elem==NULL){
    return INFEASIBLE;//�ձ� 
}else{
    for(int i = 0;i < L.length;i++){
		if(L.elem[i] == e){
			return i+1;
		}
	}//����ƥ��Ԫ��e 
    return ERROR;
}
}
#endif

