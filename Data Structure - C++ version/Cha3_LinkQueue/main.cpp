#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
#include"bo3.h"//定义队列和链表处理的基本数据类型
#include"bo1.h"
#include"bo2.h"
//银行排队事件模拟
#include"bo4.h"

void main(){
	for(int i=0;i<10;i++)
		cout<<rand()%(11)<<endl;
	system("pause");
}