#include<iostream>
#include<string>
using namespace std;

#define IsChar 0//������������
typedef bool Status;

#include"bo1.h"
#include"bo2.h"

void main(){
	Huffmantree T;
	T.CreateHuffman();
	T.Traverse();
	T.PrintCode();
	system("pause");
}