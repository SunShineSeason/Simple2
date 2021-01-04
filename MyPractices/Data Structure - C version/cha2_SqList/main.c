/* main2-1.c 检验bo2-1.c的主程序 */
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
	 printf("初始化L以后：L.elem=%u  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
	 for(j=1;j<=5;j++){
		 ListInsert(&L,1,j);
	 }
	 printf("在L的表头依次插入1~5后：");
	 for(j=0;j<5;j++)
		 printf("%5d",*(L.elem+j));
	 printf("\n");
	 printf("L.elem=%u  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
     i=ListEmpty(L);
	 printf("L是否为空：i=%d(1为是，0为否)",i);
	 printf("\n");
     ClearList(&L);
	 printf("清空L后，L.elem=%d  L.length=%d  L.listsize=%d",L.elem,L.length,L.listsize);
	 printf("\n");
	 i=ListEmpty(L);
	 printf("L是否为空： i=%d(1为是，0为否)",i);
	 printf("\n");
	 for(j=1;j<=10;j++)
		 i=ListInsert(&L,j,j);
     printf("在L的表尾依次插入1~10后：");
     for(j=0;j<L.length;j++)
		 printf("%3d",*(L.elem+j));
	 printf("\n");
     printf("L.elem=%u  L.length=%d  L.listsize=%d\n",L.elem,L.length,L.listsize);
     i=ListInsert(&L,1,0);
	 printf("在L的表头插入0后，*L.elem=");
     for(j=0;j<L.length;j++)
		 printf("%3d",*(L.elem+j));
	 printf("\n");
	 e=*(L.elem+4);
	 printf("第五个元素的值为：%d\n",e);
	 for(j=3;j<=4;j++){
		 k=LocateElem(L,j,comp);
		 if(k)printf("第%d个元素为%d的平方\n",k,j);
		 else printf("没有元素的值为%d的平方\n",j);
	 }
	 *(L.elem+3)=2;
	 for(j=0;j<L.length;j++)
		 printf("%3d",*(L.elem+j));
	 printf("\n");
	 for(j=1;j<=4;j++){
		 e=*(L.elem+j-1);
		 i=PriorElem(L,e,&e0);
	 if(i==FALSE)
       printf("元素%d无前驱\n",e);
     else
       printf("元素%d的前驱为：%d\n",e,e0);
	 }
   printf("依次输出L的元素：");
   ListTraverse(L,visit); /* 依次对元素调用visit()，输出元素的值 */
   printf("L的元素值加倍后：");
   ListTraverse(L,dbl); /* 依次对元素调用dbl()，元素值乘2 */
   ListTraverse(L,visit);
   printf("%d\n",*(L.elem+6));
   DestroyList(&L);
   printf("销毁L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
 }
