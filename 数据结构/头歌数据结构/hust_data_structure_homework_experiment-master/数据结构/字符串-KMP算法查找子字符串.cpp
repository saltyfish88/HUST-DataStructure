#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
char *ch;
int length;
}HString;
int KMPsearch(HString &S,HString T,int left);
void Replace(HString &S,HString T,HString V);
int main()
{
HString S[3];
char buf[100],i,j;
for(i=0;i<3;i++)
{
	fgets(buf,100,stdin);
	S[i].length=strlen(buf)-1;  //-1是去掉回车符号
	S[i].ch=(char *)malloc(S[i].length);
	for(j=0;j<S[i].length; j++)
		S[i].ch[j]=*(buf+j);
}
Replace(S[0],S[1],S[2]);
printf("S的长度：%d\n",S[0].length);
for(i=0;i<S[0].length;i++)
	putchar(S[0].ch[i]);
return 1;

}
void Replace(HString &S,HString T,HString V)
{
int tag=0,sr=0,tw=0,temr=0,sw=0,vr=0;
HString tem;
tem.length=0;
tem.ch=(char*)malloc((1+V.length*S.length)*sizeof(char));
while(1)
{
	tag=KMPsearch(S,T,sr);
	if(tag==-1)
	{
		while(sr<S.length)
		{
			tem.ch[tw]=S.ch[sr];
			tw++;
			sr++;
		}
		break;
	}
	while(sr<tag)
	{
		tem.ch[tw]=S.ch[sr];
		tw++;
		sr++;
	}
	sr+=T.length;
	for(vr=0;vr<V.length;vr++)
	{
		tem.ch[tw]=V.ch[vr];
		tw++;
	}
}
tem.length=tw;
S.length=tw;
for(temr=0;temr<S.length;temr++)
{
	S.ch[sw]=tem.ch[temr];
	sw++;
}
}
int KMPsearch(HString &S,HString T,int left)
{
	int i=0,j=0,k=-1;
	int next[S.length];
	next[0]=-1;
	while(j<T.length-1)
	{
    	if(k==-1||T.ch[j]==T.ch[k])
    	{
        	j++;
			k++;
        	next[j]=k;
    	}
    	else k=next[k];
	}
	j=0;
	i=left;
    while(i<S.length&&j<T.length)
    {
    	if(j==-1||S.ch[i]==T.ch[j])
    	{
        	i++;
        	j++;
    	}
    	else j=next[j];
	}
	if(j>=T.length){return i-T.length;}
    else{return -1;}        
}
