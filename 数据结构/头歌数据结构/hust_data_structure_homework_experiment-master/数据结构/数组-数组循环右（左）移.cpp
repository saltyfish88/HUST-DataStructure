#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
void reverse(ElemType *a,int left,int right);
void ShiftRightCircular(ElemType *A,int n,int k);
int main()
{
    int n,i,k;
    ElemType *p;
    scanf("%d%d",&n,&k);
    p=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        p[i]=i+1;
    ShiftRightCircular(p,n,k);
    for(i=0;i<n;i++)
        printf(" %d",p[i]);
    return 1;
}
void ShiftRightCircular(ElemType *A,int n,int k)
{
	k%=10;
	if(k<0)
	{
		reverse(A,0,-k-1);
		reverse(A,-k,n-1);
		reverse(A,0,n-1);
	}
	else if(k>0)
	{
		reverse(A,n-k,n-1);
		reverse(A,0,n-1-k);
		reverse(A,0,n-1);
	}
}
void reverse(ElemType *a,int left,int right)
{
	int t=0;
	while(left<right)
	{
		t=a[right];
		a[right]=a[left];
		a[left]=t;
		right--;
		left++;
	}
}
