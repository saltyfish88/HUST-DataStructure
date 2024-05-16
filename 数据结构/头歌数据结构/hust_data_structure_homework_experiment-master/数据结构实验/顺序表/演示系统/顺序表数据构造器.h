#ifndef DATACREATER
#define DATACREATER
int getrnum()
{
	srand((unsigned)time(NULL));
	return 1+rand()%10000007;
}
void createdataforsqlist(SqList &L,int len,const char name[])//随机生成顺序表数据。 
{
	int i=0,n=0;
	srand((unsigned)time(NULL));
	if(L.length!=0){return;}
    L.elem=(ElemType*)malloc(sizeof(ElemType)*(1+2*len));
    L.length=0;
    L.listsize=len;
    for(i=0;i<len;i++)
    {
    	n=1+rand()%10000;
        L.elem[L.length++]=n;
    }  
	FILE*fp=fopen(name,"w");
	for(i=0;i<len;i++){fprintf(fp,"%d ",L.elem[i]);}
	fclose(fp);
}
void savelistforsqlist(SqList L,const char FileName[])
{
	int i=0;
	FILE*fp=fopen(FileName,"w");
	if(fp==NULL){return;}
	for(i=0;i<L.length;i++)
	{
	    fprintf(fp,"%d",L.elem[i]);
	    if(i<L.length-1){fprintf(fp," ");}
	}
	fclose(fp);
}
#endif
