#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
typedef  int ElemType;
#include"bo1.h"
#include"bo2.h"

void print(ElemType e){
	cout<<e<<"  ";
}

void main(){
	DuLinkList list;
	list.InitList();
	for(int i=1;i<10;i++)
		list.ListInsert(1,i*10);
	list.ListTraverse(print);
	cout<<list.ListInsert(10,32)<<endl;
    cout<<list.ListInsert(1,32)<<endl;
	list.ListTraverse(print);
	cout<<list.NextElem(0)<<"  "<<list.NextElem(90)<<endl;
	system("pause");
}