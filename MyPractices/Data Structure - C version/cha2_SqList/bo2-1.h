/* bo2-1.c ˳���ʾ�����Ա�(�洢�ṹ��c2-1.h����)�Ļ�������(12��) */
 Status InitList(SqList *L) /* �㷨2.3 */
 { /* �������������һ���յ�˳�����Ա� */
   (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
     exit(OVERFLOW); /* �洢����ʧ�� */
   (*L).length=0; /* �ձ���Ϊ0 */
   (*L).listsize=LIST_INIT_SIZE; /* ��ʼ�洢���� */
   return OK;
 }

 Status DestroyList(SqList *L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L */
   free((*L).elem);
   (*L).elem=NULL;
   (*L).length=0;
   (*L).listsize=0;
   return OK;
 }

 Status ClearList(SqList *L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   (*L).length=0;
   return OK;
 }

 Status ListEmpty(SqList L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   return L.length;
 }

 Status GetElem(SqList L,int i,ElemType *e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
   /* �����������e����L�е�i������Ԫ�ص�ֵ */
   if(i<1||i>L.length)
     return FALSE;
   *e=*(L.elem+i-1);
   return OK;
 }

 int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType)){
	 int i=1;
	 ElemType *p=L.elem;
	 while(i<=L.length&&!((*compare)(*p++,e)))
		 i++;
	 if(i<=L.length)return i;
	 else return 0;
 }

 Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� */
   /*           �������ʧ�ܣ�pre_e�޶��� */
   int i=2;
   ElemType *p=L.elem+1;
   while(i<=L.length&&*p!=cur_e)
   {
     p++;
     i++;
   }
   if(i>L.length)
     return FALSE;
   else
   {
     *pre_e=*--p;
     return OK;
   }
 }

 Status NextElem(SqList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� */
   /*           �������ʧ�ܣ�next_e�޶��� */
   int i=1;
   ElemType *p=L.elem;
   while(i<L.length&&*p!=cur_e)
   {
     i++;
     p++;
   }
   if(i==L.length)
     return FALSE;
   else
   {
     *next_e=*++p;
     return OK;
   }
 }

 Status ListInsert(SqList *L,int i,ElemType e){
	 ElemType *newbase,*q,*p;
	 if(i>(*L).length+1||i<1)
		 return ERROR;
	 if((*L).length==(*L).listsize){
		 newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
		 if(newbase==NULL)
			 exit(FALSE);
		 (*L).elem=newbase;
		 (*L).listsize+=LISTINCREMENT;
	 }
	 q=(*L).elem+i-1;;
	 p=(*L).elem+(*L).length-1;
     while(q<=p){
		 *(p+1)=*p;
		 p--;
	 }
	 *q=e;
	 (*L).length++;
	 return OK;
 }

 

 Status ListTraverse(SqList L,void(*vi)(ElemType*))
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ�� */
   /*           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ */
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
    (*vi)(p++);
   printf("\n");
   return OK;
 }