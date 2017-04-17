#include <cstdio>

#define maxn 100

using namespace std;

int max(int a, int b){if(a > b) return a; return b;}

int tree[maxn] = {0};

void _build_segment_tree(int node, int start, int end, int Array[]){
	if(start == end){
		tree[node] = Array[start];
	}else{
		int mid = (start + end)/2;
		_build_segment_tree(node * 2, start, mid, Array);
		_build_segment_tree(node * 2 + 1, mid + 1, end, Array);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int _query_segment_tree(int node, int start, int end, int l, int r){
	if(r < start || l > end || start > end)//fuera de limites
		return -100000;
	if(l <= start && r >= end)//esta dentro de limite
		return tree[node];

	int mid = (start + end)/2;

	int p1 = _query_segment_tree(node * 2, start, mid, l, r);
	int p2 = _query_segment_tree(node * 2 + 1, mid + 1, end, l, r);

	return max(p1, p2);
}

int main(){
	int Array[8] = {5,2,-5,8,22,4,21,9};

	_build_segment_tree(1, 0, 7, Array);

	printf("%d\n",_query_segment_tree(1, 0, 7, 2, 5));
	printf("%d\n",_query_segment_tree(1, 0, 7, 0, 7));
	printf("%d\n",_query_segment_tree(1, 0, 7, 0, 2));
	printf("%d\n",_query_segment_tree(1, 0, 7, 3, 3));


	return 0;
}