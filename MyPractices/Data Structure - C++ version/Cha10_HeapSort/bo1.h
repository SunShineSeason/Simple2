 typedef int KeyType; /* ����ؼ�������Ϊ���� */
 typedef struct
 {
   KeyType key; /* �ؼ����� */
   InfoType otherinfo; /* ������������������������ж��� */
 }RedType; /* ��¼���� */

 typedef struct
 {
   RedType *r; /* r[0]���û������ڱ���Ԫ */
   int length; /* ˳����� */
 }SqList; /* ˳������� */
