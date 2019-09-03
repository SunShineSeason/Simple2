#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
#define MAX_NAME 5 /* 顶点字符串的最大长度+1 */
#define MAX_INFO 20 /* 相关信息字符串的最大长度+1 */
typedef int VRType;
typedef char InfoType;
typedef string VertexType;

#include"bo1.h"
#include"bo2.h"

void main(){
	cout<<INT_MAX<<endl;
	char c[10]={'h',' e'};//其余字符自动定义为空字符,注意，一个字符数组可以不包含空字符!!
	cout<<c<<endl;
	cin>>c;cout<<c;//输入时遇到空格即将缓冲区中前面的内容送入内存，后面输入的内容留在缓冲区中
	cin>>c;cout<<c;//cin不将空格或回车符送入内存中!!
	char *ch;//注意，字符指针不能直接输入!!
	system("pause");
}