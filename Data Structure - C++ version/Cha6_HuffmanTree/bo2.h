class Huffmantree{
private:
	int n;//记录叶子结点的值
	HuffmanTree T;
	HuffmanCode HC;
	void select(int i,int &p,int &q){//从1到i-1个结点中找出权值最小的两个根结点!!
		int s1,s2;
		s1=s2=INT_MAX;//取宏定义中的无穷大!!
		for(int j=1;j<i;j++){
			if(T[j].parent!=0)//不是根结点
				continue;
			if(T[j].weight<=s1 && T[j].weight<=s2){//比两个数据元素都小，或等于其中较小的权值
				if(s1>s2){
					s1=T[j].weight;
					p=j;
				}
				else{
					s2=T[j].weight;
					q=j;
				}
			}
			else
				if(T[j].weight>s1 && T[j].weight<s2){
					s2=T[j].weight;
					q=j;
				}
				else
					if((T[j].weight<s1 && T[j].weight>s2)){
						s1=T[j].weight;
						p=j;
					}
		}
	}
	void HuffmanCoding(int *w){
		int m=2*n,p1,p2;
		this->T=new HTNode[m];//0号单元不用!
		for(int i=1;i<=n;i++,w++){//初始化
			T[i].weight=*w;
			T[i].lchild=T[i].rchild=T[i].parent=0;
		}
		for(int i=n+1;i<m;i++){
			T[i].parent=T[i].lchild=T[i].rchild=T[i].weight=0;
		}
		for(int i=n+1;i<m;i++){//构建赫夫曼树
			select(i,p1,p2);
			T[i].lchild=p1;T[i].rchild=p2;
			T[i].weight=T[p1].weight+T[p2].weight;//注意，要修改权值!!
			T[p1].parent=i;T[p2].parent=i;
		}
		for(int i=1;i<2*n;i++)
			cout<<T[i].weight<<"  ";
		cout<<endl;
		
		//求赫夫曼编码
		int pt;
		this->HC=new string[n+1];
		for(int k=1;k<=n;k++){//从每个叶子节点逆向求编码
			int i=k;
			while(T[i].parent!=0){//不是根结点
				pt=T[i].parent;
				if(T[pt].lchild==i)//左子树为0，右子树为1
					HC[k]='0'+HC[k];
				else
					HC[k]='1'+HC[k];
				i=pt;	
			}
		}
	}
	void PreorderTraverse(int i){
		if(i!=0){//注意条件
			cout<<T[i].weight<<"  ";
			PreorderTraverse(T[i].lchild);
			PreorderTraverse(T[i].rchild);
		}
		else
			cout<<0<<"  ";
	}
public:
	void CreateHuffman(){
		int *w;
		cout<<"请输入叶子节点的个数：";
		cin>>n;
		w=new int[n];//注意，动态分配的内存空间返回的指针不是常量指针!!!
		cout<<"输入各个叶子结点的权值:";
		for(int i=0;i<n;i++)
			cin>>w[i];
		this->HuffmanCoding(w);
	}
	void Traverse(){
		this->PreorderTraverse(2*n-1);
		cout<<endl;
	}
	void PrintCode(){//打印各字符的赫夫曼编码
		for(int i=1;i<=n;i++)
			cout<<HC[i]<<endl;
	}
};