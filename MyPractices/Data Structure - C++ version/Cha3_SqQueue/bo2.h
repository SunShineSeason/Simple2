class Sq_queue{
private:
	SqQueue queue;
public:
	Status InitQueue(){
		queue.base=new QElemType[MAXSIZE];//�����ڴ�
		queue.rear=queue.top=0;
		return true;
	}
	Status DestroyQueue(){
		delete[] queue.base;
		queue.base=NULL;
		queue.rear=queue.top=0;
		return true;
	}
	Status CleatQueue(){
		queue.rear=queue.top=0;//ע�⣬��ն���ֻҪ�ƶ�ָ�뼴��!
		return true;
	}
	Status QueueEmpty(){//ע���ж϶���Ϊ�պ�Ϊ��������!
		if(queue.top==queue.rear)
			return true;
		return false;
	}
	Status GetHead(QElemType &e){
		if(!this->QueueEmpty()){
			e=queue.base[queue.top];
			return true;
		}
		else 
			return false;
	}
	int length(){
		return (queue.rear-queue.top+MAXSIZE)%MAXSIZE;
	}
	Status EnQueue(QElemType e){
		if((queue.rear-queue.top+1)%MAXSIZE==0)//������
			return false;
		queue.base[queue.rear]=e;
		queue.rear=(queue.rear+1)%MAXSIZE;
		return true;
	}
	Status DeQueue(QElemType &e){//������

	}
}