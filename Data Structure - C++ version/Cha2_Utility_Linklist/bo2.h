class UtLinklist{
private:
	Link head,tail;
	int len;
public:
	Status InitList(){
		head=tail=new LNode;
		head->next=NULL;
		len=0;
		return true;
	}
	Status DestroyList(){
		Link ps;
		while(head!=tail){
			ps=head->next;
			delete head;
			head=ps;
		}
		delete head;
		head=tail=NULL;
		len=0;
		return true;
	}
	Status ClearList(){
		Link ps=head->next,pt;
		while(ps){
			pt=ps->next;
			delete ps;
			ps=pt;
		}
		tail=head;
		head->next=NULL;//注意，要将后继指针置为空
		return true;
	}
	Status InsFirst(){}//注意链表为空时要修改尾指针
	Status DelFirst(){
		Link ps=head->next;
		if(ps){
			head->next=ps->next;
			if(ps==tail)
				tail=head;
			delete ps;
			len--;//长度要注意修改
			return true;
		}
		else 
			return false;
	}

}