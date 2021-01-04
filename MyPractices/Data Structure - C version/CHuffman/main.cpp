#include<iostream>
#include<string>
#include"c1.h"
#include"bo1.h"

void main(){
	int a[]={5,29,7,8,14,23,3,11},i;
	int *w=a;
	HuffmanTree HT;
	HuffmanCode HC;
	HuffmanCoding(HT,HC,w,8);
	for(i=1;i<=15;i++)
	    printf("%d\t%d%\t%d\t%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);//为什么用printf语句
	printf("各字符的编码为:\n");
	for(i=1;i<=8;i++)
		printf("%s\n",HC[i]);
	system("pause");
}