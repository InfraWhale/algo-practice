#include <bits/stdc++.h> // 에라토스테네스 체 

using namespace std;

vector<int> era(int mx_n){
	vector<int> v;
	vector<int> che(mx_n, 0);
	
	for(int i = 2; i <= mx_n; i++){
		if(che[i]) continue;
		for(int j = 2 * i; j <= mx_n; j += i){
			che[j] = 1;
		}
	}
	
	for(int i = 2; i <= mx_n; i++) {
		if(che[i] == 0) {
			v.push_back(i);
		}
	}

	return v;
}

int main() {
	
	vector<int> vec;
	vec = era(100);
		
	for(int i = 0; i < vec.size(); i++ ) {
		cout << vec[i] << '\n';
	}
	
	return 0;
}
