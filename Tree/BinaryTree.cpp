#include "iostream"

struct Node {
	int data;
	Node *lchild;
	Node *rchild;
};

class BinaryTree {
	public:
		BinaryTree();
		~BinaryTree();
		Node* GetRoot();
		bool BinaryTreeInsert(int e);
		bool BinaryTreeIsEmpty();
		void PreTravel(Node *node);
		void MidTravel(Node *node);
		void PostTravel(Node *node);
	private:
		Node *root;

};

BinaryTree::BinaryTree() {
	this->root=NULL;
	std::cout<<"BinaryTree has created\n";
}

BinaryTree::~BinaryTree() {
	delete this->root;
	std::cout<<"BinaryTree has deleted\n";
}

Node* BinaryTree::GetRoot(){
	return this->root;
}

bool BinaryTree::BinaryTreeIsEmpty() {
	if(this->root == NULL) {
		return true;
	} else {
		return false;
	}
}

bool BinaryTree::BinaryTreeInsert(int e) {
	if(this->root == NULL) {
		this->root = new Node();
		this->root->data = e;
		this->root->lchild = NULL;
		this->root->rchild = NULL;
		return true;
	}
	Node *tem = this->root;
	bool hasInserted = false;
	while(!hasInserted) {
		if( e < tem->data) {
			if(tem->lchild == NULL) {
				Node *ltem = new Node();
				ltem->data = e;
				ltem->lchild = NULL;
				ltem->rchild = NULL;
				tem->lchild = ltem;
				hasInserted = true;
				break;
			}
			tem = tem->lchild;

		} else {
			if(tem->rchild == NULL) {
				Node *rtem = new Node();
				rtem->data = e;
				rtem->lchild = NULL;
				rtem->rchild = NULL;
				tem->rchild = rtem;
				hasInserted = true;
				break;
			}
			tem = tem->rchild;
		}
	}

}

void BinaryTree::PreTravel(Node *node){
	if(node == NULL){
		return;
	}else{
		std::cout<<node->data<<"->";
		this->PreTravel(node->lchild);
		this->PreTravel(node->rchild);
	}
	
}

void BinaryTree::MidTravel(Node *node){
	
	if(node == NULL){
		return;
	}else{
		this->MidTravel(node->lchild);
		std::cout<<node->data<<"->";
		this->MidTravel(node->rchild);
	}
}

void BinaryTree::PostTravel(Node *node){
	
	if(node == NULL){
		return;
	}else{
		this->MidTravel(node->lchild);
		this->MidTravel(node->rchild);
		std::cout<<node->data<<"->";
	}
}


void test() {
	BinaryTree binaryTree;
	binaryTree.BinaryTreeInsert(5);
	binaryTree.BinaryTreeInsert(1);
	binaryTree.BinaryTreeInsert(6);
	binaryTree.BinaryTreeInsert(3);
	std::cout<<"\n PreTravel:\n";
	binaryTree.PreTravel(binaryTree.GetRoot());
	std::cout<<"\n MidTravel:\n";
	binaryTree.MidTravel(binaryTree.GetRoot());
	std::cout<<"\n PostTravel:\n";
	binaryTree.PostTravel(binaryTree.GetRoot());
	std::cout<<"\n";
}



int main() {
	test();
	return 0;
}
