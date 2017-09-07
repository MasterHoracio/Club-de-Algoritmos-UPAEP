#include <iostream>
#include <vector>
#include <set>

/*
**	Time Complexity: O(E +V)
**	Space Complexity: O(V)
*/

using namespace std;

const int maxn = 1e3 + 10;
vector <int> Grafo[maxn];

void addEdge(int a, int b){
	Grafo[a].push_back(b);
}

void moveNode(int node, set <int> &origin, set <int> &destiny){
	origin.erase(node);
	destiny.insert(node);
}

bool dfs(int node, set <int> &unVisited, set <int> visiting, set <int> visited){
	moveNode(node, unVisited, visiting);
	for(int i = 0; i < Grafo[node].size(); i++){
		
		if(visited.find(Grafo[node][i]) != visited.end())
			continue;
		
		if(visiting.find(Grafo[node][i]) != visiting.end())
			return true;
			
		if(dfs(Grafo[node][i], unVisited, visiting, visited))
			return true;
	}
	moveNode(node, visiting, visited);
	return false;
}

bool hasCycle(int n){
	set <int>::iterator it;
	set <int> unVisited;
	set <int> visiting;
	set <int> visited;
	int curr;
	
	for(int i = 1; i <= n; i++)
		unVisited.insert(i);
		
	while(unVisited.size() > 0){
		it = unVisited.begin();
		curr = *it;
		if(dfs(curr, unVisited, visiting, visited)){
			return true;
		}
	}
	return false;
}

int main(){
	
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(1, 3);
	addEdge(4, 5);
	addEdge(4, 1);
	addEdge(5, 6);
	addEdge(6, 4);
	
	if(hasCycle(6)){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	
	return 0;
}
