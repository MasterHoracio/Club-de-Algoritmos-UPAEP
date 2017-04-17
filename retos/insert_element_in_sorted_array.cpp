#include <cstdio>
#include <cstring>

#define maxn 100

using namespace std;

void insert(int set[], int len, int num){
	int pos, prev, temp;
	bool cont = true;
	
	for(int i = 0; i < len && cont; i++){
		if(num < set[i]){
			pos = i;
			cont = false;
		}
	}
	
	if(cont)
		pos = len;
	
	temp = set[pos];
	set[pos] = num;
	
	for(int i = pos + 1; i < len + 1; i++){
		prev = temp;
		temp = set[i];
		set[i] = prev;
	}
}

void _print(int set[], int len){
	for(int i = 0; i < len; i++)
		printf("%d ",set[i]);
	printf("\n");
}

int main(){
	int set[maxn], tc, num, len = 6;
	
	memset(set, 0, sizeof(set));
	
	set[0] = -8;
	set[1] =  1;
	set[2] =  7;
	set[3] = 17;
	set[4] = 21;
	set[5] = 54;
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d",&num);
		insert(set, len++, num);
		_print(set, len);
	}
	return 0;
}
