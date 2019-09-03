/* main3-1.c 检验bo3-1.cpp的主程序 */
 #include"c.h"
 typedef int SElemType; /* 定义栈元素类型，此句要在c3-1.h的前面 */
 #include"c3-1.h"
 #include"bo3-1.h"

 
void conversion(){
	 SqStack S;
	 SElemType e;
	 int a,b,c;
	 InitStack(&S);
	 printf("请输入一个非负十进制整数：");
	 scanf("%d",&a);
	 printf("%d的十六进制数为：",a);
     do{
		 c=a%8;
		 a/=8;
		 Push(&S,c);
	 }while(a!=0);
	while(Pop(&S,&e)) /* 当栈不空 */
    {
      printf("%d",e);	
	}
	printf("\n");
 }
 void main(){
	 conversion();
 }