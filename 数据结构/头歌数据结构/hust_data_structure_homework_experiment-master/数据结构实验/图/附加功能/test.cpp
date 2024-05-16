#include<stdio.h>
int*f()
{
	int i=0,b=101;
	int a[5];
	for(i=1;i<5;i++){scanf("%d",&a[i]);}
	a[0]=b;
	int*p; 
	p=a;
	return a;
}
int main()
{
	int*ptr=f();
	printf("%d",ptr[2]);
	return 0;
}
 
 
 
 
 
