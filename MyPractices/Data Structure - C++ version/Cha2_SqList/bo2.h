class SqList{//�ڳ�Ա�����У�����ֱ�ӷ���˽�г�Ա������
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
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   SqList &L=*this;
   return L.length;
 }

Status GetElem(int i,ElemType &e){//�������Ա��е�i�����ݵ�ֵ����һ������ʹ���˳������ã�
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
	else{  //���Ƽ�ʹ��realloc�������·���ռ�
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
			*(pointer-1)=*pointer;//ע�⣬����ʹ��--pointer���״�
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