//什么时候用到LinkList *L,当需要对指向头结点的指针直接进行操作的时候
Status InitList(LinkList *L){
	*L=(LinkList)malloc(sizeof(struct LNode));//生成头结点，使L指向此头结点
	if(!*L)
		exit(OVERFLOW);
	(*L)->next=NULL;
	return OK;
}

Status DestroyList(LinkList *L){
	LinkList q;
	while(*L){
		q=(*L)->next;
        free(*L);
		*L=q;
	}
	return OK;
}//如何保证释放以后L为0

Status ClearList(LinkList L){
    LinkList p,q;
	p=L->next;
	while(p){
       q=p->next;
	   free(p);
	   p=q;
	}
	L->next=NULL;
	return OK;
}

Status ListEmpty(LinkList L){
    if(L->next)
		return FALSE;
	else 
		return TRUE;
}

int ListLength(LinkList L){
	LinkList p;
	int i=0;
	p=L->next;
	while(p){
       p=p->next;
	   i++;
	}
    return i;
}

 Status GetElem(LinkList L,int i,ElemType *e) /* 算法2.8 */
 { /* L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
   int j=1; /* j为计数器 */
   LinkList p=L->next; /* p指向第一个结点 */
   while(p&&j<i) /* 顺指针向后查找,直到p指向第i个元素或p为空 */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i) /* 第i个元素不存在 */{
	   return(FALSE);
       
   }
   *e=p->data; /* 取第i个元素 */
   return OK;
 }

int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
   int i=0;
   LinkList p=L->next;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* 找到这样的数据元素 */
       return i;
     p=p->next;
   }
   return 0;
 }//方法值得学习!!

Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e){
	LinkList p=L->next,q;
	while(p){
		q=p->next;
		if(!q)
			break;//保证p有后继
		if(q->data==cur_e){
			*pre_e=p->data;
			return OK;
		}
		p=p->next;
	}
	return FALSE;
}

Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e){
	LinkList p=L->next,q;
	while(p){
        q=p->next;
		if(!q)
			break;
		if(p->data==cur_e){
			*next_e=q->data;
			return OK;
		}
		p=q;
	}
	return FALSE;
}

Status ListInsert(LinkList L,int i,ElemType e){
	LinkList q=L,s;
	int j=0;
    while(q&&j<i-1){
		q=q->next;
		j++;
	}//如何寻找第i-1个结点,重点！
    if(i<1||!q)
		return ERROR;
	s=(LinkList)malloc(sizeof(struct LNode));
	s->data=e;
	s->next=q->next;
	q->next=s;
	return OK;
}//注意，函数调用结束以后，用malloc函数分配的存储空间不会被释放！！

Status ListDelete(LinkList L,int i,ElemType *e){
    LinkList q=L,s;
    int j=0;
	while(j<i-1&&q->next){
		q=q->next;
		j++;
	}
	if(i<1||!q->next)
		return ERROR;//条件设置非常巧妙
	s=q->next;
	q->next=s->next;
	*e=s->data;
	free(s);
	return OK;
}

Status ListTraverse(LinkList L,void(*visit)(ElemType*)){
	LinkList p=L->next;
	while(p){
		visit(&(p->data));
		p=p->next;
	}
	printf("\n");
	return OK;
}
void MergeList(LinkList La,LinkList *Lb,LinkList *Lc){
    LinkList pa,pb,pc;
	pa=La->next;
	pb=(*Lb)->next;
    *Lc=La;
	pc=La;
    while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(*Lb);
	*Lb=NULL;
}


