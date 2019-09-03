 /* bo3-1.c 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
 Status InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
 }

Status GetTop(SqStack S,SElemType *e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

Status Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return OK;
 }

Status Pop(SqStack *S,SElemType *e){
	if((*S).base==(*S).top)
		return ERROR;
	*e=*(--(*S).top);
	return OK; 
}

Status DestroyStack(SqStack *S){
	free((*S).base);
	(*S).base=NULL;
	(*S).top=NULL;
	(*S).stacksize=0;
	return OK;
}

Status ClearStack(SqStack *S){
	(*S).top=(*S).top;
	return OK;
}

Status StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 }

 int StackLength(SqStack S)
 { /* 返回S的元素个数，即栈的长度 */
   return S.top-S.base;
 }//注意一下！！！！

 Status StackTraverse(SqStack S,Status(*visit)(SElemType)){
	 while(S.base<S.top){
		 visit(*S.base);
		 S.base++;
	 }
	 printf("\n");
	 return OK;
 }
