#include "iostream"
#define MAXSize 50
using namespace std;


class SequenceList {

	public:
		SequenceList();
		~SequenceList();
		bool ListInsert(int i,int e);
		void ListShow();
		bool ListInit(int n);
		bool ListDelete(int i,int &e);
		int ListLength();
		bool ListIsEmpty();
		int GetElem(int i);
		int LocateElem(int e);
	private:
		int data[MAXSize];
		int length;
};

SequenceList::SequenceList() {
	std::cout<<"SequenceList has created\n";
}

SequenceList::~SequenceList() {
	std::cout<<"SequenceList has destroyed\n";
}
bool SequenceList::ListInsert(int i,int e) {
	if(i<1||i>MAXSize) {
		return false;
	}
	if(this->length>=MAXSize) {
		return false;
	}

	for(int k=this->length; k>=i; k--) {
		this->data[k] = this->data[k-1];
	}
	this->data[i-1] = e;
	this->length++;
	return true;

}

void SequenceList::ListShow() {
	for(int i=0; i<MAXSize; i++) {
		if(this->data[i] == -1) {
			break;
		}
		if(i == MAXSize-1) {
			std::cout<<this->data[i];
		} else {
			std::cout<<this->data[i]<<"->";
		}

	}
	std::cout<<"end"<<std::endl;

}

bool SequenceList::ListInit(int n) {
	if(n<1||n>MAXSize) {
		return false;
	}
	this->length=0;
	for(int i=0; i<MAXSize; i++) {
		this->data[i] = -1;
	}
	for(int i=0; i<n; i++) {
		int e=0;
		cout<<"input a negative int number :\n";
		cin>>e;
		this->data[i] = e;
		this->length++;
	}
	return true;
}

bool SequenceList::ListDelete(int i,int &e) {
	if(i<1||i>MAXSize) {
		return false;
	}
	if(i>this->length) {
		return false;
	}
	e = this->data[i-1];
	for(int k=i; k<this->length; i++) {
		this->data[k-1]=this->data[k];
	}
	this->length--;
	return true;
}

bool SequenceList::ListIsEmpty() {
	if(this->length == 0) {
		return true;
	} else {
		return false;
	}
}

int SequenceList::ListLength() {
	return this->length;
}

int SequenceList::GetElem(int i) {
	if(i<1 || i>this->length) {
		return -1;
	}

	return this->data[i-1];

}

int SequenceList::LocateElem(int e) {
	for(int i =0; i<this->length; i++) {
		if(this->data[i] == e) {
			return i+1;
		}
	}
	return -1;
}

int main() {

	SequenceList SqList ;
	int n=0;
	int i=0,e=0;
	bool isEmpty=true;
	std::cout<<"input n to init the List \n";
	std::cin>>n;
	SqList.ListInit(n);
	SqList.ListShow();
	std::cout<<"input i and e to insert in ith \n";
	std::cin>>i>>e;
	SqList.ListInsert(i,e);
	SqList.ListShow();
	isEmpty = SqList.ListIsEmpty();
	if(isEmpty == false) {
		std::cout<<"isEmpty:false"<<std::endl;
	} else {
		std::cout<<"isEmpty:true"<<std::endl;
	}

	std::cout<<"input i to get ith element\n";
	std::cin>>i;
	std::cout<<SqList.GetElem(i)<<std::endl;
	std::cout<<"input e to get element's sequence\n";
	std::cin>>e;
	std::cout<<SqList.LocateElem(e)<<std::endl;

	return 0;
}
