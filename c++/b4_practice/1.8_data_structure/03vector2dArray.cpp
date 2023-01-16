#include<bits/stdc++.h> // // vector 2차원 배열 
using namespace std;

vector<vector<int>> v1;
vector<vector<int>> v2(10, vector<int>(10, 0));
vector<int> v3[10];

int main(){
	
	// v1
	
	for(int i = 0; i < 10; i++){
		vector<int> vv(10, i);
		v1.push_back(vv);
	}
	
	for(vector<int> v : v1){
		for(int i : v) cout << i << ' ';
		cout << '\n';
	}
	
	cout << '\n';
	
	// v2
	
	for(vector<int> v : v2){
		for(int i : v) cout << i << ' ';
		cout << '\n';
	}
	
	return 0;
}
