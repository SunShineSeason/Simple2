 /* main3-3.c ѭ������ ����bo3-3.c�������� */
 #include"c1.h"
 typedef int QElemType;
 #include"c3-3.h"
 #include"bo3-3.c"

 void visit(QElemType i)
 {
   printf("%d ",i);
 }

 void main()
 {
   Status j;
   int i=0,l;
   QElemType d;
   SqQueue Q;
   InitQueue(&Q);
   printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ",MAXQSIZE-1);
   do
   {
     scanf("%d",&d);
     if(d==-1)
       break;
     i++;
     EnQueue(&Q,d);
   }while(i<MAXQSIZE-1);//����ʵ����������n������ʱ�����������һ������Ϊ������־!!
   printf("���г���Ϊ: %d\n",QueueLength(Q));
   printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n",MAXQSIZE);
   for(l=1;l<=MAXQSIZE;l++)
   {
     DeQueue(&Q,&d);
     printf("ɾ����Ԫ����%d,������������Ԫ��: ",d);
     scanf("%d",&d);
     EnQueue(&Q,d);
   }
   l=QueueLength(Q);
   printf("���ڶ����е�Ԫ��Ϊ: \n");
   QueueTraverse(Q,visit);
   printf("�����β������%d��Ԫ��\n",i+MAXQSIZE);
   if(l-2>0)
     printf("�����ɶ�ͷɾ��%d��Ԫ��:\n",l-2);
   while(QueueLength(Q)>2)
   {
     DeQueue(&Q,&d);
     printf("ɾ����Ԫ��ֵΪ%d\n",d);
   }
   j=GetHead(Q,&d);
   if(j)
     printf("���ڶ�ͷԪ��Ϊ: %d\n",d);
   ClearQueue(&Q);
   printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   DestroyQueue(&Q);
 }