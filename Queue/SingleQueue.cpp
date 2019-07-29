#include "iostream"
#define MaxSize 50

class SingleQueue{
	public:
		SingleQueue();
		~SingleQueue();
		bool QueueIsEmpty();
		bool EnQueue(int e);
		bool DeQueue(int &e);
		bool GetHead(int &e);
		void Show();

	private:
		int data[MaxSize];
		int front,rear;
};

SingleQueue::SingleQueue(){ 
	this->front = 0;
	this->rear = 0;
	std::cout<<"Queue has created\n";
}
SingleQueue::~SingleQueue(){
	this->front = 0;
	this->rear = 0;
	std::cout<<"Queue has deleted\n";
}
bool SingleQueue::QueueIsEmpty(){
	if(this->front == this->rear ){
		return true;
	}else{
		return false;
	}
}
bool SingleQueue::EnQueue(int e){
	if( (this->rear+1)%MaxSize == this->front){
		return false;
	}
	this->data[this->rear] = e;
	this->rear = (this->rear+1)%MaxSize;
	return true;
}
bool SingleQueue::DeQueue(int &e){
	if(this->front == this->rear){
		e = -1;
		return false;
	}
	e =  this->data[this->front] ;
	this->front= (this->front+1)%MaxSize;
	return true;
}
bool SingleQueue::GetHead(int &e){
	if(this->front ==  this->rear ){
		e = -1;
		return false;
	}
	e =  this->data[this->front] ;
	return true;
}
void SingleQueue::Show(){
	if(this->front ==  this->rear ){
		return ;
	}
	int ftem = this->front;
	while(ftem<this->rear){
		std::cout<<this->data[ftem]<<"->";
		ftem++;
	}
		std::cout<<"rear\n";
}

void test(){
	SingleQueue squeue ;
	int e = 0;
	if(squeue.QueueIsEmpty()){
		std::cout<<"empty\n";
	}else{
		std::cout<<"notempty\n";
	}
	squeue.EnQueue(1);
	squeue.EnQueue(2);
	squeue.EnQueue(3);
	squeue.Show();
	if(squeue.QueueIsEmpty()){
		std::cout<<"empty\n";
	}else{
		std::cout<<"notempty\n";
	}
	squeue.DeQueue(e);
	std::cout<<e<<std::endl;
	squeue.GetHead(e);
	std::cout<<e<<std::endl;
	squeue.Show();
}

int main(){
	test();
	return 0;
}
