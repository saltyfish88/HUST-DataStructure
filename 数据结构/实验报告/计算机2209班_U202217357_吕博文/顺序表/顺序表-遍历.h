#ifndef ListTraverse_
#define ListTraverse_
status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
	int i=0;
	if(L.length==0){return INFEASIBLE;}//�ձ� 
	for(i=0;i<L.length;i++)//���� 
	{
		printf("%d",L.elem[i]);
		if(i<L.length-1){
		printf(" ");
		}//��ӡ�ո� 
	}
	return OK;
}
#endif
