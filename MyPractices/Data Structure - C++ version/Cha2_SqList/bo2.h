class SqList{//在成员函数中，可以直接访问私有成员变量！
private:
	ElemType *elem;
	int length;
	int listsize;
public:
Status InitList(){
	SqList &L=*this;
	L.elem=new ElemType[initsize];
	L.length=0;
	L.listsize=initsize;
	return true;
}

Status DestroyList(){
	SqList &L=*this;
	delete[] L.elem;
	L.length=0;
	L.listsize=0;
	return true;
}

Status ClearList(){
	SqList &L=*this;
	L.length=0;
	return true;
}

Status ListEmpty(){
	SqList &L=*this;
	if(L.length==0)
		return true;
	else 
		return false;
}

 int ListLength()
 { /* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
   SqList &L=*this;
   return L.length;
 }

Status GetElem(int i,ElemType &e){//返回线性表中第i个数据的值，第一个参数使用了常量引用！
	SqList &L=*this;
	if(i>L.length||i<1)
		return false;
	e=L.elem[i-1];
	return true;
}

Status PriorElem(ElemType cur_e,ElemType &pre_e){
	SqList &L=*this;
	int i;
	for(i=1;i<L.length;i++)
		if(L.elem[i]==cur_e)
			break;
	if(i!=L.length){
		pre_e=L.elem[i-1];
		return true;
	}
	return false;
}

Status ListInsert(int i,ElemType e){
	SqList &L=*this;
	if(i<1 || i>L.length+1)
		return false;
	else{  //不推荐使用realloc函数重新分配空间
		for(ElemType *pointer=L.elem+L.length-1;pointer>=L.elem+i-1;pointer--)
			*(pointer+1)=*pointer;
		L.elem[i-1]=e;
		L.length++;
		return true;
	}
}

Status ListDelete(int i){
	SqList &L=*this;
	if(i<1||i>L.length)
		return false;
	else{
		ElemType *pointer=L.elem+i;
		for(;pointer<L.elem+L.length;pointer++)
			*(pointer-1)=*pointer;//注意，不能使用--pointer，易错！
		L.length--;
		return true;
	}
}

void Print(){
	for(int i=0;i<this->length;i++)
		cout<<this->elem[i]<<"  ";
	cout<<endl;
}
};