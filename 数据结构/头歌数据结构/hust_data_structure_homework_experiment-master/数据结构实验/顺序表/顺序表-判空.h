#ifndef ListEmpty_
#define ListEmpty_
status ListEmpty(SqList L)// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
if(L.elem==NULL){
    return INFEASIBLE;//���Ա����� 
}else{
    if(L.length!=0){
    return FALSE;//�ǿ����Ա�
    }
    if(L.length==0){
    return TRUE;//�����Ա�
    }
}
}
#endif

