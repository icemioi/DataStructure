#include <iostream>
#include <queue>
#include <stack>

using namespace std;
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
		void LevelTravel(Node *node);

		void StackPreTravel(Node *node);
		void StackMidTravel(Node *node);
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

Node* BinaryTree::GetRoot() {
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

void BinaryTree::PreTravel(Node *node) {
	if(node == NULL) {
		return;
	} else {
		std::cout<<node->data<<"->";
		this->PreTravel(node->lchild);
		this->PreTravel(node->rchild);
	}

}

void BinaryTree::StackPreTravel(Node *node) {
	if(node == NULL) {
		return;
	}
	stack<Node*> pstack;
	Node *tem ;
	while(node||!pstack.empty()) {
		if(node) {
			cout<<node->data<<"->";
			pstack.push(node);
			node = node->lchild;
		} else {
			tem = pstack.top();
			pstack.pop();
			node = tem->rchild;
		}



	}

}

void BinaryTree::MidTravel(Node *node) {

	if(node == NULL) {
		return;
	} else {
		this->MidTravel(node->lchild);
		std::cout<<node->data<<"->";
		this->MidTravel(node->rchild);
	}
}

void BinaryTree::StackMidTravel(Node *node) {
	if(node == NULL) {
		return;
	}
	stack<Node*> pstack;
	Node *tem ;
	while(node||!pstack.empty()) {
		if(node) {
			pstack.push(node);
			node = node->lchild;
		} else {
			tem = pstack.top();
			cout<<tem->data<<"->";
			pstack.pop();
			node = tem->rchild;
		}

	}

}

void BinaryTree::PostTravel(Node *node) {

	if(node == NULL) {
		return;
	} else {
		this->MidTravel(node->lchild);
		this->MidTravel(node->rchild);
		std::cout<<node->data<<"->";
	}
}

void BinaryTree::LevelTravel(Node *node) {
	if(node == NULL) {
		return ;
	}
	queue<Node*> vqueue;
	Node *vtem;
	vqueue.push(node);
	while(!vqueue.empty()) {
		vtem = vqueue.front();
		cout<<vtem->data<<"->";
		vqueue.pop();
		if(vtem->lchild !=NULL) {
			vqueue.push(vtem->lchild);
		}
		if(vtem->rchild !=NULL) {
			vqueue.push(vtem->rchild);
		}
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
	std::cout<<"\n StackPreTravel:\n";
	binaryTree.StackPreTravel(binaryTree.GetRoot());
	std::cout<<"\n MidTravel:\n";
	binaryTree.MidTravel(binaryTree.GetRoot());
	std::cout<<"\n StackMidTravel:\n";
	binaryTree.StackMidTravel(binaryTree.GetRoot());
	std::cout<<"\n PostTravel:\n";
	binaryTree.PostTravel(binaryTree.GetRoot());
	std::cout<<"\n LeveLTravel:\n";
	binaryTree.LevelTravel(binaryTree.GetRoot());
	std::cout<<"\n";
}



int main() {
	test();
	return 0;
}
