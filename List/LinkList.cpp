# include "iostream"

struct LNode {
	int data;
	struct LNode *next;
};

class LinkList {
	public:
		LinkList();
		~LinkList();

	private:
		LNode *head;
		LNode *tail;
		
};

LinkList::LinkList() {
	this->head = new LNode;
	this->head->next=NULL;
	this->tail=NULL;
	std::cout<<"LinkList has created\n";
}

LinkList::~LinkList() {
	LNode *tem, *htem;
	htem = head;
	while(htem->next) {
		tem = htem;
		htem = htem->next;
		delete tem;
	}
}
