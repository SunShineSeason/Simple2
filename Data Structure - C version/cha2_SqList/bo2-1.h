/* bo2-1.c 顺序表示的线性表(存储结构由c2-1.h定义)的基本操作(12个) */
 Status InitList(SqList *L) /* 算法2.3 */
 { /* 操作结果：构造一个空的顺序线性表 */
   (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
     exit(OVERFLOW); /* 存储分配失败 */
   (*L).length=0; /* 空表长度为0 */
   (*L).listsize=LIST_INIT_SIZE; /* 初始存储容量 */
   return OK;
 }

 Status DestroyList(SqList *L)
 { /* 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L */
   free((*L).elem);
   (*L).elem=NULL;
   (*L).length=0;
   (*L).listsize=0;
   return OK;
 }

 Status ClearList(SqList *L)
 { /* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
   (*L).length=0;
   return OK;
 }

 Status ListEmpty(SqList L)
 { /* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { /* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
   return L.length;
 }

 Status GetElem(SqList L,int i,ElemType *e)
 { /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
   /* 操作结果：用e返回L中第i个数据元素的值 */
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
 { /* 初始条件：顺序线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， */
   /*           否则操作失败，pre_e无定义 */
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
 { /* 初始条件：顺序线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， */
   /*           否则操作失败，next_e无定义 */
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
 { /* 初始条件：顺序线性表L已存在 */
   /* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */
   /*           vi()的形参加'&'，表明可通过调用vi()改变元素的值 */
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
    (*vi)(p++);
   printf("\n");
   return OK;
 }