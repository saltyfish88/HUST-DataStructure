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
//�ж��ַ���str�Ƿ���ģ����򷵻�1�����򷵻�0
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
//�ú���ʵ�ֳ�ʼ��S���õ�2����ջ������˫��ջ��ʾ��ͼ������ʼ��Ҫ��
{
S.top2=N-1;
S.top1=0;
}
int push(TWSTACK &S,int i,ElemType e)
//iȡֵ1��2���ֱ��Ӧ�����ջ����Ԫ��eѹ��S�Ķ�Ӧջ���ɹ���ջ����1�����򷵻�0
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
//iȡֵ1��2���ֱ��Ӧ�����ջ����S��Ӧջ��ջ��Ԫ�س�ջ����ֵ��e���ɹ���ջ����1�����򷵻�0
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


