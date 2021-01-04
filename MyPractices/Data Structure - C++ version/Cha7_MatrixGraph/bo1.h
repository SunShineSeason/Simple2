#define MAX_NUM 20//最大顶点个数
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct{
	VRType adj;//该边权值
}ArcCell,AdjMatrix[MAX_NUM][MAX_NUM];//也可以动态生成二维数组，这样节省内存空间，而且没有数量限制
typedef struct{
   VertexType vexs[MAX_NUM]; /* 顶点向量，包含各顶点的信息 */
   AdjMatrix arcs; /* 邻接矩阵，包含各条边的信息 */
   int vexnum,arcnum; /* 图的当前顶点数和弧数 */
   GraphKind kind; /* 图的种类标志 */
 }MGraph;