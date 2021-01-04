#define MAXSIZE 100
typedef struct{
	QElemType *base;//指向动态分配的数组空间
	int top;
	int rear; 
}SqQueue;