Status InitBiTree(BiTree *T)
{
	*T=NULL;//因为没有设置头结点
	return OK;
}

void DestroyBiTree(BiTree *T)//递归算法!!
 { /* 初始条件: 二叉树T存在*/
	
	/*操作结果: 按后序遍历的顺序销毁二叉树T !!*/
	if(*T){
		if((*T)->lchild)
			DestroyBiTree(&(*T)->lchild);
		if((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T=NULL;
	}
 }//什么情况下可以用递归!!熟悉一下

 void CreateBiTree(BiTree *T)
 { /* 算法6.4:按先序次序输入二叉树中结点的值（可为字符型或整型，在主程中 */
   /* 定义），构造二叉链表表示的二叉树T。变量Nil表示空（子）树。有改动 */
   TElemType ch;
 #if CHAR
   scanf("%c",&ch);
 #else
   scanf("%d",&ch);
 #endif
   if(ch==Nil) /* 空 */
     *T=NULL;
   else
   {
     *T=(BiTree)malloc(sizeof(BiTNode));
     if(!(*T))
       exit(OVERFLOW);
     (*T)->data=ch; /* 生成根结点 */
     CreateBiTree(&(*T)->lchild); /* 构造左子树 */
     CreateBiTree(&(*T)->rchild); /* 构造右子树 */
   }
 }

Status BiTreeEmpty(BiTree T)
 { /* 初始条件: 二叉树T存在 */
   /* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
   if(T)
     return FALSE;
   else
     return TRUE;	
}

int BiTreeDepth(BiTree T)
 { /* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
   int i,j;
   if(!T)
     return 0;
   if(T->lchild)
     i=BiTreeDepth(T->lchild);
   else
     i=0;
   if(T->rchild)
     j=BiTreeDepth(T->rchild);
   else
     j=0;
   return i>j?i+1:j+1;
 }

TElemType Root(BiTree T)
 { /* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
   if(BiTreeEmpty(T))
     return Nil;
   else
     return T->data;
 }

 TElemType Value(BiTree p)
 { /* 初始条件: 二叉树T存在，p指向T中某个结点 */
   /* 操作结果: 返回p所指结点的值 */
   return p->data;
 }

 void Assign(BiTree p,TElemType value)
 { /* 给p所指结点赋值为value */
   p->data=value;
 }

 typedef BiTree QElemType; /* 设队列元素为二叉树的指针类型,这种方法技巧性很强!! */
 #include"c2.h"
 #include"bo3.h"
 TElemType Parent(BiTree T,TElemType e)
 { /* 初始条件: 二叉树T存在,e是T中某个结点 */
   /* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
   LinkQueue q;
   QElemType a;
   if(T) /* 非空树 */
   {
     InitQueue(&q); /* 初始化队列 */
     EnQueue(&q,T); /* 树根入队 */
     while(!QueueEmpty(q))
	 {
		 DeQueue(&q,&a);
         if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)//注意条件设置!!
			 return a->data;
		 else
		 {
			 if(a->lchild)
				 EnQueue(&q,a->lchild);
			 if(a->rchild)
				 EnQueue(&q,a->rchild);
		 }
	 }
   }//此循环相当于层序遍历!!!
   return Nil; /* 树空或没找到e */
 }
 
 BiTree Point(BiTree T,TElemType s)/* 返回二叉树T中指向元素值为s的结点的指针。另加 */
 {
     LinkQueue q;
	 QElemType a;
	 if(T)
	 {
		 InitQueue(&q);
		 EnQueue(&q,T);
         while(!QueueEmpty(q))
		 {
			 DeQueue(&q,&a);
			 if(a->data==s)
				 return a;
             if(a->lchild)
				 EnQueue(&q,a->lchild);
			 if(a->rchild)
				 EnQueue(&q,a->rchild);
		 }
	 }
	 return NULL;
 }//这种方法一定要熟练掌握!!!

 TElemType LeftChild(BiTree T,TElemType s)
{
	 LinkQueue q;
	 QElemType a;
	 if(T)
	 {
		 InitQueue(&q);
		 EnQueue(&q,T);
         while(!QueueEmpty(q))
		 {
			 DeQueue(&q,&a);
			 if(a->data==s&&a->lchild)
				 return a->lchild->data;
             if(a->lchild)
				 EnQueue(&q,a->lchild);
			 if(a->rchild)
				 EnQueue(&q,a->rchild);
		 }
	 }
	 return Nil;
 }

 TElemType LeftSibling(BiTree T,TElemType s)//层序遍历，返回左兄弟
 { 
	 LinkQueue q;
	 QElemType a;
	 if(T)
	 {
		 InitQueue(&q);
		 EnQueue(&q,T);
         while(!QueueEmpty(q))
		 {
			 DeQueue(&q,&a);
			 if(a->rchild&&a->rchild->data==s&&a->lchild)
				 return a->lchild->data;
             if(a->lchild)
				 EnQueue(&q,a->lchild);
			 if(a->rchild)
				 EnQueue(&q,a->rchild);
		 }
	 }
	 return Nil;
 }

 void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))//先序遍历
 {
	 if(T)
	 {
		 (*Visit)(T->data);
		 PreOrderTraverse(T->lchild,Visit);
		 PreOrderTraverse(T->rchild,Visit);
	 }
 }

 void InOrderTraverse(BiTree T,Status(*Visit)(TElemType))//中序遍历
 { 
   if(T)
   {
     InOrderTraverse(T->lchild,Visit); 
     Visit(T->data); 
     InOrderTraverse(T->rchild,Visit); 
   }
 }

 void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))//后序遍历
 {
	 if(T)
	 {
		 PostOrderTraverse(T->lchild,Visit);
		 PostOrderTraverse(T->rchild,Visit);
		 Visit(T->data);
	 }
 }

 void LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))//层序遍历
 {
	 LinkQueue q;
	 QElemType a;
	 if(T)
	 {
		 InitQueue(&q);
		 EnQueue(&q,T);
         while(!QueueEmpty(q))
		 {
			 DeQueue(&q,&a);
			 (*Visit)(a->data);
			 if(a->lchild)
				 EnQueue(&q,a->lchild);
			 if(a->rchild)
				 EnQueue(&q,a->rchild);
		 }
	 }
 }
//中序遍历的非递归算法

 typedef BiTree SElemType;
 #include"c3.h"
 #include"bo4.h"
 Status InOrderTraverse1(BiTree T,Status(*Visit)(TElemType))
 { /* 采用二叉链表存储结构，Visit是对数据元素操作的应用函数。算法6.3 */
	 /* 中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit */
	 SqStack q;
	 InitStack(&q);
	 while(T||!StackEmpty(q)){
		 if(T)
		 { /* 根指针进栈,遍历左子树 */
			 Push(&q,T);
			 T=T->lchild;
		 }
		 else
		 {/* 根指针退栈,访问根结点,遍历右子树 */
			 Pop(&q,&T);
			 if(!Visit(T->data))
                  return ERROR;
			 T=T->rchild;
		 }
	 }
	 printf("\n");
	 return OK;
 }
 Status PreOrderTraverse1(BiTree T,Status(*Visit)(TElemType))
 { 
	 SqStack q;
	 InitStack(&q);
	 while(T||!StackEmpty(q))
	 {
		 if(T){//先访问根结点，根结点进栈，然后遍历左子树
			 if(!Visit(T->data))
                  return ERROR;
			 Push(&q,T);
			 T=T->lchild;
		 }
		 else{//根结点退栈，遍历右子树
			 Pop(&q,&T);
			 T=T->rchild;
		 }
	 }
	 printf("\n");
	 return OK;
 }
 








