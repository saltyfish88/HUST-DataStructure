#ifndef PriorElem_
#define PriorElem_
status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem==NULL){
    return INFEASIBLE;//�ձ� 
}else{
    for(int i = 0;i < L.length;i++){
		if(L.elem[i] == e&&i>0){
			pre=L.elem[i-1];
            return OK;
		}//����Ѱ��Ԫ��e 
	}
    return ERROR;//δ�ҵ� 
}
}
#endif

