#ifndef LocateList_
#define LocateList_
int LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
       for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name,ListName)==0){//ƥ������ 
        return i+1;
        }
    }
    return 0;
}
#endif

