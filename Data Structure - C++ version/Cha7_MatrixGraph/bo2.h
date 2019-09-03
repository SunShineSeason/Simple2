class Graph{
private:
	MGraph graph;

	int Locatevex(VertexType vt){
		for(int i=0;i<graph.vexnum;i++){
			if(graph.vexs[i]==vt)
				return i;
		}
		return -1;
	}
	void CreateUDN(){
		VertexType s1,s2;
		VRType vr;
		cout<<"请输入无向网G的顶点数,边数:"<<endl;
		cin>>graph.vexnum>>graph.arcnum;
		cout<<"请输入各个顶点的信息"<<endl;
		for(int i=0;i<graph.vexnum;++i)
			cin>>graph.vexs[i];
		for(int i=0;i<graph.vexnum;i++)
			for(int j=0;j<graph.vexnum;j++){
				graph.arcs[i][j].adj=INT_MAX;//邻接矩阵初始化,各边权值置为无穷大，表示该边不存在
			}
	   for(int i=0;i<graph.arcnum;i++){
		   cout<<"输入两顶点的信息与权值:";
		   cin>>s1>>s2>>vr;
		   int k=this->Locatevex(s1);int j=this->Locatevex(s2);
		   graph.arcs[i][j].adj=graph.arcs[j][i].adj=vr;//无向图
	   }
	}
#define CreateUDG CreateUDN
	void CreateDN(){//建立有向网（即各条边带权值）
		VertexType s1,s2;
		VRType vr;
		cout<<"请输入有向网G的顶点数,边数:"<<endl;
		cin>>graph.vexnum>>graph.arcnum;
		cout<<"请输入各个顶点的信息"<<endl;
		for(int i=0;i<graph.vexnum;i++){
			cin>>graph.vexs[i];
		}
		for(int i=0;i<graph.vexnum;i++)
			for(int j=0;j<graph.vexnum;j++)
				graph.arcs[i][j].adj=INT_MAX;
		 printf("请输入%d条弧的弧尾 弧头 权值(以空格作为间隔): \n",graph.arcnum);
		 for(int i=0;i<graph.arcnum;i++){
			 cin>>s1>>s2>>vr;
			  int k=this->Locatevex(s1);int j=this->Locatevex(s2);
			  graph.arcs[k][j].adj=vr;
		 }
	}
#define CreateDG CreateDN
public:
	void CreateGraph(){
		int k;
		cout<<"请输入图的类型1：";
		cin>>k;
		switch(k){
		case 0:
			graph.kind=DG;
			CreateDG();
			break;
		case 1:
			graph.kind=DN;
			CreateDN();
			break;
		case 2:
			graph.kind=UDG;
			CreateUDG();
			break;
		case 3:
			graph.kind=UDN;
			CreateUDN();
		}
	}
	Status InsertVex(VertexType v){
		this->graph.vexs[this->graph.vexnum++]=v;
		int j=this->graph.vexnum-1;
		for(int i=0;i<this->graph.vexnum;i++){
			this->graph.arcs[j][i].adj=INT_MAX;
			this->graph.arcs[i][j].adj=INT_MAX;
		}
		return true;
	}
	
}