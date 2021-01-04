#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
typedef  int ElemType;
#include"bo1.h"

void visit(ElemType c) 
 {
   cout<<c<<"   ";
 }

void main(){
	LinkList list;
	list.InitList();
	for(int i=1;i<8;i++){
		list.ListInsert(i,i*10);
	}
	list.ListTraverse(visit);
    list.ListDelete(2);
	list.ListTraverse(visit);
	cout<<list.Listlength()<<endl;
	cout<<list.PriorElem(10)<<endl;
	list.ClearList();
	cout<<list.Listlength()<<endl;
	list.CreateList(5);
	list.ListTraverse(visit);
	system("pause");
}