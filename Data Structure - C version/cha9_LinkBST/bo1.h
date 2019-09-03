 /* bo9-2.c 动态查找表(二叉排序树)的基本操作(8个) */
 typedef int KeyType; /* 设关键字域为整型 */
 typedef struct
 {
   KeyType key;
   int others;
 } ElemType; /* 数据元素类型 */

 typedef ElemType TElemType;
 #include"c1.h"

Status InitDSTable(BiTree *DT) /* 同bo6-2.c */
 { /* 操作结果: 构造一个空的动态查找表DT */
   *DT=NULL;
   return OK;
 }

 void DestroyDSTable(BiTree *DT) /* 同bo6-2.c */
 { /* 初始条件: 动态查找表DT存在。操作结果: 销毁动态查找表DT */
   if(*DT) /* 非空树 */
   {
     if((*DT)->lchild) /* 有左孩子 */
       DestroyDSTable(&(*DT)->lchild); /* 销毁左孩子子树 */
     if((*DT)->rchild) /* 有右孩子 */
       DestroyDSTable(&(*DT)->rchild); /* 销毁右孩子子树 */
     free(*DT); /* 释放根结点 */
     *DT=NULL; /* 空指针赋0 */
   }
 }

 BiTree SearchBST(BiTree T,KeyType key)
 { /* 在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素， */
   /* 若查找成功，则返回指向该数据元素结点的指针,否则返回空指针。算法9.5(a) */
   if((!T)||EQ(key,T->data.key))
     return T; /* 查找结束 */
   else if LT(key,T->data.key) /* 在左子树中继续查找 */
     return SearchBST(T->lchild,key);
   else
     return SearchBST(T->rchild,key); /* 在右子树中继续查找 */
 }

 Status SearchBST1(BiTree T,KeyType key,BiTree f,BiTree *p){
   //f为双亲指针!!!
   /* 在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找 */
   /* 成功，则指针p指向该数据元素结点，并返回TRUE，否则指针p指向查找路径上 */
   /* 访问的最后一个结点并返回FALSE,指针f指向T的双亲，其初始调用值为NULL */
	 if(!T){ 
		 *p=f;
		 return FALSE;
	 }
	 else if(key==T->data.key){
		 *p=T;
		 return TRUE;
	 }
	 else if(key<T->data.key)
		 return SearchBST1(T->lchild,key,T,p);
	 else
		 return SearchBST1(T->rchild,key,T,p);
 }

 Status InsertBST(BiTree *T,ElemType e){
	/* 当二叉排序树T中不存在关键字等于e.key的数据元素时，插入e并返回TRUE， */
   /* 否则返回FALSE。算法9.6(改) */
     BiTree p,s;
	 if(!SearchBST1(*T,e.key,NULL,&p))
	 {
		 s=(BiTree)malloc(sizeof(BiTNode));
		 s->lchild=NULL;
		 s->rchild=NULL;
		 s->data=e;
		 if(!p)
			 *T=s;//被插结点s为根结点
		 else 
			 if LT(e.key,p->data.key)
                p->lchild=s; /* 被插结点*s为左孩子 */
         else
             p->rchild=s; /* 被插结点*s为右孩子 */
         return TRUE;
	 }
	 else 
		 return FALSE;
 }

