/* main2-1.c ����bo2-1.c�������� */
 #include"c.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.h"
 
 Status comp(ElemType a,ElemType b){
	 if(a==b*b)
		 return(OK);
	 else return(FALSE);
}
 void visit(ElemType *c){
	 printf("%5d",*c);
 }
 void dbl(ElemType *c){
	 *c*=2;
 }
 void main(){
	 SqList L;
	 ElemType e,e0;
	 Status i;
	 int j,k;
	 i=InitList(&L);
	 printf("��ʼ��L�Ժ�L.elem=%u  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
	 for(j=1;j<=5;j++){
		 ListInsert(&L,1,j);
	 }
	 printf("��L�ı�ͷ���β���1~5��");
	 for(j=0;j<5;j++)
		 printf("%5d",*(L.elem+j));
	 printf("\n");
	 printf("L.elem=%u  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
     i=ListEmpty(L);
	 printf("L�Ƿ�Ϊ�գ�i=%d(1Ϊ�ǣ�0Ϊ��)",i);
	 printf("\n");
     ClearList(&L);
	 printf("���L��L.elem=%d  L.length=%d  L.listsize=%d",L.elem,L.length,L.listsize);
	 printf("\n");
	 i=ListEmpty(L);
	 printf("L�Ƿ�Ϊ�գ� i=%d(1Ϊ�ǣ�0Ϊ��)",i);
	 printf("\n");
	 for(j=1;j<=10;j++)
		 i=ListInsert(&L,j,j);
     printf("��L�ı�β���β���1~10��");
     for(j=0;j<L.length;j++)
		 printf("%3d",*(L.elem+j));
	 printf("\n");
     printf("L.elem=%u  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
     i=ListInsert(&L,1,0);
	 printf("��L�ı�ͷ����0��*L.elem=");
     for(j=0;j<L.length;j++)
		 printf("%3d",*(L.elem+j));
	 printf("\n");
	 e=*(L.elem+4);
	 printf("�����Ԫ�ص�ֵΪ��%d\n",e);
	 for(j=3;j<=4;j++){
		 k=LocateElem(L,j,comp);
		 if(k)printf("��%d��Ԫ��Ϊ%d��ƽ��\n",k,j);
		 else printf("û��Ԫ�ص�ֵΪ%d��ƽ��\n",j);
	 }
	 *(L.elem+3)=2;
	 for(j=0;j<L.length;j++)
		 printf("%3d",*(L.elem+j));
	 printf("\n");
	 for(j=1;j<=4;j++){
		 e=*(L.elem+j-1);
		 i=PriorElem(L,e,&e0);
	 if(i==FALSE)
       printf("Ԫ��%d��ǰ��\n",e);
     else
       printf("Ԫ��%d��ǰ��Ϊ��%d\n",e,e0);
	 }
   printf("�������L��Ԫ�أ�");
   ListTraverse(L,visit); /* ���ζ�Ԫ�ص���visit()�����Ԫ�ص�ֵ */
   printf("L��Ԫ��ֵ�ӱ���");
   ListTraverse(L,dbl); /* ���ζ�Ԫ�ص���dbl()��Ԫ��ֵ��2 */
   ListTraverse(L,visit);
   printf("%d\n",*(L.elem+6));
   DestroyList(&L);
   printf("����L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
 }
