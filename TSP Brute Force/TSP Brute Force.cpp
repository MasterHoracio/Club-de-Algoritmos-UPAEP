/*
*	Author: Horacio Jesús Jarquín Vásquez
*	University: Universidad Popular Autonoma del Estado de Puebla
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

#define INF INT_MAX

using namespace std;

int computeCurrentCost(int Array[], int cost[10][10], int n){
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += cost[Array[i] - 1][Array[i + 1] - 1];
	return sum;
}

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
	for(int i = 1; i < n - 1; i++){
		if(Array[i] < Array[i + 1])
			max_i = i;
	}
	return max_i;
}

int find_max_of_i(int Array[], int max_i, int n){
	int max_j;
	for(int i = 1; i < n; i++){
		if(Array[i] > Array[max_i])
			max_j = i;
	}
	return max_j;
}

int main(){
	freopen ("in/in_10.txt","r",stdin);
	int Array[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1}, cost[10][10];
	int n = 10, max_i, max_j, min, sum;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> cost[i][j];
	
	min = INF;
	
	for(;;){
		
		sum = computeCurrentCost(Array, cost, n);
		
		if(sum < min){
			min = sum;
			for(int i = 0; i <= n; i++)
				(i + 1 <= n) ? cout << Array[i] << " " : cout << Array[i] << endl;
			cout << min << endl;
		}
		
		max_i = find_precedence(Array, n);
		max_j = find_max_of_i(Array, max_i, n);
		
		if(max_i == -1)
			break;
		
		custom_swap(Array, max_i, max_j);
		custom_reverse(Array, max_i + 1, n - 1);
	}
	fclose (stdout);
	
	return 0;
}
