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
		head->next=NULL;//ע�⣬Ҫ�����ָ����Ϊ��
		return true;
	}
	Status InsFirst(){}//ע������Ϊ��ʱҪ�޸�βָ��
	Status DelFirst(){
		Link ps=head->next;
		if(ps){
			head->next=ps->next;
			if(ps==tail)
				tail=head;
			delete ps;
			len--;//����Ҫע���޸�
			return true;
		}
		else 
			return false;
	}

}