#include <cstdio>

#define maxn 10005

using namespace std;

int max(int a, int b){if(a > b) return a; return b;}

int tree[maxn] = {0};

void _build_segment_tree(int node, int begin, int end, int Array[]){
	if(begin == end){
		tree[node] = Array[begin];
	}else{
		int mid = (begin + end)/2;

		_build_segment_tree(node * 2, begin, mid, Array);

		_build_segment_tree((node * 2) + 1, mid + 1, end, Array);

		tree[node] = max(tree[node * 2], tree[(node * 2) + 1]);
	}
}

int main(){
	int Array[8] = {5,2,-5,8,22,4,21,9};

	_build_segment_tree(1, 0, 7, Array);

	for(int i = 1; i <= (2 * 8) - 1; i++)
		printf("tree[%d] = %d\n",i,tree[i]);

	return 0;
}