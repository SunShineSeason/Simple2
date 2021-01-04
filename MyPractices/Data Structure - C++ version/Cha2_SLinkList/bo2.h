class SLinklist{
private:
	SLinkList list;
public:
	void InitList(){
		/* ����һ���յ�������ͷΪL�����һ����ԪL[MAXSIZE-1]�����൥Ԫ���� */
		/* һ������������ͷΪL�ĵ�һ����ԪL[0]����0����ʾ��ָ�� */
		int i;
		list[MAXSIZE-1].cur=0; /* L�����һ����ԪΪ������ı�ͷ */
		for(i=0;i<MAXSIZE-2;i++) /* �����൥Ԫ���ӳ���L[0]Ϊ��ͷ�ı������� */
			list[i].cur=i+1;
		list[MAXSIZE-2].cur=0;//����ͷ��㲻��������
    }
	Status ClearList(){  //ע�⣬�ص㣡
		int i=list[MAXSIZE-1].cur;
		list[MAXSIZE-1].cur=0;//������Ϊ��
		int m=0;
		while(list[m].cur){
			m=list[m].cur;
		}
		list[m].cur=i;
		return true;
	}
	Status ListEmpty(){
		if(list[MAXSIZE-1].cur)
			return true;
		else 
			return false;
	}
	int ListLength(){
		int i=0;
		int m=list[MAXSIZE-1].cur;
		while(m){
			i++;
			m=list[m].cur;
		}
		return i;
	}
	int LocateElem(ElemType e){
		int i=list[MAXSIZE-1].cur;
		while(i && list[i].data!=e){
			i=list[i].cur;
		}
		return i;//���ص����������е�λ��
	}
	ElemType PriorElem(ElemType e){
		int i=list[MAXSIZE-1].cur;
		while(list[i].cur){
			int m=list[i].cur;
			ElemType value=list[m].data;
			if(value==e)
				return list[i].data;
			i=list[i].cur;
		}
		return 0;
	}
	Status ListDelete(int i){
		int n=MAXSIZE-1;
		int m=1;
		while(m<i && list[n].cur){
			m++;
			n=list[n].cur;
		}
		if(!list[n].cur || m>i)
			return false;
		m=list[n].cur;
		list[n].cur=list[m].cur;//������Ҫ���ս�㣬����ɾ���Ľ��ҵ����ж��е��ײ�
		list[m].cur=list[0].cur;
		list[0].cur=m;
		return true;
	}
	int Apply(){
		if(list[0].cur){
			int i=list[0].cur;
			list[0].cur=list[i].cur;
			return i;
		}
		else
			return 0;
	}
	Status ListInsert(int i,ElemType e){
		int cur=Apply();//Ҫ������ж���������!
		if(!cur)
			return false;
		int n=MAXSIZE-1;
		int m=1;
		for(;m<i && n;m++){
			n=list[n].cur;
		}
		if(m>i || !n)
			return false;
		list[cur].data=e;
		list[cur].cur=list[n].cur;
		list[n].cur=cur;
		return true;
	}
	Status ListTraverse(void(*vi)(ElemType)){
		int i=list[MAXSIZE-1].cur;
		while(i){
			vi(list[i].data);
			i=list[i].cur;
		}
		cout<<endl;
		return true;
	}
};