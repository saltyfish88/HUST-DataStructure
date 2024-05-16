#include "def.h"
#include "顺序表-初始化.h"
#include "顺序表-销毁.h"
#include "顺序表-插入.h"
#include "顺序表-删除.h"
#include "顺序表-遍历.h"
#include "多顺序表管理-增加一个新顺序表.h"
#include "多顺序表管理-移除一个顺序表.h"
int main() {
	LISTS Lists;
   int n,e;
   char name[30];
   Lists.length=0;
	scanf("%d", &n);
	while(n--)
   {
    	scanf("%s",name);
   		AddList(Lists,name);
      scanf("%d",&e);
      while (e)
      {
      		ListInsert(Lists.elem[Lists.length-1].L,Lists.elem[Lists.length-1].L.length+1,e);
      		scanf("%d",&e);
      }
   }
   scanf("%s",name);
   if (RemoveList(Lists,name)==OK)
	   for(n=0;n<Lists.length;n++)
   		{
   			printf("%s ",Lists.elem[n].name);
   			ListTraverse(Lists.elem[n].L);
        	putchar('\n');
   		}
   else printf("删除失败");
return 1;
}
