class LinkBiTree{
private:
	BiTree T;
	//先序创建二叉树，算法要重点掌握!!
	void CreateBitree(BiTree &T){//注意，要使用引用参数
		TElemType e;
		cin>>e;
		if(e==Nil)
			T=NULL;
		else{
			T=new BiTNode;
			T->data=e;
			this->CreateBitree(T->lchild);
			this->CreateBitree(T->rchild);
		}
	}
	int length(BiTree T){//算法是重点!!
		int i=0,j=0;
		if(T->lchild)
			i=length(T->lchild);//左子树不为空，返回左子树的深度
		if(T->rchild)
			j=length(T->rchild);//右子树不为空，返回右子树的深度
		if(i>j)
			return i+1;
		else
			return j+1;
	}
	void DestroyBiTree(BiTree &T){//只能采用后序遍历，注意要使用引用参数!!
		if(T){
			if(T->lchild)
				DestroyBiTree(T->lchild);
			if(T->rchild)
				DestroyBiTree(T->rchild);
			delete T;
			T=NULL;
		}
	}
public:
	Status InitBiTree(){
		T=NULL;//根结点为空
		return true;
	}
	void Destroy(){
		DestroyBiTree(this->T);
	}
	Status CreateBiTree(){
		cout<<"按先序输入各结点值:"<<endl;
		CreateBitree(this->T);
		return true;
	}
	 #define ClearBiTree DestroyBiTree
	//重点，如何求二叉树的深度
	int BiTreeLength(){
		return this->length(this->T);
	}
	//重点，寻找双亲结点
	typedef bool Status ;
	typedef BiTree QElemType ;
#include"bo3.h"
#include"bo4.h"
	BiTree Locate(TElemType e){
		Queue queue;
		BiTree ps;
		if(this->T){
			queue.InitQueue();
			queue.EnQueue(T);
			while(!queue.Empty()){
				queue.DeQueue(ps);
				if(ps->data==e)
					return ps;
				if(ps->lchild)
					queue.EnQueue(ps->lchild);
				if(ps->rchild)
					queue.EnQueue(ps->rchild);
			}
		}
		return NULL;
	}
	TElemType Parent(TElemType e){
		//使用队列可以实现层次遍历，利用栈可以实现中序遍历等其他遍历!!!
		Queue queue;
		BiTree ps;
		if(this->T){//二叉树不为空
			queue.InitQueue();
			queue.EnQueue(T);//根结点进栈
			while(!queue.Empty()){//队列不为空
				queue.DeQueue(ps);
				if(ps->lchild){
					if(ps->lchild->data==e)
						return ps->data;//找到该双亲结点，则可以直接结束遍历!!
					else 
						queue.EnQueue(ps->lchild);
				}
				if(ps->rchild){
					if(ps->rchild->data==e)
						return ps->data;
					else
						queue.EnQueue(ps->rchild);
				}
			}
		}
		return Nil;//其余情况返回空
	}
	void LevelOrderTraverse(void(*visit)(TElemType)){
		BiTree ps;
		Queue queue;
		if(this->T){
			queue.InitQueue();
			queue.EnQueue(this->T);//根结点入栈
			while(!queue.Empty()){
				queue.DeQueue(ps);
				visit(ps->data);
				if(ps->lchild)
					queue.EnQueue(ps->lchild);
				if(ps->rchild)
					queue.EnQueue(ps->rchild);
			}
		}
	}
	typedef BiTree SElemType;
#include"bo5.h"
#include"bo6.h"//包含栈的数据结构与操作
	void PreorderTraverse(void (*visit)(TElemType e)){
		BiTree bt;
		Sqstack stack; 
		if(this->T){
			stack.InitStack();
			stack.Push(T);//根结点入栈
			while(!stack.Empty()){
				stack.Pop(bt);
				visit(bt->data);
				if(bt->rchild)//右孩子先入栈，后出栈
					stack.Push(bt->rchild);
				if(bt->lchild)
					stack.Push(bt->lchild);
			}
		}
	}
	//难点，怎样实现利用栈实现中序遍历!!
	void InorderTraverse(void (*visit)(TElemType e)){
		Sqstack stack;
		BiTree bt,bs;
		stack.InitStack();//栈要先初始化!!
		stack.Push(T);//根结点入栈
		while(stack.GetTop(bt)){//在本算法中，空指针入栈对于正确执行程序非常重要!!!
			while(bt){//注意，不要判空，空结点入栈程序才能正确执行!!!!!
				stack.Push(bt->lchild);
				bt=bt->lchild;
			}
			stack.Pop(bt);//空结点退栈
			if(!stack.Empty()){
				stack.Pop(bs);//此时栈顶结点左孩子为空，执行出栈操作
			    visit(bs->data);//访问根结点
				stack.Push(bs->rchild);//同样注意，不要判空，空结点入栈程序才能正确执行!!!!!
			}
		}
	}
	BiTree Position(TElemType e,int LR){//返回左孩子或右孩子数值为e的双亲结点
		BiTree bt;
		Queue queue;
		queue.InitQueue();
		queue.EnQueue(this->T);
		while(!queue.Empty()){
			queue.DeQueue(bt);
        if(LR){//注意，左右结点都要入栈!!
		  if(bt->lchild)
				queue.EnQueue(bt->lchild);
			if(bt->rchild){
				if(bt->rchild->data==e)
					return bt;
				else
					queue.EnQueue(bt->rchild);
			}
	  }
     else{
		 if(bt->lchild){
				if(bt->lchild->data==e)
					return bt;
				else
					queue.EnQueue(bt->lchild);
			}
			if(bt->rchild)
				queue.EnQueue(bt->rchild);
	 }
   }
		return NULL;
	}
	Status InsertChild(TElemType e,LinkBiTree &bt,int LR){
		//将bt插入结点p（数值为e）的左子树或右子树，销毁二叉树bt
		BiTree bs=this->Locate(e);
#if LR
		bt.T->rchild=bs->rchild;
		bs->rchild=bt.T;
		bt.T=NULL;//bt置为空树
#else
		bt.T->rchild=bs->lchild;
		bs->lchild=bt.T;
		bt.T=NULL;
#endif
		return true;
	}
};