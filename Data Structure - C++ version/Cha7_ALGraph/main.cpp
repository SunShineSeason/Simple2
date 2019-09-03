#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
#define MAX_NUM 20 /* 相关信息字符串的最大长度+1 */
typedef int VRType;
typedef char InfoType;
typedef string VertexType;

#include"bo1.h"
#include"bo2.h"

void main(){
	ALGraph graph;
	graph.CreateGraph();
	graph.DFSTraverse();
	graph.BFSTraverse();
	graph.DeleteVex(4);
	graph.DFSTraverse();
	graph.BFSTraverse();
	system("pause");
}