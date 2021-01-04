typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*Linklist;

class LinkList{
private:
	Linklist list;
public:
	Status InitList(){
		list=new LNode;
		list->next=NULL;//�����þֲ���������!!
		return true;
	}
	Status DestroyList(){
		Linklist pointer=list;
		while(list){
			list=pointer->next;
			delete pointer;
			pointer=list;
		}	
		return true;
	}
	Status ClearList(){
		Linklist next,pointer=list->next;
		while(pointer){
			next=pointer->next;
			delete pointer;
			pointer=next;
		}
		list->next=NULL;
		return true;
	}
	int Listlength(){
		int length=0;
		Linklist pointer=list->next;
		while(pointer){
			length++;
			pointer=pointer->next;
		}
		return length;
	}
	ElemType GetElem(int i){
		if(i<1|| i>this->Listlength())
			return 0;
		else{
			Linklist pointer=list;
			for(int k=0;k<i;k++){
				pointer=pointer->next;
			}
			return pointer->data;
		}
	}
	int locateElem(ElemType e,Status (*ps)(ElemType,ElemType)){
		Linklist pointer=list->next;
		int i=1;
		while(pointer && !(*ps)(pointer->data,e)){ //Ҳ���Խ���벿�ֵ�����תΪ�������
			pointer=pointer->next;
			i++;
		}
		if(pointer)
			return i;
		else
			return 0;
	}
	ElemType PriorElem(ElemType cur_e){
		Linklist ps,pointer=list->next;
		while(pointer->next){  //ע���������ǳ������
			ps=pointer->next;
			if(ps->data==cur_e)
				return pointer->data;
			pointer=ps;
		}
		return 0;
	}
	Status ListInsert(int i,ElemType e){
		if(i<1 || i>this->Listlength()+1)
			return false;
		Linklist ps=list;
		for(int k=1;k<i;k++){
			ps=ps->next;
		}
		Linklist pt=new LNode;
		pt->next=ps->next;
		pt->data=e;
		ps->next=pt;
		return true;
	}
	Status ListDelete(int i){
		int k=1;
		Linklist pointer=list->next,ps=list;//����ֻ��һ��ָ��ps
		while(pointer && k<i){
			ps=pointer;
			pointer=pointer->next;
			k++;
		}
		if(!pointer || i<k)
			return false;
		ps->next=pointer->next;
		delete pointer;
		return true;
	}
	Status ListTraverse(void (*visit)(ElemType)){
		Linklist pointer=list->next;
		while(pointer){
			visit(pointer->data);
			pointer=pointer->next;
		}
		cout<<endl;
		return true;
	}
	Status CreateList(int n){
		list=new LNode;
		list->next=NULL;//ע�⣬��������һ��
		Linklist pointer;
		for(int i=0;i<n;i++){
			pointer=new LNode;
			cin>>pointer->data;
			pointer->next=list->next;
			list->next=pointer;
		}
		return true;
	}
};