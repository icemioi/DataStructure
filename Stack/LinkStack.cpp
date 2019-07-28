#include "iostream"

struct LNode{
	int data;
	LNode* next;
};

class LinkStack{
	public:
		LinkStack();
		~LinkStack();
		bool StackIsEmpty();
		bool StackPush(int e);
		bool StackPop(int &e);
		bool StackGetTop(int &e);
		void StackShow();
	private:
		LNode* head;
		LNode* tail;
};
LinkStack::LinkStack(){
	this->head = new LNode;
	this->head->next = NULL;
	std::cout<<"stack has created\n";
}
LinkStack::~LinkStack(){
	LNode *tem = this->head;
	if(this->head->next!=NULL){
		this->head = this->head->next;
		delete tem;
	}
	delete this->head;
	std::cout<<"stack has deleted\n";
}
bool LinkStack::StackIsEmpty(){
	if(this->head->next == NULL ){
		return true;
	}else{
		return false;
	}
}

bool LinkStack::StackPush(int e){
	if(this->head->next == NULL){
		LNode *node = new LNode();
		node->data = e;
		node->next = NULL;
		this->head->next = node;
		return true;
	}
	LNode *tem =this->head->next;
	LNode *node = new LNode();
	node->data = e;
	node->next = tem;
	this->head->next = node;
	return true;
}
bool LinkStack::StackPop(int &e){
	if(this->head->next == NULL){
		e = -1;
		return false;
	}
	LNode *tem = this->head->next;
	LNode *next = tem->next;
	this->head->next = next;
	e = tem->data;
	delete tem;
	return true;
}
bool LinkStack::StackGetTop(int &e){
	if(this->head->next == NULL){
		e = -1;
		return false;
	}else{
		e = this->head->next->data;
		return true;
	}
}
void LinkStack::StackShow(){
	LNode *htem = this->head;
	while(htem->next != NULL){
		std::cout<<htem->next->data<<"->";
		htem = htem->next;
	}
	std::cout<<"bottom\n";
}

void test(){
	LinkStack linkstack;
	int e = 0;
	linkstack.StackPush(1);
	linkstack.StackPush(2);
	linkstack.StackPush(3);
	linkstack.StackShow();
	if(linkstack.StackIsEmpty()){
		std::cout<<"empty\n";
	}else{
		std::cout<<"notempty\n";
	}
	linkstack.StackPop(e);
	std::cout<<e<<std::endl;
	linkstack.StackGetTop(e);
	std::cout<<e<<std::endl;
	linkstack.StackShow();
}

int main(){
	test();
	return 0;
}
