Status InitBiTree(BiTree *T)
{
	*T=NULL;//��Ϊû������ͷ���
	return OK;
}

void DestroyBiTree(BiTree *T)//�ݹ��㷨!!
 { /* ��ʼ����: ������T����*/
	
	/*�������: �����������˳�����ٶ�����T !!*/
	if(*T){
		if((*T)->lchild)
			DestroyBiTree(&(*T)->lchild);
		if((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T=NULL;
	}
 }//ʲô����¿����õݹ�!!��Ϥһ��

 void CreateBiTree(BiTree *T)
 { /* �㷨6.4:�������������������н���ֵ����Ϊ�ַ��ͻ����ͣ��������� */
   /* ���壩��������������ʾ�Ķ�����T������Nil��ʾ�գ��ӣ������иĶ� */
   TElemType ch;
 #if CHAR
   scanf("%c",&ch);
 #else
   scanf("%d",&ch);
 #endif
   if(ch==Nil) /* �� */
     *T=NULL;
   else
   {
     *T=(BiTree)malloc(sizeof(BiTNode));
     if(!(*T))
       exit(OVERFLOW);
     (*T)->data=ch; /* ���ɸ���� */
     CreateBiTree(&(*T)->lchild); /* ���������� */
     CreateBiTree(&(*T)->rchild); /* ���������� */
   }
 }

Status BiTreeEmpty(BiTree T)
 { /* ��ʼ����: ������T���� */
   /* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
   if(T)
     return FALSE;
   else
     return TRUE;	
}

int BiTreeDepth(BiTree T)
 { /* ��ʼ����: ������T���ڡ��������: ����T����� */
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
 { /* ��ʼ����: ������T���ڡ��������: ����T�ĸ� */
   if(BiTreeEmpty(T))
     return Nil;
   else
     return T->data;
 }

 TElemType Value(BiTree p)
 { /* ��ʼ����: ������T���ڣ�pָ��T��ĳ����� */
   /* �������: ����p��ָ����ֵ */
   return p->data;
 }

 void Assign(BiTree p,TElemType value)
 { /* ��p��ָ��㸳ֵΪvalue */
   p->data=value;
 }

 typedef BiTree QElemType; /* �����Ԫ��Ϊ��������ָ������,���ַ��������Ժ�ǿ!! */
 #include"c2.h"
 #include"bo3.h"
 TElemType Parent(BiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ��e��T�ķǸ����,�򷵻�����˫��,���򷵻أ��գ� */
   LinkQueue q;
   QElemType a;
   if(T) /* �ǿ��� */
   {
     InitQueue(&q); /* ��ʼ������ */
     EnQueue(&q,T); /* ������� */
     while(!QueueEmpty(q))
	 {
		 DeQueue(&q,&a);
         if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)//ע����������!!
			 return a->data;
		 else
		 {
			 if(a->lchild)
				 EnQueue(&q,a->lchild);
			 if(a->rchild)
				 EnQueue(&q,a->rchild);
		 }
	 }
   }//��ѭ���൱�ڲ������!!!
   return Nil; /* ���ջ�û�ҵ�e */
 }
 
 BiTree Point(BiTree T,TElemType s)/* ���ض�����T��ָ��Ԫ��ֵΪs�Ľ���ָ�롣��� */
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
 }//���ַ���һ��Ҫ��������!!!

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

 TElemType LeftSibling(BiTree T,TElemType s)//����������������ֵ�
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

 void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))//�������
 {
	 if(T)
	 {
		 (*Visit)(T->data);
		 PreOrderTraverse(T->lchild,Visit);
		 PreOrderTraverse(T->rchild,Visit);
	 }
 }

 void InOrderTraverse(BiTree T,Status(*Visit)(TElemType))//�������
 { 
   if(T)
   {
     InOrderTraverse(T->lchild,Visit); 
     Visit(T->data); 
     InOrderTraverse(T->rchild,Visit); 
   }
 }

 void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))//�������
 {
	 if(T)
	 {
		 PostOrderTraverse(T->lchild,Visit);
		 PostOrderTraverse(T->rchild,Visit);
		 Visit(T->data);
	 }
 }

 void LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))//�������
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
//��������ķǵݹ��㷨

 typedef BiTree SElemType;
 #include"c3.h"
 #include"bo4.h"
 Status InOrderTraverse1(BiTree T,Status(*Visit)(TElemType))
 { /* ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú������㷨6.3 */
	 /* �������������T�ķǵݹ��㷨(����ջ)����ÿ������Ԫ�ص��ú���Visit */
	 SqStack q;
	 InitStack(&q);
	 while(T||!StackEmpty(q)){
		 if(T)
		 { /* ��ָ���ջ,���������� */
			 Push(&q,T);
			 T=T->lchild;
		 }
		 else
		 {/* ��ָ����ջ,���ʸ����,���������� */
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
		 if(T){//�ȷ��ʸ���㣬������ջ��Ȼ�����������
			 if(!Visit(T->data))
                  return ERROR;
			 Push(&q,T);
			 T=T->lchild;
		 }
		 else{//�������ջ������������
			 Pop(&q,&T);
			 T=T->rchild;
		 }
	 }
	 printf("\n");
	 return OK;
 }
 








