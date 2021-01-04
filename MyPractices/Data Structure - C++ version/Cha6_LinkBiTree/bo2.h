class LinkBiTree{
private:
	BiTree T;
	//���򴴽����������㷨Ҫ�ص�����!!
	void CreateBitree(BiTree &T){//ע�⣬Ҫʹ�����ò���
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
	int length(BiTree T){//�㷨���ص�!!
		int i=0,j=0;
		if(T->lchild)
			i=length(T->lchild);//��������Ϊ�գ����������������
		if(T->rchild)
			j=length(T->rchild);//��������Ϊ�գ����������������
		if(i>j)
			return i+1;
		else
			return j+1;
	}
	void DestroyBiTree(BiTree &T){//ֻ�ܲ��ú��������ע��Ҫʹ�����ò���!!
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
		T=NULL;//�����Ϊ��
		return true;
	}
	void Destroy(){
		DestroyBiTree(this->T);
	}
	Status CreateBiTree(){
		cout<<"��������������ֵ:"<<endl;
		CreateBitree(this->T);
		return true;
	}
	 #define ClearBiTree DestroyBiTree
	//�ص㣬���������������
	int BiTreeLength(){
		return this->length(this->T);
	}
	//�ص㣬Ѱ��˫�׽��
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
		//ʹ�ö��п���ʵ�ֲ�α���������ջ����ʵ�������������������!!!
		Queue queue;
		BiTree ps;
		if(this->T){//��������Ϊ��
			queue.InitQueue();
			queue.EnQueue(T);//������ջ
			while(!queue.Empty()){//���в�Ϊ��
				queue.DeQueue(ps);
				if(ps->lchild){
					if(ps->lchild->data==e)
						return ps->data;//�ҵ���˫�׽�㣬�����ֱ�ӽ�������!!
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
		return Nil;//����������ؿ�
	}
	void LevelOrderTraverse(void(*visit)(TElemType)){
		BiTree ps;
		Queue queue;
		if(this->T){
			queue.InitQueue();
			queue.EnQueue(this->T);//�������ջ
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
#include"bo6.h"//����ջ�����ݽṹ�����
	void PreorderTraverse(void (*visit)(TElemType e)){
		BiTree bt;
		Sqstack stack; 
		if(this->T){
			stack.InitStack();
			stack.Push(T);//�������ջ
			while(!stack.Empty()){
				stack.Pop(bt);
				visit(bt->data);
				if(bt->rchild)//�Һ�������ջ�����ջ
					stack.Push(bt->rchild);
				if(bt->lchild)
					stack.Push(bt->lchild);
			}
		}
	}
	//�ѵ㣬����ʵ������ջʵ���������!!
	void InorderTraverse(void (*visit)(TElemType e)){
		Sqstack stack;
		BiTree bt,bs;
		stack.InitStack();//ջҪ�ȳ�ʼ��!!
		stack.Push(T);//�������ջ
		while(stack.GetTop(bt)){//�ڱ��㷨�У���ָ����ջ������ȷִ�г���ǳ���Ҫ!!!
			while(bt){//ע�⣬��Ҫ�пգ��ս����ջ���������ȷִ��!!!!!
				stack.Push(bt->lchild);
				bt=bt->lchild;
			}
			stack.Pop(bt);//�ս����ջ
			if(!stack.Empty()){
				stack.Pop(bs);//��ʱջ���������Ϊ�գ�ִ�г�ջ����
			    visit(bs->data);//���ʸ����
				stack.Push(bs->rchild);//ͬ��ע�⣬��Ҫ�пգ��ս����ջ���������ȷִ��!!!!!
			}
		}
	}
	BiTree Position(TElemType e,int LR){//�������ӻ��Һ�����ֵΪe��˫�׽��
		BiTree bt;
		Queue queue;
		queue.InitQueue();
		queue.EnQueue(this->T);
		while(!queue.Empty()){
			queue.DeQueue(bt);
        if(LR){//ע�⣬���ҽ�㶼Ҫ��ջ!!
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
		//��bt������p����ֵΪe�����������������������ٶ�����bt
		BiTree bs=this->Locate(e);
#if LR
		bt.T->rchild=bs->rchild;
		bs->rchild=bt.T;
		bt.T=NULL;//bt��Ϊ����
#else
		bt.T->rchild=bs->lchild;
		bs->lchild=bt.T;
		bt.T=NULL;
#endif
		return true;
	}
};