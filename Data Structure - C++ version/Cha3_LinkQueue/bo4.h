class Bank_Simulation{//银行排队事件模拟
private:
	EventList ev;
	Event en;
	Queue q[5];
	QElemType customer;
	int TotalTime,CustomerNum,CloseTime;
	int Minumum(){
		int i=1,length=0;
		for(int i=1;i<5;i++){
			if(q[i].Length())
		}
	}
public:
	void OpenForday(){
		this->TotalTime=0;
		this->CustomerNum=0;
		ev.InitList();//事件链表初始化!
		en.OccurTime=0;//第一个客户到达的时间为0
		en.NType=0;//设置事件类型
		ev.OrderInsert(en);
		for(int i=1;i<5;i++)
			this->q[i].InitQueue();//排队队列初始化!!
	}
	void CustomerArrived(){//处理客户到达事件
		int duringTime,interTime;
		Event et;
		++this->CustomerNum;
		duringTime=rand()%11;
		interTime=rand()%11;//删除0到10之间的随机数
		int t=en.OccurTime+interTime;//下一个客户到达的时间
		if(this->CloseTime>t){//客户到达时银行尚未关门
			et.NType=0;
			et.OccurTime=t;
			this->ev.OrderInsert(et);
		}

	}
};