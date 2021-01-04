class ShellSort{
private:
	SqList list;
	vector<int> dt;
	void Sort(int space){
		for(int i=1;i<=list.length;i++){
			int j;
			list.r[0]=list.r[i];
			for(j=i-space;j>0 && list.r[j].key>list.r[0].key;j=j-space){
				list.r[j+space]=list.r[j];
			}
			list.r[j+space]=list.r[0];
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
	void Shellsort(){
		int space;
		cout<<"������ÿһ������ļ�ࣺ(����0����)";
		do{
			cin>>space;
			dt.push_back(space);
		}while(space!=0);
		for(int i=0;i<dt.size();i++)
			this->Sort(dt[i]);
	}
	void print(){
		for(int i=1;i<=list.length;i++){
			cout<<list.r[i].key<<"  ";
		}
		cout<<endl;
	}
};