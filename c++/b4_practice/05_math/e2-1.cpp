#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << "\n";
}

void makePermutation(int n, int r, int depth){ //n : 배열개수 r : 목표 깊이 depth : 현재 깊이 
	if(r == depth){
		cout << "-- ";
		printV(v);
		cout << "-- ";	
		cout << n << " : " << r << " : " << depth <<'\n';
	return;
	}
	for(int i = depth; i < n; i++){
		swap(v[i], v[depth]);
		cout << "@@ ";
		printV(v);
		cout << "@@ ";
		cout << n << " : " << r << " : " << depth <<'\n';
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
		cout << "## ";		
		printV(v);
		cout << "## ";	
		cout << n << " : " << r << " : " << depth <<'\n';
	}
	return;
}

int main(){
	for(int i = 0; i < 3; i++)
		v.push_back(a[i]);
	makePermutation(3, 3, 0);
	return 0;
}
