typedef struct{
	int OccurTime;
	int NType;//事件类型
}Event,ElemType;//链表处理的数据类型是事件
#include"Cha2_LinkList\bo1.h"
typedef LinkList EventList;
typedef struct{
	int ArrivalTime;
	int SolveTime;
}QElemType;//队列处理的数据类型是客户信息