class Queue{
private:
	LinkQueue queue;
public:
	Status InitQueue(){//��ʼ�����У�������ͷ���
		queue.front=new QNode;
		queue.rear=queue.front;
		queue.front->next=NULL;
		return true;
	}
	Status Destroy(){
		QueuePtr ps;//���Բ�����ָ�룬ֱ��ʹ��βָ��
		while(queue.front){
			ps=queue.front->next;
			delete queue.front;
			queue.front=ps;
		}
		queue.rear=NULL;
		return true;
	}
	Status ClearQueue(){
		QueuePtr ps;
		queue.rear=queue.front->next;
		while(queue.rear){
			ps=queue.rear->next;
			delete queue.rear;
			queue.rear=ps;
		}
		queue.rear=queue.front;
		queue.front->next=NULL;//ע�⣬Ҫ�����ÿ�!!
		return true;
	}
	int Length(){
		int i=0;
		QueuePtr pt=queue.front->next;
		while(pt){
			i++;
			pt=pt->next;
		}
		return i;
	}
	Status EnQueue(QElemType e){
		QueuePtr ps=new QNode;
		queue.rear->next=ps;
		ps->data=e;
		ps->next=NULL;
		queue.rear=ps;
		return true;
	}
	Status DeQueue(QElemType &e){
		QueuePtr ps=queue.front->next;
		if(ps){//���в�Ϊ��
			queue.front->next=ps->next;
			e=ps->data;
			if(!ps->next)
				queue.rear=queue.front;
			delete ps;
			return true;
		}
		else
			return false;
	}
	Status Traverse(void (*visit)(QElemType e)){
		if(queue.front==queue.rear)
			return false;
		QueuePtr ps=queue.front->next;
		while(ps){
			visit(ps->data);
			ps=ps->next;
		}
		return true;
	}
};