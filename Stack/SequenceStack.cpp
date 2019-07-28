#include "iostream"
#define MaxSize 50
class SequenceStack{
	public:
		SequenceStack();
		~SequenceStack();
		bool StackIsEmpty();
		bool StackPush(int e);
		bool StackPop(int &e);
		bool StackGetTop(int &e);
		void StackShow();
	private:
		int data[MaxSize];
		int top;

};

SequenceStack::SequenceStack(){
	this->top = -1;
	std::cout<<"stack has created\n";
}
SequenceStack::~SequenceStack(){
	std::cout<<"stack has deleted\n";
}
bool SequenceStack::StackIsEmpty(){
	if(top == -1){
		return true;
	}else{
		return false;
	}
}
bool SequenceStack::StackPush(int e){
	if(this->top == MaxSize -1){
		return false;
	}else{
		this->top++;
		this->data[this->top] = e;
		return true;
	}
}
bool SequenceStack::StackPop(int &e){
	if(this->top == -1){
		e = -1;
		return false;
	}else{
		
		e = this->data[this->top];
		this->data[this->top] = 0;
		this->top--;
	}
}
bool SequenceStack::StackGetTop(int &e){
	if(this->top == -1){
		e = -1;
		return false;
	}else{
		e = this->data[this->top];
		return true;
	}
}
void SequenceStack::StackShow(){
	if(this->top == -1){
	std::cout<<"empty\n";
	}else{
		int length = this->top;
		while(length != -1){
			std::cout<<this->data[length]<<"->";
			length -- ;
		}
		std::cout<<"bottom\n";
	}

}

void test(){
	SequenceStack sqstack;
	int e = 0;
	sqstack.StackPush(1);
	sqstack.StackPush(2);
	sqstack.StackPush(3);
	sqstack.StackShow();
	if(sqstack.StackIsEmpty()){
		std::cout<<"empty\n";
	}else{
		std::cout<<"notempty\n";
	}
	sqstack.StackPop(e);
	std::cout<<e<<std::endl;
	sqstack.StackGetTop(e);
	std::cout<<e<<std::endl;
	sqstack.StackShow();
}

int main(){
	test();
	return 0;
}
