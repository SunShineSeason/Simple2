Status InitQueue(LinkQueue *Q){
	(*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));//定义方法,同时定义了所开辟空间能存储的数据类型
	if(!(*Q).front)
		exit(OVERFLOW);
    (*Q).front->next=NULL;//要注意！初始化时指针变量设为空
	return OK;
}

Status DestroyQueue(LinkQueue *Q)
 { /* 销毁队列Q(无论空否均可) */
   while((*Q).front)
   {
     (*Q).rear=(*Q).front->next;//直接使用了尾指针，方便
     free((*Q).front);
     (*Q).front=(*Q).rear;
   }
   return OK;
 }//方法非常棒！

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
}//各结点也要清空，保留头结点（与删除不同的地方）

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
	if(!p) /* 存储分配失败 */
     exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	(*Q).rear->next=p;
	(*Q).rear=p;
	return OK;
}//重要！！

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
}//要考虑到只有一个元素的情况

 Status QueueTraverse(LinkQueue Q,void(*visit)(QElemType)){
	QueuePtr p=Q.front->next;
	while(p){
		 visit(p->data);
		 p=p->next;
	}
	printf("\n");
	return OK;
}




