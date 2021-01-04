/* algo9-4.c 检验bo9-2.c的程序 */
 #include"c.h"
 #define N 10 /* 数据元素个数 */
 #include"c9.h"
 #include"bo1.h"

 void print(ElemType c)
 {
   printf("(%d,%d) ",c.key,c.others);
 }

 void main()
 {
   BiTree dt,p;
   int i;
   KeyType j;
   ElemType r[N]={{45,1},{12,2},{53,3},{3,4},{37,5},{24,6},{100,7},{61,8},{90,9},{78,10}}; /* 以教科书图9.7(a)为例 */
   InitDSTable(&dt); /* 构造空表 */
   for(i=0;i<N;i++)
     InsertBST(&dt,r[i]); /* 依次插入数据元素 */

 }
