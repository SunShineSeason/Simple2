#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef bool Status;
typedef string VertexType ;
#include"bo1.h"
#include"bo2.h"
#include"bo3.h"

void main(){
	MiniSpanTree tree;
	tree.InitGraph();
	tree.PRIM_MINITree();
	system("pause");
}