class Sq_queue{
private:
	SqQueue queue;
public:
	Status InitQueue(){
		queue.base=new QElemType[MAXSIZE];//分配内存
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
		queue.rear=queue.top=0;//注意，清空队列只要移动指针即可!
		return true;
	}
	Status QueueEmpty(){//注意判断队列为空和为满的条件!
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
		if((queue.rear-queue.top+1)%MAXSIZE==0)//队列满
			return false;
		queue.base[queue.rear]=e;
		queue.rear=(queue.rear+1)%MAXSIZE;
		return true;
	}
	Status DeQueue(QElemType &e){//出队列

	}
}