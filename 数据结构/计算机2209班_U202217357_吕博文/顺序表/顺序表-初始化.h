#ifndef InitList_
#define InitList_
status InitList(SqList& L)// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem==NULL){
        L.elem=(ElemType *) malloc(sizeof(ElemType));//����ռ� 
        L.length=0;
        L.listsize=LIST_INIT_SIZE;
        return OK;
    }else{
        return INFEASIBLE;
    }
}
#endif
