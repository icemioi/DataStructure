#include "iostream"

struct LNode {
	int data;
	LNode *next;
};

class LinkQueue {
	public:
		LinkQueue();
		~LinkQueue();
		bool QueueIsEmpty();
		bool EnQueue(int e);
		bool DeQueue(int &e);
		bool GetHead(int &e);
		void Show();

	private:
		LNode *head;
		LNode *rear;
};

LinkQueue::LinkQueue() {
	this->head = new LNode();
	this->head->next = NULL;
	this->rear = NULL;
	std::cout<<"queue has created\n";
}
LinkQueue::~LinkQueue() {
	LNode *htem = this->head;
	while(htem->next !=NULL) {
		LNode *dtem;
		dtem = htem->next;
		this->head->next = this->head->next->next;
		delete dtem;
	}
	delete this->head;
	std::cout<<"queue has deleted\n";
}
bool LinkQueue::QueueIsEmpty() {
	if(this->head->next == NULL && this->rear == NULL) {
		return true;
	} else {
		return false;
	}
}

bool LinkQueue::EnQueue(int e) {
	if(this->head->next == NULL && this->rear == NULL) {
		LNode *node = new LNode;
		node->data = e;
		node->next=NULL;
		this->head->next = node;
		this->rear = this->head->next;
		return true;
	}
	LNode *node = new LNode;
	LNode *tem;
	tem = this->rear;
	node->data = e;
	node->next = NULL;
	tem->next = node;
	this->rear = node;
	return true;
}
bool LinkQueue::DeQueue(int &e) {
	if(this->head->next == NULL && this->rear == NULL) {
		e = -1;
		return false;
	}
	LNode *dtem = this->head->next;
	this->head->next = dtem->next;
	e = dtem->data;
	delete dtem;
	return true;
}
bool LinkQueue::GetHead(int &e) {
	if(this->head->next == NULL && this->rear == NULL) {
		e = -1;
		return false;
	}
	LNode *tem = this->head->next;
	e = tem->data;
	return true;
}
void LinkQueue::Show() {
	LNode *htem = this->head;
	while(htem->next!=NULL){
		std::cout<<htem->next->data<<"->";
		htem = htem->next;
	}
	std::cout<<"rear\n";
}

void test(){
	LinkQueue linkqueue ;
	int e = 0;
	if(linkqueue.QueueIsEmpty()){
		std::cout<<"empty\n";
	}else{
		std::cout<<"notempty\n";
	}
	linkqueue.EnQueue(1);
	linkqueue.EnQueue(2);
	linkqueue.EnQueue(3);
	linkqueue.Show();
	if(linkqueue.QueueIsEmpty()){
		std::cout<<"empty\n";
	}else{
		std::cout<<"notempty\n";
	}
	linkqueue.DeQueue(e);
	std::cout<<e<<std::endl;
	linkqueue.GetHead(e);
	std::cout<<e<<std::endl;
	linkqueue.Show();
}

int main(){
	test();
	return 0;
}
