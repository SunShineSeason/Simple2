class SqBitree{
	friend void DestroyNode(TElemType &e);//定义一个友元函数
private:
	SqBiTree bt;
	void (*visit)(TElemType &);//声明了一个指针变量!!
	void PreTraverse(int i){
		if(bt[i]!=Nil){
			visit(bt[i]);
			if(bt[i*2+1]!=Nil)
				PreTraverse(i*2+1);
			if(bt[i*2+2]!=Nil)
				PreTraverse(i*2+2);
		}
	}
	void PostTraverse(int i){
		if(bt[i]!=Nil){
			if(bt[i*2+1]!=Nil)
				this->PostTraverse(i*2+1);
			if(bt[i*2+2]!=Nil)
				this->PostTraverse(i*2+2);
			visit(bt[i]);
		}
	}
public:
	Status InitBiTree(){
		for(int i=0;i<MAXSIZE;i++)
			bt[i]=Nil;//宏定义了Nil，以实现通用性
		return true;
	}
	Status CreateBiTree(){
		//按层次次序输入，0表示空结点
		TElemType e;
		int i=0;
#if IsChar
		cout<<"请输入数据，空格表示空结点，以#号为结束:"<<endl;
		while((e=getchar())!='#'){
			if(e!=' '){
				if(i!=0 && bt[(i+1)/2-1]==Nil){//注意双亲结点的表示方法！！
					cout<<"输入错误，该结点双亲结点为空"<<endl;
					return false;
				}
				else
					bt[i++]=e;
			}//为空结点
			else
				bt[i++]=Nil;
		}
		return true;
#else
		cout<<"输入数据，0表示空结点，以000#结束："<<endl;
		//注意，循环结束以后需要将输入流重置为有效！！
		while(cin>>e){//注意，执行次序为从左向右!!
			if(e!=0){
				if(i!=0 && bt[(i+1)/2-1]==Nil){//注意，下标从0开始，而序号从1开始!!
					cout<<"输入错误，该结点双亲结点为空"<<endl;
					i++;
				}
				else
					bt[i++]=e;//i要进行自加
			}
			else
				bt[i++]=Nil;
		}
		cin.clear();//输入流重置为有效
		while(cin.get()!='\n')
			continue;//cin.get()函数在没有参数的情况下，读取下一个字符，即使该字符是空格，制表符或换行符!!
		return true;
#endif
	}
#define ClearBiTree InitBiTree//两函数完全相同!
	int Depth(){
		int i,j=0;
		for(i=MAXSIZE-1;i>=0;i--)
			if(bt[i]!=Nil)
				break;
		i++;//与二叉树中的序号对应
		for(;i>=pow((double)2,(double)j);j++){}
		return j;
	}
	TElemType Root(){
		return bt[0];
	}
	TElemType Value(position pt){
		return bt[(int)pow(2,(double)pt.level-1)+pt.order-2];//注意，数组下标必须为整型或枚举类型!!
	}
	Status Assign(position pt,TElemType e){
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-1;//ps为该结点在二叉树中的序号
		if(e==Nil && (bt[ps*2-1]!=Nil || bt[ps*2]!=Nil)){//注意是否该结点是否有孩子
			cout<<"该结点存在孩子，因此无法置空"<<endl;
			return false;
		}
		if(e!=Nil && bt[ps/2-1]==Nil){//注意赋非空值时该节点双亲结点不能为空!!
			cout<<"该结点的双亲结点不存在，因此只能赋空值"<<endl;
			return false;
		}
		bt[ps-1]=e;
		return true;
	}
	TElemType Parent(position pt){
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-1;//ps为该结点在二叉树中的序号
		if(ps!=1)
			return bt[ps/2-1];
		else
			return Nil;

	}
	TElemType LeftBrother(position pt){
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-1;//ps为该结点在二叉树中的序号
		if(ps!=1 && ps%2==1)
			return bt[ps-2];
		else
			return Nil;
	}
	void PreOrderTraverse(void(*visit)(TElemType &e)){//从指针的角度理解函数
		this->visit=visit;//函数指针赋值!!
		if(bt[0]!=Nil)
			PreTraverse(0);//从根结点开始进行先序遍历
		cout<<endl;
	}
	Status LevelTraverse(void (*visit)(TElemType &e)){//注意方法，非常巧妙，先从后往前遍历，找到最后一个非空结点
		int i;
		for(i=MAXSIZE-1;i>=0;i--)
			if(bt[i]!=Nil)
				break;
		for(int j=0;j<=i;j++)
			visit(bt[j]);
		cout<<endl;
		return true;
	}
	Status DeleteBiTree(position pt,int LR){
		//删除e所指向的结点的左子树或右子树
		//可以采用递归或栈来实现算法，这里使用递归算法
		visit=DestroyNode;
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-2;//ps为该结点在数组中的序号
		ps=ps*2+1+LR;//0表示左，1表示右
		if(bt[ps]!=Nil)//左子树或右子树不为空
			PostTraverse(ps);
		return true;
	}
};
	void DestroyNode(TElemType &e){
		e=Nil;
	}