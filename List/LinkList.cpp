# include "iostream"

struct LNode {
	int data;
	struct LNode *next;
};

class LinkList {
	public:
		LinkList();
		~LinkList();
		bool ListisEmpty();
		int ListLength();
		bool ListInsert(int e);
		int ListGetElem(int i);
		void ListShow();
		bool ListDelete(int i,int &e);
		int ListLocateElem(int e);

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

bool LinkList::ListisEmpty() {
	if(this->head->next== NULL && this->tail == NULL) {
		return true;
	} else {
		return false;
	}
}

int LinkList::ListLength() {
	int length =0;
	LNode *htem = this->head;
	while(htem->next!= NULL) {
		length++;
		htem = htem->next;
	}
	return length;
}

bool LinkList::ListInsert(int e) {
	if(this->head == NULL) {
		return false;
	}

	if(this->head->next == NULL) {
		LNode *NNode = new LNode();
		NNode->data = e;
		NNode->next = NULL;
		this->head->next = NNode;
		this->tail = NNode;
		return true;
	}

	LNode *NNode = new LNode();
	NNode->data = e;
	NNode->next = NULL;
	this->tail->next = NNode;
	this->tail = NNode;
	return true;
}

int LinkList::ListGetElem(int i) {
	if(this->head->next == NULL) {
		return 0;
	}
	LNode *htem = this->head;
	int n = 1;
	while(n<i&&htem->next!=NULL) {
		htem = htem->next;
		n++;
	}
	if(htem->next == NULL) {
		return 0;
	} else {
		return htem->next->data;
	}

}

void LinkList::ListShow() {
	LNode *htem = this->head;
	while(htem->next !=NULL) {
		if(htem->next->next !=NULL) {
			std::cout<<htem->next->data<<"->";
		} else {
			std::cout<<htem->next->data;
		}
		htem = htem->next;
	}
	std::cout<<std::endl;
}

bool LinkList::ListDelete(int i,int &e) {

	if(i<1 || this->head->next == NULL) {
		e = -1;
		return false;
	}
	LNode *htem = this->head;
	int n = 1;
	while(n<i-1&&htem->next!=NULL) {
		htem = htem->next;
		n++;
	}
	if(htem->next == NULL || htem->next->next == NULL) {
		e = -1;
		return false;
	} else {
		LNode *tem = htem->next->next;
		LNode *dtem;
		dtem = htem->next;
		e = dtem->data;
		htem->next = tem;
		delete dtem;
		return true;
	}
}
int LinkList::ListLocateElem(int e) {
	int i =0;
	LNode *htem = this->head;
	while(htem->next !=NULL) {
		i++;
		htem = htem->next;
		if(htem->data == e) {
			return i;
		}
	}
	return 0;
}

int main() {

	LinkList linkList ;
	int e =0;
	int i=0;
	int length =0;
	linkList.ListisEmpty();
	linkList.ListInsert(1);
	linkList.ListInsert(2);
	linkList.ListInsert(3);
	linkList.ListInsert(4);
	linkList.ListShow();
	linkList.ListisEmpty();
	length = linkList.ListLength();
	std::cout<<"Len: "<<length<<std::endl;
	e = linkList.ListGetElem(2);
	std::cout<<"Get: "<<e<<std::endl;
	linkList.ListDelete(1,e);
	std::cout<<"Del: "<<e<<std::endl;
	linkList.ListShow();
	length = linkList.ListLength();
	std::cout<<"Len: "<<length<<std::endl;
	i = linkList.ListLocateElem(3);
	std::cout<<"Loc: "<< i<<std::endl;
	return 0;
}
