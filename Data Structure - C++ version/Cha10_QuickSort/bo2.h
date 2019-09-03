class QuickSort{
private:
	SqList list;
	int Partition(int low,int high){//每一趟快速排序
		list.r[0]=list.r[low];
		while(low<high){
			if(list.r[low].key==list.r[0].key){//两个结构体变量不能直接比较是否相等
				while( list.r[high].key>=list.r[0].key && high>low )
				   high--;//从后往前找到小于枢轴记录的第一个记录
			}
			if(list.r[high].key==list.r[0].key){
				while(list.r[low].key<=list.r[0].key && high>low )
				   low++;
			}
			RedType pivotkey=list.r[high];
			list.r[high]=list.r[low];
			list.r[low]=pivotkey;
		}
		return low;
	}
	void Quicksort(int low,int high){
		int pivotkey=this->Partition(low,high);
		if(low<pivotkey-1)
			this->Quicksort(low,pivotkey-1);
		if(high>pivotkey+1)
			this->Quicksort(pivotkey+1,high);
	}
public:
	void CreateList(){
		cout<<"输入表的长度："<<endl;
		cin>>list.length;
		list.r=new RedType[list.length+1];//0号单元用作哨兵
		for(int i=1;i<=list.length;i++)
			cin>>list.r[i].key;
	}
	void quickSort(){
		this->Quicksort(1,this->list.length);
	}
	void print(){
		for(int i=1;i<=list.length;i++){
			cout<<list.r[i].key<<"  ";
		}
		cout<<endl;
	}
};