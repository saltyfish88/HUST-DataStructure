#ifndef DestroyList_
#define DestroyList_
status DestroyList(SqList& L)// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
if(L.elem==NULL){
        return INFEASIBLE;//�ձ�
}else{
    free(L.elem);//���տռ䡣 
	L.elem = NULL;
    return OK;
}
}
#endif
