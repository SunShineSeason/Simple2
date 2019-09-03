#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
typedef  int ElemType;
#include"bo1.h"
#include"bo2.h"

void print(ElemType e){
	cout<<e<<"   ";
}

void main(){
	SLinklist list;
	list.InitList();
	for(int i=1;i<10;i++){
		list.ListInsert(i,i*10);
	}
	list.ListTraverse(print);
	cout<<list.ListLength()<<endl;
	list.ListDelete(1);
	list.ListDelete(list.ListLength());
	list.ListTraverse(print);
	cout<<list.PriorElem(40)<<endl;
	cout<<list.ListLength()<<endl;
	list.ClearList();
	cout<<list.ListLength()<<"   "<<list.ListDelete(2)<<endl;
	system("pause");
}