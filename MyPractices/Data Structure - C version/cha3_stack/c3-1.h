 /* c3-1.h ջ��˳��洢��ʾ */
 #define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 2 /* �洢�ռ�������� */
typedef struct{
	SElemType *base;
    SElemType *top;
	int stacksize;
}SqStack;