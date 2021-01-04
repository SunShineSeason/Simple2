 /* bo9-2.c ��̬���ұ�(����������)�Ļ�������(8��) */
 typedef int KeyType; /* ��ؼ�����Ϊ���� */
 typedef struct
 {
   KeyType key;
   int others;
 } ElemType; /* ����Ԫ������ */

 typedef ElemType TElemType;
 #include"c1.h"

Status InitDSTable(BiTree *DT) /* ͬbo6-2.c */
 { /* �������: ����һ���յĶ�̬���ұ�DT */
   *DT=NULL;
   return OK;
 }

 void DestroyDSTable(BiTree *DT) /* ͬbo6-2.c */
 { /* ��ʼ����: ��̬���ұ�DT���ڡ��������: ���ٶ�̬���ұ�DT */
   if(*DT) /* �ǿ��� */
   {
     if((*DT)->lchild) /* ������ */
       DestroyDSTable(&(*DT)->lchild); /* ������������ */
     if((*DT)->rchild) /* ���Һ��� */
       DestroyDSTable(&(*DT)->rchild); /* �����Һ������� */
     free(*DT); /* �ͷŸ���� */
     *DT=NULL; /* ��ָ�븳0 */
   }
 }

 BiTree SearchBST(BiTree T,KeyType key)
 { /* �ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ�أ� */
   /* �����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ��,���򷵻ؿ�ָ�롣�㷨9.5(a) */
   if((!T)||EQ(key,T->data.key))
     return T; /* ���ҽ��� */
   else if LT(key,T->data.key) /* ���������м������� */
     return SearchBST(T->lchild,key);
   else
     return SearchBST(T->rchild,key); /* ���������м������� */
 }

 Status SearchBST1(BiTree T,KeyType key,BiTree f,BiTree *p){
   //fΪ˫��ָ��!!!
   /* �ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ������� */
   /* �ɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ�����·���� */
   /* ���ʵ����һ����㲢����FALSE,ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
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
	/* ������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ������e������TRUE�� */
   /* ���򷵻�FALSE���㷨9.6(��) */
     BiTree p,s;
	 if(!SearchBST1(*T,e.key,NULL,&p))
	 {
		 s=(BiTree)malloc(sizeof(BiTNode));
		 s->lchild=NULL;
		 s->rchild=NULL;
		 s->data=e;
		 if(!p)
			 *T=s;//������sΪ�����
		 else 
			 if LT(e.key,p->data.key)
                p->lchild=s; /* ������*sΪ���� */
         else
             p->rchild=s; /* ������*sΪ�Һ��� */
         return TRUE;
	 }
	 else 
		 return FALSE;
 }

