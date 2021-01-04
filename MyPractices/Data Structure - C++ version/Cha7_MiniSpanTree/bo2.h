class ALGraph{
public:
	VNP graph;
	int vexnum,arcnum;
	GraphKind kind;
	bool *visited;//��־���飬���ڱ�������
private:
	int Locate(VertexType s){
		for(int i=0;i<this->vexnum;i++){
			if(this->graph[i].data==s)
				return i;
		}
		return -1;
	}
	void CreateDN(){
		VertexType s1,s2;
		int weight;
		cout<<"��������������Ϣ��"<<endl;
		for(int i=0;i<this->vexnum;i++){
			cin>>this->graph[i].data;
			this->graph[i].firstarc=NULL;//ע�⣬ָ����ʹ��֮ǰһ��Ҫ�ȳ�ʼ������ʹ�Ǹ�ֵΪ��!!
		}
		cout<<"������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(�Կո���Ϊ���):"<<endl;
		for(int i=0;i<this->arcnum;i++){
			cin>>weight>>s1>>s2;
			int j=Locate(s1);//��β
			int k=Locate(s2);//��ͷ
			ArcPointer pt=new ArcNode;
			pt->adjvex=k;  pt->weight=weight;
			pt->nextarc=this->graph[j].firstarc;
			this->graph[j].firstarc=pt;
		}
	}
	void CreateUDN(){
		VertexType s1,s2;
		int weight;
		cout<<"��������������Ϣ��"<<endl;
		for(int i=0;i<this->vexnum;i++){
			cin>>this->graph[i].data;
			this->graph[i].firstarc=NULL;//ע�⣬ָ����ʹ��֮ǰһ��Ҫ�ȳ�ʼ������ʹ�Ǹ�ֵΪ��!!
		}
		cout<<"������ÿ����(��)��Ȩֵ�Ͷ���(�Կո���Ϊ���):"<<endl;
		for(int i=0;i<this->arcnum;i++){
			cin>>s1>>s2>>weight;
			int j=Locate(s1);
			int k=Locate(s2);
			ArcPointer pt=new ArcNode;
			pt->adjvex=k;  pt->weight=weight; pt->nextarc=this->graph[j].firstarc;
			this->graph[j].firstarc=pt;
			pt=new ArcNode;
			pt->adjvex=j;  pt->weight=weight; pt->nextarc=this->graph[k].firstarc;
			this->graph[k].firstarc=pt;
		}
	}
#define CreateDG CreateDN
#define CreateUDG CreateUDN
	void DFStraverse(int i){
		cout<<this->graph[i].data<<"  ";
		this->visited[i]=true;//�ñ�־λΪtrue
		ArcPointer pt=this->graph[i].firstarc;
		while(pt){
			if(!visited[pt->adjvex])//��ǰ����δ�����ʹ�
				this->DFStraverse(pt->adjvex);//�ݹ����
			pt=pt->nextarc;
		}
	}
public:
	void CreateGraph(){
		int k;
		cout<<"������ͼ������1��";
		cin>>k;
		cout<<"�����붥�����뻡����"<<endl;
		cin>>this->vexnum>>this->arcnum;
		graph=new VNode[this->vexnum];
		switch(k){
		case 0:
			this->kind=DG;
			CreateDG();
			break;
		case 1:
			this->kind=DN;
			CreateDN();
			break;
		case 2:
			this->kind=UDG;
			CreateUDG();
			break;
		case 3:
			this->kind=UDN;
			CreateUDN();
		}

	}
	void DeleteVex(int k){//ɾ��ĳһ���㼰����صı�
		VNP pt=new VNode[this->vexnum-1];
		for(int i=0,j=0;j<this->vexnum;j++){
			if(j==k){//ע�⣬��Ҫд��i==k���״�!!
				ArcNode *ps=this->graph[j].firstarc,*pr;
				while(ps){
					pr=ps->nextarc;
					delete ps;
					ps=pr;
					this->arcnum--;//һ��Ҫע�⣬����Ҫ����Ӧ���޸�!!
				}
				continue;//ע�⣬��ʱ��Ҫ������������ִ��
			}
			pt[i]=this->graph[j];
			ArcNode *ps=pt[i].firstarc,*pr;//prָ��ps��ǰ��!!
			while(ps){
				//��Ҫ�޸�ÿ������Ӧ�Ķ���λ�ú�ɾ������Ϊk�Ļ�
				if(ps->adjvex==k){//��ǰ���Ķ�����k����Ҫɾ��
					if(ps==pt[i].firstarc){//ע�⣬�����ɾ���Ļ��ǵ�һ���ڽӽ�㣬��Ҫ���⴦��
						pt[i].firstarc=ps->nextarc;
						delete ps;
						this->arcnum--;
						ps=pt[i].firstarc;//ע�⣬ps��Ҫָ����һ����
					}
					else{
						pr->nextarc=ps->nextarc;
						delete ps;
						this->arcnum--;
						ps=pr->nextarc;
					}
				}
				else{
					if(ps->adjvex>k)
						ps->adjvex--;//ע��!!!
					pr=ps;//��pr��¼ǰ��������ִ��ɾ������!!
					ps=ps->nextarc;
				}
			}
			i++;//ע��!!
		}
		this->vexnum--;//ע��!!
		delete[] this->graph;//�ͷ�ԭͼ�ڴ�ռ�
		this->graph=pt;
	}
	void DFSTraverse(){//������ȱ���
		this->visited=new bool[this->vexnum];
		for(int i=0;i<this->vexnum;i++)
			this->visited[i]=false;
		DFStraverse(0);//ע�⣬�������ý���ʱ����V1������·����ͨ�Ķ��㶼�ᱻ���ʵ���
		cout<<endl;   //����ͼ������Ϊ�����ʵĶ��㣬��Ҫѡ�иö��㣬�����ݹ����!!!
	}
};