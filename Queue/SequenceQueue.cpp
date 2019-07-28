#include "iostream"
#define MaxSize 50

class SequenceQueue{
	public:
		SequenceQueue();
		~SequenceQueue();
		bool QueueIsEmpty();
		bool EnQueue(int e);
		bool DeQueue(int &e);
		bool GetHead(int &e);
		void Show();

	private:
		int data[MaxSize];
		int front,rear;
};

SequenceQueue::SequenceQueue(){ 
	this->front = 0;
	this->rear = 0;
	std::cout<<"Queue has created\n";
}
SequenceQueue::~SequenceQueue(){
	this->front = 0;
	this->rear = 0;
	std::cout<<"Queue has deleted\n";
}
bool SequenceQueue::QueueIsEmpty(){
	if(this->front == 0 && this->rear == 0){
		return true;
	}else{
		return false;
	}
}
bool SequenceQueue::EnQueue(int e){
	if(this->front == 0 && this->rear == 0){
		this->data[this->rear] = e;
		this->rear++;
		return true;
	}
	this->data[this->rear] = e;
	this->rear++;
	return true;
}
bool SequenceQueue::DeQueue(int &e){
	if(this->front == 0 && this->rear == 0){
		e = -1;
		return false;
	}
	e =  this->data[this->front] ;
	this->front++;
	return true;
}
bool SequenceQueue::GetHead(int &e){
	if(this->front == 0 && this->rear == 0){
		e = -1;
		return false;
	}
	e =  this->data[this->front] ;
	return true;
}
void SequenceQueue::Show(){
	if(this->front == 0 && this->rear == 0){
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
	SequenceQueue squeue ;
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
