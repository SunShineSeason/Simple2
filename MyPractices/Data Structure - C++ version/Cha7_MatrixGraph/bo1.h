#define MAX_NUM 20//��󶥵����
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct{
	VRType adj;//�ñ�Ȩֵ
}ArcCell,AdjMatrix[MAX_NUM][MAX_NUM];//Ҳ���Զ�̬���ɶ�ά���飬������ʡ�ڴ�ռ䣬����û����������
typedef struct{
   VertexType vexs[MAX_NUM]; /* �����������������������Ϣ */
   AdjMatrix arcs; /* �ڽӾ��󣬰��������ߵ���Ϣ */
   int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
   GraphKind kind; /* ͼ�������־ */
 }MGraph;