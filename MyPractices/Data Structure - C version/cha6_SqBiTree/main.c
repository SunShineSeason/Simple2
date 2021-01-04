#define CHAR 0 /* 整型(二者选一) */
 #include"c1.h"
 #if CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* 设字符型以空格符为空 */
 #else
   typedef int TElemType;
   TElemType Nil=0; /* 设整型以0为空 */
 #endif
 #include"c6-1.h"
 #include"bo6-1.h"
void main()
 {
   Status i;
   int j;
   position p={2,1};
   TElemType e;
   SqBiTree T,s;
   InitBiTree(T);
   CreateBiTree(T);
   printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   Assign(T,p,12);
   printf("%d\n",T[0]);//注意，系统中允许数组下标的值超出定义的长度，但此时数值不确定!!!
   e=LeftSibling(T,66);
   printf("%d\n",e);
}
