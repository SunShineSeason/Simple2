class HeapSort{
private:
	SqList list;
	int Select(int i,int k){
		int min=i;
		for(int j=0;j<2;j++)
			if(i*2+j<=k && list.r[i*2+j].key<list.r[min].key)
				min=i*2+j;
		return min;
	}
	void Filter(int i,int j){
		//����ȫ�����������Ϊi�Ľ���γɵĶѽ���ɸѡ
		int min=this->Select(i,j);
		if(i!=min){
			list.r[0]=list.r[min];
			list.r[min]=list.r[i];
			list.r[i]=list.r[0];
			if(min<=(j/2))//minΪ��Ҷ�ӽ����ţ���Ҫ��������ɸѡ!
				this->Filter(min,j);
		}
	}
public:
	void CreateList(){
		cout<<"�����ĳ��ȣ�"<<endl;
		cin>>list.length;
		list.r=new RedType[list.length+1];//0�ŵ�Ԫ�����ڱ�
		for(int i=1;i<=list.length;i++)
			cin>>list.r[i].key;
	}
	void CreateHeap(){
		int i=list.length/2,j=list.length;
		for(;i>0;i--){
			this->Filter(i,j);
		}
		while(j){
			list.r[0]=list.r[1];
			list.r[1]=list.r[j];
			list.r[j]=list.r[0];
			j--;
			this->Filter(1,j);
		}
	}
	void print(){
		for(int i=1;i<=list.length;i++)
			cout<<list.r[i].key<<"  ";
		cout<<endl;
	}
};