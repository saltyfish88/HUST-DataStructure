#ifndef SaveList_
#define SaveList_
status SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
if(L.elem==NULL){
    return INFEASIBLE;//�ձ�
}
if(L.elem!=NULL){
    int i=0;
    FILE* fp=fopen(FileName,"w");//��ֻд
    if(fp==NULL){
        return ERROR;//��ʧ��
    }
    else for(i=0;i<L.length;i++){
        fprintf(fp,"%d ",L.elem[i]);//����д��
    }
    fclose(fp);//�ر��ļ� 
    return OK;
}
}
#endif
#ifndef LoadList_
#define LoadList_
status LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
if(L.elem!=NULL){
    return INFEASIBLE;//���Ա��Ѵ���
}
if(L.elem==NULL){
    int i=0,j,s[100];
    FILE*fp=fopen(FileName,"r");//��ֻ��
    if(fp==NULL){
        return ERROR;//��ʧ��
    }
    else L.length=0;
    while(fscanf(fp,"%d",&j)!=EOF){
        s[L.length++]=j;
    }//���볤��
    L.elem=(ElemType*)malloc(L.listsize*sizeof(ElemType));//����ռ�
    for(i=0;i<L.length;i++){
        L.elem[i]=s[i];
    }//��������
    fclose(fp);//�ر��ļ� 
    return OK;
}

}
#endif
