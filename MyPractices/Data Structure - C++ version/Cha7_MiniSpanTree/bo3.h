class MiniSpanTree{
private:
	ALGraph graph;//��������Ϊ��Ա����
	Aid *closedge;//��������
	vector<VertexType> u;
	Status Locate(VertexType v){
		for(int i=0;i<u.size();i++)
			if(this->u[i]==v)
				return true;
		return false;
	}
	int MIN(Aid *close){
		int min=INT_MAX,k;
		for(int i=1;i<this->graph.vexnum;i++)
			if(close[i].weight<min){
				k=i;min=close[i].weight;
			}
		return k;
	}
public:
	void InitGraph(){
		graph.CreateGraph();
		this->closedge=new Aid[this->graph.vexnum];//0�ſռ䲻��
		for(int i=1;i<this->graph.vexnum;i++)
			this->closedge[i].weight=INT_MAX;
	}
	void PRIM_MINITree(){
		u.push_back(graph.graph[0].data);
		for(int i=1;i<graph.vexnum;i++){
			for(int j=1;j<this->graph.vexnum;j++){
				if(!Locate(graph.graph[j].data)){
					int min=INT_MAX;VertexType v;
					ArcNode *pt=this->graph.graph[j].firstarc;
					while(pt){
						if(Locate(this->graph.graph[pt->adjvex].data)&&min>pt->weight){//��ǰ�������Ķ�����u�У���Ȩֵ��С
							min=pt->weight;v=this->graph.graph[pt->adjvex].data;
						}
						pt=pt->nextarc;
					}
				   if(min!=INT_MAX){
					   this->closedge[j].weight=min;this->closedge[j].v=v;
				   }
				}
			}
			int no=MIN(this->closedge);//���ظ���������Ȩֵ��С�Ķ������
			u.push_back(this->graph.graph[no].data);//�ö���ѹ������
			cout<<this->graph.graph[no].data<<"  "<<this->closedge[no].v<<"  "<<this->closedge[no].weight<<endl;
			this->closedge[no].weight=INT_MAX;
		}
	}
};