#define CHAR 0 /* ����(����ѡһ) */
 #include"c1.h"
 #if CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* ���ַ����Կո��Ϊ�� */
 #else
   typedef int TElemType;
   TElemType Nil=0; /* ��������0Ϊ�� */
 #endif
 #include"c6-1.h"
 #include"bo6-1.h"
void main()
 {
   Status i;
   int j;
   position p={2,1};
   TElemType e;
   SqBiTree T,s;
   InitBiTree(T);
   CreateBiTree(T);
   printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   Assign(T,p,12);
   printf("%d\n",T[0]);//ע�⣬ϵͳ�����������±��ֵ��������ĳ��ȣ�����ʱ��ֵ��ȷ��!!!
   e=LeftSibling(T,66);
   printf("%d\n",e);
}
