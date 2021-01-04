 /* c3-1.h 栈的顺序存储表示 */
 #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct{
	SElemType *base;
    SElemType *top;
	int stacksize;
}SqStack;