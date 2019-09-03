Status InitBiTree(SqBiTree T){
	int i;
	for(i=0;i<MAX_TREE_SIZE;i++){
		T[i]=Nil;
	}
	return OK;
}

Status CreateBiTree(SqBiTree T){
	int i=0;
#if CHAR
	int l;
	char s[MAX_TREE_SIZE];
	printf("请按层序输入结点的值(字符)，空格表示空结点，结点数≤%d:\n",MAX_TREE_SIZE);
	scanf("%s",s);
	l=strlen(s);
	for(;i<l;i++){
		T[i]=s[i];
		if(i!=0&&T[i]!=Nil&&T[(i+1)/2-1]==Nil)/* 此结点(不空)无双亲且不是根 */
		{
			printf("出现无双亲的非根结点%c\n",T[i]);
            exit(ERROR);
		}
	}
	for(;i<MAX_TREE_SIZE;i++)
		T[i]=Nil;
#else
	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n",MAX_TREE_SIZE);
	while(1)//循环结束的条件是遇到了999!!!
   {
     scanf("%d",&T[i]);
     if(T[i]==999)
       break;
     if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* 此结点(不空)无双亲且不是根 */
     {
       printf("出现无双亲的非根结点%d\n",T[i]);
       exit(ERROR);
     }
     i++;
   }
   while(i<MAX_TREE_SIZE)
   {
     T[i]=Nil; /* 将空赋值给T的后面的结点 */
     i++;
   }
#endif
   return OK;
}

#define ClearBiTree InitBiTree

Status BiTreeEmpty(SqBiTree T){
	if(T[0]==Nil)
		return TRUE;
	else 
		return FALSE;
}

int BiTreeDepth(SqBiTree T){
	int depth=1,i,j=0;
	i=MAX_TREE_SIZE-1;
    while(T[i]==Nil){//从后往前找!!
        i--;
	}//找到最后一个节点T[i]
    i++;
	while(pow(2,j)<i+1)//2的j次方为第j+1层第一个数据在二叉树中的位置!!!!
		j++;
	return j;
}//如何确定树的深度

Status Root(SqBiTree T,TElemType *e)
 { /* 初始条件: 二叉树T存在 */
   /* 操作结果:  当T不空,用e返回T的根,返回OK;否则返回ERROR,e无定义 */
   if(BiTreeEmpty(T)) /* T空 */
     return ERROR;
   else
   {
     *e=T[0];
     return OK;
   }
 }

TElemType Value(SqBiTree T,position e)
{/* 初始条件: 二叉树T存在,e是T中某个结点(的位置) */
   /* 操作结果: 返回处于位置e(层,本层序号)的结点的值 */
   return(T[(int)pow(2,e.level-1)+e.order-2]);//注意类型转换!
}

Status Assign(SqBiTree T,position e,TElemType value){
   int i=(int)pow(2,e.level-1)+e.order-2;
   if(T[(i+1)/2-1]==Nil&&value!=Nil)//给某一节点赋非空值但双亲节点为空
	   return ERROR;
   else
	   if(value==Nil&&(T[i*2+1]!=Nil||T[2*i+2]!=Nil))//给某一节点赋空值但存在叶子，方法值得学习
		   return ERROR;
   T[i]=value;
   return OK;
}

TElemType Parent(SqBiTree T,TElemType e)
 { /* 初始条件: 二叉树T存在,e是T中某个结点 */
   /* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
   int i;
   if(T[0]==Nil) /* 空树 */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
	   if(T[i]==e) /* 找到e */
          return T[(i+1)/2-1];
   return Nil; /* 没找到e */
 }

TElemType LeftChild(SqBiTree T,TElemType e){
	int i;
    if(T[0]==Nil) /* 空树 */
       return Nil;
    for(i=0;i<=MAX_TREE_SIZE-1;i++)
	   if(T[i]==e) /* 找到e */
          return T[i*2+1];
    return Nil; /* 没找到e */
}

TElemType RightChild(SqBiTree T,TElemType e)
 { /* 初始条件: 二叉树T存在,e是T中某个结点 */
   /* 操作结果: 返回e的右孩子。若e无右孩子,则返回＂空＂ */
   int i;
   if(T[0]==Nil) /* 空树 */
     return Nil;
   for(i=0;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* 找到e */
       return T[i*2+2];
   return Nil; /* 没找到e */
 }

TElemType LeftSibling(SqBiTree T,TElemType e)
 { /* 初始条件: 二叉树T存在,e是T中某个结点 */
   /* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
   int i;
   if(T[0]==Nil) /* 空树 */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2==0) /* 找到e且其序号为偶数(是右孩子) */
       return T[i-1];
   return Nil; /* 没找到e */
 }

 TElemType RightSibling(SqBiTree T,TElemType e)
 { /* 初始条件: 二叉树T存在,e是T中某个结点 */
   /* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
   int i;
   if(T[0]==Nil) /* 空树 */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2) /* 找到e且其序号为奇数(是左孩子) */
       return T[i+1];
   return Nil; /* 没找到e */
 }

 //后面的六个函数暂不学习!!
	


