class SLinklist{
private:
	SLinkList list;
public:
	void InitList(){
		/* 构造一个空的链表，表头为L的最后一个单元L[MAXSIZE-1]，其余单元链成 */
		/* 一个备用链表，表头为L的第一个单元L[0]，“0”表示空指针 */
		int i;
		list[MAXSIZE-1].cur=0; /* L的最后一个单元为空链表的表头 */
		for(i=0;i<MAXSIZE-2;i++) /* 将其余单元链接成以L[0]为表头的备用链表 */
			list[i].cur=i+1;
		list[MAXSIZE-2].cur=0;//两个头结点不分配数据
    }
	Status ClearList(){  //注意，重点！
		int i=list[MAXSIZE-1].cur;
		list[MAXSIZE-1].cur=0;//链表置为空
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
		return i;//返回的是在数组中的位置
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
		list[n].cur=list[m].cur;//接下来要回收结点，将被删除的结点挂到空闲队列的首部
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
		int cur=Apply();//要先向空闲队列申请结点!
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