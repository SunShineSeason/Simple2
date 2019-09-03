#define CHAR 0 /* 整型(二者选一) */
 #if CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* 设字符型以空格符为空 */
 #else
   typedef int TElemType;
   TElemType Nil=0; /* 设整型以0为空 */
 #endif
 #include"c1.h"
 #include"c.h"
 #include"bo2.h"

 Status visit(TElemType e)
 {
   printf("%4d ",e);
   return OK;
 }
 
void main(){
   int i;
   char s='*';
   BiTree T;
   TElemType e1,e2;
   InitBiTree(&T);
   printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
 
#if CHAR
   printf("请先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
 #else
    printf("请先序输入二叉树(如:1 2 0 0 0表示1为根结点,2为左子树的二叉树)\n");
 #endif
  
   CreateBiTree(&T);//注意输入的方法：先将二叉树补Nil，使每个非空结点的度为2，再按先序遍历输入数据
   printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   printf("先序遍历二叉树:\n");
   PreOrderTraverse1(T,visit);
   printf("层序遍历二叉树:\n");
   LevelOrderTraverse(T,visit);
   printf("\n");
   printf("中序遍历二叉树:\n");
   InOrderTraverse1(T,visit);
   printf("\n");
   printf("后序遍历二叉树:\n");
   PostOrderTraverse(T,visit);
   printf("\n");
   while(1)
   {
	    printf("请输入i的数值：");
        scanf("%d",&i);
        e1=LeftChild(T,i);
        printf("%d\n",e1);
        e1=LeftSibling(T,i);
        printf("%d\n",e1);
   }
}
