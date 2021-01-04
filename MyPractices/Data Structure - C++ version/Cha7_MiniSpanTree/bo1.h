typedef struct ArcNode{
	int adjvex;//指向该弧顶点的位置
	int weight;//该弧的权值
	struct ArcNode *nextarc;//指向下一条弧的指针
}ArcNode,*ArcPointer;//弧的数据结构
typedef struct VNode{
	VertexType data;//顶点信息
	ArcNode *firstarc;//指向依附于该顶点的第一条弧的指针
}VNode,* VNP;
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct{
	int weight;
	VertexType v;
}Aid;
