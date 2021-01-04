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
	printf("�밴�����������ֵ(�ַ�)���ո��ʾ�ս�㣬�������%d:\n",MAX_TREE_SIZE);
	scanf("%s",s);
	l=strlen(s);
	for(;i<l;i++){
		T[i]=s[i];
		if(i!=0&&T[i]!=Nil&&T[(i+1)/2-1]==Nil)/* �˽��(����)��˫���Ҳ��Ǹ� */
		{
			printf("������˫�׵ķǸ����%c\n",T[i]);
            exit(ERROR);
		}
	}
	for(;i<MAX_TREE_SIZE;i++)
		T[i]=Nil;
#else
	printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n",MAX_TREE_SIZE);
	while(1)//ѭ��������������������999!!!
   {
     scanf("%d",&T[i]);
     if(T[i]==999)
       break;
     if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* �˽��(����)��˫���Ҳ��Ǹ� */
     {
       printf("������˫�׵ķǸ����%d\n",T[i]);
       exit(ERROR);
     }
     i++;
   }
   while(i<MAX_TREE_SIZE)
   {
     T[i]=Nil; /* ���ո�ֵ��T�ĺ���Ľ�� */
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
    while(T[i]==Nil){//�Ӻ���ǰ��!!
        i--;
	}//�ҵ����һ���ڵ�T[i]
    i++;
	while(pow(2,j)<i+1)//2��j�η�Ϊ��j+1���һ�������ڶ������е�λ��!!!!
		j++;
	return j;
}//���ȷ���������

Status Root(SqBiTree T,TElemType *e)
 { /* ��ʼ����: ������T���� */
   /* �������:  ��T����,��e����T�ĸ�,����OK;���򷵻�ERROR,e�޶��� */
   if(BiTreeEmpty(T)) /* T�� */
     return ERROR;
   else
   {
     *e=T[0];
     return OK;
   }
 }

TElemType Value(SqBiTree T,position e)
{/* ��ʼ����: ������T����,e��T��ĳ�����(��λ��) */
   /* �������: ���ش���λ��e(��,�������)�Ľ���ֵ */
   return(T[(int)pow(2,e.level-1)+e.order-2]);//ע������ת��!
}

Status Assign(SqBiTree T,position e,TElemType value){
   int i=(int)pow(2,e.level-1)+e.order-2;
   if(T[(i+1)/2-1]==Nil&&value!=Nil)//��ĳһ�ڵ㸳�ǿ�ֵ��˫�׽ڵ�Ϊ��
	   return ERROR;
   else
	   if(value==Nil&&(T[i*2+1]!=Nil||T[2*i+2]!=Nil))//��ĳһ�ڵ㸳��ֵ������Ҷ�ӣ�����ֵ��ѧϰ
		   return ERROR;
   T[i]=value;
   return OK;
}

TElemType Parent(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ��e��T�ķǸ����,�򷵻�����˫��,���򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
	   if(T[i]==e) /* �ҵ�e */
          return T[(i+1)/2-1];
   return Nil; /* û�ҵ�e */
 }

TElemType LeftChild(SqBiTree T,TElemType e){
	int i;
    if(T[0]==Nil) /* ���� */
       return Nil;
    for(i=0;i<=MAX_TREE_SIZE-1;i++)
	   if(T[i]==e) /* �ҵ�e */
          return T[i*2+1];
    return Nil; /* û�ҵ�e */
}

TElemType RightChild(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e���Һ��ӡ���e���Һ���,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=0;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* �ҵ�e */
       return T[i*2+2];
   return Nil; /* û�ҵ�e */
 }

TElemType LeftSibling(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ֵܡ���e��T�����ӻ������ֵ�,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2==0) /* �ҵ�e�������Ϊż��(���Һ���) */
       return T[i-1];
   return Nil; /* û�ҵ�e */
 }

 TElemType RightSibling(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ֵܡ���e��T���Һ��ӻ������ֵ�,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2) /* �ҵ�e�������Ϊ����(������) */
       return T[i+1];
   return Nil; /* û�ҵ�e */
 }

 //��������������ݲ�ѧϰ!!
	


