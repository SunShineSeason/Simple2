#define MAXSIZE 100//宏定义
typedef TElemType SqBiTree[MAXSIZE];//声明数组类型

typedef struct
 {
   int level,order; /* 结点的层,本层序号(按满二叉树计算) */
 }position;