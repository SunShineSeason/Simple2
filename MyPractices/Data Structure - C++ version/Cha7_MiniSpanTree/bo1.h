typedef struct ArcNode{
	int adjvex;//ָ��û������λ��
	int weight;//�û���Ȩֵ
	struct ArcNode *nextarc;//ָ����һ������ָ��
}ArcNode,*ArcPointer;//�������ݽṹ
typedef struct VNode{
	VertexType data;//������Ϣ
	ArcNode *firstarc;//ָ�������ڸö���ĵ�һ������ָ��
}VNode,* VNP;
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct{
	int weight;
	VertexType v;
}Aid;
