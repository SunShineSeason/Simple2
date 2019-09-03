class Sqstack{
private:
	SqStack stack;
public:
	Status InitStack(){
		stack.base=new SElemType[STACK_INIT_SIZE];
		stack.top=stack.base;
		stack.stacksize=STACK_INIT_SIZE;
		return true;
	}
	Status Empty(){//为空时返回true
		if(stack.base==stack.top)
			return true;
		else
			return false;
	}
	Status Destroy(){
		delete[] stack.base;
		stack.base=stack.top=NULL;
		stack.stacksize=0;
		return true;
	}
	Status ClearStack(){
		stack.top=stack.base;
		return true;
	}
	int StackLength(){
		return stack.top-stack.base;
	}
	Status GetTop(SElemType &e){
		if(stack.base==stack.top)
			return false;
		else{
			e=*(stack.top-1);//自减会改变变量的值，注意！
			return true;
		}
	}
	Status Push(SElemType e){//在C++中，动态重新分配内存最好使用容器
	    *(stack.top)=e;
		stack.top++;
		return true;
	}
	Status Pop(SElemType &e){
		e=*(--stack.top);
		return true;
	}
	Status Traverse(void (*visit)(SElemType e)){
		SElemType *ps=stack.base;
		while(ps!=stack.top){
			visit(*ps);
			ps++;
		}
		cout<<endl;
		return true;
	}
};