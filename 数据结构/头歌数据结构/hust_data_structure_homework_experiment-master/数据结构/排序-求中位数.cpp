#include<stdio.h>
#include<stdlib.h>
int MidValue(int a[],int n); 
int main()
{
int ans,*a,n,i;
scanf("%d",&n);
a=(int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("%d",MidValue(a,n));
free(a);
return 1;
}
int MidValue(int a[],int n)
//求a的中位数
{
	int i=0,pr=0,cnt=0,ret=0;
	int num[10000]={0};
	for(i=0;i<n;i++){num[a[i]]++;}
	for(i=0;i<=10000;i++)
	{
		if(num[i]==0){continue;}
		cnt+=num[i];
		if(cnt>n/2)
		{
			ret=i;
			if(n%2==0&&num[i]==1)
			{
				while(1)
				{
					if(num[i--]!=0)
					{
						ret=(i+ret)/2;
						break;
					}
				}
			}
			return ret;
		}
	}
}
