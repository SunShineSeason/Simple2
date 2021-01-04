Status InitQueue(LinkQueue *Q){
	(*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));//���巽��,ͬʱ�����������ٿռ��ܴ洢����������
	if(!(*Q).front)
		exit(OVERFLOW);
    (*Q).front->next=NULL;//Ҫע�⣡��ʼ��ʱָ�������Ϊ��
	return OK;
}

Status DestroyQueue(LinkQueue *Q)
 { /* ���ٶ���Q(���ۿշ����) */
   while((*Q).front)
   {
     (*Q).rear=(*Q).front->next;//ֱ��ʹ����βָ�룬����
     free((*Q).front);
     (*Q).front=(*Q).rear;
   }
   return OK;
 }//�����ǳ�����

Status ClearQueue(LinkQueue *Q){
	QueuePtr p,q;
	p=(*Q).front->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	(*Q).rear=(*Q).front;
	(*Q).front->next=NULL;
	return OK;
}//�����ҲҪ��գ�����ͷ��㣨��ɾ����ͬ�ĵط���

Status QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear)
		return TRUE;
	else 
		return FALSE;
}

int QueueLength(LinkQueue Q){
	int i=0;
	QueuePtr p=Q.front->next;
    if(p){
		p=p->next;
		i++;
	}
    return i;
}

Status GetHead(LinkQueue Q,QElemType *e){
	QueuePtr p;
	if(QueueEmpty(Q))
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) /* �洢����ʧ�� */
     exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	(*Q).rear->next=p;
	(*Q).rear=p;
	return OK;
}//��Ҫ����

 Status DeQueue(LinkQueue *Q,QElemType *e){	
	QueuePtr p;
	if((*Q).front==(*Q).rear)
		return ERROR;
	p=(*Q).front->next;
    *e=p->data;
	(*Q).front->next=p->next;
	if((*Q).rear==p)
		(*Q).rear=(*Q).front;
	free(p);
	return OK;
}//Ҫ���ǵ�ֻ��һ��Ԫ�ص����

 Status QueueTraverse(LinkQueue Q,void(*visit)(QElemType)){
	QueuePtr p=Q.front->next;
	while(p){
		 visit(p->data);
		 p=p->next;
	}
	printf("\n");
	return OK;
}




