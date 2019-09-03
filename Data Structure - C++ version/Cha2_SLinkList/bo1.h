#define MAXSIZE 100
typedef struct{
	ElemType data;
	int cur;//指示结点在链表中的位置
}component,SLinkList[MAXSIZE];//利用typedef可以为指针类型与数组类型定义别名！！