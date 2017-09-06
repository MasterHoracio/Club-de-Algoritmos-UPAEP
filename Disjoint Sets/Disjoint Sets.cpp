#include <iostream>
#include <map>

/*	
**		Space complexity: O(n)
**		Time complexity: O(m * a(n))	
*/

using namespace std;

typedef struct{
	int rank;
	int node;
	int parent;
}Node;

map <int, Node> forest;

Node makeNode(int n){
	Node tmp;
	tmp.rank = 0;
	tmp.node = n;
	tmp.parent = n;
	return tmp;
}

int find(int n){
	int parent = forest[n].parent;
	
	if(n == parent){
		return parent;
	}
	forest[n].parent = find(forest[n].parent);
	return forest[n].parent;
}

void Union(int a, int b){
	int parent1 = find(a);
	int parent2 = find(b);
	
	if(parent1 == parent2){
		return;
	}else{
		if(forest[parent1].rank >= forest[parent2].rank){
			forest[parent1].rank = (forest[parent1].rank == forest[parent2].rank) ? forest[parent1].rank + 1 : forest[parent1].rank;
			forest[parent2].parent = forest[parent1].node;
		}else{
			forest[parent1].parent = forest[parent2].node;
		}
	}
}

int main(){
	
	forest[1] = makeNode(1);
	forest[2] = makeNode(2);
	forest[3] = makeNode(3);
	forest[4] = makeNode(4);
	forest[5] = makeNode(5);
	forest[6] = makeNode(6);
	
	Union(1,2);
	Union(2,3);
	
	Union(4,5);
	Union(5,6);
	Union(4,6);
	
	cout << find(1) << endl;
	cout << find(2) << endl;
	cout << find(3) << endl;
	cout << find(4) << endl;
	cout << find(5) << endl;
	cout << find(6) << endl;
	
	Union(3,4);
	
	cout << find(1) << endl;
	cout << find(2) << endl;
	cout << find(3) << endl;
	cout << find(4) << endl;
	cout << find(5) << endl;
	cout << find(6) << endl;
	
	
	return 0;
}
