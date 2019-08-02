#include <iostream>
#define MaxVertex 5
class MatrixGraph {
	public:
		MatrixGraph();
		~MatrixGraph();
		bool Adjacent(int v1,int v2);//判断图中是否存在边v1，v2
		int* Neighbors(int v);//顶点v的所有边
		bool InsertVertex(int v);
		bool DeleteVertex(int v);
		bool AddEdge(int v1,int v2);
		bool RemoveEdge(int v1,int v2);
		int FirstNeighbor(int v);//v的第一个邻接点
		int* NextNeighbor(int v1,int v2);//v1的除v2的邻接点
		void ShowVertex();
		void ShowEdge();
	private:
		int vertex[MaxVertex];
		int edge[MaxVertex][MaxVertex];
};
MatrixGraph::MatrixGraph() {
	for(int i =0 ; i<MaxVertex; i++) {
		this->vertex[i] = 0;
		for(int j =0; j<MaxVertex; j++) {
			this->edge[i][j]=0;
		}
	}
	std::cout<<"MatrixGraph has created \n";
}
MatrixGraph::~MatrixGraph() {
	std::cout<<"MatrixGraph has deleted \n";
}
bool MatrixGraph::Adjacent(int v1,int v2) {//判断图中是否存在边v1，v2
	if(v1<0 || v1>=MaxVertex||v2<0 || v2>=MaxVertex) {
		return false;
	} else {
		if(this->edge[v1][v2] == 1) {
			return true;
		} else {
			return false;
		}
	}
}
int* MatrixGraph::Neighbors(int v) {//顶点v的所有边
	int *tem = new int[MaxVertex];
	int n = 0;
	for(int i =0; i<MaxVertex; i++) {
		if(this->edge[v][i]!=0 ) {
			tem[n] = i;
			n++;
		}
	}
	if(n == 0) {
		int *i = new int[1];
		i[0] = -1;
		return i;
	}
	int *res = new int[n];
	for(int i =0; i<n; i++) {
		res[i] = tem[i];
	}
	return res;
}
bool MatrixGraph::InsertVertex(int v) {
	if(v<0 || v>=MaxVertex) {
		return false;
	}
	if(this->vertex[v] != 0) {
		return false;
	} else {
		this->vertex[v] = 1;
		return true;
	}
}
bool MatrixGraph::DeleteVertex(int v) {
	if(v<0 || v>=MaxVertex) {
		return false;
	}
	if(this->vertex[v] != 1) {
		return false;
	} else {
		this->vertex[v] = 0;
		return true;
	}
}
bool MatrixGraph::AddEdge(int v1,int v2) {
	if(v1<0 || v1>=MaxVertex||v2<0 || v2>=MaxVertex) {
		return false;
	}
	if(this->vertex[v1] == 0 || this->vertex[v2] == 0 ) {
		return false;
	}
	if(this->edge[v1][v2] != 0 || this->edge[v2][v1] != 0) {
		return false;
	} else {
		this->edge[v1][v2] = 1;
		this->edge[v2][v1] = 1;
		return true;
	}
}
bool MatrixGraph::RemoveEdge(int v1,int v2) {
	if(v1<0 || v1>=MaxVertex||v2<0 || v2>=MaxVertex) {
		return false;
	}
	if(this->vertex[v1] == 0 || this->vertex[v2] == 0 ) {
		return false;
	}
	if(this->edge[v1][v2] != 1 ||this->edge[v2][v1] != 1) {
		return false;
	} else {
		this->edge[v1][v2] = 0;
		this->edge[v2][v1] = 0;
		return true;
	}
}
int MatrixGraph::FirstNeighbor(int v) {//v的第一个邻接点
	if(v<0 || v>=MaxVertex) {
		return false;
	}
	for(int i =0; i<MaxVertex; i++) {
		if(this->edge[v][i]!=0) {
			return i;
		}
	}
	return -1;
}
int* MatrixGraph::NextNeighbor(int v1,int v2) {//v1的除v2的邻接点
	int *tem = new int[MaxVertex];
	int n = 0;
	for(int i =0; i<MaxVertex; i++) {
		if(this->edge[v1][i]!=0 && i!=v2) {
			tem[n] = i;
			n++;
		}
	}
	if(n == 0) {
		int *i = new int[1];
		i[0] = -1;
		return i;
	}
	int *res = new int[n];
	for(int i =0; i<n; i++) {
		res[i] = tem[i];
	}
	return res;
}

void MatrixGraph::ShowVertex() {
	std::cout<<"showVertex: \n";
	for(int i = 0; i<MaxVertex; i++) {
		std::cout<<this->vertex[i]<<" ";
	}
	std::cout<<"\n";
}

void MatrixGraph::ShowEdge() {
	std::cout<<"showEdge: \n";
	for(int i = 0; i<MaxVertex; i++) {
		for(int j =0 ; j<MaxVertex; j++) {
			std::cout<<this->edge[i][j]<<" ";
		}
		std::cout<<"\n";
	}

}

void test() {
	MatrixGraph mgraph;
	mgraph.InsertVertex(0);
	mgraph.InsertVertex(2);
	mgraph.InsertVertex(3);
	mgraph.ShowVertex();
	mgraph.AddEdge(0,2);
	mgraph.AddEdge(0,3);
	mgraph.AddEdge(2,3);
	mgraph.ShowEdge();
}

int main() {
	test();
	return 0;
}

