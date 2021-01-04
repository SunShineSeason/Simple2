class Huffmantree{
private:
	int n;//��¼Ҷ�ӽ���ֵ
	HuffmanTree T;
	HuffmanCode HC;
	void select(int i,int &p,int &q){//��1��i-1��������ҳ�Ȩֵ��С�����������!!
		int s1,s2;
		s1=s2=INT_MAX;//ȡ�궨���е������!!
		for(int j=1;j<i;j++){
			if(T[j].parent!=0)//���Ǹ����
				continue;
			if(T[j].weight<=s1 && T[j].weight<=s2){//����������Ԫ�ض�С����������н�С��Ȩֵ
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
		this->T=new HTNode[m];//0�ŵ�Ԫ����!
		for(int i=1;i<=n;i++,w++){//��ʼ��
			T[i].weight=*w;
			T[i].lchild=T[i].rchild=T[i].parent=0;
		}
		for(int i=n+1;i<m;i++){
			T[i].parent=T[i].lchild=T[i].rchild=T[i].weight=0;
		}
		for(int i=n+1;i<m;i++){//�����շ�����
			select(i,p1,p2);
			T[i].lchild=p1;T[i].rchild=p2;
			T[i].weight=T[p1].weight+T[p2].weight;//ע�⣬Ҫ�޸�Ȩֵ!!
			T[p1].parent=i;T[p2].parent=i;
		}
		for(int i=1;i<2*n;i++)
			cout<<T[i].weight<<"  ";
		cout<<endl;
		
		//��շ�������
		int pt;
		this->HC=new string[n+1];
		for(int k=1;k<=n;k++){//��ÿ��Ҷ�ӽڵ����������
			int i=k;
			while(T[i].parent!=0){//���Ǹ����
				pt=T[i].parent;
				if(T[pt].lchild==i)//������Ϊ0��������Ϊ1
					HC[k]='0'+HC[k];
				else
					HC[k]='1'+HC[k];
				i=pt;	
			}
		}
	}
	void PreorderTraverse(int i){
		if(i!=0){//ע������
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
		cout<<"������Ҷ�ӽڵ�ĸ�����";
		cin>>n;
		w=new int[n];//ע�⣬��̬������ڴ�ռ䷵�ص�ָ�벻�ǳ���ָ��!!!
		cout<<"�������Ҷ�ӽ���Ȩֵ:";
		for(int i=0;i<n;i++)
			cin>>w[i];
		this->HuffmanCoding(w);
	}
	void Traverse(){
		this->PreorderTraverse(2*n-1);
		cout<<endl;
	}
	void PrintCode(){//��ӡ���ַ��ĺշ�������
		for(int i=1;i<=n;i++)
			cout<<HC[i]<<endl;
	}
};