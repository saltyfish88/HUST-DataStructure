#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MAXLENGTH 100
typedef struct QUEUE {
     ElemType elem[MAXLENGTH];
     int front,length;
     } QUEUE;
void iniQueue(QUEUE &Q);
int enQueue(QUEUE &Q,ElemType e);
int deQueue(QUEUE &Q, ElemType &e);
int main()
{
int  i,f,e1,e2;
QUEUE Q;
scanf("%d",&f);
switch(f)
{
case 0: iniQueue(Q);
      if (Q.front>=0 && Q.front<MAXLENGTH && !Q.length) printf("OK");
      else printf("初始化失败");
		break;
case 1:	Q.length=MAXLENGTH;
		Q.front=0;
      e1=rand();
		if (enQueue(Q,e1))
      		{  printf("入队时未判满");break;}
		Q.length=MAXLENGTH-1;
		if (!enQueue(Q,e1))
      		{  printf("队列容量设置不正确");break;}
		Q.length=rand()%MAXLENGTH;
		Q.front=0;
      if (enQueue(Q,e1)==0)
      		{  printf("入队返回值有错");break;}
      printf("OK");
		break;
case 2: Q.front=rand()%MAXLENGTH;
      Q.length=0;
      if (deQueue(Q,e1)) 
      	{  printf("出队时未判空");break;}
      e1=rand();
      enQueue(Q,e1); 
      if (deQueue(Q,e2)==0 || e1!=e2) {printf("元素出队返回值进出队元素有错");break;} 
      printf("OK");
		break;
case 3: i=1;
	   iniQueue(Q);
      scanf("%d",&f);
      while (f)
      {
      	if (f==1) enQueue(Q,i++);
       else deQueue(Q,e1);
	     scanf("%d",&f);
      }
      for(i=0;i<Q.length;i++)
      	printf(" %d",Q.elem[(Q.front+i)%MAXLENGTH]);
}
return 1;

}
//在下面的begin和end间填写相应代码
void iniQueue(QUEUE &Q)
//该函数实现初始化Q
{
/***************begin***************/
Q.length=0;
/*************** end ***************/
}
int enQueue(QUEUE &Q,ElemType e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
/***************begin***************/
if(Q.length==MAXLENGTH){return 0;}
Q.elem[(Q.length+Q.front)%MAXLENGTH]=e;
Q.length++;
return 1;
/*************** end ***************/
}
int deQueue(QUEUE &Q, ElemType &e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
if(Q.length==0){return 0;}
e=Q.elem[Q.front];
Q.front=(1+Q.front)%MAXLENGTH;
Q.length--;
return 1;
/*************** end ***************/
}

