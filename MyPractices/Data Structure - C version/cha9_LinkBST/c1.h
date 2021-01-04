/* c6-2.h 二叉树的二叉链表存储表示 */
 typedef struct BiTNode
 {
   TElemType data;//此时二叉树的数据类型为结构体类型
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
 }BiTNode,*BiTree;

