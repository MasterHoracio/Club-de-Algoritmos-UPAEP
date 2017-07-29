/*
*	Author: Horacio Jesús Jarquín Vásquez
*	University: Universidad Popular Autonoma del Estado de Puebla
*
*	Argorithm:
*	1.- Find the largest i such that P[i] < P[i + 1]. (If there is no such x, P is the last permutation.)
*	2.- Find the largest j such that P[i] < P[j].
*	3.- Swap P[i] and P[j].
*	4.- Reverse P[i + 1 ... n].
*
*	time complexity: O(n.n!)
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <cctype>
#include <queue>
#include <cmath>
#include <list>

#define INF LLONG_MAX

using namespace std;

void custom_swap(int Array[], int i, int j){
	int tmp = Array[i];
	Array[i] = Array[j];
	Array[j] = tmp;
}

void custom_reverse(int Array[], int j, int n){
	int tmp;
	while(j != n && j < n){
		tmp = Array[j];
		Array[j++] = Array[n];
		Array[n--] = tmp;
	}
}

int find_precedence(int Array[], int n){
	int max_i = -1;
	for(int i = 0; i < n - 1; i++){
		if(Array[i] < Array[i + 1])
			max_i = i;
	}
	return max_i;
}

int find_max_of_i(int Array[], int max_i, int n){
	int max_j;
	for(int i = 0; i < n; i++){
		if(Array[i] > Array[max_i])
			max_j = i;
	}
	return max_j;
}

int main(){
	int Array[4] = {0, 1, 2, 3};
	int n = 4, max_i, max_j;
	
	for(;;){
		
		for(int i = 0; i < n; i++){
			(i + 1 < n) ? printf("%d ",Array[i]) : printf("%d\n",Array[i]);
		}
		
		max_i = find_precedence(Array, n);
		max_j = find_max_of_i(Array, max_i, n);
		
		if(max_i == -1)
			break;
		
		custom_swap(Array, max_i, max_j);
		custom_reverse(Array, max_i + 1, n - 1);
	}
	
	return 0;
}
