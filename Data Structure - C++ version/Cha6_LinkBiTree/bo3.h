typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front,rear;
}LinkQueue;