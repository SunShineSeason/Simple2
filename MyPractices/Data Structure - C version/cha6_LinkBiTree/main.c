#define CHAR 0 /* ����(����ѡһ) */
 #if CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* ���ַ����Կո��Ϊ�� */
 #else
   typedef int TElemType;
   TElemType Nil=0; /* ��������0Ϊ�� */
 #endif
 #include"c1.h"
 #include"c.h"
 #include"bo2.h"

 Status visit(TElemType e)
 {
   printf("%4d ",e);
   return OK;
 }
 
void main(){
   int i;
   char s='*';
   BiTree T;
   TElemType e1,e2;
   InitBiTree(&T);
   printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
 
#if CHAR
   printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #else
    printf("���������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
  
   CreateBiTree(&T);//ע������ķ������Ƚ���������Nil��ʹÿ���ǿս��Ķ�Ϊ2���ٰ����������������
   printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   printf("�������������:\n");
   PreOrderTraverse1(T,visit);
   printf("�������������:\n");
   LevelOrderTraverse(T,visit);
   printf("\n");
   printf("�������������:\n");
   InOrderTraverse1(T,visit);
   printf("\n");
   printf("�������������:\n");
   PostOrderTraverse(T,visit);
   printf("\n");
   while(1)
   {
	    printf("������i����ֵ��");
        scanf("%d",&i);
        e1=LeftChild(T,i);
        printf("%d\n",e1);
        e1=LeftSibling(T,i);
        printf("%d\n",e1);
   }
}
