#include<iostream>
#include<string>
using namespace std;

typedef bool Status;
#include"bo3.h"//������к�������Ļ�����������
#include"bo1.h"
#include"bo2.h"
//�����Ŷ��¼�ģ��
#include"bo4.h"

void main(){
	for(int i=0;i<10;i++)
		cout<<rand()%(11)<<endl;
	system("pause");
}