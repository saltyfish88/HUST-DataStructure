#include<stdio.h>
typedef char ElemType;
#define MAXLENGTH 100
#define N 100
typedef struct TWSTACK 
{
ElemType elem[N];
int top1,top2;
}TWSTACK;
int isPalindrome(char *str); 
void inistack(TWSTACK &S);
int push(TWSTACK &S,int i,ElemType e);
int pop(TWSTACK &S,int i, ElemType &e);
int main()
{
    char str[100];
    scanf("%s",str);
    printf("%s",isPalindrome(str)?"YES":"NO");
    return 0;
}
int isPalindrome(char *str)
//判断字符串str是否回文，是则返回1，否则返回0
{
int i=0,j=0,len=0;
char c;
while(str[i++]!='@'){len++;}
TWSTACK s;
inistack(s);
for(i=0;i<len/2;i++){push(s,1,str[i]);}
if(len%2==1){j=1+i;}
else{j=i;}
for(i=0;i<len/2;i++)
{
    pop(s,1,c);
    if(str[j++]!=c){return 0;}
}
return 1;
}
void inistack(TWSTACK &S)
//该函数实现初始化S，得到2个空栈。根据双向栈的示意图，理解初始化要求。
{
S.top2=N-1;
S.top1=0;
}
int push(TWSTACK &S,int i,ElemType e)
//i取值1或2，分别对应左或右栈，将元素e压入S的对应栈。成功入栈返回1，否则返回0
{
if(i==1)
{
	if(S.top1>S.top2){return 0;}
	else
	{
		S.elem[S.top1]=e;
		S.top1++;
		return 1;
	}
}
else if(i==2)
{
	if(S.top1>S.top2){return 0;}
	else
	{
		S.elem[S.top2]=e;
		S.top2--;
		return 1;
	}
}
}
int pop(TWSTACK &S,int i, ElemType &e)
//i取值1或2，分别对应左或右栈，将S对应栈的栈顶元素出栈，赋值给e。成功出栈返回1，否则返回0
{
if(i==2)
{
	if(S.top2==N-1){return 0;}
	else
	{
		e=S.elem[1+S.top2];
	    S.top2++;
	    return 1;
	}
}
else if(i==1)
{
	if(S.top1==0){return 0;}
	else
	{
		e=S.elem[S.top1-1];
	    S.top1--;
	    return 1;
	}
}
}


