 /* algo10-1.c 检验bo10-1.c的程序 */
 #include"c1.h"
 typedef int InfoType; /* 定义其它数据项的类型 */
 #include"c9.h"
 #include"c10-1.h"

 void InsertSort(SqList *L){
	 int i,j,k;
	 RedType r;
	 for(i=2;i<=(*L).length;i++)
	 {
		 k=i;
		 (*L).r[0]=(*L).r[i];
		 while(LT((*L).r[k].key,(*L).r[k-1].key))
		 {
			 r=(*L).r[k];
             (*L).r[k]=(*L).r[k-1];
			 (*L).r[k-1]=r;
			 k--;
		 }
	 }
 }

void print(SqList L)
 {
   int i;
   for(i=1;i<=L.length;i++)
     printf("(%d,%d)",L.r[i].key,L.r[i].otherinfo);
   printf("\n");
 }

 #define N 8
 void main()
 {
   RedType d[N]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
   SqList l1;
   int i;
   for(i=0;i<N;i++) /* 给l1.r赋值 */
     l1.r[i+1]=d[i];
   l1.length=N;
   printf("排序前:\n");
   print(l1);
   InsertSort(&l1);
   printf("直接插入排序后:\n");
   print(l1);
 }