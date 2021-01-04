class SqBitree{
	friend void DestroyNode(TElemType &e);//����һ����Ԫ����
private:
	SqBiTree bt;
	void (*visit)(TElemType &);//������һ��ָ�����!!
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
			bt[i]=Nil;//�궨����Nil����ʵ��ͨ����
		return true;
	}
	Status CreateBiTree(){
		//����δ������룬0��ʾ�ս��
		TElemType e;
		int i=0;
#if IsChar
		cout<<"���������ݣ��ո��ʾ�ս�㣬��#��Ϊ����:"<<endl;
		while((e=getchar())!='#'){
			if(e!=' '){
				if(i!=0 && bt[(i+1)/2-1]==Nil){//ע��˫�׽��ı�ʾ��������
					cout<<"������󣬸ý��˫�׽��Ϊ��"<<endl;
					return false;
				}
				else
					bt[i++]=e;
			}//Ϊ�ս��
			else
				bt[i++]=Nil;
		}
		return true;
#else
		cout<<"�������ݣ�0��ʾ�ս�㣬��000#������"<<endl;
		//ע�⣬ѭ�������Ժ���Ҫ������������Ϊ��Ч����
		while(cin>>e){//ע�⣬ִ�д���Ϊ��������!!
			if(e!=0){
				if(i!=0 && bt[(i+1)/2-1]==Nil){//ע�⣬�±��0��ʼ������Ŵ�1��ʼ!!
					cout<<"������󣬸ý��˫�׽��Ϊ��"<<endl;
					i++;
				}
				else
					bt[i++]=e;//iҪ�����Լ�
			}
			else
				bt[i++]=Nil;
		}
		cin.clear();//����������Ϊ��Ч
		while(cin.get()!='\n')
			continue;//cin.get()������û�в���������£���ȡ��һ���ַ�����ʹ���ַ��ǿո��Ʊ�����з�!!
		return true;
#endif
	}
#define ClearBiTree InitBiTree//��������ȫ��ͬ!
	int Depth(){
		int i,j=0;
		for(i=MAXSIZE-1;i>=0;i--)
			if(bt[i]!=Nil)
				break;
		i++;//��������е���Ŷ�Ӧ
		for(;i>=pow((double)2,(double)j);j++){}
		return j;
	}
	TElemType Root(){
		return bt[0];
	}
	TElemType Value(position pt){
		return bt[(int)pow(2,(double)pt.level-1)+pt.order-2];//ע�⣬�����±����Ϊ���ͻ�ö������!!
	}
	Status Assign(position pt,TElemType e){
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-1;//psΪ�ý���ڶ������е����
		if(e==Nil && (bt[ps*2-1]!=Nil || bt[ps*2]!=Nil)){//ע���Ƿ�ý���Ƿ��к���
			cout<<"�ý����ں��ӣ�����޷��ÿ�"<<endl;
			return false;
		}
		if(e!=Nil && bt[ps/2-1]==Nil){//ע�⸳�ǿ�ֵʱ�ýڵ�˫�׽�㲻��Ϊ��!!
			cout<<"�ý���˫�׽�㲻���ڣ����ֻ�ܸ���ֵ"<<endl;
			return false;
		}
		bt[ps-1]=e;
		return true;
	}
	TElemType Parent(position pt){
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-1;//psΪ�ý���ڶ������е����
		if(ps!=1)
			return bt[ps/2-1];
		else
			return Nil;

	}
	TElemType LeftBrother(position pt){
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-1;//psΪ�ý���ڶ������е����
		if(ps!=1 && ps%2==1)
			return bt[ps-2];
		else
			return Nil;
	}
	void PreOrderTraverse(void(*visit)(TElemType &e)){//��ָ��ĽǶ���⺯��
		this->visit=visit;//����ָ�븳ֵ!!
		if(bt[0]!=Nil)
			PreTraverse(0);//�Ӹ���㿪ʼ�����������
		cout<<endl;
	}
	Status LevelTraverse(void (*visit)(TElemType &e)){//ע�ⷽ�����ǳ�����ȴӺ���ǰ�������ҵ����һ���ǿս��
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
		//ɾ��e��ָ��Ľ�����������������
		//���Բ��õݹ��ջ��ʵ���㷨������ʹ�õݹ��㷨
		visit=DestroyNode;
		int ps=(int)pow(2,(double)pt.level-1)+pt.order-2;//psΪ�ý���������е����
		ps=ps*2+1+LR;//0��ʾ��1��ʾ��
		if(bt[ps]!=Nil)//����������������Ϊ��
			PostTraverse(ps);
		return true;
	}
};
	void DestroyNode(TElemType &e){
		e=Nil;
	}