//ʲôʱ���õ�LinkList *L,����Ҫ��ָ��ͷ����ָ��ֱ�ӽ��в�����ʱ��
Status InitList(LinkList *L){
	*L=(LinkList)malloc(sizeof(struct LNode));//����ͷ��㣬ʹLָ���ͷ���
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
}//��α�֤�ͷ��Ժ�LΪ0

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

 Status GetElem(LinkList L,int i,ElemType *e) /* �㷨2.8 */
 { /* LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
   int j=1; /* jΪ������ */
   LinkList p=L->next; /* pָ���һ����� */
   while(p&&j<i) /* ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ�� */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i) /* ��i��Ԫ�ز����� */{
	   return(FALSE);
       
   }
   *e=p->data; /* ȡ��i��Ԫ�� */
   return OK;
 }

int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
   int i=0;
   LinkList p=L->next;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* �ҵ�����������Ԫ�� */
       return i;
     p=p->next;
   }
   return 0;
 }//����ֵ��ѧϰ!!

Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e){
	LinkList p=L->next,q;
	while(p){
		q=p->next;
		if(!q)
			break;//��֤p�к��
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
	}//���Ѱ�ҵ�i-1�����,�ص㣡
    if(i<1||!q)
		return ERROR;
	s=(LinkList)malloc(sizeof(struct LNode));
	s->data=e;
	s->next=q->next;
	q->next=s;
	return OK;
}//ע�⣬�������ý����Ժ���malloc��������Ĵ洢�ռ䲻�ᱻ�ͷţ���

Status ListDelete(LinkList L,int i,ElemType *e){
    LinkList q=L,s;
    int j=0;
	while(j<i-1&&q->next){
		q=q->next;
		j++;
	}
	if(i<1||!q->next)
		return ERROR;//�������÷ǳ�����
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


