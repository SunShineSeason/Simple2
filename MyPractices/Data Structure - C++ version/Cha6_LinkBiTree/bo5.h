typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

#define STACK_INIT_SIZE 100