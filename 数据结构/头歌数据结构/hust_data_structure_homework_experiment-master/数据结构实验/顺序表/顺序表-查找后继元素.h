#ifndef NextElem_
#define NextElem_
status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem==NULL){
    return INFEASIBLE;//�ձ� 
}else{
    for(int i = 0;i < L.length;i++){
		if(L.elem[i] == e&&i+1<L.length){//Խ���ж� 
			next=L.elem[i+1];
            return OK;
		}//����Ѱ��e 
	}
    return ERROR;
}
}
#endif

