#ifndef ListEmpty_
#define ListEmpty_
status ListEmpty(SqList L)// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
if(L.elem==NULL){
    return INFEASIBLE;//线性表不存在 
}else{
    if(L.length!=0){
    return FALSE;//非空线性表
    }
    if(L.length==0){
    return TRUE;//空线性表
    }
}
}
#endif

