class DuLinkList{
private:
	DuLinklist list;
public:
	Status InitList(){
		list=new DuLNode;
		list->next=list->prior=list;
		return true;
	}
	Status DestroyList(){
		DuLinklist ps,pointer=list->next;
		while(pointer!=list){//从第一个结点开始删除
			ps=pointer;
			pointer=pointer->next;
			delete ps;
		}
		delete list;
		list=NULL;
		return true;
	}
	int LocateElem(ElemType e,Status(*compare)(ElemType,ElemType)){
		DuLinklist pointer=list->next;
		int i=1;
		while(pointer!=list){
			if(compare(pointer->data,e))
				return i;
			i++;
			pointer=pointer->next;
		}
		return 0;
	}
	ElemType NextElem(ElemType e){
		DuLinklist pointer=list->next;
		while(pointer->next!=list){
			if(pointer->data==e)
				return pointer->next->data;
			pointer=pointer->next;
		}
		return 0;
	}
	Status ListInsert(int i,ElemType e){//注意，插入情况比较复杂!!
		DuLinklist pointer=list;
		int m;
		for(m=1;m<i && pointer->next!=list;m++){//双向循环线性链表，循环结束时指针指向前驱
			 pointer=pointer->next;
		}
		if(m>i || (pointer->next==list && m<i))//注意，当链表为空时插入以及插入到表头时的特殊情况!!!
			return false;

		DuLinklist ps=pointer->next,pt=new DuLNode;
		pt->data=e;
		pointer->next=pt;
		pt->prior=pointer;
		pt->next=ps;
		ps->prior=pt;
		return true;
	}   
	void ListTraverse(void(*visit)(ElemType)){
		DuLinklist pointer=list->next;
		while(pointer!=list){
			visit(pointer->data);
			pointer=pointer->next;
		}
		cout<<endl;
	}
	Status Delete(int i){
		DuLinklist pointer=list->next;
		int m=1;
		for(;m<i && pointer->next!=list;m++){
			pointer=pointer->next;
		}
		if(m>i || (pointer->next==list && m<i))
			return false;
		
	}
};