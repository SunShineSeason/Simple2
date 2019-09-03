class ALGraph{
public:
	VNP graph;
	int vexnum,arcnum;
	GraphKind kind;
	bool *visited;//标志数组，用于遍历过程
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
		cout<<"请输入各顶点的信息："<<endl;
		for(int i=0;i<this->vexnum;i++){
			cin>>this->graph[i].data;
			this->graph[i].firstarc=NULL;//注意，指针在使用之前一定要先初始化，即使是赋值为空!!
		}
		cout<<"请输入每条弧(边)的权值、弧尾和弧头(以空格作为间隔):"<<endl;
		for(int i=0;i<this->arcnum;i++){
			cin>>weight>>s1>>s2;
			int j=Locate(s1);//弧尾
			int k=Locate(s2);//弧头
			ArcPointer pt=new ArcNode;
			pt->adjvex=k;  pt->weight=weight;
			pt->nextarc=this->graph[j].firstarc;
			this->graph[j].firstarc=pt;
		}
	}
	void CreateUDN(){
		VertexType s1,s2;
		int weight;
		cout<<"请输入各顶点的信息："<<endl;
		for(int i=0;i<this->vexnum;i++){
			cin>>this->graph[i].data;
			this->graph[i].firstarc=NULL;//注意，指针在使用之前一定要先初始化，即使是赋值为空!!
		}
		cout<<"请输入每条弧(边)的权值和顶点(以空格作为间隔):"<<endl;
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
		this->visited[i]=true;//置标志位为true
		ArcPointer pt=this->graph[i].firstarc;
		while(pt){
			if(!visited[pt->adjvex])//当前顶点未被访问过
				this->DFStraverse(pt->adjvex);//递归调用
			pt=pt->nextarc;
		}
	}
public:
	void CreateGraph(){
		int k;
		cout<<"请输入图的类型1：";
		cin>>k;
		cout<<"请输入顶点数与弧数："<<endl;
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
	void DeleteVex(int k){//删除某一顶点及其相关的边
		VNP pt=new VNode[this->vexnum-1];
		for(int i=0,j=0;j<this->vexnum;j++){
			if(j==k){//注意，不要写成i==k，易错!!
				ArcNode *ps=this->graph[j].firstarc,*pr;
				while(ps){
					pr=ps->nextarc;
					delete ps;
					ps=pr;
					this->arcnum--;//一定要注意，弧数要做相应的修改!!
				}
				continue;//注意，此时需要跳过后面语句的执行
			}
			pt[i]=this->graph[j];
			ArcNode *ps=pt[i].firstarc,*pr;//pr指向ps的前驱!!
			while(ps){
				//需要修改每条弧相应的顶点位置和删除顶点为k的弧
				if(ps->adjvex==k){//当前弧的顶点是k，需要删除
					if(ps==pt[i].firstarc){//注意，如果待删除的弧是第一个邻接结点，需要特殊处理
						pt[i].firstarc=ps->nextarc;
						delete ps;
						this->arcnum--;
						ps=pt[i].firstarc;//注意，ps需要指向下一条弧
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
						ps->adjvex--;//注意!!!
					pr=ps;//用pr记录前驱，便于执行删除操作!!
					ps=ps->nextarc;
				}
			}
			i++;//注意!!
		}
		this->vexnum--;//注意!!
		delete[] this->graph;//释放原图内存空间
		this->graph=pt;
	}
	void DFSTraverse(){//深度优先遍历
		this->visited=new bool[this->vexnum];
		for(int i=0;i<this->vexnum;i++)
			this->visited[i]=false;
		DFStraverse(0);//注意，函数调用结束时，与V1顶点有路径相通的顶点都会被访问到，
		cout<<endl;   //若此图中尚有为被访问的顶点，则要选中该顶点，继续递归调用!!!
	}
};