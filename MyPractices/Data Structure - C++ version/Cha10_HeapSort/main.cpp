#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef bool Status;
typedef string InfoType;
#include"bo1.h"
#include"bo2.h"

void main(){
	HeapSort list;
	list.CreateList();
	list.CreateHeap();
	list.print();
	system("pause");
}