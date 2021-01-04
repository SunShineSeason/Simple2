#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
typedef  int ElemType;
#include"bo1.h"
#include"bo2.h"

void main(){
	SqList list1;
	list1.InitList();
	list1.ListInsert(1,23);
	list1.ListInsert(2,20);
	list1.ListDelete(1);
	list1.Print();
	system("pause");
}