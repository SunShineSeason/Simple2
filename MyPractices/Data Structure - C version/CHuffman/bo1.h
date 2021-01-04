void Select(HuffmanTree T,int p,int &s1,int &s2){
	int i;
	for(i=1;i<=p;i++)
		if(!T[i].parent)
		{
			s1=i;
			break;
		}
	for(i=1;i<=p;i++){
		if(T[i].parent)
			continue;
		if(T[i].weight<T[s1].weight)
			s1=i;
	}
	for(i=1;i<=p;i++)
		if(!T[i].parent && i!=s1)
		{
			s2=i;
			break;
		}
	for(i=1;i<=p;i++){
		if(i==s1 || T[i].parent)
			continue;
		if(T[i].weight<T[s2].weight)
			s2=i;
	}
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){//w存放n个字符的权值
	int m,s1,s2,i=1;
	char *cd;
	HuffmanTree p;
	if(n<=1)
		return;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//分配了大小为2n的数组，数组元素为结构体变量
	if(!HT)
		exit(-1);
	for(p=HT+1;i<=n;i++){
		(*p).parent=0;(*p).lchild=0;(*p).rchild=0;(*p).weight=*w;
		p++;
		w++;
	}
	for(;i<=m;i++){
		(*p).parent=0;(*p).lchild=0;(*p).rchild=0;(*p).weight=0;
		p++;
	}
		
	for(i=n+1;i<=m;i++){//构建赫夫曼树
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;  HT[s2].parent=i;
		HT[i].lchild=s1;  HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//创建了大小为n+1的数组，数组元素为字符型指针变量
	cd=(char *)malloc(n*sizeof(char));//动态分配字符数组
	cd[n-1]='\0';
	for(i=1;i<=n;i++){
		int c,f,start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
			if(HT[f].lchild==c) 
				cd[--start]='0';
			else 
				cd[--start]='1';
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
	cd=NULL;
}