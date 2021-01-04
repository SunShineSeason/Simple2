#include<iostream>
#include<string>
using namespace std;

#define IsChar 0//进行条件编译
typedef bool Status;
#if IsChar
   typedef  char TElemType;
   #define Nil '#'
#else
   typedef  int TElemType;
   #define Nil 0 
#endif

#include"bo1.h"
#include"bo2.h"

   void print(TElemType e){
	   cout<<e;
   }

   void main(){
	   int LR;
	   TElemType e;
	   LinkBiTree tree;
	   tree.InitBiTree();
	   tree.CreateBiTree();
	   cout<<tree.BiTreeLength()<<endl;
	   tree.LevelOrderTraverse(print);
	   cout<<endl;
	   tree.PreorderTraverse(print);
	   cout<<endl;
	   tree.InorderTraverse(print);
	   cout<<endl;
	   while(1){
		   cin>>e>>LR;
		   cout<<tree.Position(e,LR)<<endl;
	   }
	   system("pause");
   }