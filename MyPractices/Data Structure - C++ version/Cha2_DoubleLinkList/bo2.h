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
		while(pointer!=list){//�ӵ�һ����㿪ʼɾ��
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
	Status ListInsert(int i,ElemType e){//ע�⣬��������Ƚϸ���!!
		DuLinklist pointer=list;
		int m;
		for(m=1;m<i && pointer->next!=list;m++){//˫��ѭ����������ѭ������ʱָ��ָ��ǰ��
			 pointer=pointer->next;
		}
		if(m>i || (pointer->next==list && m<i))//ע�⣬������Ϊ��ʱ�����Լ����뵽��ͷʱ���������!!!
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