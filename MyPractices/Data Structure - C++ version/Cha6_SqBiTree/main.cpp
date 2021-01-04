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

   void Print(TElemType &e){
	   cout<<e<<"  ";
   }

void main(){
	char c=NULL;
	cout<<int(c)<<endl;//空字符ASCII值为0
	SqBitree Sqtree;
	Sqtree.InitBiTree();
	cout<<"深度为："<<Sqtree.Depth()<<endl;
	Sqtree.CreateBiTree();
	Sqtree.LevelTraverse(Print);
	cout<<"深度为："<<Sqtree.Depth()<<endl;
	while(1){
		int i,j;
		cin>>i>>j;
		position e;
		e.level=i;
		e.order=j;
		Sqtree.Assign(e,25);
		cout<<Sqtree.Parent(e)<<"  "<<Sqtree.LeftBrother(e)<<endl;
		Sqtree.PreOrderTraverse(Print);
		Sqtree.DeleteBiTree(e,0);//删除左子树
		Sqtree.LevelTraverse(Print);
    }
	system("pause");
}