class Bank_Simulation{//�����Ŷ��¼�ģ��
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
		ev.InitList();//�¼������ʼ��!
		en.OccurTime=0;//��һ���ͻ������ʱ��Ϊ0
		en.NType=0;//�����¼�����
		ev.OrderInsert(en);
		for(int i=1;i<5;i++)
			this->q[i].InitQueue();//�ŶӶ��г�ʼ��!!
	}
	void CustomerArrived(){//����ͻ������¼�
		int duringTime,interTime;
		Event et;
		++this->CustomerNum;
		duringTime=rand()%11;
		interTime=rand()%11;//ɾ��0��10֮��������
		int t=en.OccurTime+interTime;//��һ���ͻ������ʱ��
		if(this->CloseTime>t){//�ͻ�����ʱ������δ����
			et.NType=0;
			et.OccurTime=t;
			this->ev.OrderInsert(et);
		}

	}
};