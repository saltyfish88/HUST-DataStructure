#ifndef ClearList_
#define ClearList_
status ClearList(SqList& L)// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
if(L.elem==NULL){
    return INFEASIBLE;//�ձ� 
}else{
    for (int j = 0; j < L.length; j++){
		L.elem[j] = 0;
	}//Ԫ������ 
	L.length = 0;//������0 
    return OK;
}
}
#endif
