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
		cout<<"������������G�Ķ�����,����:"<<endl;
		cin>>graph.vexnum>>graph.arcnum;
		cout<<"����������������Ϣ"<<endl;
		for(int i=0;i<graph.vexnum;++i)
			cin>>graph.vexs[i];
		for(int i=0;i<graph.vexnum;i++)
			for(int j=0;j<graph.vexnum;j++){
				graph.arcs[i][j].adj=INT_MAX;//�ڽӾ����ʼ��,����Ȩֵ��Ϊ����󣬱�ʾ�ñ߲�����
			}
	   for(int i=0;i<graph.arcnum;i++){
		   cout<<"�������������Ϣ��Ȩֵ:";
		   cin>>s1>>s2>>vr;
		   int k=this->Locatevex(s1);int j=this->Locatevex(s2);
		   graph.arcs[i][j].adj=graph.arcs[j][i].adj=vr;//����ͼ
	   }
	}
#define CreateUDG CreateUDN
	void CreateDN(){//�������������������ߴ�Ȩֵ��
		VertexType s1,s2;
		VRType vr;
		cout<<"������������G�Ķ�����,����:"<<endl;
		cin>>graph.vexnum>>graph.arcnum;
		cout<<"����������������Ϣ"<<endl;
		for(int i=0;i<graph.vexnum;i++){
			cin>>graph.vexs[i];
		}
		for(int i=0;i<graph.vexnum;i++)
			for(int j=0;j<graph.vexnum;j++)
				graph.arcs[i][j].adj=INT_MAX;
		 printf("������%d�����Ļ�β ��ͷ Ȩֵ(�Կո���Ϊ���): \n",graph.arcnum);
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
		cout<<"������ͼ������1��";
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