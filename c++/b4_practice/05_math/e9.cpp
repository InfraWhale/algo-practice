#include<bits/stdc++.h> // 소수 구하기 2
using namespace std;

vector<int> era(int mx_n){
	vector<int> v;
	int che[100] ={0, };
	
	for(int i = 2; i <= mx_n; i++){
		if(che[i]) continue;
		for(int j = 2*i; j <= mx_n; j += i){
			che[j] = 1;
		}
	}
	for(int i = 2; i <= mx_n; i++) if(che[i] == 0) v.push_back(i);
	return v;
}

int main(){
	
	vector<int> chera = era(20);
	
	for(auto e : chera){
		cout << e << "\n";
	}
	return 0;
}
