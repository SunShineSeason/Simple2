/* main3-1.c ����bo3-1.cpp�������� */
 #include"c.h"
 typedef int SElemType; /* ����ջԪ�����ͣ��˾�Ҫ��c3-1.h��ǰ�� */
 #include"c3-1.h"
 #include"bo3-1.h"

 
void conversion(){
	 SqStack S;
	 SElemType e;
	 int a,b,c;
	 InitStack(&S);
	 printf("������һ���Ǹ�ʮ����������");
	 scanf("%d",&a);
	 printf("%d��ʮ��������Ϊ��",a);
     do{
		 c=a%8;
		 a/=8;
		 Push(&S,c);
	 }while(a!=0);
	while(Pop(&S,&e)) /* ��ջ���� */
    {
      printf("%d",e);	
	}
	printf("\n");
 }
 void main(){
	 conversion();
 }